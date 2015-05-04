#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H
#include <vector>

template <class T>
class BinaryHeap
{
private:
	std::vector<T> vector_;
	int size_;
	void FindLessValues(const T&, int index);
public:
	void insert(const T& x);
	void remove(T&);
	BinaryHeap(int);
	void FindLessValues(const T&);
	~BinaryHeap(void);
};

template <class T>
BinaryHeap<T>::BinaryHeap(int capacity = 100) : vector_(capacity)
{
	size_ = 0;
}

template <class T>
BinaryHeap<T>::~BinaryHeap(void)
{
}

template <class T>
void BinaryHeap<T>::insert(const T& x)
{
	if( size_ == vector_.size( ) - 1 )
		vector_.resize( vector_.size( ) * 2 );

	//Percolate up
	int hole = ++size_;

	for( ; hole > 1 && x < vector_[ hole / 2 ]; hole /= 2 )
		vector_[ hole ] = vector_[ hole / 2 ];
	
	vector_[ hole ] = x;
}

template <class T>
void BinaryHeap<T>::remove(T& node)
{
}

template <class T>
void BinaryHeap<T>::FindLessValues(const T& value)
{
	//Start at index 1
	FindLessValues(value, 1);
}

template <class T>
void BinaryHeap<T>::FindLessValues(const T& value, int index)
{
	if(index < vector_.size())
	{
		if(vector_[index] < value)
		{
			cout << vector_[index];

			//Left child
			FindLessValues(value, index * 2);
		
			//Right child
			FindLessValues(value, index * 2 + 1);
		}
	}
}

template <class T>
int BinaryHeap<T>::FindValue(const T& value)
{
	for(int i = 1; i < vector_.size(); i++)
	{
		if(vector_[i] == value)
		{
			return vector_[i];
		}
	}
}

#endif
