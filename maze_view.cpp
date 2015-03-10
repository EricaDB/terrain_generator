#include <iostream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "maze_view.hpp"
#include "tile.hpp"

using namespace std;

MazeView::MazeView(){	
}

MazeView::~MazeView(){
}

string MazeView::wrap(string tag, char content){
	map<char, string> classMap;
	classMap.insert(pair<char, string>('@', "wall") );
	classMap.insert(pair<char, string>(' ', "path") );
	return "<" + tag + " class='" + classMap.find(content)->second + "'>" + "</" + tag + ">";
}

string MazeView::arrayToTable(int size, vector<vector<Tile>> vec){
    string html = "<table>";
    for (int r = 0; r < size; r++) {
        html += "<tr>";      
            for (int c = 0; c < size; c++) {
              if (vec[r][c].getType() == "wall") {
                  html += this->wrap("td", '@');	
              } else { 
                  html += this->wrap("td", ' ');	
              }
            }  
            html += "</tr>";      
        }
        html += "</table>";
    return html;
}

void MazeView::arrayToIndex(int size, vector<vector<Tile>> vec){
	string style = "<style>td{width:100px;height:100px}.wall{background:black} .path{background:white}</style>";
	string header = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Document</title>"+ style +"</head><body>";
    string footer = "</body></html>";
    string body = "<table>";
    for (int r = 0; r < size; r++) {
        body += "<tr>";      
        for (int c = 0; c < size; c++) {
            if (vec[r][c].getType() == "wall") {
                body += this->wrap("td", '@');	
            } else { 
                body += this->wrap("td", ' ');	
            }
        }  
        body += "</tr>";      
    }
    body += "</table>";
    FILE *f = fopen("maze_view.html", "w");
	  std::string html = header + body + footer;
    fprintf(f, "%s", html.c_str());
}
