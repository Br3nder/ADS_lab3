#include "Stack.h"

binaryElement* Stack::pop()
{
	if (cur)
	{
		binaryElement* element = cur->getElement();
		cur = cur->getPrev();
		return element;
	}
	return nullptr;
}

void Stack::push(binaryElement* newElement)
{
	Item* newItem = new Item(newElement, cur);
	cur = newItem;
}

bool Stack::isEmpty()
{
	if (cur)
		return false;
	return true;
}