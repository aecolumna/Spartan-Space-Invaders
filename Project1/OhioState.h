/**
 * \file OhioState.h
 *
 * \author Andres Columna
 *
 * COhioState class
 */

#pragma once
#include "Invader.h"


/**
 * Ohiostate Buckeye Invader Object
 */
class COhioState :	public CInvader
{
public:
	/**
	* Constructor
	 * \param game Game OSU object is a part of
	 */
	COhioState(CGame *game);
	virtual ~COhioState();
	/**
	 * draws ohio state object
	* \param graphics pbject in which OSU image is overlayed into
	*/
	void Draw(Gdiplus::Graphics * graphics) override;

	COhioState() = delete;						///< Default constructor (disabled)
	COhioState(const COhioState &) = delete;	///< Copy constructor (disabled)
	/**
	* Updates position of OSU object on screen.
	 * \param elapsed Amount of time elapsed since last time elapsed was called
	*/
	void COhioState::Update(double elapsed);

private:
	/// First image shown
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
	/// First image shown after its been hit
	std::unique_ptr<Gdiplus::Bitmap> mFirstImage;
	/// Second image shown after its been hit
	std::unique_ptr<Gdiplus::Bitmap> mSecondImage;
	/// how fast it oscillates between images
	double mCounter = 1.5;
};
