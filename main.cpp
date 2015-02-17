#include "generator.hpp"
#include "terrain_generator.hpp"
#include <iostream>

int main() {
    TerrainGenerator tg(30, 30);
    tg.makeMap();
    tg.printMap();
    return 0;
}
