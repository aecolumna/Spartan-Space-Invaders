
#include "stdafx.h"
#include "Game.h"
#include "Sparty.h"
#include "Bunker.h"
#include "OhioState.h"
#include "Nebraska.h"
#include "Wisconsin.h"
#include "Iowa.h"
#include "Michigan.h"
#include "Scoreboard.h"
#include "EndButton.h"

using namespace Gdiplus;
using namespace std;

/**
 * Game Constructor
 */
CGame::CGame()
{


}


CGame::~CGame()
{
}

void CGame::CheckEndGame(int Bunkers, int Invaders)
{
}


/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height)
{
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);
	
	
	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// call mScoreboard.OnDraw(Gdiplus::Graphics * graphics); -Andres

	// From here on you are drawing virtual pixels

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

	mScoreboard.Draw(graphics);


}

/** Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * \param x X location
 * \param y Y location
 * \returns Pointer to item we clicked on or nullptr if none.
 */
std::shared_ptr<CItem> CGame::HitTest(double x, double y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/**
 * Add an item to the game
 * \param item New item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/**
 * Removes all items that need to be removed from mItems vector 
 */
void CGame::UpdateItems()
{
	// Delete balls that are out of bounds
	std::vector<std::shared_ptr<CItem> > toKeep;
	for (auto item : mItems)
	{
		if (!item->getRemove())
		{
			toKeep.push_back(item);
		}
	}

	mItems = toKeep;

}


/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
	bool hit;

	CHitVisitor visitor;
	for (auto item : mItems)
	{
		item->Accept(&visitor);
	}

	std::vector<CInvader*> invaders = visitor.getInvader();
	std::vector<CBall*> balls = visitor.getBalls();
	std::vector<CBunker*> bunkers = visitor.getBunkers();


	// Removes any balls that go off of the screen
	for (auto ball : balls)
	{
		double ballY = ball->GetY();
		if (ballY <= 0 || ballY >= Height)
		{
			ball->setRemove();
		}
	}

	// Remove any invaders that go off of the screen
	for (auto invader : invaders)
	{
		if (invader->GetX() <= -625 || invader->GetX() >= 625 || invader->GetY() >= 1000 || invader->GetY() <= 0)
		{
			invader->setRemove();
		}
	}

	// Sets an invader to be removed if hit by a ball
	// sets ball to be removed as well
	for (auto invader : invaders)
	{
		for (auto ball : balls)
		{
			hit = invader->HitTest(ball->GetX(), ball->GetY());
			if (hit && ball->getThrower())
			{
				if (!invader->getHit())
				{
					invader->setHit();
					mScoreboard.AddPointMSU();
				}
				ball->setRemove();

			}
		}
	}

	// removes any bunker and ball that is hit 
	for (auto bunker : bunkers)
	{
		for (auto ball : balls)
		{
			hit = bunker->HitTest(ball->GetX(), ball->GetY());
			if (hit && !ball->getThrower())
			{
				if (!bunker->getHit())
				{
					bunker->setHit();
				}
				ball->setRemove();

			}
		}
	}

	// increments invader score and removes ball if it hits sparty
	for (auto ball : balls)
	{
		hit = getSparty()->HitTest(ball->GetX(), ball->GetY());
		if (hit && !ball->getThrower())
		{
			getSparty()->setHit();
			mScoreboard.AddPointInvaders();
			ball->setRemove();

		}
	}

	UpdateItems();

	for (auto item : mItems)
	{
		item->Update(elapsed);

	}


	mTime -= elapsed;  //counts remaining time left
	if (mTime < 0)
	{
		srand(time(NULL));
		int maxBall = invaders.size();
		int ballSelection = maxBall % 10;
		int i = 0;
		std::vector<int> indices;
		while (i < 5 && maxBall)
		{
			int randomMax = (int)rand() % maxBall; // Modulo by zero is error
			indices.push_back(randomMax);
			i += 1;
		}
		for (auto invader : invaders)
		{
			for (auto index : indices)
			{
				if (invaders[index] == invader)
				{
					double iX = invader->GetX();
					double iY = invader->GetY();
					auto ball = make_shared<CBall>(this, false);

					ball->SetLocation(iX, iY);
					Add(ball);
				}
			}

		}
		mTime = 1;
	}

	// Check if an invader is off-screen
	for (auto invader : invaders)
	{
		if (invader->GetY() >= 1000)
		{
			mInvaderMax = true;
		}
	}
	mNumInvaders = invaders.size();

	// Make "New Game" button when game is completed
	if (mNumInvaders == 0 && !mFinished)
	{
		mEndButton = make_shared<CEndButton>(this);
		mEndButton->SetLocation(0, 500);
		Add(mEndButton);
		mFinished = true;
	}

}


