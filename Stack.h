#pragma once
#include "BinaryElement.h"
#include "Item.h"

class Stack
{
public:
	Stack() : cur(nullptr) {};
	~Stack() { cur = nullptr; };
	binaryElement* pop();
	void push(binaryElement* newElement);
	bool isEmpty();
private:
	Item* cur;
};

