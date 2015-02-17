#include "generator.hpp"
#include "terrain_generator.hpp"
#include <iostream>

int main() {
  TerrainGenerator tg(80, 80);
  tg.makeMap();
  tg.printMap();
  return 0;
}
