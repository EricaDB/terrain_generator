/*
 * terrain_generator.cpp
 */

#include <random>
#include <iostream>
#include <algorithm>  // to fill arrays with characters

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
        std::fill(this->map[i], this->map[i] + col, '0');
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
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0,10);
    for (int r = 0; r < this->row; r++) {
        char terrain[11] = {' ', '.', '^', '0', 
                            '0', '0', '0', '0', 
                            '0', '0', '0',};
        for (int c = 0; c < this->col; c++) {
            if (r > 0) {
                terrain[4] = this->map[r - 1][c]; 
                if (c > 0) {
                    terrain[3] = this->map[r - 1][c - 1];
                }
                if (c + 1 < this->col) {
                    terrain[5] = this->map[r - 1][c + 1];
                }
            }
            if (c > 0) {
                terrain[6] = this->map[r][c - 1];
            }
            if (c + 1 < this->col) {
                terrain[7] = this->map[r][c + 1];
            }
            if (r + 1 < this->row) {
                terrain[9] = this->map[r + 1][c]; 
                if (c > 0) {
                    terrain[8] = this->map[r + 1][c - 1];
                }
                if (c + 1 < this->col) {
                    terrain[10] = this->map[r + 1][c + 1];
                }
            }
            char terrain_symbol = '0';
            while (terrain_symbol == '0') {
                terrain_symbol = terrain[dist(mt)];
            }
            this->map[r][c] = terrain_symbol;
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
