#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/binaryTree.cpp"
#include "../lab3/iterator.cpp"
#include "../lab3/queue.cpp"
#include "../lab3/stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		
		TEST_METHOD(TestIteratorNLR)
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
			
			NLRIterator* iterator = new NLRIterator(tree->root);
			while (iterator->hasNext())
				iterator->next()->key;
		}
		TEST_METHOD(TestIteratorBFS)
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

			BFSIterator* iterator = new BFSIterator(tree->root);
			while (iterator->hasNext())
				iterator->next()->key;
		}
		TEST_METHOD(TestInsert)
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
		}
		TEST_METHOD(TestRemove)
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
			tree->remove(13);
			tree->remove(100);
			Assert::IsTrue(!tree->contains(13));
		}
		TEST_METHOD(TestContains)
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
			Assert::IsTrue(tree->contains(13) && !tree->contains(100));
		}
	};
}
