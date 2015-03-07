/*
 * altitude_generator.hpp
 */

#ifndef ALTITUDE_GENERATOR_HPP_
#define ALTITUDE_GENERATOR_HPP_

#include "generator.hpp"
#include "tile.hpp"

class AltitudeGenerator : public Generator {
public:
    AltitudeGenerator(int row, int col);
    ~AltitudeGenerator();
    
    void makeMap();
    
    // print out the map (for debugging)
    void printMap();
    
    Tile **getMap();
    
private:
    //the dimensions of the map
    int row;
    int col;
    
    Tile **map;
    
    // Tiles for terrain features
    Tile water;
    Tile land;
};

#endif /* ALTITUDE_GENERATOR_HPP_ */
