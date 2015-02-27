#include <iostream>
#include <vector>

using namespace std;

class ArgHtml
{
public:
	ArgHtml();
	~ArgHtml();

	string wrap(string tag, char content);
	string arrayToTable(int size, vector<vector<char>> vec);
    void arrayToIndex(int size, vector<vector<char>> vec);

};
