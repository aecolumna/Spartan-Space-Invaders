/**
 * \file Ball.h
 *
 * \author Andres Columna
 */

#pragma once
#include "Item.h"



/**
 * Class denotes a Ball in Space Invaders game.
 */
class CBall :
	public CItem
{
public:
	/// Disable default constructor
	CBall() = delete;

	/// Disable copy constructor
	CBall(CBall &) = delete;

	CBall(CGame *game, bool spartyBall);

	virtual ~CBall();

	//void LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	void Draw(Gdiplus::Graphics * graphics);

	void Update(double elapsed);

	/// Accepts Visitor Base class and concrete classes.
	virtual void Accept(CItemVisitor *visitor) { visitor->VisitBall(this); }

	///Getter for mSpartyBall
	bool getThrower() { return mSpartyBall; }

private:

	/// loaded Ball Image PNG file
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// Vector position of ball
	CVector mVY = CVector(0, 35);

	/// If Ball thrown by Sparty (as opposed to Invaders)
	bool mSpartyBall;

	/// Whether the ball out of range the coordinates of the screen so it can be deleted from mItems
	bool mOutOfBounds = false;
};

