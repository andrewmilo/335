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

		//Get Node
		getline(ss, parsed_line, ' ');

		if(!graph.Contains(parsed_line))
			graph.Insert(parsed_line);

		if(node == NULL)
			node = graph.Find(parsed_line);

		//Get Edge
		getline(ss, parsed_line, ' ');

		Edge* edge = new Edge(atoi(parsed_line.c_str()), node);

		node->edges_.push_back();

		
	}



	myfile.close();

	cin.get();
}