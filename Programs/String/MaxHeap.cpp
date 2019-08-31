/*
 * MaxHeap.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: Prash
 */

#include<iostream>
#include"vector"
#include<algorithm> // for heap operations
using namespace std;
int MaxHeap_main()
{

	// Initializing a vector
	vector<int> v1 = {20, 30, 40, 25, 15};

	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());

	// Displaying heap elements
	cout << "The heap elements are : ";
	for (int &x : v1)
	cout << x << " ";
	cout << endl;

	// sorting heap using sort_heap()
	sort_heap(v1.begin(), v1.end());

	// Displaying heap elements
	cout << "The heap elements after sorting are : ";
	for (int &x : v1)
	cout << x << " ";

	return 0;
}
