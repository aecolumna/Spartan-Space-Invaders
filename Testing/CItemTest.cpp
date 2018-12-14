#include "stdafx.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// Fish filename
const std::wstring SpartyImageName = L"sparty.png";

namespace Testing
{
 
	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		/** Abstract CItem class for testing*/
		CItemMock(CGame *game) : CItem(game)
		{
			LoadImage(mItemImage, SpartyImageName);
		}
		/** Abstract Draw function for testing*/
		virtual void Draw(Gdiplus::Graphics *graphics) {}
	private:
		std::unique_ptr<Gdiplus::Bitmap> mItemImage;
	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemConstruct)
		{
			// Construct an item to test
			CGame game;
			CItemMock item(&game);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCIttemMockHitTest)
		{
			// Create a fish to test
			CGame game;
			CItemMock sparty(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			sparty.SetLocation(100, 200);

			// Little below the center of sparty should be true
			Assert::IsTrue(sparty.HitTest(100, 210));

			// Left of sparty
			Assert::IsFalse(sparty.HitTest(10, 200));

			// Right of sparty
			Assert::IsFalse(sparty.HitTest(200, 200));

			// Above sparty
			Assert::IsFalse(sparty.HitTest(100, 0));

			// Below sparty
			Assert::IsFalse(sparty.HitTest(100, 300));

			// Of fish transparent pixel
			Assert::IsFalse(sparty.HitTest(100, 200));
		}

	};
}