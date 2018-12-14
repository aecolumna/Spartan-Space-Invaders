/**
 * \file Nebraska.cpp
 *
 * \author Andres Columna
 *
 * Implementation of Nebraska class
 */

#include"stdafx.h"
#include "Nebraska.h"

using namespace std;
using namespace Gdiplus;


const wstring FirstImage= L"invaderNa.png"; ///<	 Nebraska filename 
const wstring SecondImage= L"invaderNb.png"; ///<	 Nebraska filename 


const double RunawaySpeedX = 100;		///< speed traveled in the x direction 
const double RunawaySpeedY = 100;		///< speed traveled in the y direction 
const double RunawayAngularSpeed = 3.14/2;	///< speed traveled at an angle 
const double RunawayDistanceSpeed = 10;		///< distance speed 

/**
 * Constructor
 */
CNebraska::CNebraska(CGame *game) :	CInvader(game)
{
	LoadImage(mSecondImage, SecondImage);
	LoadImage(mFirstImage, FirstImage);
}

CNebraska::~CNebraska()
{
}

void CNebraska::Draw(Gdiplus::Graphics *graphics)
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


void CNebraska::Update(double elapsed)
{
	if (CItem::getHit())
	{
		double x = GetX();
		double y = GetY();

		x += elapsed * RunawaySpeedX;
		y += elapsed * RunawaySpeedY;
		mAngle += elapsed * RunawayAngularSpeed;
		mDistance += elapsed * RunawayDistanceSpeed;

		double X = double(x) + mDistance * cos(mAngle);
		double Y = double(y) + mDistance * sin(mAngle);

		SetLocation(X, Y);	
		if (GetX() <= -625 || GetX() >= 625 || GetY() >= 1000 || GetY() <= 0) 
		{
			CItem::setRemove();
		}

	}
	else
	{
		CInvader::Update(elapsed);
	}

}