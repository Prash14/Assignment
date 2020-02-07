/*
 * TrappingRainWater.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: 212331148
 */

// C++ program to find maximum amount of water that can
// be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;

int findWater(int arr[], int n)
{
	// left[i] contains height of tallest bar to the
	// left of i'th bar including itself
	vector<int>left(n);

	// Right contains height of tallest bar to
	// the right of ith bar including itself
	int right;
    int waterAtIndex = 0;
	// Initialize result
	int water = 0;

	// Fill left array
	left[0] = arr[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i-1]);

	// Fill right array
	right = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		right = max(right, arr[i+1]);
		// Calculate the accumulated water element by element
		// consider the amount of water on i'th bar, the
		// amount of water accumulated on this particular
		// bar will be equal to min(left[i], right) - arr[i] .
		waterAtIndex = min(left[i+1], right) - arr[i+1];
		if(waterAtIndex > 0 )
			water +=waterAtIndex;
	}

	return water;
}

// Driver program
int TPmain()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n);
	return 0;
}


