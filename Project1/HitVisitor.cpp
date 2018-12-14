/**
 * \file HitVisitor.cpp
 *
 * \author Andres Columna
 *
 * Implementation of HitVisitor.h
 * Visitor class for extracting Items of certain subtypes
 */



#include "stdafx.h"
#include "HitVisitor.h"


/**
 * Constructor
 */
CHitVisitor::CHitVisitor()
{
}


/**
 * Destructor
 */
CHitVisitor::~CHitVisitor()
{
}


/**
 * Visitor for balls
 * \param ball exclusively accepts Items that happen to 
 * to be balls
 */
void CHitVisitor::VisitBall(CBall * ball)
{
	mBalls.push_back(ball);
}

/**
 * Visitor for Invaders
 * \param invader we intend to visit
 * exclusively accepts Items that happen to
 * to be Invaders
 */
void CHitVisitor::VisitInvader(CInvader * invader)
{ 
	mInvaders.push_back(invader); 
}


/**
 * Visitor for Bunker
 * \param bunker to visit
 * exclusively accepts Items that happen to
 * to be Bunkers
 */
void CHitVisitor::VisitBunker(CBunker *bunker)
{
	mBunkers.push_back(bunker);
}

/**
 * Visitor for EndButton
 * \param endButton to visit
 * exclusively accepts Items that happen to
 * to be EndButtons
 */
void CHitVisitor::VisitEndButton(CEndButton *endButton)
{
	mEndButton = endButton;
}