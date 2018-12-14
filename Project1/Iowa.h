/**
 * \file Iowa.h
 *
 * \author Andres Columna
 *
 * 
 */

#pragma once
#include "Invader.h"

/**
 * Implements Iowa Hawkeye
 */
class CIowa : public CInvader
{
public:
	///Disable default Constructor
	CIowa() = delete;

	/// Disable Copy Constructor
	CIowa(const CIowa&) = delete;


	/**
	* 
	*
	*\param game game is where the invaders will be held
	*/
	CIowa(CGame *game);

	/// Iowa destructor
	virtual ~CIowa();

	/**
	* Draws image of the iowa invader
	*
	*\param graphics Gaphics object that remembers
	*/
	void Draw(Gdiplus::Graphics * graphics);	

	/**setting the hit flag true*/
	void setHit();	

	/**
	*Updates our image of each invader
	*
	*\param elapsed elapsed enables us to use our counter
	*/
	void Update(double elapsed);	

	/**
	*Direction 
	*allowing us to choose the direction the invader will run 
	*\return the direction we will move 
	*/
	int Direction();	 


private: 
	std::unique_ptr<Gdiplus::Bitmap> mFirstImage; ///< The first image of the Iowa invader

	std::unique_ptr<Gdiplus::Bitmap> mSecondImage; ///< The second Image of the Iowa Invader 

	/// flag for if it is hit or not 
	bool mIsHit = false;	 

	///containing all of our invaders
	CVector mVX = CVector(5, 0);	

	///the speed at which the invader will move 
	bool mSpeedSet = false;	 

	/// the defaulted direction 
	int mDirection = 0;	
};

