#include "Iterator.h"

binaryElement* NLRIterator::next()
{
	if (cur)
	{
		binaryElement* tmp = cur;
		if (cur->right)
			stack->push(cur);
		if (cur->left)
			cur = cur->left;
		else
		{
			cur = stack->pop();
			if (cur)
				cur = cur->right;
		}
		return tmp;
	}
}

bool NLRIterator::hasNext()
{
	if (cur || !stack->isEmpty()) return true;
	return false;
}

NLRIterator::NLRIterator(binaryElement* root) : cur(root)
{
	stack = new Stack(); 
}

binaryElement* BFSIterator::next()
{
	if (!queue->isEmpty())
	{
		binaryElement* tmpElement = queue->dequeue();
		if (tmpElement)
		{
			if (tmpElement->left)
				queue->enqueue(tmpElement->left);
			if (tmpElement->right)
				queue->enqueue(tmpElement->right);
		}
		return tmpElement;
	}
	return nullptr;
}

bool BFSIterator::hasNext()
{
	if (cur && queue->size() > 0)
		return true;
	return false;
}

BFSIterator::BFSIterator(binaryElement* root): cur(root)
{
	queue = new Queue();
	queue->enqueue(root);
}