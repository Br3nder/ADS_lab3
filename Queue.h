#pragma once
#include "BinaryElement.h"
#include "Item.h"

class Queue
{
private:
	Item* cur = nullptr;
	int count = 0;
public:
	void enqueue(binaryElement* newElement);
	binaryElement* dequeue();
	bool isEmpty();
	int size();
};

