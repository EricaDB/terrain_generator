/*
 * main.cpp
 */

#include <iostream>

#include "generator.hpp"
#include "terrain_generator.hpp"
#include "maze_generator.hpp"
#include "cave_generator.hpp"
#include "terrain_view.hpp"
#include "maze_view.hpp"

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

int main(int argc, const char *argv[]) {
    int tg_size = 41;
    TerrainGenerator tg(tg_size, tg_size);
    for (int i = 0; i < 2; i ++) {
        tg.smoothMap();
    }
    tg.printMap();

    TerrainView terrain_view;
    char **map = tg.getMap();
    //makes html file visualizing map
    terrain_view.arrayToIndex(tg_size, arr_to_vec(map, tg_size));

    int mg_size = 41;
    MazeView maze_view;
    MazeGenerator mg(mg_size, mg_size);
    Tile **maze = mg.getMap();
    //mg.printMap();
    maze_view.arrayToIndex(mg_size, arr_to_vec(maze, mg_size));

    CaveGenerator cg(30, 30);
    //cg.printMap();

    return 0;
}
