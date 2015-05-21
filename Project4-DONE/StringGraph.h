/***
/* String Graph Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #4
/* May 1st, 2015
***/

#ifndef _STRING_GRAPH_
#define _STRING_GRAPH_
#include "Graph.h"

class StringGraph : public Graph<std::string>
{
public:
	void LoadGraph(const std::string& path);
	StringGraph(void);
	~StringGraph(void);
};

#endif