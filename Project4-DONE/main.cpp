/***
/* Assignment #4 by Andrew Miloslavsky
/* May 1st, 2015
***/

#include <iostream>
#include <vector>
#include "StringGraph.h"

using namespace std;

int main()
{
	// Create a graph of string nodes
	// StringGraph derives from the Graph<string> class,
	// and includes the extra function "LoadGraph" which allows the loading of text files into a graph
	StringGraph graph;

	cout << "Enter the path of the graph text file: ";
	string path;
	cin >> path;

	//Load the graph from a text file
	graph.LoadGraph(path);

	cout << "Enter the index of a source node to start from: ";
	int index;
	cin >> index;

	//Run Dijkstra's algorithm starting at a source index
	graph.Dijkstra(index);

	cin.get();cin.get();
}