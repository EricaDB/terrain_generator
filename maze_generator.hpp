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
    
    virtual void makeMap();
    void buildPath(int r, int c); 
    void buildDoublePath(int r, int c); 
    bool canBuildPath(int r, int c, std::string dir); 

    // Print out the map (for debugging)
    virtual void printMap();
     
    Tile **getMap();
    
private:
    // The dimensions of the map
    int row;
    int col;
    
    Tile **map;
    
    // Tiles for maze features
    Tile wall;
    Tile path;
};

#endif /* MAZE_GENERATOR_HPP_ */
