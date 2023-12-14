#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 10.1 C++/lab 10.1 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str1[] = "-,-,-,-,--";
			Assert::AreEqual(CountCommaDash(str1), 4);
		}
	};
}
