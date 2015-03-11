// compilation instructions:
// EMCC_FAST_COMPILER=0 emcc -O3 --bind --memory-init-file 0 -o cave.js cave_bind.cpp
// requires 
// 		1: local copy of emcc and dependencies 
// 		2: linking of source script in bash_profile
// 		3: optionally install guard to compile auto-magically compile on file save

#include <emscripten/bind.h>
#include "generator.hpp"
#include "tile.cpp"
#include "cave_generator.cpp"
#include "cave_view.cpp"

template<typename T>
std::vector<std::vector<T>> arr_to_vec(T **map, int size) {
    std::vector<std::vector<T>> vec_map;
    for (int i = 0; i < size; i++) {
        std::vector<T> row;
        vec_map.push_back(row);
        for (int j = 0; j < size; j++) {
            vec_map[i].push_back(map[i][j]);
        }
    }
    return vec_map;
}

std::string cave(std::string size) {
	std::string::size_type sz;
	int mapSize = std::stoi (size,&sz);

	CaveView cave_view;
	CaveGenerator cg(mapSize, mapSize);
    Tile **cave = cg.getMap();
    return cave_view.arrayToTable(mapSize, arr_to_vec(cave, mapSize));
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("cave", &cave);
}


