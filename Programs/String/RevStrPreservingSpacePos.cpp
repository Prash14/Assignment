/* ReverseStringPreservingSpacePositions
 * Input : "Help others"
 * Output : sreh topleH
 */

// C++ program to reverse a string preserving
// spaces.
#include<iostream>
#include "string"
#include "array"
using namespace std;

// Function to reverse the string
// and preserve the space position
string reverses(string str)
{
	// Mark spaces in result
	int j = str.length();
	string result(j,'\0');
    int idx = 0;
	for(auto itr = str.begin();itr != str.end();itr++)
	{
		if((*itr) == ' ')
		{
			result[idx] = ' ';
		}
		idx++;
	}


	// Traverse input string from beginning
	// and put characters in result from end
	j=j-1;
	for (auto itr =str.begin() ; itr != str.end(); itr++)
	{

		// Ignore spaces in input string
		if ((*itr) != ' ')
		{
			// ignore spaces in result.
			if (result[j] == ' ')
			{
				j--;
			}

			result[j] = (*itr);
			j--;
		}
	}
	return result;
}

// Driver code
int RSPSPmain()
{
	string str = "Home at GE India for geeks";
	string str1 = reverses(str);
	cout<<"1st Iteration : "<<str1<<endl;
	cout << "2nd Iteration : "<<reverses(str1) << endl;
	return 0;
}
