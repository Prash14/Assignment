/*
 * VectorSum.cpp
 *
 *  Created on: Aug 30, 2019
 *      Author: Prash
 */
/* Sum can be found with the help of accumulate() function provided in STL.
 * accumulate(first_index, last_index, initial value of sum);
 */
#include "iostream"
#include "vector"
#include "array"
#include "algorithm"
#include "numeric"
using namespace std;

int myProduct(int x, int y)
{
	return x*y;
}

int main()
{
	auto sum = [](auto a,auto b){ return a+b;};
	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	array<int,5> arr = {1,2,3,4,5};
	auto cursum = 0;

	cout<<"Func Accumulate Vector Sum = "<<accumulate(vec.begin(),vec.end(),cursum)<<endl;
	cout<<"Func Accumulate Array Sum = "<<accumulate(arr.begin(),arr.end(),cursum)<<endl;

	for(auto itr : vec)
	{
		cursum = sum(cursum,itr);
	}

	cout<<"Vector Sum using Lambda "<<cursum<<endl;

    //Find difference using Accumulate fun
	auto difference = 0;
	difference = accumulate(arr.begin(),arr.end(),difference,std::minus<int>());
	cout<<"Lib minus() Accumulate Array Difference = "<<difference<<endl;


	//Find difference using Accumulate fun
	auto product = 1;
	product = accumulate(arr.begin(),arr.end(),product,myProduct);
	cout<<"myProduct() Accumulate Array Product = "<<product<<endl;

	return 0;
}

