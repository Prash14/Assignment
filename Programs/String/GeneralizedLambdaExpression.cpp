// Cpp program to demonstrate
// generalized lambda expressions
/* Suppose we create a lambda function to return the sum of two integers. So our lambda function would look like

[](int a, int b) -> int { return a + b; }
But what if we needed to obtain the sum of two floating point values later on. So we would need to declare another lambda expression that would work for only double values. Similarly each time our input parameters changed in type, the lambda function needed to be rewritten.

[](double a, double b) -> double { return a + b; }
Before C++ 14 there was a way to circumvent this problem by using template parameters,

template<typename T>
[](T a, T b) -> T { return a + b };
C++ 14 does away with this and allows us to use the keyword auto in the input parameters of the lambda expression. Thus the compilers can now deduce the type of parameters during compile time. So, in our previous example, a lambda expression that would work for both integer and floating point values would be

[](auto a, auto b) { return a + b; }
A very important application of this feature is that enhances existing
algorithms greatly. Take for instance the sort() function.
The following snippet will sort all data types
( provided they have overloaded < operators) in descending order.

sort(container.begin(), container.end(),
[](auto i, auto j) -> bool { return i > j; }
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printElements(auto & container)
{
	//Rangebased for loop
	for(auto item : container)
		cout<<item<<" ";
cout<<endl;
}

void lambdaSort()
{
	// Declare a generalized lambda and store it in sum
	auto greater = [](auto a, auto b) {
		return (a>b)?false:true;
	};

	// Initialize a vector of integers
	vector<int> vi = { 1, 4, 2, 1, 6, 62, 636 };

	// Initialize a vector of doubles
	vector<double> vd = { 4.62, 161.3, 62.26, 13.4, 235.5 };

	// Initialize a vector of strings
	vector<string> vs = { "Tom", "Harry", "Ram", "Shyam" };

	// Sort integers
	sort(vi.begin(), vi.end(), greater);

	// Sort doubles
	sort(vd.begin(), vd.end(), greater);

	// Sort strings
	sort(vs.begin(), vs.end(), greater);

	printElements(vi);
	printElements(vd);
	printElements(vs);
}

void lambdaSum()
{
	// Declare a generalized lambda and store it in sum
	auto sum = [](auto a, auto b) {
		return a + b;
	};

	// Find sum of two integers
	cout << sum(1, 6) << endl;

	// Find sum of two floating numbers
	cout << sum(1.0, 5.6) << endl;

	// Find sum of two strings
	cout << sum(string("Prashant "), string("Tiwari")) << endl;
}

int GLambda_main()
{
	lambdaSum();
	lambdaSort();
	return 0;
}
