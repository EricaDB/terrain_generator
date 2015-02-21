/*
 * cave_generator.hpp
 */

#ifndef CAVE_GENERATOR_HPP_
#define CAVE_GENERATOR_HPP_

#include "generator.hpp"
#include <random>

class CaveGenerator : public Generator {
public:
    CaveGenerator(int row, int col);
    ~CaveGenerator();
    
    enum Direction { DOWN, RIGHT, UP, LEFT };
    
    void makeMap();
    void recursiveGen(int row, int col, int len, int width, Direction dir, std::mt19937 mt, int max_rec);
    
    // print out the map (for debugging)
    void printMap();
    char **getMap();
    
private:
    //the dimensions of the map
    int row;
    int col;
    
    char **map;
    enum Direction dir;
    
    // characters for terrain features
    char air;
    char wall;
    // gems?
};

#endif /* CAVE_GENERATOR_HPP_ */
