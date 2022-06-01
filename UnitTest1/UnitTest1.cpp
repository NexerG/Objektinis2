#include "pch.h"
#include "CppUnitTest.h"
#include "../MVSDeque_Strategija1/Mok.h"
#include "../MVSDeque_Strategija1/Mok.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string name = "Mokinys";
			Mokinys2 Mok;
			Assert::AreEqual(name, Mok.getVar());
		}

		TEST_METHOD(TestMethod2)
		{
			std::string name = "Erikas";
			Mokinys2 mc;
			Assert::AreEqual(name, mc.getVar());
		}

		TEST_METHOD(TestMethod3)
		{
			std::string pavarde = "pavardenis";
			Mokinys2 Mok;
			Assert::AreEqual(pavarde, Mok.getPav());
		}
	};
}
