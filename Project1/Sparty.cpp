/**
 * \file Sparty.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Sparty.h"
#include <string>

using namespace Gdiplus;
using namespace std;

/// Sparty filename 
const wstring SpartyImageName = L"sparty.png";

/**
 * Constructor
 */
CSparty::CSparty(CGame* game) :
	CItem(game)
{
	LoadImage(mItemImage, SpartyImageName);
}

/**
 * Destructor
 */
CSparty::~CSparty()
{
}


void CSparty::Update(double elapsed)
{
	SetLocation(GetX(), GetY());
}


void CSparty::Draw(Gdiplus::Graphics *graphics)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}
