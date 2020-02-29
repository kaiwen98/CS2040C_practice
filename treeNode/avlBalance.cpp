#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

treeNode* tree::avlBalance(treeNode* node) {
	if (node->left != NULL) node->left = avlBalance(node->left);
	if (node->right != NULL) node->right = avlBalance(node->right);
	node = balanceNode(node);
	//cout << "node at avl is " << node->val << endl;
	//printTree();
	return node;
}

treeNode* tree::balanceNode(treeNode* node) {
	//cout << "node is " << node->val << endl;
	//printTree();
	inOrderTrasversal(); cout << endl;
	cout << "node height is " << node->findHeight() << " tree height is " << findTreeHeight() << endl;
	int flag = (node->findHeight() == findTreeHeight()) ? 1 : 0;

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
		cout << "new node is " << node->val << "left:" << node->left->val << "right:" << node->right->val << endl;
	}

	if (node->left != NULL) node->left = balanceNode(node->left);
	if (node->right != NULL) node->right = balanceNode(node->right);

	if (flag) root = node;
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

