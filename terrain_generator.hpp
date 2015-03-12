/*
 * terrain_generator.hpp
 */

#ifndef TERRAIN_GENERATOR_HPP_
#define TERRAIN_GENERATOR_HPP_

#include "generator.hpp"
#include "tile.hpp"

class TerrainGenerator : public Generator {
public:
    TerrainGenerator(int row, int col, int smoothness,
                     int water, int valley, int mountains);
    virtual ~TerrainGenerator();
    
    virtual void makeMap();
    void smoothMap();

    int water_amount; //proportion of water on map
    int valley_amount;
    int mountains_amount;

    // print out the map (for debugging)
    virtual void printMap();
    
    Tile **getMap();
    std::tuple<int, int> *getArrayOfRandomCoords();

private:
    //the dimensions of the map
    int row;
    int col;

    

    Tile **map;
    
    // Tile objects for terrain features
    Tile mountain;
    Tile water;
    Tile valley;
};

#endif /* TERRAIN_GENERATOR_HPP_ */
