/*
 * maze_generator.cpp
 */

#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip> // for setw cout formatting

#include "generator.hpp"
#include "tile.hpp"
#include "maze_generator.hpp"

// Constructor, initialize variables and allocate memory for map
MazeGenerator::MazeGenerator(int row, int col) :
Generator(), row(row), col(col) {
    this->wall.setType("wall");
    this->path.setType("path");
    this->wall.setName("Wall");
    this->path.setName("Path");
    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->wall);
    }
    srand(time(0));
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
    buildDoublePath(1, 1); // build first path coords 1, 1
    //create an entrance
    this->map[1][0].setType("path"); 
    //create an exit
    this->map[this->row - 2][this->col - 1].setType("path");
}

//helper function
int myrandom (int i) { 
    return std::rand() % i; 
}

//builds maze, drawback: no guaranteed exit
void MazeGenerator::buildPath(int r, int c) {
    this->map[r][c].setType("path");
    std::vector<std::string> dirs = {"UP", "DOWN", "LEFT", "RIGHT"};
    random_shuffle(dirs.begin(), dirs.end(), myrandom); 
    for (int i = 0; i < 4; i++) {
        if (r > 0 || r < this->row - 1 ||
            c > 0 || c < this->col - 1) {
            if (dirs[i] == "UP" && canBuildPath(r - 1, c, "UP")) {
                buildPath(r - 1, c);
            }
            else if (dirs[i] == "DOWN" && canBuildPath(r + 1, c, "DOWN")) {
                buildPath(r + 1, c);
            }
            else if (dirs[i] == "LEFT" && canBuildPath(r, c - 1, "LEFT")) {
                buildPath(r, c - 1);
            }
            else if (dirs[i] == "RIGHT" && canBuildPath(r, c + 1, "RIGHT")) {
                buildPath(r, c + 1);
            }
        }
    }
}

//builds maze, drawback: only looks good if cave has dimensions of odd number
void MazeGenerator::buildDoublePath(int r, int c) {
    this->map[r][c].setType("path");
    std::vector<std::string> dirs = {"UP", "DOWN", "LEFT", "RIGHT"};
    random_shuffle(dirs.begin(), dirs.end(), myrandom); 
    for (int i = 0; i < 4; i++) {
        if (dirs[i] == "UP" && r > 1 
            && canBuildPath(r - 1, c, "UP")
            && canBuildPath(r - 2, c, "UP")) {
            this->map[r - 1][c].setType("path");  
            buildDoublePath(r - 2, c);
        }
        else if (dirs[i] == "DOWN" && r < this->row - 1
                 && canBuildPath(r + 1, c, "DOWN") 
                 && canBuildPath(r + 2, c, "DOWN")) {
            this->map[r + 1][c].setType("path");
            buildDoublePath(r + 2, c);
        }
        else if (dirs[i] == "LEFT" && c > 1 
                 && canBuildPath(r, c - 1, "LEFT")
                 && canBuildPath(r, c - 2, "LEFT")) {
            this->map[r][c - 1].setType("path");
            buildDoublePath(r, c - 2);
        }
        else if (dirs[i] == "RIGHT" && c < this->col - 1 
                 && canBuildPath(r, c + 1, "RIGHT")
                 && canBuildPath(r, c + 2, "RIGHT")) {
            this->map[r][c + 1].setType("path");
            buildDoublePath(r, c + 2);
        }
    }
}

bool MazeGenerator::canBuildPath(int r, int c, std::string dir) { 
    if (r == 0 || r == this->row - 1 ||
        c == 0 || c == this->col - 1) {
        return false;
    }
    if (dir == "UP" && 
       this->map[r - 1][c - 1].getType() == "wall" && 
       this->map[r - 1][c].getType() == "wall" && 
       this->map[r - 1][c + 1].getType() == "wall" && 
       this->map[r][c - 1].getType() == "wall" && 
       this->map[r][c + 1].getType() == "wall") {
        return true;
    }
    if (dir == "DOWN" && 
       this->map[r + 1][c - 1].getType() == "wall" && 
       this->map[r + 1][c].getType() == "wall" && 
       this->map[r + 1][c + 1].getType() == "wall" && 
       this->map[r][c - 1].getType() == "wall" && 
       this->map[r][c + 1].getType() == "wall") {
        return true;
    }
    if (dir == "LEFT" && 
       this->map[r][c - 1].getType() == "wall" && 
       this->map[r - 1][c - 1].getType() == "wall" && 
       this->map[r + 1][c - 1].getType() == "wall" && 
       this->map[r - 1][c].getType() == "wall" && 
       this->map[r + 1][c].getType() == "wall") {
        return true;
    }
    if (dir == "RIGHT" && 
       this->map[r][c + 1].getType() == "wall" && 
       this->map[r - 1][c + 1].getType() == "wall" && 
       this->map[r + 1][c + 1].getType() == "wall" && 
       this->map[r - 1][c].getType() == "wall" && 
       this->map[r + 1][c].getType() == "wall") {
        return true;
    }
    return false;
}

void MazeGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            if (this->map[r][c].getType() == "wall") {
                std::cout << "@"; 
            }
            else { std::cout << " "; }
        }
        std::cout << std::endl;
    }
}

Tile **MazeGenerator::getMap() {
    return this->map;
}
