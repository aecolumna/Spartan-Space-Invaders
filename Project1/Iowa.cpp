/**
 * \file Iowa.cpp
 *
 * \author Andres Columna
 */



#include "stdafx.h"
#include "Iowa.h"

using namespace std;
using namespace Gdiplus;

//Iowa image filename
const wstring FirstImage = L"invaderIa.png";	///<first image of the incader
const wstring SecondImage = L"invaderIb.png";	///< second image of the invader

/**
 * Constructor
 */
CIowa::CIowa(CGame* game) : CInvader(game)
{
	LoadImage(mSecondImage, SecondImage);
	LoadImage(mFirstImage, FirstImage);
}

CIowa::~CIowa()
{
}

void CIowa::Draw(Gdiplus::Graphics *graphics)
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

void CIowa::setHit()
{
	CItem::setHit();
}

void CIowa::Update(double elapsed)
{
	if (getHit())
	{
		CVector NewV=CVector(500,0);
		if (!mSpeedSet)
		{
			mDirection = Direction();
			mSpeedSet = true;
		}

		CVector newP = GetP() + NewV*mDirection* elapsed;

		SetLocation(newP.X(), newP.Y());
	}
	else
	{
		CInvader::Update(elapsed);
	}
}

int CIowa::Direction()
{
	srand(time(NULL));
	int random = (int)rand() % 2;
	int a=0;
	if (random)
	{
		a=1;
	}
	else
	{
		a= -1;
	}
	return a;
}
