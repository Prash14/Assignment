/*
 * LevelOrder.cpp
 *
 *  Created on: Dec 16, 2019
 *      Author: 212331148
 *    https://www.geeksforgeeks.org/level-order-traversal-line-line-set-2-using-two-queues/
 */


// C++ program to do level order traversal line by
// line
#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

void levelOrder(Node *root)
{

}

// Prints level order traversal line by line
// using two queues.
void levelOrder2Q(Node *root)
{
	queue<Node *> q1, q2;

	if (root == NULL)
		return;

	// Pushing first level node into first queue
	q1.push(root);

	// Executing loop till both the queues
	// become empty
	while (!q1.empty() || !q2.empty())
	{
		while (!q1.empty())
		{
			// Pushing left child of current node in
			// first queue into second queue
			if (q1.front()->left != NULL)
				q2.push(q1.front()->left);

			// pushing right child of current node
			// in first queue into second queue
			if (q1.front()->right != NULL)
				q2.push(q1.front()->right);

			cout << q1.front()->data << " ";
			q1.pop();
		}

		cout << "\n";

		while (!q2.empty())
		{
			// pushing left child of current node
			// in second queue into first queue
			if (q2.front()->left != NULL)
				q1.push(q2.front()->left);

			// pushing right child of current
			// node in second queue into first queue
			if (q2.front()->right != NULL)
				q1.push(q2.front()->right);

			cout << q2.front()->data << " ";
			q2.pop();
		}

		cout << "\n";
	}
}

void levelOrderSpiral(Node *root)
{
	if (root == NULL)
		return; // NULL check

	// Create two stacks to store alternate levels
	stack<Node*> s1; // For levels to be printed from right to left
	stack<Node*> s2; // For levels to be printed from left to right

	// Push first level to first stack 's1'
	s1.push(root);

	// Keep printing while any of the stacks has some nodes
	while (!s1.empty() || !s2.empty()) {
		// Print nodes of current level from s1 and push nodes of
		// next level to s2
		while (!s1.empty()) {
			cout << s1.top()->data << " ";

			// Note that is right is pushed before left
			if (s1.top()->right)
				s2.push(s1.top()->right);
			if (s1.top()->left)
				s2.push(s1.top()->left);

			s1.pop();
		}
		cout<<endl;
		// Print nodes of current level from s2 and push nodes of
		// next level to s1
		while (!s2.empty()) {

			cout << s2.top()->data << " ";

			// Note that is left is pushed before right
			if (s2.top()->left)
				s1.push(s2.top()->left);
			if (s2.top()->right)
				s1.push(s2.top()->right);
			s2.pop();
		}
		cout<<endl;
	}

}

void verticleOrder(Node * root)
{
	map<int,vector<int>> m;
	int hd=0;

	queue<pair<Node*,int>> q;
	q.push(make_pair(root,hd));

	while(!q.empty())
	{
		Node* temp = q.front().first;
		hd = q.front().second;
		m[hd].push_back(temp->data);
		q.pop();

		if(temp->left)
			q.push(make_pair(temp->left,hd-1));
		if(temp->right)
			q.push(make_pair(temp->right,hd+1));
	}

	for(auto itr : m)
	{
		for(auto i: itr.second)
			cout<<i<<" ";
		cout<<endl;
	}

}

void getVertOrder(Node * root, int hd, map<int,vector<int>>&m)
{
	if(root == NULL)
		return;

	m[hd].push_back(root->data);

	getVertOrder(root->left,hd-1,m);

	getVertOrder(root->right,hd+1,m);
}

void _printVerticalOrder(Node* root)
{
	// Create a map and store vertical order in map using
	// function getVerticalOrder()
	map<int,vector<int>> m;
	int hd =0;

	getVertOrder(root,hd, m);

	// Traverse the map and print nodes at every horigontal
	// distance (hd)
	for(auto itr : m)
	{
		for(auto idx : itr.second)
			cout<<idx<<" ";

		cout<<endl;
	}

}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left= newNode(10);
	root->right->right->left->right= newNode(11);
	root->right->right->left->right->right= newNode(12);

	cout<<"------LevelOrder----------"<<endl;
	levelOrder(root);

	cout<<"------Level Order Using 2Q----------"<<endl;
	levelOrder2Q(root);
	cout<<"------SPIRAL----------"<<endl;
	levelOrderSpiral(root);
	cout<<"------Verticle Using Queue ----------"<<endl;
	verticleOrder(root);
	cout<<"------Verticle Order ----------"<<endl;
	_printVerticalOrder(root);
	cout<<"------Top View ----------"<<endl;
	return 0;
}


