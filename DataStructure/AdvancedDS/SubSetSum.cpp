/*
 * SubSetSum.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: 212331148
 *      https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
 */


// A Dynamic Programming solution for subset sum problem
#include <iostream>
using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a
	// subset of set[0..j-1] with sum equal to i
	bool subset[n+1][sum+1];

	// If sum is 0, then answer is true
	if( sum == 0)
		return true;

	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty, then answer is false
	/*	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;*/
	if(n == 0)
		return false;

	// Fill the subset table in botton up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if(j<set[i-1])
				subset[i][j] = subset[i-1][j];
			if (j >= set[i-1])
				subset[i][j] = subset[i-1][j] ||
				subset[i - 1][j-set[i-1]];
		}
	}

	return subset[n][sum];
}

// Driver program to test above function
int SubSun_main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n = sizeof(set)/sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout<<"Found a subset with given sum"<<endl;
	else
		cout<<"No subset with given sum"<<endl;
	return 0;
}
