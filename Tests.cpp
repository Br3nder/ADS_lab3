#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/binaryTree.cpp"
#include "../lab3/iterator.cpp"
#include "../lab3/queue.cpp"
#include "../lab3/stack.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		TEST_METHOD(TestInsert)
		{
			binaryTree* tree = new binaryTree(8);
			tree->insert(3);
			tree->insert(1);
			Assert::IsTrue(tree->contains(8) && tree->contains(3) && tree->contains(1));
		}
		TEST_METHOD(TestLeaf)
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
			tree->remove(1);
			tree->remove(100);
			Assert::IsTrue(!tree->contains(1));
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
		TEST_METHOD(TestRoot)
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
			tree->remove(8);
			Assert::IsTrue(tree->contains(3) && tree->contains(10));
		}
		TEST_METHOD(TestNode2)
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
			tree->remove(6);
			Assert::IsTrue(tree->contains(4) && tree->contains(7));
		}
		TEST_METHOD(TestNode1)
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
			tree->remove(14);
			Assert::IsTrue(tree->contains(13));
		}
		TEST_METHOD(TestNLR)
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
			NLRIterator* iterator = tree->createNLRIterator();
			int arr[9] = {8, 3, 1, 6, 4, 7, 10, 14, 13}, i = 0;
			bool isEqual = true;
			while (iterator->hasNext())
			{
				if (iterator->next()->key != arr[i]) isEqual = false;
				i++;
			}
			Assert::IsTrue(isEqual);

		}
		TEST_METHOD(TestBFS)
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
			BFSIterator* iterator = tree->createBFSIterator();
			int arr[9] = {8, 3, 10, 1, 6, 14, 4, 7, 13}, i = 0;
			bool isEqual = true;
			while (iterator->hasNext())
			{
				if (iterator->next()->key != arr[i]) isEqual = false;
				i++;
			}
			Assert::IsTrue(isEqual);
		}
	};
}
