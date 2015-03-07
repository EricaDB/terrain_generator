/*
 * altitude_generator.cpp
 */

#include <iostream>
#include "generator.hpp"
#include "tile.hpp"
#include "altitude_generator.hpp"
#include <iomanip> // for setw cout formatting

// Constructor, initialize variables and allocate memory for map
AltitudeGenerator::AltitudeGenerator(int row, int col) :
Generator(), row(row), col(col) {
    this->water.setType("water");
    this->water.setAltitude(0);
    this->land.setType("land");
    this->land.setAltitude(0);
    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->land);
    }
    //makeMap();
}

// Destructor, free the map memory
AltitudeGenerator::~AltitudeGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

void AltitudeGenerator::makeMap() {
    
}

void AltitudeGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            std::cout << std::setw(4) << std::left << this->map[r][c].getType();
        }
        std::cout << std::endl;
    }
}

Tile **AltitudeGenerator::getMap() {
    return this->map;
}