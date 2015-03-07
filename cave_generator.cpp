/*
 * cave_generator.cpp
 */

#include <random>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip> // for setw cout formatting

#include "generator.hpp"
#include "cave_generator.hpp"
#include "tile.hpp"

// Constructor, initialize variables and allocate memory for map
CaveGenerator::CaveGenerator(int row, int col) :
Generator(), dir(DOWN) {
    this->air.setType("air"); // to make the cave more readable for printMap() change "air" to an empty string
    this->wall.setType("rock");
    
    this->row = row;
    this->col = col;
    this->map = new Tile*[row];
    for (int i = 0; i < row; i++) {
        this->map[i] = new Tile[col];
        std::fill(this->map[i], this->map[i] + col, this->wall);
    }
    makeMap();
}

// Destructor, free the map memory
CaveGenerator::~CaveGenerator() {
    for (int i = 0; i < this->row; i++) {
        delete []this->map[i];
    }
    delete []this->map;
}

// Recursively generates the cave map
void CaveGenerator::recursiveGen(int row, int col, int cavern_len, int cavern_width, enum Direction dir, std::mt19937 mt, int max_rec) {
    std::uniform_int_distribution<int> len(1, this->col/2);
    std::uniform_int_distribution<int> width(1, this->col/5);
    std::uniform_int_distribution<int> direction(0, 3);
    std::uniform_int_distribution<int> new_cave_chance(1, 50);
    std::uniform_int_distribution<int> angle(-1, 1);
    std::uniform_int_distribution<int> cave_width(1, cavern_width);
    
    if (dir == UP) {
        for (int i = row; i > row - cavern_len; i--) {
            if (i > 0) {
                for (int j = col; j < col + cave_width(mt); j++) {
                    if ((j < this->col - 1) && (j > 0)) {
                        j = j + angle(mt); 
                        this->map[i][j] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(i, j, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
                for (int j = col; j > col - cave_width(mt); j--) {
                    if ((j > 0) && (j < this->col - 1)) {
                        j = j + angle(mt);
                        this->map[i][j] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(i, j, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
            }
        }
    } else if (dir == DOWN) {
        for (int i = row; i < row + cavern_len; i++) {
            if (i < this->row - 1) {
                for (int j = col; j < col + cave_width(mt); j++) {
                    if ((j < this->col - 1) && (j > 0)) {
                        j = j + angle(mt);
                        this->map[i][j] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(i, j, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
                for (int j = col; j > col - cave_width(mt); j--) {
                    if ((j > 0) && (j < this->col - 1)) {
                        j = j + angle(mt);
                        this->map[i][j] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(i, j, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
            }
        }
    } else if (dir == RIGHT) {
        for (int i = col; i < col + cavern_len; i++) {
            if (i < this->col - 1) {
                for (int j = row; j < row + cave_width(mt); j++) {
                    if ((j < this->row - 1) && (j > 0)) {
                        j = j + angle(mt);
                        this->map[j][i] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(j, i, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
                for (int j = row; j > row - cave_width(mt); j--) {
                    if ((j > 0) && (j < this->row - 1)) {
                        j = j + angle(mt);
                        this->map[j][i] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(j, i, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
            }
        }
    } else { // dir == LEFT
        for (int i = col; i > col - cavern_len; i--) {
            if (i > 0) {
                for (int j = row; j < row + cave_width(mt); j++) {
                    if ((j < this->row - 1) && (j > 0)) {
                        j = j + angle(mt);
                        this->map[j][i] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(j, i, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
                for (int j = row; j > row - cave_width(mt); j--) {
                    if ((j > 0) && (j < this->row - 1)) {
                        j = j + angle(mt);
                        this->map[j][i] = this->air;
                        if (new_cave_chance(mt) == 1 && max_rec > 0) {
                            max_rec -= 1;
                            recursiveGen(j, i, len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, max_rec); // cast direction
                        }
                    }
                }
            }
        }
    }
}

void CaveGenerator::makeMap() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> start_col(1, (this->col - 2));
    std::uniform_int_distribution<int> start_row(1, (this->row - 2));
    std::uniform_int_distribution<int> len(1, this->col/2);
    std::uniform_int_distribution<int> width(1, this->col/5);
    std::uniform_int_distribution<int> direction(0, 3);

    // create 3 caverns in the cave
    recursiveGen(start_row(mt), start_col(mt), len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, 7);
    recursiveGen(start_row(mt), start_col(mt), len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, 7);
    recursiveGen(start_row(mt), start_col(mt), len(mt), width(mt), (CaveGenerator::Direction)direction(mt), mt, 7);
}

void CaveGenerator::printMap() {
    for (int r = 0; r < this->row; r++) {
        for (int c = 0; c < this->col; c++) {
            std::cout << std::setw(4) << std::left << this->map[r][c].getType();
        }
        std::cout << std::endl;
    }
}

Tile **CaveGenerator::getMap() {
    return this->map;
}
