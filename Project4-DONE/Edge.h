#pragma once
#include "Node.h"

class Edge
{
public:
	float value_;
	Node destination_;
	Edge(float, Node&);
	~Edge(void);
};



