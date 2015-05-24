/***
/* String Graph Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #4
/* May 1st, 2015
***/

#include "StringGraph.h"
#include <iostream>
#include <sstream>
#include <fstream>

StringGraph::StringGraph(void)
{
}

StringGraph::~StringGraph(void)
{
}

/***
* Loads the graph where each line is in the format of NODE DISTANCE NODE per line
* Example: A 5 B
***/
void StringGraph::LoadGraph(const std::string& path)
{
	std::fstream myfile;
	std::string line;

	myfile.open (path);

	//Iterates through the lines
	while(getline (myfile, line))
	{
		std::istringstream ss (line);
		
		std::string parsed_line;

		std::vector<std::string> temp_line;

		while(getline(ss, parsed_line, ' '))
		{
			temp_line.push_back(parsed_line);
		}

		//Add Edge based on split lines
		this->AddEdge(temp_line[0], temp_line[2], std::atof(temp_line[1].c_str()));
	}

	myfile.close();
}
