#pragma once
#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;



//Constructor
template <class T>
treeNode<T>::treeNode(T a, bool n) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = n;
}

template <class T>
treeNode<T>::treeNode(T a) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = true;
}

template <class T>
tree<T>::tree() {
	root = NULL;
}

//Checks if a value exists
template <class T>
bool tree<T>::exist(T a) {
	treeNode* temp = root;
	//Traverse left or right depending on value of current node.
	//O(log n) time
	while (temp != NULL) {
		if (temp->val == a) return true;
		else if (temp->val < a) temp = temp->right;
		else temp = temp->left;
	}
	return false;
}

//Inserts node into BST
//When new node is created, each node is assigned a new address with the modified chain of pointers to the new treeNodes.
template <class T>
treeNode<T>* tree<T>::insertTreeNode(T a, treeNode<T>* node) {

	//Case 1: BST is empty. Then new node becomes root of BST.
	if (root == NULL) {
		root = new treeNode<T>(a);
		//cout << "new root made!" << endl;
	}

	else {
		//cout << "height of the treeNode is: " << node->findHeight() << endl;
		if (a > node->val) {
			node->right = (node->right == NULL) ? node->right = new treeNode<T>(a) : insertTreeNode(a, node->right);
		}
		else if (a < node->val) {
			node->left = (node->left == NULL) ? node->left = new treeNode<T>(a) : insertTreeNode(a, node->left);
		}
	}
	return node;
}

//Finds max value in BST
template <class T>
T tree<T>::findMaxVal() {
	treeNode<T>* temp = root;
	if (temp == NULL) return 0;
	while (temp->right != NULL) temp = temp->right;
	return temp->val;
}

//Finds min value in BST
template <class T>
T tree<T>::findMinVal() {
	treeNode<T>* temp = root;
	if (temp == NULL) return 0;
	while (temp->left != NULL) temp = temp->left;
	return temp->val;
}

//Finds the bottom right value in BST
template <class T>
T tree<T>::findLowestVal(treeNode<T>* node) {
	//Case 1: Only one node in BST
	if (node->left == NULL && node->right == NULL) return node->val;

	// Disabled since findHeight() now returns -1 on NULL

	/*//Case2: One of the children is NULL, in which case we cannot access it.
	else if (node->right != NULL && node->left == NULL) {
		return findLowestVal(node->right);
	}
	else if (node->right == NULL && node->left != NULL) {
		return findLowestVal(node->left);
	}*/

	//Case 2: Both children can be accessed.

	if (node->left->findHeight() > node->right->findHeight()) return findLowestVal(node->left);
	else return findLowestVal(node->right);
}

//Find successor to given integer.
//Logic is such that the most closely proximate predecessor node that the 
//temp node pointer trasverses left from before it stops search
//Is the successor to the key value.
template <class T>
T tree<T>::findSuccessor(T a) {
	treeNode<T>* temp = root;
	treeNode<T>* key = root;
	int flag = 0;
	while (temp != 0) {
		if (a >= temp->val && temp->right != NULL) {
			temp = temp->right;
		}
		else if (a < temp->val && temp->left != NULL) {
			flag = 1;
			key = temp;
			temp = temp->left;
		}

		//When the successor exists at terminal node
		else {
			if (a < temp->val) {
				key = temp;
				flag = 1;
			}

			break;
		}
	}
	return (flag == 0) ? 0 : key->val;

}

//Determine height of the node recursively.
template <class T>
int treeNode<T>::findHeight() {
	if (this == NULL) return -1;
	int leftHeight = (left == NULL) ? -1 : left->findHeight();
	int rightHeight = (right == NULL) ? -1 : right->findHeight();
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

//Return maximum height of the tree
template <class T>
int tree<T>::findTreeHeight() {
	return root->findHeight();
}

template <class T>
void tree<T>::inOrderTrasversal(treeNode<T>* node) {
	if (node->left != NULL) inOrderTrasversal(node->left);
	cout << node->val << " ";
	if (node->right != NULL) inOrderTrasversal(node->right);
}

template <class T>
void tree<T>::preOrderTrasversal(treeNode<T>* node) {
	cout << node->val << " ";
	if (node->left != NULL) preOrderTrasversal(node->left);
	if (node->right != NULL) preOrderTrasversal(node->right);
}

template <class T>
void tree<T>::reverseOrderTrasversal(treeNode<T>* node) {
	if (node->right != NULL)reverseOrderTrasversal(node->right);
	cout << node->val << " ";
	if (node->left != NULL)reverseOrderTrasversal(node->left);
}

template <class T>
void tree<T>::postOrderTrasversal(treeNode<T>* node) {
	if (node->left != NULL) postOrderTrasversal(node->left);
	if (node->right != NULL) postOrderTrasversal(node->right);
	cout << node->val << " ";
}

//Declared to conveniently print treeNode in queue implementation
template <class T>
ostream&  operator<<(ostream& os, treeNode<T>* node) {
	os << node->val;
	return os;
}

