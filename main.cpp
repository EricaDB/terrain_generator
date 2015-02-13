#include "generator.hpp"
#include "terrain_generator.hpp"

int main() {
  TerrainGenerator tg(80, 80);
  tg.makeMap();
  return 0;
}
