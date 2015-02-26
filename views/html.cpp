#include "html.hpp"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <utility>


using namespace std;

Html::Html(){	
}

Html::~Html(){
	// 
}

string Html::wrap(string tag, char content){
	map<char, string> classMap;
	classMap.insert(pair<char, string>('^', "moutain") );
	classMap.insert(pair<char, string>('.', "plains") );
	classMap.insert(pair<char, string>(' ', "ocean") );
	return "<" + tag + " class='" + classMap.find(content)->second + "'>" + content + "</" + tag + ">";
}

string Html::arrayToTable(int size, char arr[100][100]){
	string html = "<table>";
	for (int r = 0; r < size; r++) {
		html += "<tr>";      
        for (int c = 0; c < size; c++) {
        	html+= this->wrap("td", arr[r][c]);	
        }  
        html += "</tr>";      
    }
    html += "</table>";
	return html;
}