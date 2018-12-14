/**
 * \file EndButton.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "EndButton.h"

#include <string>

using namespace std;
using namespace Gdiplus;


/// End button filename 
const wstring EndButtonImage = L"new-game.png";

/** 
 Implementation of an EndButton class
 */
CEndButton::CEndButton(CGame *game) : CItem(game)
{
	///Load image
	LoadImage(mEndButtonImage, EndButtonImage);
}


CEndButton::~CEndButton()
{
}
