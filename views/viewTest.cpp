#include "html.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	FILE *f = fopen("index.html", "w");
	if(f == NULL){
		printf("Error opening file \n");
		exit(1);
	}
	string style = "<style>td{width:100px;height:100px}.moutain{background:brown} .plains{background:yellow} .ocean{background:blue}</style>";
	string header = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Document</title>"+ style +"</head><body>";
	string footer = "</body></html>";
	string body = "";

	// int foo[5] = {1,2,3,4,5};
	// for(int i=0; i<5; i++){
	// 	body += to_string(foo[i]);
	// }
    
	Html hyper;

	char arr[100][100] = {{'.', '.', '.'},{'^', '.', ' '},{'^', '.', ' '}};

	body += hyper.arrayToTable(3, arr);

	std::string html = header + body + footer;
	fprintf(f, "%s", html.c_str());

	return 1;
}
