#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2Iter/Lab_07.2Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
           /* int** T = new int* [2];
            for (int i = 0; i < 2; i++) {

                T[i] = new int[2];
            }
            T[0][0] = 1;
            T[0][1] = 2;


            T[1][0] = 4;
            T[1][1] = 5;*/
            int arr[3][3] =
            {
                {1, 2 , -1},
                {3, -7, 6},
                {8, 10, 0}
            };
            int* pa[3] = { arr[0], arr[1], arr[2] };
            int minmin = arr[0][0];
            int result = Min(pa, 3, 3, minmin, 0);
          
            Assert::AreEqual(-7, result);

		}
	};
}
