/*
 * ReverseWord.cpp
 *
 *  Created on: Aug 25, 2019
 *      Author: Prash
 *
 *  Input: "I Love My India"
 *  Output: "India My Love I"
 */
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
static int const SUCCESS = 0;

void reverseString(string & str,int stIdx,int edIdx)
{
	for (auto i=stIdx, j=edIdx-1; i<j; i++,j--)
	     swap(str.at(i), str.at(j));
}

void withIterator(string &str)
{
	int startIdx = 0, endIdx =0;

	for(auto itr = str.begin(); itr != str.end();itr++)
	{
		if((*itr) == ' ')
		{
			reverseString(str,startIdx,endIdx);
			startIdx = endIdx+1;
		}
		endIdx++;
	}
	reverseString(str,startIdx,endIdx);

	startIdx=0;
	//Reverse complete string
	reverseString(str,startIdx,endIdx);

}

int ReverseWord_main()
{
	string str;
	cout<<"Enter string you want to push"<<endl;
	getline(cin,str);
	withIterator(str);
	cout<<str<<endl;
	return SUCCESS;
}


