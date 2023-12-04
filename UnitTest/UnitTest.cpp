#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_6.4_ITER/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Arrange
			const int size = 7;
			double arr[size] = { 2.0, -5.0, 4.0, 3.0, 6.0, 1.0, 7.0 };

			// Act
			int zerosCount = countZeros(arr, size);
			double sumAfterMinResult = sumAfterMin(arr, size);

			// Sorting odd elements
			double sortedArr[size];
			std::copy(arr, arr + size, sortedArr);
			sortOddElements(sortedArr, size);

			// Assert
			Assert::AreEqual(0, zerosCount);
			Assert::AreEqual(21, sumAfterMinResult, 0.001);

			double expectedSortedArr[size] = { 2.0, 1.0, 4.0, 3.0, 6.0, -5.0, 7.0 };
			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expectedSortedArr[i], sortedArr[i], 0.001);
			}
		}
	};
}
