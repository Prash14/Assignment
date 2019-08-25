/*
 * Iterator.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: Prash
 */

// C++ code to demonstrate the working of
// iterator, begin() and end()
#include<iostream>
#include<algorithm>
#include<vector> // for vectors
#include<array>
using namespace std;

int iterator_main()
{
	vector<int> ar = { 1, 2, 3, 4, 5 };
	vector<int> ar1 = {10, 20, 30};

	// Declaring iterator to a vector
	auto ptr = ar.begin();

	// Using advance to set position
	advance(ptr, 3);

	// copying 1 vector elements in other using inserter()
	// inserts ar1 after 3rd position in ar
	copy(ar1.begin(), ar1.end(), inserter(ar,ptr));

	// Displaying new vector elements
	cout << "The new vector after inserting elements is : ";
	for (int &x : ar)
		cout << x << " ";

	return 0;
}



int main_itr()
{
	vector<int> ar = { 1, 2, 3, 4, 5 };

	// Declaring iterator to a vector
	vector<int>::iterator ptr;

	// Displaying vector elements using begin() and end()
	cout << "The vector elements are : ";
	for (ptr = ar.begin(); ptr < ar.end(); ptr++)
		cout << *ptr << " ";

	cout <<endl<< "Reverse & print vector using RangeBased"<<endl
			<<"The vector elements are : ";

    reverse(ar.begin(),ar.end());

    for(auto item : ar)
    {
    	cout << item << " ";
    }

    iterator_main();

	return 0;
}
