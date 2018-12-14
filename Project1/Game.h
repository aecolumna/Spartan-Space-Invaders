#pragma once
#include <memory> 
#include <vector>
#include <unordered_set>
#include "Item.h"
#include "Scoreboard.h"
#include "Sparty.h"
#include "Ball.h"
#include "HitVisitor.h"


/**
 * Game class
 * 
 * Created by: Andres Columna
 * Modified by Andres Columna 10/9/18
 */


/**
 * Represents a game
 */
class CGame
{
public:
	CGame();
	virtual ~CGame();
	CGame *mGame;	///< the game where things will be added 

	/**
	*GetNumBunkers
	*allowig us to know how many bunkers are in play
	*\return the number of bunkers
	*/
	int GetNumBunkers() { return mNumBunkers; } 

	/**
	*GetNumInvaders
	*allowig us to know how many invaders are in play
	*\return the number of invaders
	*/
	int GetNumInvaders() { return mNumInvaders; } 

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	std::shared_ptr<CItem> HitTest(double x, double y);

	/**
	*Updates our image of each invader
	*
	*\param Bunkers number of bunkers in the game
	*\param Invaders number of invaders in the game 
	*/
	void CheckEndGame(int Bunkers, int Invaders); ///< Checks the if the number of bunkers is zero or if all invaders killed

	//void OnDraw(Gdiplus::Graphics * graphics);

	//General hit tests, win conditions, etc

	void Add(std::shared_ptr<CItem> item);

	void UpdateItems();

	void Update(double elapsed);

	//set up the game board
	void Setup();

	void OnLButtonDown(int x, int y);

	void MoveSparty(CPoint point);
	
	/// Game area in virtual pixels
	const static int Width = 1250;

	/// Game area height in virtual pixels
	const static int Height = 1000;

	/**
	*\return the opinter to sparty
	*/
	std::shared_ptr<CSparty> getSparty() { return mSparty; };
	/**
	*Allows us to accept visitors
	*\param visitor visitor allows us to for certain conditions
	*/
	void Accept(CItemVisitor* visitor);


private:
	int mNumBunkers = 3;	///< number of bunkers currently in the game;
	int mNumInvaders = 50;	///< number of invaders currently in the game;

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

	float mXOffset;		///< offset for the x axis 
	float mYOffset;		///< the offset for the y axis
	float mScale = 2;	///< defaluting the scale variable to 2
	
	double mTime = 1;	///< defaulting the time variable to start at 1

	std::unordered_set<std::shared_ptr<CItem>> mDelete;  ///< Keep track of items to delete

	///member variable for how many balls on the screen 
	int mBallOnScreen = 0;

	///shared pointer to sparty
	std::shared_ptr<CSparty> mSparty;

	///shareed pointer to the item that is being affected 
	std::shared_ptr<CItem> mGrabbedItem;
	
	/// The scoreboard within the game 
	CScoreboard mScoreboard;

	/// maximum number of invaders reached
	bool mInvaderMax = false;
	/// is game done
	bool mFinished = false;
	/// End button for game to display at end
	std::shared_ptr<CEndButton> mEndButton;
};

