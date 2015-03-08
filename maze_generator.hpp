/*
 * maze_generator.hpp
 */

#ifndef MAZE_GENERATOR_HPP_
#define MAZE_GENERATOR_HPP_

#include "generator.hpp"
#include "tile.hpp"

class MazeGenerator : public Generator {
public:
    MazeGenerator(int row, int col);
    ~MazeGenerator();
    
    void makeMap();
    void buildWall(int r, int c); 
    bool canBuildWall(int r, int c, std::string dir); 

    // print out the map (for debugging)
    void printMap();
     
    Tile **getMap();
    
private:
    //the dimensions of the map
    int row;
    int col;
    
    Tile **map;
    
    // Tiles for terrain features
    Tile wall;
    Tile path;
};

#endif /* MAZE_GENERATOR_HPP_ */
