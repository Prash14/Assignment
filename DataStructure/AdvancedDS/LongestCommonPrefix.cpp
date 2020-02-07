/*
 * LongestCommonPrefix.cpp
 *
 *  Created on: Dec 8, 2019
 *      Author: 212331148
 * https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/
*/

// A Program to find the longest common
// prefix of the given words

#include <iostream>
#include <unordered_map>
using namespace std;

// A Trie node
struct Trie
{
	// true when node is a leaf node
	bool isLeaf;

	// each node stores a map to its child nodes
	unordered_map<char, Trie*> children;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->isLeaf = false;
	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie* & head, string str)
{
	if (head == nullptr)
		head = getNewTrieNode();

	// start from root node
	Trie* pCrawl = head;
	for(auto itr : str)
	{
		// create a new node if path doesn't exists
		if (pCrawl->children.find(itr) == pCrawl->children.end())
			pCrawl->children[itr] = getNewTrieNode();

		// go to next node
		pCrawl = pCrawl->children[itr];

	}

	// mark current node as leaf
	pCrawl->isLeaf = true;
}


// Perform a walk on the trie and return the
// longest common prefix string
string walkTrie(Trie *root)
{
	Trie *pCrawl = root;
	string prefix;

	while ((pCrawl->children.size() == 1)&&
			pCrawl->isLeaf == false)
	{

		char ch = pCrawl->children.begin()->first;
		pCrawl = pCrawl->children.begin()->second;
		prefix.push_back(ch);
	}
	return (prefix);
}

// A Function to construct trie
void constructTrie(string arr[], int n, struct Trie *root)
{
	for (int i = 0; i < n; i++)
		insert (root, arr[i]);
	return;
}

// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix(string arr[], int n)
{
	struct Trie *root = getNewTrieNode();
	constructTrie(arr, n, root);

	// Perform a walk on the trie
	return walkTrie(root);
}

// Driver program to test above function
int LPmain()
{
	string arr[] = {"geeksforgeeks", "geeks",
					"geek", "geezer"};
	int n = sizeof (arr) / sizeof (arr[0]);

	string ans = commonPrefix(arr, n);

	if (ans.length())
		cout << "The longest common prefix is "
			<< ans;
	else
		cout << "There is no common prefix";
	return (0);
}
