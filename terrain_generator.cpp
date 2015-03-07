/*
 * terrain_generator.cpp
 */

#include <random>
#include <iostream>
#include <algorithm>  // to fill arrays with characters
#include <map>
#include <tuple>

#include "raffle.hpp" 
#include "generator.hpp"
#include "terrain_generator.hpp"

// Constructor, initialize variables and allocate memory for map
TerrainGenerator::TerrainGenerator(int row, int col) : 
    Generator(), mountain('^'), water('~'), valley('.') {
    this->row = row;
    this->col = col;
    this->map = new char*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new char[col];
        std::fill(this->map[i], this->map[i] + col, ' ');
    }
    makeMap();
}

// Destructor, free the map memory
TerrainGenerator::~TerrainGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

void TerrainGenerator::makeMap() {
    for (int r = 0; r < this->row; r++) {
        Raffle raffle;
        raffle.put(' ', 1);
        raffle.put('.', 30);
        raffle.put('^', 20);
        for (int c = 0; c < this->col; c++) {
            if (r > 0) {
                raffle.put(this->map[r - 1][c], 1);
                if (c > 0) {
                    raffle.put(this->map[r - 1][c - 1], 1);
                }
                if (c + 1 < this->col) {
                    raffle.put(this->map[r - 1][c + 1], 1);
                }
            }
            if (c > 0) {
                raffle.put(this->map[r][c - 1], 1);
            }
            if (c + 1 < this->col) {
                raffle.put(this->map[r][c + 1], 1);
            }
            if (r + 1 < this->row) {
                raffle.put(this->map[r + 1][c], 1);
                if (c > 0) {
                    raffle.put(this->map[r + 1][c - 1], 1);
                }
                if (c + 1 < this->col) {
                    raffle.put(this->map[r + 1][c + 1], 1);
                }
            }
            char terrain_symbol = raffle.get();
                  terrain_symbol = raffle.get();
            this->map[r][c] = terrain_symbol;
        }
    }
}

void TerrainGenerator::smoothMap() {
    std::map<char, int> majority;
    int max;
    char max_char;
    std::tuple<int, int> *coords_arr= getArrayOfRandomCoords();
    int r, c;
    //for (int r = 0; r < this->row; r++) {
        //for (int c = 0; c < this->col; c++) {
    for (int a = 0; a < this->row * this->col - 1; a++) {
        r = std::get<0>(coords_arr[a]);
        c = std::get<1>(coords_arr[a]);
        majority[' '] = 0;
        majority['.'] = 0;
        majority['^'] = 0; //hard coded, make dynamic ??
        //clear out the map each time

        if (r > 0) {
            majority[this->map[r - 1][c]] += 1;  
            if (c > 0) {
                majority[this->map[r - 1][c - 1]] += 1;  
            }
            if (c + 1 < this->col) {
                majority[this->map[r - 1][c + 1]] += 1;  
            }
        }
        if (c > 0) {
            majority[this->map[r][c - 1]] += 1;  
        }
        if (c + 1 < this->col) {
            majority[this->map[r][c + 1]] += 1;  
        }
        if (r + 1 < this->row) {
            if (c > 0) {
                majority[this->map[r + 1][c - 1]] += 1;  
            }
            if (c + 1 < this->col) {
                majority[this->map[r + 1][c + 1]] += 1;  
            }
        }
        //find the char with the biggest count and set
        //the current char to be that char
        max = 0;
        max_char;
        for (auto iterator = majority.begin();
             iterator != majority.end();
             iterator++) {
            if (iterator->second > max) {
              max = iterator->second;
              max_char = iterator->first;
            }
        }
        if (max_char) {
            this->map[r][c] = max_char;
        }
    }
}

void TerrainGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            std::cout << this->map[r][c];
        }        
        std::cout << std::endl;
    } 
}

char **TerrainGenerator::getMap() {
  return this->map;
}

//helper function
std::tuple<int, int> *TerrainGenerator::getArrayOfRandomCoords() {
    //std::tuple<int, int> coords_arr[this->row * this->col];
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
