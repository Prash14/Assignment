/*
 * HeapFunction.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: Prash
 */



// C++ code to demonstrate the working of
// make_heap(), front()
#include<iostream>
#include "vector"
#include<algorithm> // for heap operations
using namespace std;

int HeapFunction_main()
{

	// Initializing a vector
	vector<int> v1 = {20, 30, 40, 25, 15};

	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());

	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap is : ";
	cout << v1.front() << endl;

	// using push_back() to enter element
	// in vector
	v1.push_back(50);

	// using push_heap() to reorder elements
	push_heap(v1.begin(), v1.end());

	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap after push is : ";
	cout << v1.front() << endl;

	// using pop_heap() to delete maximum element
	pop_heap(v1.begin(), v1.end());
	v1.pop_back();

	// Displaying the maximum element of heap
	// using front()
	cout << "The maximum element of heap after pop is : ";
	cout << v1.front() << endl;

	return 0;
}

