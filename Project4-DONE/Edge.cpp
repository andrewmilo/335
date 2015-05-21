#include "Edge.h"

Edge::Edge(float v, Node& n)
{
	this->value_ = v;
	this->destination_ = n;
}

Edge::~Edge(void)
{
}