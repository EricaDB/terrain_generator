/*
 * terrain_generator.cpp
 */

#include <random>
#include <algorithm>  // to fill arrays with characters
#include <iostream>
#include <tuple>
#include <map>
#include <vector>

#include "generator.hpp"
#include "terrain_generator.hpp"
#include "tile.hpp"

// Constructor, initialize variables and allocate memory for map
TerrainGenerator::TerrainGenerator(
    int row, int col, int smoothness, 
    int water_amount, int valley_amount, int mountains_amount
    ) : Generator() {
    this->mountain.setType("mountain");
    this->water.setType("water");
    this->valley.setType("valley");
        
    this->mountain.setName("Mountain");
    this->water.setName("Water");
    this->valley.setName("Valley");
        
    this->row = row;
    this->col = col;
    this->water_amount = water_amount;
    this->valley_amount = valley_amount;
    this->mountains_amount = mountains_amount;

    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->mountain);
    }
    makeMap();
    for (int i = 0; i < smoothness; i++) {
        smoothMap();
    }
}

// Destructor, free the map memory
TerrainGenerator::~TerrainGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

void TerrainGenerator::makeMap() {
    //fills map with random tiles
    int array_len = this->water_amount + 
                    this->valley_amount + 
                    this->mountains_amount;
    std::vector<Tile> terrain;

    int i = 0;
    while (i < array_len) {
        
        if (i < this->water_amount) {
            terrain.push_back(this->water); 
        }
        else if (i < this->water_amount + this->valley_amount) {
            terrain.push_back(this->valley); 
        }
        else if (i < array_len) {
            terrain.push_back(this->mountain); 
        }
        i++;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, array_len - 1);
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            this->map[r][c] = terrain[dist(mt)];
        }
    }
}

void TerrainGenerator::smoothMap() {
    std::map<std::string, int> majority;
    int max;
    std::string max_tile;
    std::tuple<int, int> *coords_arr= getArrayOfRandomCoords();
    int r, c;
    for (int a = 0; a < this->row * this->col - 1; a++) {
        r = std::get<0>(coords_arr[a]);
        c = std::get<1>(coords_arr[a]);
        
        majority[this->water.getType()] = 0;
        majority[this->valley.getType()] = 0;
        majority[this->mountain.getType()] = 0;
        //clear out the map each time

        if (r > 0) {
            majority[this->map[r - 1][c].getType()] += 1;
            if (c > 0) {
                majority[this->map[r - 1][c - 1].getType()] += 1;
            }
            if (c + 1 < this->col) {
                majority[this->map[r - 1][c + 1].getType()] += 1;
            }
        }
        if (c > 0) {
            majority[this->map[r][c - 1].getType()] += 1;
        }
        if (c + 1 < this->col) {
            majority[this->map[r][c + 1].getType()] += 1;
        }
        if (r + 1 < this->row) {
            majority[this->map[r + 1][c].getType()] += 1;
            if (c > 0) {
                majority[this->map[r + 1][c - 1].getType()] += 1;
            }
            if (c + 1 < this->col) {
                majority[this->map[r + 1][c + 1].getType()] += 1;
            }
        }
        // find the char with the biggest count and set
        // the current char to be that char
        max = 0;
        for (auto iterator = majority.begin();
             iterator != majority.end();
             iterator++) {
            if (iterator->second > max) {
              max = iterator->second;
              max_tile = iterator->first;
            }
        }
        
        if (max_tile == this->water.getType()) {
            this->map[r][c] = this->water;
        } else if (max_tile == this->valley.getType()) {
            this->map[r][c] = this->valley;
        } else {
            this->map[r][c] = this->mountain;
        }
    }
}

void TerrainGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            if (this->map[r][c].getType() == "water") {
                std::cout << " ";
            } else if (this->map[r][c].getType() == "mountain") {
                std::cout << "^";
            } else {
                std::cout << ".";
            }
       }
        std::cout << std::endl;
    } 
}

Tile **TerrainGenerator::getMap() {
  return this->map;
}

// helper function
std::tuple<int, int> *TerrainGenerator::getArrayOfRandomCoords() {
    std::tuple<int, int> *coords_arr = 
        new std::tuple<int, int>[this->row * this->col];
    int i = 0;
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            std::tuple<int, int> coords (r, c);
            coords_arr[i] = coords;
            i++;
        }
    }
    random_shuffle(&coords_arr[0], &coords_arr[this->row * this->col- 1]);
    return coords_arr;
}
