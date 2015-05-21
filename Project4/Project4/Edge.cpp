#include "Edge.h"

Edge::Edge(float value, Node& node)
{
	this->value_ = value;
	this->destination_ = node;
}

Edge::~Edge(void)
{
}