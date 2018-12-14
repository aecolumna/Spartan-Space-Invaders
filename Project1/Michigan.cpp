/**
 * \file Michigan.cpp
 *
 * \author Andres Columna
 *
 * Implementation of Michigan class
 */

#include "stdafx.h"
#include "Michigan.h"

using namespace std;
using namespace Gdiplus;

 /// Michigan first image filename
const wstring FirstImage = L"invaderUMa.png";
/// Michigan second image filename
const wstring SecondImage = L"invaderUMb.png";
/// Michigan first image after its been hit
const wstring HitImage1 = L"invaderUMw1.png";
/// Michigan second image hit image 2
const wstring HitImage2 = L"invaderUMw2.png";

/**
 * Constructor
 */
CMichigan::CMichigan(CGame *game) :	CInvader(game)
{
	LoadImage(mFirstImage, FirstImage);
	LoadImage(mSecondImage, SecondImage);
	LoadImage(mHitImage1, HitImage1);
	LoadImage(mHitImage2, HitImage2);
}

/**
 * Destructor
 */
CMichigan::~CMichigan()
{
}


/** Draws Michigan stuff
 * 
 * \param graphics 
 */
void CMichigan::Draw(Gdiplus::Graphics *graphics)
{
	// Change images when hit
	if (CItem::getHit())
	{
		if (mCounter >= 1.5) {
			CInvader::Draw(graphics, mHitImage1);
		}
		else if (mCounter > 0) {
			CInvader::Draw(graphics, mHitImage2);
		}
		else {
			CItem::setRemove();
		}
	}
	// Normal images to change based on counter
	else if (GetCount() % 2)
	{
		CInvader::Draw(graphics, mFirstImage);
	}
	else
	{
		CInvader::Draw(graphics, mSecondImage);
	}
}


/**
 * Setter for hit
 */
void CMichigan::setHit()
{
	CItem::setHit(); // set CItem.mHit = true

}


/**
 * Updates position for Michigan object
 * \param elapsed 
 */
void CMichigan::Update(double elapsed)
{
	if (!getHit())
	{
		CInvader::Update(elapsed);
		return;
	}

	mCounter -= elapsed;
	
}