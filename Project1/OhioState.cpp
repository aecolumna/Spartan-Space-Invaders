/**
 * \file OhioState.cpp
 *
 * \author Andres Columna
 *
 *Implementation of OhioState class
 */

#include "stdafx.h"
#include "OhioState.h"

using namespace std;
using namespace Gdiplus;

const wstring OhioFirstImageName = L"invaderOSa.png";		///< intial OhioState Filename
const wstring OhioSecondImageName = L"invaderOSb.png";		///< second OhioState Filename


 /**
  * Constructor
  */
COhioState::COhioState(CGame *game) : CInvader(game)
{
	LoadImage(mSecondImage, OhioSecondImageName);
	LoadImage(mFirstImage, OhioFirstImageName);
}

COhioState::~COhioState()
{
}

void COhioState::Draw(Gdiplus::Graphics *graphics)
{
	double x = GetX() - 50;
	double y = GetY();

	if (CItem::getHit())
	{
		if (mCounter > 0)
		{
			FontFamily fontFamily(L"Times New Roman");
			Gdiplus::Font font(&fontFamily, 42);
			SolidBrush white(Color(255, 255, 255));
			graphics->DrawString(L"The", -1, &font, PointF(x, y), &white);
		}
		else
		{
			CItem::setRemove();
		}
	}
	else
	{
		if (GetCount() % 2)
		{
			CInvader::Draw(graphics, mFirstImage);
		}
		else
		{
			CInvader::Draw(graphics, mSecondImage);
		}
	}
}

void COhioState::Update(double elapsed)
{
	if (!getHit())
	{
		CInvader::Update(elapsed);
		return;
	}

	mCounter -= elapsed;
}