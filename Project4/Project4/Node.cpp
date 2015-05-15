#include "Node.h"
#include <string>
using namespace std;

Node::Node(std::string name)
{
	this->name_ = name;
}

Node::~Node(void)
{
}

void Node::AddEdge(float distance, const Node& dest)
{
    edges_.push_back(new Edge(distance, dest));
}

bool Node::operator==(const Node& other) const
{
	if(this->name_ == other.name_)
		return true;

	return false;
}

bool Node::operator<(const Node& other) const
{
	if(this->value_ == other.value_)
		return true;

	return false;
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}