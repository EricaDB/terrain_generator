#include <iostream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "tile.hpp"
#include "terrain_view.hpp"

using namespace std;

TerrainView::TerrainView(){	
}

TerrainView::~TerrainView(){
}

string TerrainView::wrap(string tag, char content){
    map<char, string> classMap;
    classMap.insert(pair<char, string>('^', "moutain") );
    classMap.insert(pair<char, string>('.', "plains") );
    classMap.insert(pair<char, string>(' ', "ocean") );
    return "<" + tag + " class='" + classMap.find(content)->second + "'>" + content + "</" + tag + ">";
}

string TerrainView::arrayToTable(int size, vector<vector<Tile>> vec){
	string html = "<table>";
	for (int r = 0; r < size; r++) {
		html += "<tr>";      
        for (int c = 0; c < size; c++) {
        	html += this->wrap("td", ' ');	
        }  
        html += "</tr>";
    }
    html += "</table>";
	return html;
}

void TerrainView::arrayToIndex(int size, vector<vector<Tile>> vec){
    string style = "<style>td{width:10px;height:10px}.moutain{background:brown} .plains{background:#4CB649} .ocean{background:#4CC1E7}</style>";
    string header = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Document</title>"+ style +"</head><body>";
    string footer = "</body></html>";
    string body = "<table>";
    for (int r = 0; r < size; r++) {
        body += "<tr>";      
        for (int c = 0; c < size; c++) {
            if (vec[r][c].getType() == "valley") {
                body += this->wrap("td", '.');	
            }
            else if (vec[r][c].getType() == "mountain") {
                body += this->wrap("td", '^');	
            } else { 
                body += this->wrap("td", ' ');	
            }
        //body += this->wrap("td", vec[r][c].getType());	
        }  
    body += "</tr>";      
    }
    body += "</table>";
    FILE *f = fopen("terrain_view.html", "w");
    std::string html = header + body + footer;
    fprintf(f, "%s", html.c_str());
}
