#include <iostream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "cave_view.hpp"
#include "tile.hpp"

using namespace std;

CaveView::CaveView(){
}

CaveView::~CaveView(){
}

string CaveView::wrap(string tag, char content){
    map<char, string> classMap;
    classMap.insert(pair<char, string>('@', "rock") );
    classMap.insert(pair<char, string>(' ', "air") );
    classMap.insert(pair<char, string>('r', "ruby") );
    classMap.insert(pair<char, string>('e', "emerald") );
    classMap.insert(pair<char, string>('d', "diamond") );
    return "<" + tag + " class='" + classMap.find(content)->second + "'>" + "</" + tag + ">";
}

string CaveView::arrayToTable(int size, vector<vector<Tile>> vec){
    string html = "<table>";
    for (int r = 0; r < size; r++) {
        html += "<tr>";
        for (int c = 0; c < size; c++) {
            if (vec[r][c].getType() == "rock") {
                html += this->wrap("td", '@');
            } else if (vec[r][c].getType() == "air") {
                html += this->wrap("td", ' ');
            } else if (vec[r][c].getType() == "ruby") {
                html += this->wrap("td", 'r');
            } else if (vec[r][c].getType() == "emerald") {
                html += this->wrap("td", 'e');
            } else {
                html += this->wrap("td", 'd');
            }
        }
        html += "</tr>";
    }
    html += "</table>";
    return html;
}

void CaveView::arrayToIndex(int size, vector<vector<Tile>> vec){
    string style = "<style>td{width:100px;height:100px}.rock{background:navy} .air{background:white} .ruby{background:red} .emerald{background:green} .diamond{background:teal}</style>";
    string header = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Document</title>"+ style +"</head><body>";
    string footer = "</body></html>";
    string body = "<table>";
    for (int r = 0; r < size; r++) {
        body += "<tr>";
        for (int c = 0; c < size; c++) {
            if (vec[r][c].getType() == "rock") {
                body += this->wrap("td", '@');
            } else if (vec[r][c].getType() == "air") {
                body += this->wrap("td", ' ');
            } else if (vec[r][c].getType() == "ruby") {
                body += this->wrap("td", 'r');
            } else if (vec[r][c].getType() == "emerald") {
                body += this->wrap("td", 'e');
            } else {
                body += this->wrap("td", 'd');
            }
        }
        body += "</tr>";
    }
    body += "</table>";
    FILE *f = fopen("cave_view.html", "w");
    std::string html = header + body + footer;
    fprintf(f, "%s", html.c_str());
}
