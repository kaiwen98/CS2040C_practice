#pragma once
#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

//Reorganise the tree from bottom to up in accordance to AVL rules
template <class T>
treeNode<T>* tree<T>::avlBalance(treeNode<T>* node) {
	if (node->left != NULL) {
		node->left = avlBalance(node->left);
	}
	if (node->right != NULL) {
		node->right = avlBalance(node->right);
	}

	printTree();
	//Assign new root to new BST
	if (node->findHeight() == findTreeHeight()) {
		root = balanceNode(node);
	}
	return balanceNode(node);
}

template <class T>
treeNode<T>* tree<T>::balanceNode(treeNode<T>* node) {
	//node is imbalanced and left heavy
	if (node->left->findHeight() - node->right->findHeight() > 1) {
		//if leftNode right heavy
		if (node->left->right->findHeight() > node->left->left->findHeight()) {
			//Balance the leftNode first
			node->left = left_rotate(node->left);
		}
		//Balance the node
		node = right_rotate(node);
	}

	//node is imbalanced and right heavy
	else if (node->right->findHeight() - node->left->findHeight() > 1) {
		//if rightNode is left heavy
		if (node->right->left->findHeight() > node->right->right->findHeight()) {
			//Balance the rightNode first
			node->right = right_rotate(node->right);
		}
		//Balance the node
		node = left_rotate(node);
	}

	//In case further descendents of the node becomes imbalanced after the balance process.
	if (node->left != NULL) node->left = balanceNode(node->left);
	if (node->right != NULL) node->right = balanceNode(node->right);
	return node;
}

template <class T>
treeNode<T>* tree<T>::left_rotate(treeNode<T>* node) {
	//Stores address of the child that will replace node at its position
	treeNode<T>* fix = node->right;
	//Stores left of child
	treeNode<T>* temp = node->right->left;
	//node is now the rightchild
	node->right->left = node;
	//Transfer the child to node
	node->right = temp;
	//cout << "fix is: " << fix->left->val << " " << fix->val << " " << fix->right->val << endl;
	//Return to parent node the address of the "root" of the new subtree
	return fix;
}

template <class T>
treeNode<T>* tree<T>::right_rotate(treeNode<T>* node) {
	treeNode<T>* fix = node->left;
	treeNode<T>* temp = node->left->right;
	node->left->right = node;
	node->left = temp;
	return fix;
}


