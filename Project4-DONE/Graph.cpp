#include "Graph.h"


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
		if(vertices_[i]->GetName() == name)
			return true;
	}

	return false;
}

void Graph::AddVertex(std::string name)
{
    if(!this->Contains(name))
		vertices_.push_back(new Node(name));
}

void Graph::AddEdge(const std::string& vertex1, const std::string& vertex2, float value)
{
	AddVertex(vertex1);
    Node* v1 = vertices_[vertices_.size() - 1];
	AddVertex(vertex2);
    Node* v2 = vertices_[vertices_.size() - 1];
        
	v1->AddEdge(value, *v2);
}

void Graph::LoadGraph(const std::string& path)
{
	std::fstream myfile;
	std::string line;

	myfile.open (path);

	while(getline (myfile, line))
	{
		std::istringstream ss (line);
		
		std::string parsed_line;

		std::vector<std::string> temp_line(3);

		while(getline(ss, parsed_line, ' '))
                    temp_line.push_back(parsed_line);

		//Add Edge
		this->AddEdge(temp_line[0], temp_line[2], parsed_line[1]);
	}

	myfile.close();
}