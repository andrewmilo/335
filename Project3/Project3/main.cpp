#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main()
{
	BinaryHeap<int> binary_heap(5);
	binary_heap.Insert(9);
	binary_heap.Insert(8);
	binary_heap.Insert(7);
	binary_heap.Insert(3);
	binary_heap.Insert(4);
	binary_heap.Insert(5);

	binary_heap.FindLessValues(10);
	
	cin.get();
	return 0;
}
