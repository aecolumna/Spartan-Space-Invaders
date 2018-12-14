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
	TEST_CLASS(CGameTest)
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
		

		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCGameHitTest)
		{

			CGame game;


			Assert::IsTrue(game.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");
			
			shared_ptr<CSparty> sparty = make_shared<CSparty>(&game);
			sparty->SetLocation(100, 200);
			game.Add(sparty);

			shared_ptr<CBunker> bunker = make_shared<CBunker>(&game);
			bunker->SetLocation(300, 200);
			game.Add(bunker);

			// Test little below the center of sparty
			Assert::IsTrue(game.HitTest(100, 210) == sparty,
				L"Testing fish at 100, 210");

			// The center of sparty
			Assert::IsTrue(game.HitTest(300, 210) == bunker,
				L"Testing bunker at 300, 200");
			
			// Test all invader types here
			TestAllInvaders(&game);
		}

	};
}