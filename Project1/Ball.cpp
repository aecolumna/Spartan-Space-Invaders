/**
 * \file Ball.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Ball.h"

using namespace std;
using namespace Gdiplus;

/// Relative Directory Address of Image file where PNG file of ball 
const wstring BallImageName = L"football.png";
/// Address of Images directory 
const wstring ImagesDirectory = L"images/";



/** Constructor
 * 
 *
 * \param game The game ball is a part of
 * \param spartyBall whether its a ball thrown by Sparty (and not invader)
 */
CBall::CBall(CGame *game, bool spartyBall) : CItem(game)
{
	LoadImage(mItemImage, BallImageName);
	mSpartyBall = spartyBall;
	if (spartyBall)
	{
		mVY = mVY * -1;
	}
}



/**
 * Destructor
 */
CBall::~CBall()
{
}



/** Draws ball
 * 
 * \param graphics Where to draw ball
 */
void CBall::Draw(Gdiplus::Graphics *graphics)
{

		int wid = mItemImage->GetWidth();
		int hit = mItemImage->GetHeight();

		graphics->DrawImage(mItemImage.get(),
			GetX(), GetY(),
			wid, hit);
}



/** Updates position of ball as a function of time passed
 * 
 * \param elapsed Global variable that keeps track of time between function calls
 */
void CBall::Update(double elapsed)
{
			CVector newP = GetP() + mVY;

			SetLocation(newP.X(), newP.Y());
}

