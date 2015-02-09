/*
 * terrain_generator.hpp
 */

#ifndef TERRAIN_GENERATOR_HPP_
#define TERRAIN_GENERATOR_HPP_

#include "generator.hpp"

class TerrainGenerator : public Generator {
public:
    TerrainGenerator();
    virtual ~TerrainGenerator();
    virtual void makeMap(int row_size, int col_size);
    
    // print out the map (for debugging)
    void printMap();
    
private:
    //the dimensions of the map
    int row;
    int col;
    
    char **map;
    
    // characters for terrain features
    char mountain;
    char water;
    char valley;
};

#endif /* TERRAIN_GENERATOR_HPP_ */