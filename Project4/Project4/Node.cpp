#include "Node.h"
#include <string>
using namespace std;

Node::Node(std::string name)
{
	this->name_ = name;
}

Node::~Node(void)
{

std::string& Node::GetName(void) const
{
	return name_;
}

void Node::AddEdge(float distance, Node& dest) const
{
	Edge* edge = new Edge(distance, dest);
    edges_.push_back(edge);
}

bool Node::operator==(const Node& other) const
{
	if(this->name_ == other.name_)
		return true;

	return false;
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}