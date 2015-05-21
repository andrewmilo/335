/***
/* String Graph Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #4
/* May 1st, 2015
***/

#include "StringGraph.h"

StringGraph::StringGraph(void)
{
}

StringGraph::~StringGraph(void)
{
}

void StringGraph::LoadGraph(const std::string& path)
{
	std::fstream myfile;
	std::string line;

	myfile.open (path);

	while(getline (myfile, line))
	{
		std::istringstream ss (line);
		
		std::string parsed_line;

		std::vector<std::string> temp_line(3);

		while(getline(ss, parsed_line, ' '))
                    temp_line.push_back(parsed_line);

		//Add Edge
		this->AddEdge(temp_line[0], temp_line[2], parsed_line[1]);
	}

	myfile.close();
}
