#include "arg_html.hpp"

#include <iostream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

ArgHtml::ArgHtml(){	
}

ArgHtml::~ArgHtml(){
}

string ArgHtml::wrap(string tag, char content){
	map<char, string> classMap;
	classMap.insert(pair<char, string>('^', "moutain") );
	classMap.insert(pair<char, string>('.', "plains") );
	classMap.insert(pair<char, string>(' ', "ocean") );
	return "<" + tag + " class='" + classMap.find(content)->second + "'>" + content + "</" + tag + ">";
}

string ArgHtml::arrayToTable(int size, vector<vector<char>> vec){
	string html = "<table>";
	for (int r = 0; r < size; r++) {
		html += "<tr>";      
        for (int c = 0; c < size; c++) {
        	html += this->wrap("td", vec[r][c]);	
        }  
        html += "</tr>";      
    }
    html += "</table>";
	return html;
}

void ArgHtml::arrayToIndex(int size, vector<vector<char>> vec){
	string style = "<style>td{width:100px;height:100px}.moutain{background:brown} .plains{background:yellow} .ocean{background:blue}</style>";
	string header = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Document</title>"+ style +"</head><body>";
	string footer = "</body></html>";
	string body = "<table>";
	for (int r = 0; r < size; r++) {
		body += "<tr>";      
        for (int c = 0; c < size; c++) {
        	body += this->wrap("td", vec[r][c]);	
        }  
        body += "</tr>";      
    }
    body += "</table>";
    FILE *f = fopen("index.html", "w");
	std::string html = header + body + footer;
    fprintf(f, "%s", html.c_str());
}
