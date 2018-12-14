/**
 * \file HitVisitor.h
 *
 * \author Andres Columna
 *
 * Functions to get an exclusive type from the mItems collection.
 */


#pragma once

#include "ItemVisitor.h"
#include "Item.h"


/**
 * Concrete visitor that gets specific derived types of items from 
 * CGame::mItems vector<CItem*>
 */
class CHitVisitor :
	public CItemVisitor
{
public:
	CHitVisitor();
	virtual ~CHitVisitor();

	virtual void VisitBall(CBall* ball);
	virtual void VisitInvader(CInvader * invader);
	virtual void VisitBunker(CBunker * bunker);
	virtual void VisitEndButton(CEndButton * endButton);


	/// getter for mBalls
	std::vector<CBall*> getBalls() { return mBalls; }
	/// getter for mInvaders
	std::vector<CInvader*> getInvader() { return mInvaders; }
	/// getter for mBunkers
	std::vector<CBunker*> getBunkers() { return mBunkers; }
	/// getter for mEndButton
	CEndButton* getEndButton() { return mEndButton; }
	
private:
	/// Balls collected from mItems
	std::vector<CBall*> mBalls;

	/// Invaders collected from mItems
	std::vector<CInvader*> mInvaders;

	/// Bunkers collected from mItems
	std::vector<CBunker*> mBunkers;

	/// End button collected from mItems
	CEndButton *mEndButton;
	
};

