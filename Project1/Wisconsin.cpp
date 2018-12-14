/**
 * \file Wisconsin.cpp
 *
 * \author Andres Columna
 *
 * Implementation of Wisconsin class
 *
 * Modified by Andres Columna 10/9/18
 */

#include "stdafx.h"
#include "Wisconsin.h"
#include <string>

const std::wstring FirstImage = L"invaderWa.png";		///< intial wisconsin image Filename
const std::wstring SecondImage= L"invaderWb.png";		///< second wisconsin Image filename
const std::wstring WisconsinLoseImageName = L"invaderWo.png";	///< final hit wisconsin file name 


/**
 * Constructor
 */
CWisconsin::CWisconsin(CGame* game) : 
	CInvader(game)
{
	LoadImage(mSecondImage, SecondImage);
	LoadImage(mFirstImage, FirstImage);
	
}

CWisconsin::~CWisconsin()
{
}


void CWisconsin::Draw(Gdiplus::Graphics *graphics)
{
LoadImage(mWisconsinHit, WisconsinLoseImageName);
	if (CItem::getHit())
	{
		CInvader::Draw(graphics, mWisconsinHit);
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
	
void CWisconsin::Update(double elapsed)
{
	if (CItem::getHit())
	{
		mTimer = mTimer - elapsed;
		if (mTimer <= 0)
		{
			CItem::setRemove();
		}
	}
	else
	{
		CInvader::Update(elapsed);
	}
}

	


