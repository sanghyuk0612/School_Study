#pragma once

#include<iostream>
#include<string>
#include "node.h"
using namespace std;

class DNode {
private:
	string elem;
	DNode* prev;
	DNode* next;
	friend class DLinkedList;
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const string& front() const;
	const string& back() const;
	void addFront(const string& e);
	void addBack(const string& e);
	void removeFront();
	void removeBack();
private:
	DNode* header;
	DNode* trailer;
protected:
	void add(DNode* v, const string& e);
	void remove(DNode* v);
};