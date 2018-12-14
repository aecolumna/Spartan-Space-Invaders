/**
 * \file Nebraska.h
 *
 * \author Andres Columna
 *
 * 
 */


#pragma once
#include "Invader.h"
/**
 * CNebraska Class Implements Nebraska Cornhusker
 */
class CNebraska : public CInvader
{
public:
	/**
	* Draws image of the  invader
	*
	*\param game game is where the invaders will be held
	*/
	CNebraska(CGame *game);
	///Disable default Constructor
	CNebraska() = delete;

	/// Disable Copy Constructor
	CNebraska(const CNebraska&) = delete;

	virtual ~CNebraska();

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

private:
	std::unique_ptr<Gdiplus::Bitmap> mFirstImage;	///< member variable of the first image 


	std::unique_ptr<Gdiplus::Bitmap> mSecondImage;	///< member variable for the second image 

	double mTimer = 1.0;	///< time member variable for the unique action
	double mAngle = 1;		///< member variable of the defaulted angle 
	double mDistance = 1;	///< member variable of the defaulted distance 

};

