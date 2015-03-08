/*
 * maze_generator.cpp
 */

#include "generator.hpp"
#include "tile.hpp"
#include "maze_generator.hpp"

#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip> // for setw cout formatting
#include <ctime>   // std::time 
#include <cstdlib> // std::srand

// Constructor, initialize variables and allocate memory for map
MazeGenerator::MazeGenerator(int row, int col) :
Generator(), row(row), col(col) {
    this->wall.setType("wall");
    this->path.setType("path");
    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->path);
    }
    makeMap();
}

// Destructor, free the map memory
MazeGenerator::~MazeGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

void MazeGenerator::makeMap() {
    buildWall(2, 2); // build first wall at coords 2, 2
}

void MazeGenerator::buildWall(int r, int c) {
    this->map[r][c].setType("wall");
    std::cout << "building walls" << std::endl;
    std::srand(unsigned(std::time(0)));
    std::vector<std::string> dirs = {"UP", "DOWN", "LEFT", "RIGHT"};
    random_shuffle(dirs.begin(), dirs.end()); 
    for (int i = 0; i < 4; i++) {
        if (r > 0 || r < this->row ||
            c > 0 || c < this->col) {
            if (dirs[i] == "UP" && canBuildWall(r - 1, c, "UP")) {
                buildWall(r - 1, c);
            }
            if (dirs[i] == "DOWN" && canBuildWall(r + 1, c, "DOWN")) {
                buildWall(r + 1, c);
            }
            if (dirs[i] == "LEFT" && canBuildWall(r, c - 1, "LEFT")) {
                buildWall(r, c - 1);
            }
            if (dirs[i] == "RIGHT" && canBuildWall(r, c + 1, "RIGHT")) {
                buildWall(r, c + 1);
            }
        }
    }
}

bool MazeGenerator::canBuildWall(int r, int c, std::string dir) { 
    if (r == 0 || r == this->row ||
        c == 0 || c == this->col) {
        return false;
    }
    if (dir == "UP" && 
       this->map[r - 1][c - 1].getType() == "path" && 
       this->map[r - 1][c].getType() == "path" && 
       this->map[r - 1][c + 1].getType() == "path" && 
       this->map[r][c - 1].getType() == "path" && 
       this->map[r][c + 1].getType() == "path") {
        return true;
    }
    if (dir == "DOWN" && 
       this->map[r + 1][c - 1].getType() == "path" && 
       this->map[r + 1][c].getType() == "path" && 
       this->map[r + 1][c + 1].getType() == "path" && 
       this->map[r][c - 1].getType() == "path" && 
       this->map[r][c + 1].getType() == "path") {
        return true;
    }
    if (dir == "LEFT" && 
       this->map[r][c - 1].getType() == "path" && 
       this->map[r - 1][c - 1].getType() == "path" && 
       this->map[r + 1][c - 1].getType() == "path" && 
       this->map[r - 1][c].getType() == "path" && 
       this->map[r + 1][c].getType() == "path") {
        return true;
    }
    if (dir == "RIGHT" && 
       this->map[r][c + 1].getType() == "path" && 
       this->map[r - 1][c + 1].getType() == "path" && 
       this->map[r + 1][c + 1].getType() == "path" && 
       this->map[r - 1][c].getType() == "path" && 
       this->map[r + 1][c].getType() == "path") {
        return true;
    }
    return false;
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
