/*
 * Ceaser.cpp
 *
 *  Created on: Dec 13, 2019
 *      Author: 212331148
 *      https://www.hackerrank.com/challenges/caesar-cipher-1/problem
 */

#include<iostream>
using namespace std;

string caesarCipher(string &s, int k) {

	int dup = k%26;
	for(auto &ch : s)
	{
		int val = ch;
        k = dup;

		if( (val>='A') && val<='Z' )
		{
			if((val+k)>'Z')
			{
				k = val+k - 'Z';
				ch = 'A' +k-1;
			}
			else
			{
				ch = ch +k;
			}
		}

		else if( (val>='a') && val<='z' )
		{
			if((val+k)>'z')
			{
				k = val+k - 'z';
				ch = 'a' +k-1;
			}
			else
			{
				ch = ch +k;
			}
		}

		}

return s;
}

int Ceaser_main()
{
	string str = "159357lcfd";
	int shift = 98;
	cout<<str<<endl;
	caesarCipher(str, shift);//159357fwzx
	cout<<str<<endl; //okffng-Qwvb
	return 0;
}
