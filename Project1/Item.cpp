/**
 * \file Item.cpp
 *
 * \author Andres Columna
 */

#include "stdafx.h"
#include "Item.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// Specifies common directory shared by all images.
const wstring ImagesDirectory = L"images/";


/**
 * Constructor
 * \param game game that this item belongs to.
 */
CItem::CItem(CGame *game) : mGame(game)
{
}


/**
 * Destructor
 */
CItem::~CItem()
{
}


/** Draws image of Item
 * 
 * \param graphics Graphics object that renders final image
 */
void CItem::Draw(Gdiplus::Graphics *graphics)
{
	if(mItemImage != nullptr)
	{
		double wid = mItemImage->GetWidth();
		double hit = mItemImage->GetHeight();

		graphics->DrawImage(mItemImage.get(),
			float(GetX() - wid / 2), float(GetY() - hit / 2),
			wid, hit);
	}

}

/**
 *  Test to see if input coordinates are lie within Item image
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CItem::HitTest(double x, double y)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image.
	// Subtracting the center makes x, y relative to the center of 
	// the image. Adding half the size makes x, y relative to the top 
	// corner of the image.
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mItemImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mItemImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}


/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CItem::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/** Function changes which image file the item will render
 * since every item has multiple associated images depending
 * on whether its been hit or not.
 * 
 * \param image loaded image we will be switching to
 */
void CItem::SetImage(std::unique_ptr<Gdiplus::Bitmap> &image)
{
	mItemImage.swap(image);
}

/** Function that returns whether the passed in item
* overlaps with the item calling the function
* in the Game
*
* \param item CItem* (shared pointer) to a neighboring item in the game
* \return Bool returns whether two items collide.i.e. whether they are in each
* others vicinity. What constitutes Vicinity is controlled by a const int
* at the top of this page.
*/
bool CItem::Collision(CItem* item)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image.
	// Subtracting the center makes x, y relative to the center of 
	// the image. Adding half the size makes x, y relative to the top 
	// corner of the image.
	double testX = item->GetX()- GetX() + wid / 2;
	double testY = item->GetY() - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mItemImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mItemImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}

}


