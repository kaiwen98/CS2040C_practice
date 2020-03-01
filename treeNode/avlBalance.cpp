#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

treeNode* tree::avlBalance(treeNode* node) {
	//cout << "node is " << node->val << " parent is " << parent->val << endl;
	
	if (node->left != NULL) {
		node->left = avlBalance(node->left);
	}
	if (node->right != NULL) {
		node->right = avlBalance(node->right);
	}
	if (node->findHeight() == findTreeHeight()) {
		root = balanceNode(node);
	}
	//printTree();
	/*if (node->findHeight() != findTreeHeight()) {
		parent = (direction == 1) ? parent->left : parent->right;

	}*/
	/*cout << "node is " << node->val << " parent is " << parent->val << endl;
	cout << "/////////////This is the tree before i pass to balance//////////////////////////" << endl;
	printTree();
	parent->right = balanceNode(node);
	cout << "height of tree is " << findTreeHeight() << " root is " << root->val << endl;
	cout << "/////////////This is the tree after i pass to balance//////////////////////////" << endl;
	printTree();*/
	return balanceNode(node);
}

treeNode* tree::balanceNode(treeNode* node) {

	//cout << "node is " << node->val << endl;
	//cout << "/////////////This is the tree in balance/////////////////////////" << endl;

	//printTree();
	//inOrderTrasversal(); cout << endl;
	//cout << "node height is " << node->findHeight() << " tree height is " << findTreeHeight() << endl;
	//int flag = (node->findHeight() == findTreeHeight()) ? 1 : 0;

	//cout << "left height is " << node->left->findHeight() << " right height is " << node->right->findHeight() << endl;
	if (node->left->findHeight() - node->right->findHeight() > 1) { //left heavy
		if (node->left->right->findHeight() > node->left->left->findHeight()) { //right heavy
			node->left = left_rotate(node->left);
		}
		node = right_rotate(node);
	}
	else if (node->right->findHeight() - node->left->findHeight() > 1) { //right heavy
		if (node->right->left->findHeight() > node->right->right->findHeight()) { //left heavy
			node->right = right_rotate(node->right);
		}
		node = left_rotate(node);
		//cout << "new node is " << node->val << "left:" << node->left->val << "right:" << node->right->val << endl;
		//printTree();
	}

	if (node->left != NULL) node->left = balanceNode(node->left);
	if (node->right != NULL) node->right = balanceNode(node->right);
	return node;
}

treeNode* tree::left_rotate(treeNode* node) {
	treeNode* fix = node->right;
	treeNode* temp = node->right->left;
	node->right->left = node;
	node->right = temp;
	cout << "fix is: " << fix->left->val << " " << fix->val << " " << fix->right->val << endl;
	return fix;
}

treeNode* tree::right_rotate(treeNode* node) {
	treeNode* fix = node->left;
	treeNode* temp = node->left->right;
	node->left->right = node;
	node->left = temp;
	return fix;
}

