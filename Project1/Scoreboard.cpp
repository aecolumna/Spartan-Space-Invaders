/**
 * \file Scoreboard.cpp
 *
 * \author Andres Columna
 */



#include "stdafx.h"
#include "Scoreboard.h"

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CScoreboard::CScoreboard()
{
}

/**
 * Destructor
 */
CScoreboard::~CScoreboard()
{
}


/**
 * Function formats the score that will be displayed.
 * \returns wstring
 */
std::wstring CScoreboard::getOutputString()
{
	//mMSUScore
	//mInvadersScore
	std::wstring outputString = L"MSU: " + std::to_wstring(mMSUScore) + L"        ";
	outputString += L"Invaders: " + std::to_wstring(mInvadersScore);

	return outputString;
}

/**
 * Draws the scoreboard.
 */
void CScoreboard::Draw(Gdiplus::Graphics * graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 42);
	SolidBrush lightGreen(Color(191, 234, 173));
	const wstring intermediateString = getOutputString();
	const wchar_t  *outputString = intermediateString.c_str(); // convert from wstring to suitable type for drawstring
	graphics->DrawString(outputString , -1, &font, PointF(-335, 20), &lightGreen);
}

/**
 * Update the scoreboard.
 */
void CScoreboard::UpdateSparty(int goal, Gdiplus::Graphics * graphics)
{
	mMSUScore += goal;
	CScoreboard::Draw(graphics);
}

void CScoreboard::UpdateInvaders(int goal, Gdiplus::Graphics * graphics)
{
	mInvadersScore += goal;
	CScoreboard::Draw(graphics);
}

/**
 * Reset the scoreboard.
 */
void CScoreboard::Reset()
{
	mMSUScore = 0;
	mInvadersScore = 0;
}