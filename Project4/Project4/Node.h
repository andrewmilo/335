#pragma once

#include <vector>
#include "Edge.h"

template <class T>
class Node
{
private:
	std::string name_;
	std::vector<Edge> edges_;
	T value_;
public:
	void AddEdge(float distance, const Node&);
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	Node(std::string);
	~Node(void);
};

