/**
 * \file Scoreboard.h
 *
 * \author Andres Columna
 *
 * 
 */




#pragma once
#include "Item.h"  // Item base class
#include <string>

/**
 * Implements ScoreBoard for game.
 * Should Inherit from CItem when the class is made
 */
class CScoreboard
{
public:

	/// Scoreboard constructor
	CScoreboard();

	/// Disable copy constructor
	CScoreboard(const CScoreboard&) = delete;
	
	/// Scoreboard destructor
	virtual ~CScoreboard();

	/// Output string of scoreboard
	std::wstring getOutputString();

	/**
	 * Draws the scoreboard
	 *
	 *\param graphics Graphics object that remembers
	 */
	void Draw(Gdiplus::Graphics *graphics);

	/// Setter for mMSUScore
	void AddPointMSU() { mMSUScore++ ; }

	/// Setter for mInvaders
	void AddPointInvaders() { mInvadersScore++ ; }
	
	/// Getter for MSU points
	int getPointsMSU() { return mMSUScore; }

	/// Getter for PointsInvaders
	int getPointsInvaders() { return mInvadersScore; }

	/**
	 * Updates Spartys position
	 *
	 * \param goal New score we will give it
	 * \param graphics What we will draw onto
	 */
	void CScoreboard::UpdateSparty(int goal, Gdiplus::Graphics * graphics);

	/**
	* Updates Invaders position
	*
	* \param goal New score we will give it
	* \param graphics What we will draw onto
	*/
	void CScoreboard::UpdateInvaders(int goal, Gdiplus::Graphics * graphics);

	/// Reset Scoreboard
	void Reset();
	
private:
	/// Keeps track of points won by MSU
	int mMSUScore = 0;
	/// Keeps track of points won by Invaders
	int mInvadersScore = 0;
};

