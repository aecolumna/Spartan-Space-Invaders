/**
 * \file Michigan.h
 *
 * \author Andres Columna
 *
 * CMichigan class
 */

#pragma once
#include "Invader.h"


/**
 * Michigan Invader Class
 */
class CMichigan : public CInvader
{
public:
	
	/**
	 * Constructor
	 *
	 *\param game Game michigan object belongs to
	 */
	CMichigan(CGame *game);

	/// Destructor
	virtual ~CMichigan();

	/**
	 * Draws image of michigan invader
	 *
	 *\param graphics Graphics object that remembers
	 */
	void Draw(Gdiplus::Graphics * graphics);

	CMichigan() = delete;						///< Default constructor (disabled)
	CMichigan(const CMichigan &) = delete;		///< Copy constructor (disabled)
	
	/** setting the hit flag true */
	virtual void setHit();

	/**
	 * Updates the image of Michigan invader
	 *
	 *\param elapsed enables counter
	 */
	void Update(double elapsed);

private: 

	/// Counter
	double mCounter = 2.0;

	/// Images of Michigan invader
	std::unique_ptr<Gdiplus::Bitmap> mFirstImage;
	/// Second michigan image shown
	std::unique_ptr<Gdiplus::Bitmap> mSecondImage;
	/// First image shown after Michigan object hit
	std::unique_ptr<Gdiplus::Bitmap> mHitImage1;
	/// Second image shown after Michigan object hit
	std::unique_ptr<Gdiplus::Bitmap> mHitImage2;
};

