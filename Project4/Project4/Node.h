#pragma once

#include <vector>
#include "Edge.h"

class Node
{
public:
	std::string name_;
	std::vector<Edge*> edges_;
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	Node(std::string);
	~Node(void);
};

