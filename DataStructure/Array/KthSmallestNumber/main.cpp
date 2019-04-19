/* Kth smallest Element in Unsorted array.
 * ========================================
 *
 * Method 1: Using Max Heap
 * ------------------------
 * We can easily solve this problem in O(nlogk) by using a max-heap.
 * The idea is to construct a max-heap of size k and insert first k
 * elements of array (A[0..k-1]) into the heap. Then for each of the
 * remaining element of the array  (A[k..n-1]) , if that element is
 * less than the root of the heap, we replace the root with current
 * element. We repeat this process till array is exhausted. Now we
 * will be left with  k  smallest elements of the array in the max-heap
 * and kth smallest element will reside at the root of the max-heap.
 *
 * Method2: Using Min Heap
 * -----------------------
 * We can easily solve this problem in O(n + klogn) by using a min-heap.
 * The idea is to simply construct a min-heap of size n and insert all elements
 * of the array (A[0..n-1]) into it. Then we pop first  k-1 elements from it. Now kth
 * smallest element will reside at the root of the min-heap.
 *
 * Method3: (Using std::nth_element)
 * ----------------------------------
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the K'th smallest element in the
// array using max-heap
int findKthSmallestUsingMaxheap(vector<int> const &v, int k)
{
	// create an max-heap using std::priority_queue and
	// insert first k elements of the array into the heap
	priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);

	// do for remaining array elements
	for (int i = k; i < v.size(); i++)
	{
		// if current element is less than the root of the heap
		if (v[i] < pq.top())
		{
			// replace root with the current element
			pq.pop();
			pq.push(v[i]);
		}
	}

	// return the root of max-heap
	return pq.top();
}

// Function to find the K'th smallest element in the
// array using min-heap
int findKthSmallestUsingMinheap(vector<int> const &vec, int k)
{
	// create an empty min-heap and initialize it with all elements
	// use std::greater as the comparison function for min-heap
	priority_queue<int, std::vector<int>, std::greater<>>
			pq(vec.begin(), vec.end());

	// pop from min-heap exactly (k-1) times
	while (--k) {
		pq.pop();
	}

	// return the root of min-heap
	return pq.top();
}

// Find K'th smallest element in an array
int main()
{
	vector<int> vec  = { 7, 4, 6, 3, 9, 1 };
	const size_t k = 3;

	cout << "MaxHeap:: K'th smallest element in the array is " <<
			findKthSmallestUsingMaxheap(vec, k) <<endl;
	cout << "MinHeap:: K'th smallest element in the array is " <<
	findKthSmallestUsingMinheap(vec,k)<< endl;

	return 0;
}
