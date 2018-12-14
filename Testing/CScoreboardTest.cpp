/**
 * \file CGameTest.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Item.h"
#include "Sparty.h"
#include "Michigan.h"
#include "Iowa.h"
#include "OhioState.h"
#include "Wisconsin.h"
#include "Nebraska.h"
#include "Bunker.h"


#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreboardTest)
	{
	public:

		void TestAllInvaders(CGame *game)
		{

			shared_ptr<CMichigan> invader1 = make_shared<CMichigan>(game);
			invader1->SetLocation(100, 200);
			game->Add(invader1);

			Assert::IsTrue(game->HitTest(100, 200) == invader1,
				L"Testing Michigan at 100, 210");


			shared_ptr<COhioState> invader2 = make_shared<COhioState>(game);
			invader2->SetLocation(200, 400);
			game->Add(invader2);

			Assert::IsTrue(game->HitTest(200, 400) == invader2,
				L"Testing OhioState at 100, 210");

			shared_ptr<CIowa> invader3 = make_shared<CIowa>(game);
			invader2->SetLocation(100, 200);
			game->Add(invader3);

			Assert::IsTrue(game->HitTest(100, 200) == invader2,
				L"Testing Iowa at 100, 200");
		}


		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}


		TEST_METHOD(TestCScoreboardConstruct)
		{
			CScoreboard board;
		}

		TEST_METHOD(TestCScoreboardGetPointsMSU)
		{

			CScoreboard mScoreboard;

			Assert::IsTrue(mScoreboard.getPointsMSU() == 0,
	L"Testing getPointsMSU");

			mScoreboard.AddPointMSU();

			Assert::IsTrue(mScoreboard.getPointsMSU() == 1,
				L"Testing getPointsMSU");

			mScoreboard.AddPointMSU();

			Assert::IsTrue(mScoreboard.getPointsMSU() == 2,
				L"Testing getPointsMSU");

			for (int i = 0; i < 100; i++)
			{
				mScoreboard.AddPointMSU();
			}

			Assert::IsTrue(mScoreboard.getPointsMSU() == 102,
				L"Testing getPointsInvaders");

		}

		TEST_METHOD(TestCScoreboardGetPointsInvaders)
		{

			CScoreboard mScoreboard;

			Assert::IsTrue(mScoreboard.getPointsInvaders() == 0,
				L"Testing getPointsInvaders");


			mScoreboard.AddPointInvaders();
			mScoreboard.AddPointInvaders();

			Assert::IsTrue(mScoreboard.getPointsInvaders() == 2,
				L"Testing getPointsInvaders");

			mScoreboard.AddPointInvaders();
			mScoreboard.AddPointInvaders();

			Assert::IsTrue(mScoreboard.getPointsInvaders() == 4,
				L"Testing getPointsInvaders");

			for (int i = 0; i < 100; i++)
			{
				mScoreboard.AddPointInvaders();
			}

			Assert::IsTrue(mScoreboard.getPointsInvaders() == 104,
				L"Testing getPointsInvaders");

		}

		TEST_METHOD(TestCScoreboardGetOutputString)
		{	


			CScoreboard mScoreboard;

			auto str = mScoreboard.getOutputString();
			Assert::IsTrue(str == L"MSU: 0        Invaders: 0",
				L"Testing getPointsMSU 0 to 0");

			mScoreboard.AddPointMSU();
			mScoreboard.AddPointInvaders();
			mScoreboard.AddPointInvaders();

			str = mScoreboard.getOutputString();
			Assert::IsTrue(str == L"MSU: 1        Invaders: 2",
				L"Testing getPointsMSU 1 to 2");

			mScoreboard.AddPointMSU();
			mScoreboard.AddPointMSU();

			str = mScoreboard.getOutputString();
			Assert::IsTrue(str == L"MSU: 3        Invaders: 2",
				L"Testing getPointsMSU 3 to 2");

			// Try double digit scores

			while (mScoreboard.getPointsMSU() < 10) 
			{
				mScoreboard.AddPointMSU();
			}
			
			str = mScoreboard.getOutputString();
			Assert::IsTrue(str == L"MSU: 10        Invaders: 2",
				L"Testing getPointsMSU 10 to 2");

		
		};

	};
}