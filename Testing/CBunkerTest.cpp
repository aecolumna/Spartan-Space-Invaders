/**
 * \file Bunker.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Item.h"
#include "Ball.h"
#include "Bunker.h"

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CBunkerTest)
	{
	public:

		void TestAllInvaders(CGame *game)
		{

			shared_ptr<CBunker> bunker = make_shared<CBunker>(game);
			bunker->SetLocation(100, 200);
			game->Add(bunker);

			Assert::IsTrue(game->HitTest(100, 200) == bunker,
				L"Testing Bunker at 100, 210");

		}


		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}


		TEST_METHOD(TestCBunkerHitscChange)
		{
			CGame game;
			shared_ptr<CBunker> bunker = make_shared<CBunker>(&game);
			bunker->SetLocation(0, 0);
			game.Add(bunker);
			Assert::IsTrue(game.HitTest(0, -45) == bunker,
				L"Testing bunker with 0 hits at 0, 45");
			shared_ptr<CBunker> bunker1 = make_shared<CBunker>(&game);
			bunker1->SetHits(4);
			bunker1->SetLocation(100, 100);
			game.Add(bunker1);
			Assert::IsFalse(game.HitTest(100, 53) == bunker1,
				L"Testing bunker top with 4 hits at 100, 55");
			Assert::IsTrue(game.HitTest(100, 125) == bunker1,
				L"Testing bunker top with 4 hits at 100, ");
		}

		TEST_METHOD(TestCBunkerHit)
		{

			CGame game;


			Assert::IsTrue(game.HitTest(0, 0) == nullptr,
				L"Empty at Start");

			shared_ptr<CBunker> bunker = make_shared<CBunker>(&game);
			bunker->SetLocation(0, 0);
			game.Add(bunker);

			// The center of bunker
			Assert::IsTrue(game.HitTest(0, 0) == bunker,
				L"Testing bunker at 0, 0");

			// The top of bunker
			Assert::IsTrue(game.HitTest(0, -46) == bunker,
				L"Testing bunker at 0, -45");

			// The bottom of bunker
			Assert::IsTrue(game.HitTest(0, 45) == bunker,
				L"Testing bunker at 0, 45");

			// The right of bunker
			Assert::IsTrue(game.HitTest(97, 0) == bunker,
				L"Testing bunker at 0, 97");

			// The left of bunker
			Assert::IsTrue(game.HitTest(-98, 0) == bunker,
				L"Testing bunker at 0, -97");

			// The just above top of bunker
			Assert::IsFalse(game.HitTest(0, -47) == bunker,
				L"Testing bunker at 0, -46");

			// The below bottom of bunker
			Assert::IsFalse(game.HitTest(0, 46) == bunker,
				L"Testing bunker at 0, 46");

			// The one pixel right of bunker
			Assert::IsFalse(game.HitTest(98, 0) == bunker,
				L"Testing bunker at 0, 98");

			// The one pixel left of bunker
			Assert::IsFalse(game.HitTest(-99, 0) == bunker,
				L"Testing bunker at 0, -98");


		}

		TEST_METHOD(TestCBunkerRemoved)
		{

			CGame game;
			
			shared_ptr<CBunker> bunker = make_shared<CBunker>(&game);
			bunker->SetLocation(0, 0);
			bunker->SetHits(5);
			bunker->setHit();
			Assert::IsTrue(game.HitTest(0, 45) == nullptr,
				L"Testing empty aquarium");

		}

	};
}