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