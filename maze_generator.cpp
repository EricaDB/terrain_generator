/*
 * maze_generator.cpp
 */

#include <iostream>
#include "generator.hpp"
#include "tile.hpp"
#include "maze_generator.hpp"
#include <iomanip> // for setw cout formatting

// Constructor, initialize variables and allocate memory for map
MazeGenerator::MazeGenerator(int row, int col) :
Generator(), row(row), col(col) {
    this->wall.setType("wall");
    this->path.setType("path");
    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->wall);
    }
    //makeMap();
}

// Destructor, free the map memory
MazeGenerator::~MazeGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

void MazeGenerator::makeMap() {
    
}

void MazeGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            std::cout << std::setw(4) << std::left << this->map[r][c].getType();
        }
        std::cout << std::endl;
    }
}

Tile **MazeGenerator::getMap() {
    return this->map;
}