/***
/* Linked Templated Graph Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #4
/* May 1st, 2015
***/

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <string>

template <class T>
class Graph
{
private:
	struct Node
	{
		void AddEdge(int distance, Node& destination);
		bool operator==(const Node&) const;
		bool operator!=(const Node&) const;
		Node();
		Node(T);
		~Node(void);

		struct Edge
		{
			int value_;
			Node& destination_;
			Edge();
			Edge(int, Node&);
			~Edge(void);
		};
		int weight_;
		bool known_;
		T data_;
		std::vector<Edge*> edges_;
	};
	bool directed_;
	std::vector<Node*> vertices_;
public:
	typename Node& AddVertex(const T&);
	void AddEdge(const T& node1, const T& node2, int value);
	void Dijkstra(int index);
	typename Node& GetVertex(const T& data);
	typename Graph<T>::Node* ShortestPath() const;
	Graph(bool directed);
	Graph(void);
	~Graph(void);
};

/*
* Constructors
*/
template <class T>
Graph<T>::Node::Node()
{
	this->known_ = false;
}

template <class T>
Graph<T>::Node::Node(T data)
{
	this->data_ = data;
	this->known_ = false;
}

template <class T>
Graph<T>::Node::~Node(void)
{
}

template <class T>
bool Graph<T>::Node::operator==(const Node& other) const
{
	if(this->data_ == other.data_)
		return true;

	return false;
}

template <class T>
bool Graph<T>::Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

template <class T>
Graph<T>::Graph(void)
{
	directed_ = false;
}

template <class T>
Graph<T>::Graph(bool directed)
{
	directed_ = directed;
}

template <class T>
Graph<T>::~Graph(void)
{
}

template <class T>
Graph<T>::Node::Edge::Edge(void)
{
	this->destination_ = 0;
	this->value_ = 0;
}

/*
* Initialize destination in the initializer list since it's a reference variable
*/
template <class T>
Graph<T>::Node::Edge::Edge(int f, Node& n) : destination_(n)
{
	this->value_ = f;
}

template <class T>
Graph<T>::Node::Edge::~Edge(void)
{
}

/*
* Adds a vertex to the vector of vertices.
*/
template <class T>
typename Graph<T>::Node& Graph<T>::AddVertex(const T& data)
{
	Node * temp = new Node(data);
	vertices_.push_back(temp);
	return *temp;
}

/*
* Gets the vertex based on the input data.
*/
template <class T>
typename Graph<T>::Node& Graph<T>::GetVertex(const T& data)
{
	for(unsigned int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i]->data_ == data)
			return *vertices_[i];
	}

	return AddVertex(data);
}

/*
* Adds an edge with an integer distance between 2 nodes. If the graph is directed, then only the 1st vertex in the parameters will be given the edge.
* In an undirected graph, both nodes/vertexes will be given the edge.
*/
template <class T>
void Graph<T>::AddEdge(const T& vertex1, const T& vertex2, int value)
{
	Node * t1 = &GetVertex(vertex1);
	Node * t2 = &GetVertex(vertex2);

	t1->edges_.push_back(new Node::Edge(value,*t2));
	
	if(!directed_)
		t2->edges_.push_back(new Node::Edge(value,*t1));
}

/*
* Implementation of Dijkstra's algorithm
*/
template <class T>
void Graph<T>::Dijkstra(int source_index)
{
	//Initialize all vertex weights to infinity (INT_MAX in our case)
	//Initialize all vertexes known status' as false
	for(unsigned int i = 0; i < vertices_.size(); i++)
	{
		vertices_[i]->weight_ = INT_MAX;
		vertices_[i]->known_ = false;
	}

	//Set source vertex to 0
	vertices_[source_index]->weight_ = 0;
	
	//Start from chosen source
    Node * current_node = vertices_[source_index];

	//Loop until no vertexes are left that haven't been visited
	while(current_node != 0)
	{
		current_node->known_ = true;

		//Iterate through all connected vertexes
		for(unsigned int i = 0; i < current_node->edges_.size(); i++)
		{
			Node::Edge * temp = current_node->edges_[i];

			//If the vertex has NOT been visited AND the total is less than the the weight at the destination vertex, replace the old weight
			if(temp->destination_.known_ == false && current_node->weight_ + temp->value_ < temp->destination_.weight_)
				temp->destination_.weight_ = current_node->weight_ + temp->value_;
		}

		//Get next node/vertex
		current_node = ShortestPath();
	}

	//Print Dijkstra's output
	std::cout << "V " << "Weight" << endl << endl;
	for(int m = 0; m < vertices_.size(); m++)
		std::cout << vertices_[m]->data_ << " " << vertices_[m]->weight_ << endl;
}

/*
* Calculates the next node to visit based on their weights
*/
template <class T>
typename Graph<T>::Node * Graph<T>::ShortestPath() const
{
	Node* min = 0;

	for(unsigned int i = 0; i < vertices_.size(); i++)
	{
		if(vertices_[i]->known_ == false)
		{
			if(min == 0)
				min = vertices_[i];

			if(vertices_[i]->weight_ < min->weight_)
				min = vertices_[i];
		}
	}

	return min;
}

#endif

