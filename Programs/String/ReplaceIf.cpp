/*
 * ReplaceIf.cpp
 *
 *  Created on: Aug 25, 2019
 *      Author: Prash
 */


// CPP code to demonstrate replace_if()

#include <iostream>
#include <vector>
#include <algorithm> // Header file for replace_if
using namespace std;

// Function to check if character is vowel or not
bool IsVowel(char ch)
{
	return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
		  ||ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );
}

// Function to replace all vowels with 'V'
void replace_ifDemo(string &str)
{
	replace_if(str.begin(), str.end(), IsVowel, '$');
}


// Driver code
int replaceIf_main()
{
	string str;
    getline(cin,str);
	cout << "Before replace_if " <<": "<<str<<endl;

	replace_ifDemo(str);

	cout << "After replace_if " << ": "<<str;
	return 0;
}


