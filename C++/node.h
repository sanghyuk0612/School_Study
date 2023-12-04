#pragma once

#include<iostream>
using namespace std;
typedef string Elem;
class Node {
	Elem elem;
	Node* prev;
	Node* next;
	friend class DLinkedList;
	friend class Iterator;
};