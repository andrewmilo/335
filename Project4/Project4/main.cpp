#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Graph.h"
using namespace std;

int main()
{
	fstream myfile;
	string line;

	Graph graph;
	
	myfile.open ("C:/Users/Andrew/Desktop/graph.txt");

	while(getline (myfile, line))
	{
		istringstream ss (line);
		
		string parsed_line;

		vector<string> temp_line(3);

		while(getline(ss, parsed_line, ' '))
                    temp_line.push_back(parsed_line);

		//Add Edge
		graph.AddEdge(temp_line[0], temp_line[2], parsed_line[1]);
	}

	myfile.close();

	cin.get();
}