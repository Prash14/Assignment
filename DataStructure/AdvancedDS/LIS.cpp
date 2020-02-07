/*
 * LIS.cpp
 *
 *  Created on: Dec 3, 2019
 *      Author: 212331148
 */

/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h>
#include"iostream"
using namespace std;

/* lis() returns the length of the longest increasing
subsequence in arr[] of size n */
int lis( int arr[], int n )
{
	int lis[n];

	lis[0] = 1;

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ )
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++ )
			if ( arr[i] > arr[j])
				lis[i] = max(lis[i],lis[j] + 1);
	}

	// Return maximum value in lis[]
	return *max_element(lis, lis+n);
}

/* Driver program to test above function */
int LISmain()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Length of lis is %d\n"<< lis( arr, n ) ;
	return 0;
}


