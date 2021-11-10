#include "Queue.h"
void Queue::enqueue(binaryElement* newElement)
{
	Item* newItem = new Item(newElement, nullptr), * last = cur;
	if (last)
	{
		while (last->getPrev())
			last = last->getPrev();
		last->setPrev(new Item(newElement, nullptr));
	}
	else
		cur = new Item(newElement, nullptr);
	count++;
}

binaryElement* Queue::dequeue()
{
	if (cur)
	{
		Item* tmpItem = cur->getPrev();
		binaryElement* tmpElement = cur->getElement();
		cur->~Item();
		cur = tmpItem;
		count--;
		return tmpElement;
	}
	return nullptr;
}

bool Queue::isEmpty()
{
	if (cur)
		return false;
	return true;
}

int Queue::size() { return count; };

