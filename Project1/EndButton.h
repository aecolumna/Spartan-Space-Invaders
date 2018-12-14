/**
 * \file EndButton.h
 *
 * \author Andres Columna
 *
 * Implementation of an EndButton class
 */

#pragma once
#include "Item.h"
#include <memory>


/**
 * End button for game
 */
class CEndButton : public CItem
{
public:
	///Disable default Constructor
	CEndButton() = delete;

	/// Disable Copy Constructor
	CEndButton(const CEndButton&) = delete;

	/**
	 * Constructor
	 * \param game Game that end button belongs to
	 */
	CEndButton(CGame *game);

	/// EndButton destructor
	virtual ~CEndButton();

	/// EndButton visitor
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitEndButton(this); }

private:
	/// EndButton image filename
	std::unique_ptr<Gdiplus::Bitmap> mEndButtonImage;
};

