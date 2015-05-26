/***
/* Binary Heap Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #3
/* May 1st, 2015
***/

#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H
#include <vector>

template <class T>
class BinaryHeap
{
private:
	struct Node
	{
		T data_;
		bool visited_;
		bool operator==(const Node&) const;
		bool operator!=(const Node&) const;
		bool operator>(const Node&) const;
		bool operator<(const Node&) const;
		Node();
		Node(T);
		~Node(void);
	};
	std::vector<Node*> vector_;
	int count_;
	void FindValue(const T&, int index) const;
	void FindLessValues(const T&, int index) const;
	void PercolateUp(const T&);
public:
	void Insert(const T&);
	void FindLessValues(const T&) const;
	void FindValue(const T&) const;
	BinaryHeap(void);
	~BinaryHeap(void);
};

/**
* Initialize vector with INT_MAX
**/
template <class T>
BinaryHeap<T>::BinaryHeap() : vector_(25)
{
	//Fill vector with NULL values for future comparison proof.
	for(int i = 0; i < 25; i++)
		vector_.push_back(new Node(NULL));

	count_ = 0;
}

template <class T>
BinaryHeap<T>::~BinaryHeap(void)
{
}

template <class T>
BinaryHeap<T>::Node::Node(T data)
{
	data_ = data;
	visited_ = false;
}

template <class T>
bool BinaryHeap<T>::Node::operator==(const Node& other) const
{
	if(this->data_ == other.data_)
		return true;

	return false;
}

template <class T>
bool BinaryHeap<T>::Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

template <class T>
bool BinaryHeap<T>::Node::operator>(const Node& other) const
{
	if(this->data_ > other.data_)
		return true;

	return false;
}

template <class T>
bool BinaryHeap<T>::Node::operator<(const Node& other) const
{
	if(this->data_ < other.data_)
		return true;

	return false;
}

template <class T>
BinaryHeap<T>::Node::~Node()
{
}

/**
* Inserts an item, and percolates the item up if needed.
**/
template <class T>
void BinaryHeap<T>::Insert(const T& x)
{
	//Resize the vector if it is full
	if(count_ == vector_.size() - 1)
		vector_.resize(vector_.size() * 2);
	
	PercolateUp(x);
}

/**
* Finds the correct position for an element based on its comparison with existing elements.
**/
template <class T>
void BinaryHeap<T>::PercolateUp(const T& x)
{
	int pos = ++count_;

	while(pos > 1 && x < vector_[pos/2]->data_)
	{
		vector_[pos] = vector_[pos / 2];

		pos /= 2;
	}
	
	vector_[pos] = new Node(x);
}

/**
* Wrapper function in order to start searches from the root (in this case index 1 of the vector)
**/
template <class T>
void BinaryHeap<T>::FindLessValues(const T& value) const
{
	FindLessValues(value, 1);
}

/**
* Recursive method that finds all values in the binary heap that are less than a value.
**/
template <class T>
void BinaryHeap<T>::FindLessValues(const T& value, int index) const
{
	if(index < count_)
	{
		if(*vector_[index] < value)
		{
			std::cout << vector_[index]->data_ << " ";

			//Left child
			FindLessValues(value, index * 2);
		
			//Right child
			FindLessValues(value, index * 2 + 1);
		}
	}
}

template <class T>
void BinaryHeap<T>::FindValue(const T& value) const
{
	FindValue(value, 1);
}

/**
* A binary heap has around 75% of its nodes on the last 2 levels. Eliminating sub trees is the focus here.
* The algorithm marks nodes that are greater than the value so that we do not further traverse their own deeper roots.
**/
template <class T>
void BinaryHeap<T>::FindValue(const T& value, int index) const
{
	if(index < count_)
	{
		if(*vector_[index] == value)
		{
			std::cout << "Found " << value << " at index " << index;
			return;
		}

		//Stop traversing if the node is GREATER than the value (This is the optimization)
		if(*vector_[index] > value)
			return;

		//Left child
		FindValue(value, index * 2);
	
		//Right child
		FindValue(value, index * 2 + 1);
	}
}

#endif
