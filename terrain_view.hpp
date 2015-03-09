#include <iostream>
#include <vector>

#include "tile.hpp"

using namespace std;

class TerrainView
{
public:
	TerrainView();
	~TerrainView();

	string wrap(string tag, char content);
	string arrayToTable(int size, vector<vector<Tile>> vec);
  void arrayToIndex(int size, vector<vector<Tile>> vec);

};
