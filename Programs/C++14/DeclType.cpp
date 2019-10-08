/*
 * DeclType.cpp
 * decltype Keyword
 * It inspects the declared type of an entity or the type of an expression.
 * Auto lets you declare a variable with particular type whereas decltype lets
 * you extract the type from the variable so decltype is sort of an operator
 * that evaluates the type of passed expression.
 *  Created on: Sep 23, 2019
 *      Author: Prash
 */

// C++ program to demonstrate use of decltype
#include <bits/stdc++.h>
using namespace std;

int fun1() { return 10; }
char fun2() { return 'g'; }

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}

int main()
{
	// Data type of x is same as return type of fun1()
	// and type of y is same as return type of fun2()
	decltype(fun1()) x;
	decltype(fun2()) y;

	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;

	// This call returns 3.44 of double type
	cout << findMin(4, 3.44) << endl;
	cout << typeid(findMin(4, 3.44)).name() <<endl;

	// This call returns 3 of double type
	cout << findMin(5.4, 3) << endl;

	return 0;
}



