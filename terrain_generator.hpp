/*
 * terrain_generator.hpp
 */

#ifndef TERRAIN_GENERATOR_HPP_
#define TERRAIN_GENERATOR_HPP_

#include "generator.hpp"
#include "tile.hpp"

class TerrainGenerator : public Generator {
public:
    TerrainGenerator(int row, int col);
    virtual ~TerrainGenerator();
    
    virtual void makeMap();
    virtual void smoothMap();

    // print out the map (for debugging)
    void printMap();
    
    Tile **getMap();
    std::tuple<int, int> *getArrayOfRandomCoords();

private:
    //the dimensions of the map
    int row;
    int col;
    
    Tile **map;
    
    // characters for terrain features
    Tile mountain;
    Tile water;
    Tile valley;
};

#endif /* TERRAIN_GENERATOR_HPP_ */
