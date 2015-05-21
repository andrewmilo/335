/***
/* Assignment #4 by Andrew Miloslavsky
/* May 1st, 2015
***/

#include <iostream>
#include <vector>
#include "StringGraph.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Create a graph of string nodes
	StringGraph graph;

	//Load the graph from a text file
	graph.LoadGraph(argv[1]);

	cin.get();
}