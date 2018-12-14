/**
 * \file Bunker.h
 *
 * \author Andres Columna
 *
 * Bunker Base Class
 */

#pragma once
#include <string>
#include <memory>
#include "Game.h"

/// Forward declaration of CGame to avoid Circular includes
class CGame;


/**
 * Class denotes a Bunker in Space Invaders game
 */
class CBunker : public CItem
{
public:

	CBunker()=delete;
	CBunker(CGame * game);
	virtual ~CBunker();

	/// Copy constructor (disabled)
	CBunker(const CBunker &) = delete;

	void Draw(Gdiplus::Graphics * graphics) override;


	/// getter for mHits
	int GetHits() {return mHits;}
	/// setter for mHits
	void SetHits(int hit) { mHits = hit; }
	void setHit();

	///Others to come, such as hit tests, change in the image per hit, etc
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitBunker(this); }

private:
	/// whether Bunker has been hit
	bool mHit = false;
	///  Number of times Bunker has been hit
	int mHits = 0;

	///Stuff like setting locations

	/// Original loaded image of bunker
	std::unique_ptr<Gdiplus::Bitmap> mInitial;
	/// Image when it hasn't been hit
	std::unique_ptr<Gdiplus::Bitmap> mNoHit;
	/// slightly shrunken bunker for when Bunker is hit first time
	std::unique_ptr<Gdiplus::Bitmap> mFirstHit;
	/// Even smaller bunker for when Bunker is hit second time
	std::unique_ptr<Gdiplus::Bitmap> mSecondHit;
	/// Smallest bunker for when Bunker is hit third time
	std::unique_ptr<Gdiplus::Bitmap> mThirdHit;
	/// Image for exit sequence of Bunker
	std::unique_ptr<Gdiplus::Bitmap> mLastHit;


};



