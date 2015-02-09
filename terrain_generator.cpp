/*
 * terrain_generator.cpp
 */

include "generator.hpp"
include "terrain_generator.hpp"

// Constructor, initialize variables and allocate memory for map
TerrainGenerator::TerrainGenerator(int row, int col) : Generator(), mountain("^"), water("~"), valley(".") {
    this->row = row;
    this->col = col;
    this->map = new char*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new char[col];
        for (int j = 0; j < col; j++) {
            this->map[row][col] = ' ';
        }
    }
}

// Destructor, free the map memory
TerrainGenerator::~TerrainGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}
