#include "generator.hpp"
#include "terrain_generator.hpp"
#include "cave_generator.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
    TerrainGenerator tg(80, 80);
    tg.makeMap();
    tg.printMap();
    CaveGenerator cg(40, 40);
    cg.makeMap();
    cg.printMap();
    
  return 0;
}
