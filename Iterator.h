#pragma once
#include "BinaryElement.h"
#include "Stack.h"
#include "Queue.h"

class NLRIterator
{
public:
	NLRIterator(binaryElement* node);
	binaryElement* next();
	bool hasNext();
private:
	binaryElement* cur;
	Stack* stack;
};

class BFSIterator
{
public:
	BFSIterator(binaryElement* node);
	binaryElement* next();
	bool hasNext();
private:
	binaryElement* cur;
	Queue* queue;
};
