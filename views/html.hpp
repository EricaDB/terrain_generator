#include <iostream>

using namespace std;

class Html
{
public:
	Html();
	~Html();

	string wrap(string tag, char content);
	string arrayToTable(int size, char arr[100][100]);
	
};