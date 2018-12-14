/**
 * \file Item.h
 *
 * \author Andres Columna
 *
 * 
 */

/**
 * \file Item.h
 *
 * \author Andres Columna
 *
 * Base class for any item.
 */

#pragma once

#include <memory>
#include <string>
#include "Vector.h"
#include "ItemVisitor.h"
class CGame;

 /**
  * Base class for any item.
  */
class CItem
{
public:

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	/// Destructor.
	virtual ~CItem();

	/** The width of the item image
	 * \returns width in pixels
	 */
	double GetWidth() const { return mItemImage->GetWidth(); }


	/** The height of the item image
	 * \returns height in pixels
	 */
	double GetHeight() const { return mItemImage->GetHeight(); }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	/// Set the item location
	/// \param x X location
	/// \param y Y location	
	void SetLocation(double x, double y) { mP = CVector(x, y); }


	/** Test this item to see if it has been clicked on
	 * \param x X location on the aquarium to test
	 * \param y Y location on the aquarium to test
	 * \return true if clicked on */
	bool HitTest(double x, double y);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/** The position of the item image
 * \returns position in vectors pixels
 */
	CVector GetP() { return mP; }

	/** Gets x value of item
	* \returns Double the x position from the position vector
	*/
	double GetX() { return mP.X(); }

	/** Gets the y coordinate of item
	* 
	* \returns double the y position from the position vector
	*/
	double GetY() { return mP.Y(); }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor){}


	// Load image
	void LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	/** Sets the image used in game
* /param image the image for the item
* /returns Sets the base image for the item
*/
	void SetImage(std::unique_ptr<Gdiplus::Bitmap>& image);

	/** Function that returns whether the passed in item
* overlaps with the item calling the function
* in the Game
*
* \param item CItem* (shared pointer) to a neighboring item in the game
* \return Bool returns whether two items collide.i.e. whether they are in each
* others vicinity. What constitutes Vicinity is controlled by a const int
* at the top of this page.
*/
	bool Collision(CItem* item);

	/** Gets the game we are running in
	* \return CGame * the game
	*/
	CGame *GetGame() { return mGame; }

	/** Gets if the item is hit
	* \return bool if item is hit
	*/
	bool getHit() { return mHit; }

	/** Sets the hit value to true
	* 
	*/
	virtual void setHit() { mHit = true;  }

	
	/** sets mtoRemove to be true
	* 
	*/
	void setRemove() { mToRemove = true; };
	
	/** sets mtoRemove to be true
	* \returns bool
*/
	bool getRemove() { return mToRemove; };

protected:

	/// CItem Constructor
	CItem(CGame* game);


private:

	CGame *mGame;  ///< The Game this item is contained in
	
	/// The image of the item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// Item location in the playing area
	CVector mP = CVector(0, 0);			///< Position 

	//CVector mV = CVector(0,0);

	/// Flag denoting whether Item has been hit
	bool mHit = false;

	/// Signals when invader is ready to be removed
	bool mToRemove = false;
};

