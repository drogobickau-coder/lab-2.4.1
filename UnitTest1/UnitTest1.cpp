#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-2.4.1/Matrix.h" 


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMatrixNorm)
        {
            Matrix m(2);
            m[0][0] = 5; m[0][1] = 2;
            m[1][0] = 9; m[1][1] = 1;

            int actual_norm = m.norm();
            int expected_norm = 8;

            Assert::AreEqual(expected_norm, actual_norm);
        }

        TEST_METHOD(TestMatrixSubtraction)
        {
            Matrix m1(2);
            m1[0][0] = 5; m1[0][1] = 2;
            m1[1][0] = 9; m1[1][1] = 1;

            Matrix m2(2);
            m2[0][0] = 3; m2[0][1] = 3;
            m2[1][0] = 3; m2[1][1] = 3;

            Matrix m3 = m1 - m2;

            Assert::AreEqual(2, m3[0][0]);
            Assert::AreEqual(-1, m3[0][1]);
            Assert::AreEqual(6, m3[1][0]);
            Assert::AreEqual(-2, m3[1][1]);
        }
    };
}