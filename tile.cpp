/*
 * tile.cpp
 *
 */

#include <string>
#include "tile.hpp"

Tile::Tile(std::string type, int altitude) : altitude(altitude), type(type), name(type) {
    // nothing else to do in constructor
}

Tile::Tile() : altitude(0), type("NONE"), name("") {
    // nothing else to do in constructor
}

Tile::~Tile() {}

void Tile::setType(std::string new_type) {
    this->type = new_type;
}

std::string Tile::getType() {
    return this->type;
}

void Tile::setAltitude(int new_altitude) {
    this->altitude = new_altitude;
}

int Tile::getAltitude() {
    return this->altitude;
}

void Tile::setName(std::string new_name) {
    this->name = new_name;
}

std::string Tile::getName() {
    return this->name;
}

// overload the < operator for Tile objects
bool Tile::operator<(const Tile& right_tile) const {
    int comparator = this->type.compare(right_tile.type);
    if (comparator == -1) {
        return true;
    } else {
        return false;
    }
}