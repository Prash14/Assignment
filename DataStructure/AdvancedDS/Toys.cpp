/*
 * Toys.cpp
 *
 *  Created on: Dec 8, 2019
 *      Author: 212331148
 *      Maximise the number of toys that can be purchased with amount K using min Heap
 *      https://www.geeksforgeeks.org/maximise-the-number-of-toys-that-can-be-purchased-with-amount-k-using-min-heap/
 */


// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of
// maximum toys that can be bought
int maxToys(int arr[], int n, int k)
{

	// Create a priority_queue and push
	// all the array elements in it
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) {
		pq.push(arr[i]);
	}

	// To store the count of maximum
	// toys that can be bought
	int count = 0;
	while (pq.top() <= k) {
		count++;
		k = k - pq.top();
		pq.pop();
	}
	return count;
}

// Driver code
int Toysmain()
{
	int arr[] = { 1, 12, 5, 111, 200, 1000, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 50;

	cout << maxToys(arr, n, k);

	return 0;
}


