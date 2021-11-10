#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	binaryTree* tree = new binaryTree(8);
	tree->insert(3);
	tree->insert(1);
	tree->insert(6);
	tree->insert(4);
	tree->insert(7);
	tree->insert(10);
	tree->insert(14);
	tree->insert(13);

	cout << "NLR: \n";
	NLRIterator* nlr_iterator = tree->createNLRIterator();
	while (nlr_iterator->hasNext())
		cout << nlr_iterator->next()->key << " ";

	cout << endl << "BFS: \n";;
	BFSIterator* bfs_iterator = tree->createBFSIterator();
	while (bfs_iterator->hasNext())
		cout << bfs_iterator->next()->key << " ";

	return 0;
}