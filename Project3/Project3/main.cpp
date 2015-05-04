#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main()
{
	BinaryHeap<int> binary_heap(5);
	binary_heap.insert(5);
	binary_heap.insert(6);
	binary_heap.insert(7);
	binary_heap.insert(8);
	binary_heap.insert(9);

	binary_heap.FindLessValues(10);

	cin.get();
	return 0;
}
