#include "BinaryTree.h"
#include <cstddef>

void binaryTree::deleteTree(binaryElement *element)
{
	if (element)
	{
		deleteTree(element->left);
		deleteTree(element->right);
		deleteTree(element);
	}
}

bool binaryTree::contains(int key)
{
	binaryElement* cur = root;
	while (cur && cur->key != key)
	{
		if (cur->key > key)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return cur != NULL;
}

void binaryTree::insert(int key)
{
	binaryElement* cur = root;
	while (cur && cur->key != key)
	{
		if (cur->key > key && cur->left == NULL)
			cur->left = new binaryElement(key);
		else if (cur->key < key && cur->right == NULL)
			cur->right = new binaryElement(key);

		if (cur->key > key)
			cur = cur->left;
		else
			cur = cur->right;
	}
}

void binaryTree::remove(int key)
{
	binaryElement* cur = root, * parent = NULL;
	while (cur && cur->key != key) //searching element by key
	{
		parent = cur;
		if (cur->key > key)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (!cur) return; //if element is not in tree
	if (cur->left == NULL) // if left branch is empty -> set right branch
	{
		if (parent && parent->left == cur)
			parent->left = cur->right;
		if (parent && parent->right == cur)
			parent->right = cur->right;
		delete cur;
	}
	else if (cur->right == NULL) // if right branch is empty -> set left branch
	{
		if (parent && parent->left == cur)
			parent->left = cur->left;
		if (parent && parent->right == cur)
			parent->right = cur->left;
		delete cur;
	}
	else // if left and right branch is not empty
	{
		binaryElement* repl = cur->right;
		int replKey;
		while (repl->left)
			repl = repl->left;
		replKey = repl->key;
		remove(key);
		cur->key = replKey;
	}
}

binaryTree::~binaryTree() { deleteTree(root); }