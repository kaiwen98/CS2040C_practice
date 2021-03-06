#pragma once
#include "tree.h"
#include "queue.h"
#include <iostream>


using namespace std;
//printTreeRot.cpp: Prints BST rotated 90 degrees.

//Driver function to trasverse the BST in reverse order, such that the graph can be printed as if rotated
//90 degrees anti-clockwise.
template <class T>
void tree<T>::printTreeRot(treeNode<T>* node, bool printHeight) {
	if (node == NULL) return;

	if (node->right != NULL) printTreeRot(node->right, printHeight);
	if (node != NULL) printNode(node, printHeight);
	if (node->left != NULL) printTreeRot(node->left, printHeight);
	return;
}

//Formats each line of print of BST printing
template <class T>
void tree<T>::printNode(treeNode<T>* node, bool printHeight) {
	//Prints apprpriate width of space depending on level of node
	printZero(5 * (findTreeHeight() - node->findHeight()));
	cout << node->val;
	//If true: print height value. If false, don't.
	(printHeight == true) ? cout << "(h = " << node->findHeight() << ")" : cout << "";
	cout << endl;
}