/**
 * Set up the game board
 */
void CGame::Setup()
{

	/**Creating the ohio Invaders at the begininng of the game*/
	double xpos = -500;
	for (int i = 0; i < 10; i++)
	{
		auto ohioInvader = make_shared<COhioState>(this);
		ohioInvader->SetLocation(xpos, 150);
		Add(ohioInvader);
		xpos += 110;
	}
	
	
	///**Creating the Michigan Invaders at the begininng of the game*/
	xpos = -500;
	for (int i = 0; i < 10; i++)
	{
		auto MichiganInvader = make_shared<CMichigan>(this);
		MichiganInvader->SetLocation(xpos, 275);
		Add(MichiganInvader);
		xpos += 110;
	}

	/**Creating the Wisconsin Invaders at the begininng of the game*/
	xpos = -500;
	for (int i = 0; i < 10; i++)
	{
		auto WisconsinInvader = make_shared<CWisconsin>(this);
		WisconsinInvader->SetLocation(xpos, 400);
		Add(WisconsinInvader);
		xpos += 110;
	}

	/**Creating the Nebraska Invaders at the begininng of the game*/
	xpos = -500;
	for (int i = 0; i < 10; i++)
	{
		auto NebraskaInvader = make_shared<CNebraska>(this);
		NebraskaInvader->SetLocation(xpos, 525);
		Add(NebraskaInvader);
		xpos += 110;
	}
	
	/**Creating the Iowa Invaders at the begininng of the game*/
	xpos = -500;
	for (int i = 0; i < 10; i++)
	{
		auto IowaInvader = make_shared<CIowa>(this);
		IowaInvader->SetLocation(xpos, 650);
		Add(IowaInvader);
		xpos += 110;
	}

	
	//Create Sparty and add to initial location
	auto sparty = make_shared<CSparty>(this);
	sparty->SetLocation(0, 900);
	mSparty = sparty;
	Add(sparty);

	// Creating the middle bunker
	auto bunker = make_shared<CBunker>(this);
	bunker->SetLocation(-500, 800);
	Add(bunker);

	// Creating the rightmost bunker
	auto bunker2 = make_shared<CBunker>(this);
	bunker2->SetLocation(0, 800);
	Add(bunker2);

	// Creating the leftmost bunker
	auto bunker3 = make_shared<CBunker>(this);
	bunker3->SetLocation(490, 800);
	Add(bunker3);
}

/**
* Handle a click on the game area
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonDown(int x, int y)
{
	if (mFinished)
	{
		double virtualX = (x - mXOffset) / mScale;
		double virtualY = (y - mYOffset) / mScale;
		// reset game if "New Game" button is pressed
		if (mEndButton->HitTest(virtualX, virtualY))
		{
			mFinished = false;
			mScoreboard.Reset();
			mItems.clear();
			Setup();
		}
		
	}
	else
	{
		double oX = mSparty->GetX();
		double oY = mSparty->GetY();
		auto ball = make_shared<CBall>(this, true);

		ball->SetLocation(oX, oY);
		Add(ball);
	}
}

/**
 * Updates sparty location
 * \param point Location of the mouse
 */
void CGame::MoveSparty(CPoint point)
{
	double oX = (point.x - mXOffset) / mScale;
	double oY = (point.y - mYOffset) / mScale;
	
	// Dont let sparty draw pas the boundries of the game
	if (oX <= -625)
	{
		oX = -625;
	}
	else if (oX >= 625)
	{
		oX = 625;
	}
	// Set location of Sparty
	mSparty->SetLocation(oX, 900);
}

/**
 Accepts an item visitor
*/
void CGame::Accept(CItemVisitor * visitor)
{
	for( auto item: mItems)
	{
		item->Accept(visitor);
	}
}






