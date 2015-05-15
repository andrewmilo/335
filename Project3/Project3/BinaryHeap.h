#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H
#include <vector>

template <class T>
class BinaryHeap
{
private:
	std::vector<T> vector_;
	int size_;
	void FindLessValues(const T&, int index) const;
	void PercolateDown(int);
public:
	void Enqueue(const T& x);
	void Dequeue();
	BinaryHeap(int);
	void FindLessValues(const T&) const;
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
void BinaryHeap<T>::Enqueue(const T& x)
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
void BinaryHeap<T>::Dequeue()
{
	 vector_[1] = vector_[ currentSize-- ];
     percolateDown(1);
}

template <class T>
void BinaryHeap<T>::PercolateDown( int hole )
{
    int child;
    T tmp = array[ hole ];

    for( ; hole * 2 <= currentSize; hole = child )
    {
        child = hole * 2;
        if( child != currentSize && array[ child + 1 ] < array[ child ] )
            ++child;
        if( array[ child ] < tmp )
            array[ hole ] = array[ child ];
        else
            break;
    }
    array[ hole ] = tmp;
}

template <class T>
void BinaryHeap<T>::FindLessValues(const T& value) const
{
	//Start at index 1
	FindLessValues(value, 1);
}

template <class T>
void BinaryHeap<T>::FindLessValues(const T& value, int index) const
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
T BinaryHeap<T>::FindValue(const T& value)
{
	return FindValue(value, 1);
}

template <class T>
T BinaryHeap<T>::FindValue(const T& value, int index)
{
	
}

#endif
