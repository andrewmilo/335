#pragma once

#include <vector>
#include "Edge.h"

class Node
{
private:
	std::string name_;
	std::vector<Edge&> edges_;
public:
	void AddEdge(float distance, Node&) const;
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	Node(std::string);
	~Node(void);
};

