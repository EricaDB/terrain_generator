/*
 * cave_generator.hpp
 */

#ifndef CAVE_GENERATOR_HPP_
#define CAVE_GENERATOR_HPP_

#include <random>

#include "generator.hpp"
#include "tile.hpp"

class CaveGenerator : public Generator {
public:
    CaveGenerator(int row, int col);
    ~CaveGenerator();
    
    enum Direction { DOWN, RIGHT, UP, LEFT };
    
    virtual void makeMap();
    void recursiveGen(int row, int col, int len, int width, Direction dir, std::mt19937 mt, int max_rec);
    void smoothMap(int row, int col);
    
    // Print out the map (for debugging)
    virtual void printMap();
    
    Tile **getMap();
    
private:
    // The dimensions of the map
    int row;
    int col;
    
    Tile **map;
    enum Direction dir;
    
    // Tiles for cave features
    Tile air;
    Tile rock;
    Tile ruby;
    Tile emerald;
    Tile diamond;
};

#endif /* CAVE_GENERATOR_HPP_ */
