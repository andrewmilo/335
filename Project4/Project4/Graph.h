#pragma once

#include <vector>
#include "Node.h"
#include <string>

class Graph
{
private:
	std::vector<Node*> vertices_;
public:
	void Insert(Node&);
	bool Contains(const std::string&) const;
	const Node& Find(const std::string&) const;
	Graph(void);
	~Graph(void);
};

Graph::Graph(void)
{
}

Graph::~Graph(void)
{
}

bool Graph::Contains(const std::string &name) const
{
	for(int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i]->name_ == name)
			return true;
	}

	return false;
}

const Node& Graph::Find(const std::string &name) const
{
	for(int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i]->name_ == name)
			return *vertices_[i];
	}

	return NULL;
}

void Graph::Insert(Node &x)
{
	vertices_->push_back(x);
}
