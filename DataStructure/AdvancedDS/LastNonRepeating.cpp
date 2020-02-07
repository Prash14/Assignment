/*
 * LastNonRepeating.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: 212331148
 */

// C++ implementation of the approach
#include <bits/stdc++.h>
#include<iostream>
#include <unordered_map>
using namespace std;

// Maximum distinct characters possible
const int MAX = 256;

// Function to return the last non-repeating character
static string lastNonRepeating(string str, int n)
{

	// To store the frequency of each of
	// the character of the given string
	int freq[MAX] = {0};

	// Update the frequencies
	for (int i = 0; i < n; i++)
		freq[str.at(i)]++;


	// Starting from the last character
	for (int i = n - 1; i >= 0; i--)
	{

		// Current character
		char ch = str.at(i);

		// If frequency of the current character is 1
		// then return the character
		if (freq[ch] == 1)
		{
			string res;
			res+=ch;
			return res;
		}
	}

	// All the characters of the
	// string are repeating
	return "-1";
}

string lastNonRepeatingMap(string str)
{
	unordered_map<char,int> hash ;

	for(auto itr : str)
	{
		hash[itr]++;
	}

	for(int i = str.length()-1;i>=0;i--)
	{
		if(hash[str[i]] == 1)
		{
			string res;
			res+=str[i];
			return res;
		}
	}


	// All the characters of the
	// string are repeating
	return "-1";
}

char firstRepeatingMap(const string & str)
{
	unordered_map<char,int> hash;

	for(auto itr : str)
	{
		if(hash.find(itr) != hash.end() )
		{
			return itr;
		}
		hash.insert(make_pair(itr,0));
	}

	return 1;
}

char firstRepeatingSet(const string & str)
{
	unordered_set<char> Uset;

	for(auto itr : str)
	{
		if(Uset.find(itr) != Uset.end() )
		{
			return itr;
		}
		Uset.insert(itr);
	}
	return 1;
}

// Driver code
int Rmain()
{
	string str = "GeeksForGeeks";
	int n = str.size();
	cout<< lastNonRepeating(str, n)<<endl;
	cout<< lastNonRepeatingMap(str)<<endl;
	cout<< firstRepeatingMap(str)<<endl;
	cout<<firstRepeatingSet(str)<<endl;
	return 0;
}


