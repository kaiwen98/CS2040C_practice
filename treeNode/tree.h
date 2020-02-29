#pragma once
#include <iostream>
#include "queue.h"
using namespace std;

class treeNode;

class tree {
public:
	tree();
	treeNode* insertTreeNode(int a, treeNode*);
	treeNode* insertTreeNode(int a) { return insertTreeNode(a, root); }

	void inOrderTrasversal() { inOrderTrasversal(root); }
	void inOrderTrasversal(treeNode*);
	void preOrderTrasversal() { preOrderTrasversal(root); }
	void preOrderTrasversal(treeNode*);
	void postOrderTrasversal() { postOrderTrasversal(root); }
	void postOrderTrasversal(treeNode*);
	void reverseOrderTrasversal(treeNode*);
	void reverseOrderTrasversal() { reverseOrderTrasversal(root); }

	

	void printTree();
	int findMaxVal();
	int findMinVal();
	int findNumSpace(int);
	int findTreeHeight();
	bool exist(int a);
	int findSuccessor(int a);

	
	void printZero(int);
	void printVert(int, int, queue<int>&);
	int findLowestVal(treeNode*);
	treeNode* root;

	void printTreeFromQueue(queue<treeNode*>* q1);
	void enqueue(treeNode* node, queue<treeNode*>* q1);
	void printTreeRot(bool printHeight) {
		printTreeRot(root, printHeight);
	}

	void printTreeRot(treeNode* node, bool printHeight);
	void printNode(treeNode* node, bool printHeight);


	treeNode* avlBalance(treeNode* node);
	treeNode* avlBalance() {return avlBalance(root);}
	treeNode* balanceNode(treeNode* node);
	treeNode* left_rotate(treeNode*);
	treeNode* right_rotate(treeNode*);

};


class treeNode {
public:
	treeNode(int a);
	treeNode(int a, bool);
	int findHeight();
	friend class tree;
	bool containNum;
	int val;
	treeNode* left;
	treeNode* right;
	
	friend ostream &operator<<(ostream&, treeNode*);
};
