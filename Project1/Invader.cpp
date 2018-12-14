/**
 * \file Invader.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Invader.h"


CInvader::CInvader(CGame* game) : 
	CItem(game)
{
}



CInvader::~CInvader()
{
}

void CInvader::Update(double elapsed)
{
	mRemaining -= elapsed;

		if (mVerticalCount < 5)  // If invaders move down less than 5 times
		{
			if (mRemaining <= 0)  // If less than 0 seconds left to update
			{
				if (mMoveCount > 8)  // If at edge of X movement (left or right)
				{

					mVX = mVX * -1;
					mMoveCount = 0;
					mVerticalCount += 1;

					CVector newP = GetP() + mVY;

					SetLocation(newP.X(), newP.Y());
				}
				else
				{
					CVector newP = GetP() + mVX;

					SetLocation(newP.X(), newP.Y());

					mRemaining = 1;

					mMoveCount += 1;
				}
			}
		}
		else // If 
		{
			if (mRemaining <= 0.75)
			{
				if (mMoveCount > 8) {

					mVX = mVX * -1;
					mMoveCount = 0;
					mVerticalCount += 1;

					CVector newP = GetP() + mVY;

					SetLocation(newP.X(), newP.Y());
				}

				else
				{
					CVector newP = GetP() + mVX;

					SetLocation(newP.X(), newP.Y());

					mRemaining = 1;

					mMoveCount += 1;
				}
			}
		}
}

void CInvader::Draw(Gdiplus::Graphics *graphics, std::unique_ptr<Gdiplus::Bitmap> &image)
{

	double wid = image->GetWidth();
	double hit = image->GetHeight();
	graphics->DrawImage(image.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)image->GetWidth(), (float)image->GetHeight());

}