#pragma once
#include <iostream>
#include "queue.h"
#include "modified_iostream.h"

using namespace std;

template <class T>
class treeNode;

template <class T>
class tree {
private:
	treeNode<T>* root;

public:
	//Constructor and destructor
	tree();
	//~tree();

	//Trasversal functions with print
	void inOrderTrasversal() { inOrderTrasversal(root); }
	void inOrderTrasversal(treeNode<T>*);

	void preOrderTrasversal() { preOrderTrasversal(root); }
	void preOrderTrasversal(treeNode<T>*);

	void postOrderTrasversal() { postOrderTrasversal(root); }
	void postOrderTrasversal(treeNode<T>*);

	void reverseOrderTrasversal() { reverseOrderTrasversal(root); }
	void reverseOrderTrasversal(treeNode<T>*);

	//BST Operations
	treeNode<T>* insertTreeNode(T a, treeNode<T>*);
	treeNode<T>* insertTreeNode(T a) { return insertTreeNode(a, root); }
	void printTree();
	T findMaxVal();
	T findMinVal();
	T findLowestVal(treeNode<T>*);
	T findLowestVal() { return findLowestVal(root); }
	int findTreeHeight();
	bool exist(T a);
	T findSuccessor(T a);

	//Print vertical
	int findNumSpace(int);
	void printTreeFromQueue(queue<treeNode<T>*>* q1);
	void enqueue(treeNode<T>* node, queue<treeNode<T>*>* q1);


	//Print horizontal
	void printTreeRot(treeNode<T>* node, bool printHeight);
	void printTreeRot(bool printHeight) { printTreeRot(root, printHeight); }
	void printNode(treeNode<T>* node, bool printHeight);

	//Support functions
	void printZero(int);
	void printVert(int, int, queue<int>&);
	
	//AVL Balancing
	treeNode<T>* avlBalance(treeNode<T>* node);
	treeNode<T>* avlBalance() { return avlBalance(root); }
	treeNode<T>* balanceNode(treeNode<T>* node);
	treeNode<T>* left_rotate(treeNode<T>*);
	treeNode<T>* right_rotate(treeNode<T>*);

};

template <class T>
class treeNode {
public:
	//Constructor
	treeNode(T a);
	treeNode(T a, bool);

	//TreeNode operations
	int findHeight();
	friend class tree<T>;	
	friend ostream &operator<<(ostream&, treeNode<T>*);


private:
	bool containNum;
	T val;
	treeNode<T>* left;
	treeNode<T>* right;
};

#include "tree.hpp"
#include "print_tree.hpp"
#include "printTreeRot.hpp"
#include "avlBalance.hpp"