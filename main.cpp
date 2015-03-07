#include "arg_html.hpp"
#include "generator.hpp"
#include "terrain_generator.hpp"
#include "cave_generator.hpp"

#include <iostream>

int main(int argc, const char *argv[]) {
    int tg_size = 50; // take this as user input later
    TerrainGenerator tg(tg_size, tg_size);
    tg.smoothMap();
    tg.printMap();
    ArgHtml html;
    char **map = tg.getMap();
    std::vector<std::vector<char> > vec_map; //convert arrays to vectors
    for (int i = 0; i < tg_size; i++) {
        std::vector<char> row;
        vec_map.push_back(row);
        for (int j = 0; j < tg_size; j++) {
            vec_map[i].push_back(map[i][j]);
        }
    }
    html.arrayToIndex(tg_size, vec_map);
    /*
    CaveGenerator cg(40, 40);
    cg.makeMap();
    cg.printMap();
    */
    return 0;
}
