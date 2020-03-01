#include <iostream>
#include "tree.h"
#include "queue.h"

using namespace std;
void testTree(tree<char>* t1, char[], int size);
void test(queue<int> &q1);
void testQueue(queue<int>* q1);

int main() {
	tree<char> t1;

	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr[10] = { 7,3,11,1,5,0,2,4,6 };
	//int arr[11] = { 0,7,14,21,28,35,42,49,56,63,70 };
	char arr[15] = { 'a','b','c','d','e','f','g','i','j','k','l' };
	//int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	testTree(&t1, arr, 6);
	//t1.reverseOrderTrasversal();

	cout << endl << endl;
	t1.printTreeRot(true);
	cout << endl << endl;
	//t1.printTree();
	cout << endl << endl;
	//int num = 14;
	//cout << num;  (t1.exist(num) == true) ? cout << " exists" << endl : cout << " do not exist" << endl;
	for (int i = 1; i <= 7; i++) {
		int num = 10 * (i - 1);
		cout << "Successor of " << num << " is " << t1.findSuccessor(num) << endl;
	}
	

	t1.avlBalance();
	//t1.avlBalance();
	cout << endl << endl;
	t1.printTree();
	cout << endl << endl;
	t1.printTreeRot(true);
	//t1.inOrderTrasversal();

	//cout << "Lowest val is " << t1.findLowestVal(t1.root) << endl;
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


void testQueue(queue<int>* q1) {
	q1->push_to_back(2);
	q1->push_to_back(3);
	q1->push_to_back(4);
	q1->push_to_back(5);
	q1->push_to_back(3);
	q1->push_to_back(2);
	cout << "Queue filled!" << endl;
	q1->printQueue();
}

void test(queue<int> &q1) {
	q1.pop_from_front();
	q1.printQueue();
	return;
}

void testTree(tree<char>* t1, char arr[], int size) {
	for (int i = 0; i< size; i++) {
		cout << arr[i] << endl;
		t1->insertTreeNode(arr[i]);
	}
	cout<<"Lowest val is "<< t1->findLowestVal() <<endl;
	cout << "Tree filled!" << endl;
	t1->inOrderTrasversal();
	cout << endl;
}

