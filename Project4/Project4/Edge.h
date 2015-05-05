#pragma once
#include "Node.h"

struct Edge
{
	float value_;
	Node& destination_;
	Edge(float, Node&);
	~Edge(void);
};



