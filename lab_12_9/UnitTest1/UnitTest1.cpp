#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_9/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* root = NULL;
			bool s = false;
			BinarySearchInsert(root, 1, s);
			BinarySearchInsert(root, 2, s);
			BinarySearchInsert(root, 3, s);
			BinarySearchInsert(root, 4, s);
			BinarySearchInsert(root, 5, s);
			BinarySearchInsert(root, 6, s);
			BinarySearchInsert(root, 7, s);

			int k = findMin(root);

			Assert::AreEqual(k, 1);
			
		}
	};
}
