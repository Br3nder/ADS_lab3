#pragma once
#include "BinaryElement.h"
class Item
{
public:
	Item() : element(nullptr), prev(nullptr) {};
	Item(binaryElement* newElement, Item* newItem) : element(newElement), prev(newItem) {};
	binaryElement* getElement() { return element; };
	Item* getPrev() { return prev; };
	void setPrev(Item* prevItem) { prev = prevItem; }
	~Item() { element = nullptr; prev = nullptr; };

private:
	binaryElement* element;
	Item* prev;
};
