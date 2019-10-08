/*
 * ConstExpExample.cpp
 *
 *  Created on: Sep 13, 2019
 *      Author: Prash
 */
#include "iostream"
#include "array"
using namespace std;

// return size of an array as a compile-time constant. (The
// array parameter has no name, because we care only about
// the number of elements it contains.)
template<typename T, size_t N>
constexpr size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

/* RetType function(params) noexcept; // most optimizable
 * RetType function(params) throw(); // less optimizable
 * RetType function(params); // less optimizable
 * noexcept : from C++11 style
 * throw : C++  98 style
 */

int ConstExp_main()
{
	int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };

	array<int,arraySize(keyVals)> myArray;

	int idx = 0;
	for(auto &item : myArray)
	{
		item = keyVals[idx++];
	}

	cout<<" after copy "<<endl;
	for(auto &item : myArray)
		cout<<item<<"\t";

	return 0;
}
