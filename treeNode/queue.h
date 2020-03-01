#pragma once
#include <iostream>
template <class T>
class queue;

template <class T>
class queueNode {
public:
	queueNode(T a) { val = a; next = NULL; }
	queueNode() { val = NULL; next = NULL; }
	friend class queue<T>;

	T val;
	queueNode<T>* next;
};


template <class T>
class queue {
public:
	queue() { head = NULL; size = 0; }
	~queue() { while (size > 0) pop_from_front(); }
	void push_to_back(T a);
	void pop_from_front();
	void printQueue();

	queueNode<T>* head;
	int size;
};


#include "queue.hpp"
