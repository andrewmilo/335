//
//
// BY ANDREW MILOSLAVSKY
// CSCI 335
//
//

#include <iostream>
#include "BinaryHeap.h"
#include <sstream>

using namespace std;

int main()
{
	BinaryHeap<int> binary_heap(5);
	char input[100];
	cout << "Enter values to load binary heap with separated by space: " << endl;
	cin.getline(input, sizeof(input));

	istringstream ss (input);

	string output = "";
	while(getline(ss, output, ' '))
		binary_heap.insert(atoi(output.c_str()));

	//Question 1
	cout << "Enter a value to find less values for: ";
	int temp = -1;
	cin >> temp;
	binary_heap.FindLessValues(temp);

	cout << endl << "Enter value to find" << endl;
	int temp2;
	cin >> temp2;
	
	//Question 3
	switch(binary_heap.FindValue(temp2))
	{
	case 1:
		cout << "Value FOUND";
		break;
	default:
		cout << "Value NOT FOUND";
	}

	cout << endl;
	system ("PAUSE");
	return 0;
}
