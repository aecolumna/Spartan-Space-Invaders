/**
 * \file Sparty.h
 *
 * \author Andres Columna
 *
 * Create a Sparty class
 */

#pragma once
#include "Item.h"



/**
 * Class denoting Sparty 
 */
class CSparty : public CItem
{
public:

	/// Default constructor (disabled)
	CSparty() = delete;

	/// Copy constructor (disabled)
	CSparty(const CSparty &) = delete;

	/**
	* Constructor
	*
	*\param game Game that sparty is a part of
	*/
	CSparty(CGame *game);

	/// Destructor
	virtual ~CSparty();
	
	/**
	 * Updates image of Sparty
	 *
	 *\param elapsed Graphics object that remembers
	 */
	void Update(double elapsed);
	
	/**
	 * Draws image of Sparty
	 *
	 *\param graphics Graphics object that remembers
	 */
	void Draw(Gdiplus::Graphics * graphics);
	
	/**
	 * Accepts a visitor
	 *
	 *\param visitor Visitor that is accepted
	 */
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitSpartyInvader(this); }

private:
	/// Image of Sparty
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

};

