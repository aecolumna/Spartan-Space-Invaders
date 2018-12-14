/**
 * \file Invader.h
 *
 * \author Andres Columna
 *
 * Invader Base Class
 */

#pragma once
#include "Item.h"  // Item base class
//#include "Game.h"  // Game class
#include "Vector.h"


/**
 * Invader Base class
 */
class CInvader : public CItem
{
public:
	
	// Override default constructor
	CInvader() = delete;

	// Destructor
	virtual ~CInvader();

	/** This function is to draw the invader on screen
* \param graphics the place on screen
* \param image the image file to draw
*/
	virtual void Draw(Gdiplus::Graphics *graphics, std::unique_ptr<Gdiplus::Bitmap> &image);


	/** This function is toupdate the position of invader
* \param elapsed the time between events
*/
	void Update(double elapsed);

	/** This function is to get the visitor
* \param visitor the item visitor to checkthe invader 
* \returns sets the visitor to the invader function
*/
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitInvader(this); }


	/** This function is to get the number of movements.
 * \returns mMoveCount the number of spaces moved
 */
	int GetCount() { return mMoveCount; };

private:

	CVector mVX = CVector(5, 0); 	/**< Horizontal velocity in virtual pixels/second */
	CVector mVY = CVector(0, 5);	/**< Vertical velocity in virtual pixels/second */
	double mRemaining=1;				/**< Time remaining until next update */

	
	int mMoveCount = 0; /**< Number of horizontal movements */
	int mVerticalCount = 0; /**< number of vertical movements  */

protected:

	/** Constructs the invader
* \param game The game the function runs in
*/
	CInvader(CGame* game);

};

