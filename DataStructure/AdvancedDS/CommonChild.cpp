/*
 * CommonChild.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: 212331148
 * https://www.hackerrank.com/challenges/common-child/problem
 */

#include<iostream>
using namespace std;

int commonChildSpace(string &s1, string &s2) {
	int m = s1.length();
	int n = s2.length();
	int L[2][n+1];
	int i, j;
	int p,c;//p -> previous & c -> current

	/* Following steps build L[m+1][n+1] in
	       bottom up fashion. Note that L[i][j]
	       contains length of LCS of X[0..i-1]
	       and Y[0..j-1] */

	for(int j =0;j<=n;j++)
	{
		L[0][j] = 0;
		L[1][j] = 0;
	}

	for (i = 1; i <= m; i++)
	{
		if(i%2 == 0)
		{
			p = 1;
			c = 0;

		}
		else
		{
			p = 0;
			c = 1;
		}

		for (j = 1; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[c][j] = 0;

			else if (s1[i-1] == s2[j - 1])
				L[c][j] = L[p][j - 1] + 1;

			else
				L[c][j] = max(L[p][j], L[c][j - 1]);
		}
	}

	/* L[m][n] contains length of LCS
	    for X[0..n-1] and Y[0..m-1] */
	return L[c][n];

}



int commonChild(string &s1, string &s2) {
	int m = s1.length();
	int n = s2.length();
	int L[m + 1][n + 1];
	int i, j;

	/*Following steps build L[m+1][n+1] in
	  bottom up fashion. Note that L[i][j]
	  contains length of LCS of X[0..i-1]
	  and Y[0..j-1] */
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (s1[i - 1] == s2[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	/* L[m][n] contains length of LCS
	    for X[0..n-1] and Y[0..m-1] */
	return L[m][n];

}

int LCS_CC_main()
{
	string s1 = "ABCDEF";
	string s2 = "FBDAMN";

	int result = commonChild(s1, s2);

	cout<<result<<endl;
	cout<<commonChildSpace(s1, s2);

	return 0;
}



