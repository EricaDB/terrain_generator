/*
 * terrain_generator.cpp
 */

#include <random>
#include <iostream>
#include <algorithm>  // to fill arrays with characters

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
        raffle.put('.', 10);
        raffle.put('^', 1);
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
