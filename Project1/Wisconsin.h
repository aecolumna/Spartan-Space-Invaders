/**
 * \file Wisconsin.h
 *
 * \author Andres Columna
 *
 * CWisconsin class
 */

#pragma once
#include "Invader.h"
#include <memory>



/**
 * Class denoting a Wisconsin Badger
 */
class CWisconsin :	public CInvader
{
public:

	/**
	* Draws image of the invader
	*
	*\param game game is where the invaders will be held
	*/
	CWisconsin(CGame * game);

	virtual ~CWisconsin();

	/**
	* Draws image of the wisconsin invader
	*
	*\param graphics Gaphics object that remembers
	*/
	void Draw(Gdiplus::Graphics * graphics);


	/**
	*Updates our image of each invader
	*
	*\param elapsed elapsed enables us to use our counter
	*/
	void Update(double elapsed);

	CWisconsin() = delete;						///< Default constructor (disabled)
	CWisconsin(const CWisconsin &) = delete;	///< Copy constructor (disabled)

private:
	//std::unique_ptr<Gdiplus::Bitmap> mWisconsinOrig; ///< wisconc with hands down
	//std::unique_ptr<Gdiplus::Bitmap> mWisconsinIntermediate; ///< Bucky with hands raised
	std::unique_ptr<Gdiplus::Bitmap> mWisconsinHit; ///< Bucky with "Ouch plastered accross him"
	
	double mTimer = 1.5;	///< time member variable for the unique action 

	std::unique_ptr<Gdiplus::Bitmap> mFirstImage;	///< member variable of the first image 

	std::unique_ptr<Gdiplus::Bitmap> mSecondImage;	///< member variable for the second image 
};
