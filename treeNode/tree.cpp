#include "tree.h"
#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

treeNode::treeNode(int a, bool n) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = n;
}

treeNode::treeNode(int a) {
	val = a;
	left = NULL;
	right = NULL;
	containNum = true;
}

tree::tree() {
	root = NULL;
}

bool tree::exist(int a) {
	treeNode* temp = root;
	while (temp != NULL) {
		if (temp->val == a) return true;
		else if (temp->val < a) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	return false;
}

treeNode* tree::insertTreeNode(int a, treeNode* node) {

	if (root == NULL) {
		root = new treeNode(a);
		cout << "new root made!" << endl;
	}
	else {
		cout << "height of the treeNode is: " << node->findHeight() << endl;
		if (a > node->val) {
			node->right = (node->right == NULL) ? node->right = new treeNode(a) : insertTreeNode(a, node->right);
		}
		else if (a < node->val) {
			node->left = (node->left == NULL) ? node->left = new treeNode(a) : insertTreeNode(a, node->left);
		}
	}
	return node;
}

int tree::findMaxVal() {
	treeNode* temp = root;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	return temp->val;
}

int tree::findMinVal() {
	treeNode* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp->val;
}

int tree::findLowestVal(treeNode* node) {
	if (node->left == NULL && node->right == NULL) return node->val;
	else if (node->right != NULL && node->left == NULL) {
		return findLowestVal(node->right);
	}
	else if (node->right == NULL && node->left != NULL) {
		return findLowestVal(node->left);
	}
	else {
		if (node->left->findHeight() > node->right->findHeight()) {
			return findLowestVal(node->left);
		}
		else {
			return findLowestVal(node->right);
		}
	}
}



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
	int flag = (node->findHeight() == findTreeHeight()) ? 1 : 0;

	if (node->left->findHeight() - node->right->findHeight() > 1) { //left heavy
		if (node->left->right->findHeight() > node->left->left->findHeight()) { //right heavy
			node->left = left_rotate(node->left);

		}
		node = right_rotate(node);
	}
	else if (node->right->findHeight() - node->left->findHeight() > 1){ //right heavy
		if (node->right->left->findHeight() > node->right->right->findHeight()) { //left heavy
			node->right = right_rotate(node->right);
		}
		node = left_rotate(node);
		cout << "new node is " << node->val << "left:"<<node->left->val << "right:" << node->right->val<< endl;
	}

	if (node->left != NULL) node->left = balanceNode (node->left);
	if(node->right != NULL) node->right = balanceNode (node->right);

	if (flag) root = node;
	return node;
}

treeNode* tree::left_rotate(treeNode* node) {
	treeNode* fix = node->right;
	treeNode* temp = node->right->left;
	node->right->left = node;
	node->right = temp;
	cout <<"fix is: "<< fix->left->val << " " << fix->val << " " << fix->right->val << endl;
	return fix;
}

treeNode* tree::right_rotate(treeNode* node) {
	treeNode* fix = node->left;
	treeNode* temp = node->left->right;
	node->left->right = node;
	node->left = temp;
	return fix;
}



int tree::findSuccessor(int a) {
	treeNode* temp = root;
	treeNode* key = root;
	int flag = 0;
	int answer = 0;
	while(temp!= NULL)
	if (a >= temp->val && temp->right != NULL) {
		temp = temp->right;
	}

	else if(a < temp->val && temp->left != NULL){
		flag = 1;
		key = temp;
		temp = temp->left;
	}

	else {
		if (a < temp->val) {
			key = temp;
			flag = 1;
		}
		
		break;
	}
	return (flag==0)?0:key->val;
}



int treeNode::findHeight() {
	if (this == NULL) return -1;
	int leftHeight = (left == NULL) ? -1 : left->findHeight();
	int rightHeight = (right == NULL) ? -1 : right->findHeight();
	return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int tree::findTreeHeight() {
	return root->findHeight();
}

void tree::inOrderTrasversal(treeNode* node) {
	if (node->left != NULL) inOrderTrasversal(node->left);
	cout << node->val << " ";
	if (node->right != NULL) inOrderTrasversal(node->right);
	return;
}

void tree::preOrderTrasversal(treeNode* node) {
	cout << node->val << " ";
	if (node->left != NULL) preOrderTrasversal(node->left);
	if (node->right != NULL) preOrderTrasversal(node->right);
	return;
}

void tree::reverseOrderTrasversal(treeNode* node) {
	if (node->right != NULL)reverseOrderTrasversal(node->right);
	cout << node->val <<" ";
	if (node->left != NULL)reverseOrderTrasversal(node->left);
	return;
}

void tree::postOrderTrasversal(treeNode* node) {
	if (node->left != NULL) postOrderTrasversal(node->left);
	if (node->right != NULL) postOrderTrasversal(node->right);
	cout << node->val << " ";
	return;
}



ostream& operator<<(ostream& os, treeNode* node) {
	os << node->val;
	return os;
}
