#pragma once

#include <vector>
#include "Node.h"
#include <string>

class Graph
{
private:
	std::vector<Node> vertices_;
public:
	bool Contains(const std::string&) const;
	const Node* Find(const std::string&) const;
	void AddVertex(std::string);
	void AddEdge(const std::string& node1, const std::string& node2, float value);
	Graph(void);
	~Graph(void);
};

