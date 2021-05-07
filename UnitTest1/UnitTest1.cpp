#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 12.2(Iter)/Source.cpp"
#include "../PR 12.2(Iter)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Elem* start;
			start = new Elem;
			start->info = 50;
			start->link = new Elem;
			start->link->info = 60;
			start->link->link = new Elem;
			start->link->link->info = 70;

			Elem* last = start->link->link;

			enqueue(start, last, 80); 

			Assert::AreEqual(start->link->link->link->info, 80);

		}
	};
}
