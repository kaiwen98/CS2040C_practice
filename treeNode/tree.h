#pragma once
#include <iostream>
#include "queue.h"
using namespace std;

class treeNode;

class tree {
private:
	treeNode* root;

public:
	//Constructor and destructor
	tree();
	//~tree();

	//Trasversal functions with print
	void inOrderTrasversal() { inOrderTrasversal(root); }
	void inOrderTrasversal(treeNode*);

	void preOrderTrasversal() { preOrderTrasversal(root); }
	void preOrderTrasversal(treeNode*);

	void postOrderTrasversal() { postOrderTrasversal(root); }
	void postOrderTrasversal(treeNode*);

	void reverseOrderTrasversal() { reverseOrderTrasversal(root); }
	void reverseOrderTrasversal(treeNode*);

	//BST Operations
	treeNode* insertTreeNode(int a, treeNode*);
	treeNode* insertTreeNode(int a) { return insertTreeNode(a, root); }
	void printTree();
	int findMaxVal();
	int findMinVal();
	int findLowestVal(treeNode*);
	int findLowestVal() { return findLowestVal(root); }
	int findTreeHeight();
	bool exist(int a);
	int findSuccessor(int a);

	//Print vertical
	int findNumSpace(int);
	void printTreeFromQueue(queue<treeNode*>* q1);
	void enqueue(treeNode* node, queue<treeNode*>* q1);


	//Print horizontal
	void printTreeRot(treeNode* node, bool printHeight);
	void printTreeRot(bool printHeight) { printTreeRot(root, printHeight); }
	void printNode(treeNode* node, bool printHeight);

	//Support functions
	void printZero(int);
	void printVert(int, int, queue<int>&);
	
	//AVL Balancing
	treeNode* avlBalance(treeNode* node);
	treeNode* avlBalance() { return avlBalance(root); }
	treeNode* balanceNode(treeNode* node);
	treeNode* left_rotate(treeNode*);
	treeNode* right_rotate(treeNode*);

};


class treeNode {
public:
	//Constructor
	treeNode(int a);
	treeNode(int a, bool);

	//TreeNode operations
	int findHeight();
	friend class tree;	
	friend ostream &operator<<(ostream&, treeNode*);


private:
	bool containNum;
	int val;
	treeNode* left;
	treeNode* right;
};
