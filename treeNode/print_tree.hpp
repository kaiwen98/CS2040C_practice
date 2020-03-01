#pragma once
#include "queue.h"
#include "tree.h"
#include <iostream>
#include <cmath>

using namespace std;
//print_tree.cpp: Prints BST vertically.

//Find width of space to print for BST
template <class T>
int tree<T>::findNumSpace(int height) {
	return pow(2, height) - 2;
}

//Conveniently print desired number of spaces
template <class T>
void tree<T>::printZero(int n) {
	for (int i = 0; i < n; i++) cout << " ";
}

//Print lines that connect parent node to children nodes
template <class T>
void tree<T>::printVert(int n, int height, queue<int>& levelCode) {
	//Access levelCode values
	queueNode<int>* temp = levelCode.head;
	int j;
	//Avoid printing the final layer, which are all null values
	if (height == findTreeHeight()) return;

	//Denode number of vertical levels to print slashes
	for (int i = 0; i <= n / 2; i++) {
		j = 0;
		//For each node in the level
		while (j < pow(2, height)) {
			//Left justified space
			printZero(n - i);
			(temp->val == 1) ? cout << "/" : cout << " ";
			temp = temp->next;
			//space between siblings
			printZero(i * 2 + 1);
			(temp->val == 1) ? cout << "\\" : cout << " ";
			j++;
			//space between adjacent pairs of children
			printZero(n - i + 1);
			temp = temp->next;
		}
		//Resets pointer to beginning of queue for each level down to next level of nodes
		temp = levelCode.head;
		cout << endl;
	}
}

//Enqueues a node and its children into a queue. 
template <class T>
void tree<T>::printTree() {
	queue<treeNode<T>*>* q1 = new queue<treeNode<T>*>();
	treeNode<T>* tptr = root;
	//Enqueue node and its children
	enqueue(tptr, q1);
	queueNode<treeNode<T>*>* qptr = q1->head;
	//Lowest Val is the last element that we need to enqueue.
	while (tptr->val != findLowestVal(root)) {
		tptr = qptr->val;
		enqueue(tptr, q1);
		qptr = qptr->next;
	}
	//pass queue into another function to print
	printTreeFromQueue(q1);
}

//Prints BST with appropriate spacing and format
template <class T>
void tree<T>::printTreeFromQueue(queue<treeNode<T>*>* q1) {
	//Encodes actual numbers in each level (To print slashes)
	queue<int> levelCode;
	//Read treeNode queue from head 
	queueNode<treeNode<T>*>* qptr = q1->head;

	int height = findTreeHeight();
	int val;

	//For each level of the tree
	for (int i = height; i >= 0; i--) {
		//Print left justified space
		printZero(findNumSpace(i + 1));

		//For each element present in the level 
		for (int j = 0; j < pow(2, height - i) /*&& q1->head != NULL*/; j++) {

			//Encodes next level of nodes to plan for slashes
			//If node has a left child
			val = (qptr->val->left != NULL) ? 1 : 0;
			levelCode.push_to_back(val);

			//If node has a right child
			val = (qptr->val->right != NULL) ? 1 : 0;
			levelCode.push_to_back(val);

			//If node contains a number, print number in 2 digits (spacing)
			if (qptr->val->containNum == true) {
				((qptr->val->val) / 10 == 0) ? cout << "0" : cout << " ";
				cout << qptr->val->val << "";
			}
			//Else, print space
			else cout << "  ";

			//Prints spacing between adjacent nodes in the same level
			printZero(findNumSpace(i + 2));

			//Go to next element in the level
			qptr = qptr->next;

			//Deconstruct the queue
			//q1->pop_from_front();
		}
		cout << endl;

		//print the slashes connecting this level and the next
		printVert(findNumSpace(i + 1), height - i, levelCode);

		//Reset levelCode to prepare for next level
		while (levelCode.head != NULL) levelCode.pop_from_front();
	}
}

template <class T>
void tree<T>::enqueue(treeNode<T>* node, queue<treeNode<T>*>* q1) {
	//if queue is empty, enqueue first treeNode
	if (q1->size == 0) q1->push_to_back(node);

	else {
		//Checks left child
		if (node->left == NULL) {
			//Insert dummy child with no values
			treeNode<T>* dummyNode = new treeNode<T>(0, false);
			q1->push_to_back(dummyNode);
		}
		//Enqueue left child
		else q1->push_to_back(node->left);

		//Checks right child
		if (node->right == NULL) {
			treeNode<T>* dummyNode = new treeNode<T>(0, false);
			q1->push_to_back(dummyNode);
		}
		//Enqueue right child
		else q1->push_to_back(node->right);
	}
}