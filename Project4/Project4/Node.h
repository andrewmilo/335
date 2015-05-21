#pragma once

#include <vector>
#include "Edge.h"

class Node
{
private:
	std::string name_;
	std::vector<Edge*> edges_;
public:
	const std::string& GetName() const;
	void AddEdge(float distance, Node&) const;
	bool operator==(const Node&) const;
	bool operator!=(const Node&) const;
	Node();
	Node(std::string);
	~Node(void);
};

