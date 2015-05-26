/***
/* Binary Heap Implementation by Andrew Miloslavsky
/* Originally created for CSCI 335, Assignment #3
/* May 1st, 2015
***/

#include <iostream>
#include "BinaryHeap.h"
#include <sstream>

using namespace std;

int main()
{
	BinaryHeap<int> binary_heap;
	char input[100];
	cout << "Enter values to load binary heap with separated by space: " << endl;
	cin.getline(input, sizeof(input));

	istringstream ss (input);

	string output;
	while(getline(ss, output, ' '))
		binary_heap.Insert(atoi(output.c_str()));

	//Question 1
	cout << "Enter a value to find less values for: ";
	int temp;
	cin >> temp;
	binary_heap.FindLessValues(temp);

	//Question 3
	cout << endl << "Enter value to find" << endl;
	int temp2;
	cin >> temp2;
	
	binary_heap.FindValue(temp2);

	cout << endl;
	system ("PAUSE");
	return 0;
}
