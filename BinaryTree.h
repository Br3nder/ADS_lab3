#pragma once
#include "BinaryElement.h"
#include "Item.h"
#include "Stack.h"
#include "Iterator.h"

class binaryTree
{
public:
	int key;
	class Stack;
	binaryElement* root;
	binaryTree(int k) : key(k), root(new binaryElement(key)) {};
	~binaryTree();
	bool contains(int key);
	void insert(int key);
	void remove(int key);
	NLRIterator* createNLRIterator() { return new NLRIterator(root); };
	BFSIterator* createBFSIterator() { return new BFSIterator(root); };

private:
	void deleteTree(binaryElement* element);
};