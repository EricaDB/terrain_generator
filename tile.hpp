/*
 * tile.hpp
 *
 */

#ifndef TILE_HPP_
#define TILE_HPP_

#include <string>

class Tile {
public:
    Tile(std::string type, int altitude);
    Tile();
    ~Tile();
    
    std::string getType();
    void setType(std::string new_type);
    
    int getAltitude();
    void setAltitude(int new_altitude);
    
private:
    std::string type;
    int altitude;
};

#endif /* TILE_HPP_ */