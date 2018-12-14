/**
 * \file Bunker.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Bunker.h"

using namespace std;
using namespace Gdiplus;

/// Image for background
const wstring Initial = L"stadium.png";
/// Image file for first hit
const wstring FirstHit = L"stadium1.png";
/// Image file for second hit
const wstring SecondHit = L"stadium2.png";
/// Image file for third hit
const wstring ThirdHit = L"stadium3.png";
/// Image file for last hit
const wstring LastHit = L"stadium4.png";
/// Set common images directory for all images
const wstring ImagesDirectory = L"images/";
/// X-offset relative to origin for where left-most bunker sits
const int OffsetLeft = 64;
/// Y - offset relative to origin for where left - most bunker sits
const int OffsetDown = 32;



/**
 * Constructor
 * \param game 
 */
CBunker::CBunker(CGame* game) :	CItem(game)
{
	LoadImage(mLastHit, LastHit);
	LoadImage(mThirdHit, ThirdHit);
	LoadImage(mSecondHit, SecondHit);
	LoadImage(mFirstHit, FirstHit);
	LoadImage(mInitial, Initial);
}


/**
 * Destructor
 */
CBunker::~CBunker()
{
}



/**
 * Draw a bunker
 * \param graphics 
 */
void CBunker::Draw(Gdiplus::Graphics *graphics)
{
	//CItem::Draw(graphics);

	if (mHits==0)
	{
		int wid = mInitial->GetWidth();
		int hit = mInitial->GetHeight();

		graphics->DrawImage(mInitial.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mHits == 1)
	{

		int wid = mFirstHit->GetWidth();
		int hit = mFirstHit->GetHeight();

		graphics->DrawImage(mFirstHit.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mHits == 2)
	{
		int wid = mSecondHit->GetWidth();
		int hit = mSecondHit->GetHeight();

		graphics->DrawImage(mSecondHit.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mHits == 3)
	{

		int wid = mThirdHit->GetWidth();
		int hit = mThirdHit->GetHeight();

		graphics->DrawImage(mThirdHit.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
	else if (mHits == 4)
	{
		int wid = mLastHit->GetWidth();
		int hit = mLastHit->GetHeight();
		graphics->DrawImage(mLastHit.get(),
			(int)(GetX() - OffsetLeft), (int)(GetY() + OffsetDown - hit),
			wid, hit);
	}
}


/**
 * Setter for hit and associated actions
 */
void CBunker::setHit()
{
	if (mHits < 5)
	{
		mHits += 1;
	}
	else
	{
		CItem::setRemove();
	}
	mHit = true;
}
