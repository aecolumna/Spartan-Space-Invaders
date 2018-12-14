/**
 * \file ItemVisitor.h
 *
 * \author Andres Columna
 *
 * Item visitor base class.
 */

#pragma once

#include <vector>
#include <memory>


// Forward references to all tile types
class CItem;
class CInvader;
class CSparty;
class CBunker;
class CBall;
class CMichigan;
class CNebraska;
class COhioState;
class CWisconsin;
class CIowa;
class CEndButton;


/**
 * Serves as Abstract class for concrete visitors
 *
 */
class CItemVisitor
{
public:
	CItemVisitor();
	virtual ~CItemVisitor();

	/** Visit a CMichigan object
 * \param invader Invader we are visiting */
	virtual void VisitSpartyInvader(CSparty *invader) {}

	/** Visit a CMichigan object
	 * \param invader Invader we are visiting */
	virtual void VisitMichiganInvader(CMichigan *invader) {}

	/** Visit a CWisconsin object
 * \param invader Invader we are visiting */
	virtual void VisitWisconsinInvader(CWisconsin *invader) {}

	/** Visit a CNebraska object
* \param invader Invader we are visiting */
	virtual void VisitNebraskaInvader(CNebraska *invader) {}

	/** Visit a COhioState object
* \param invader Invader we are visiting */
	virtual void VisitOhioStateInvader(COhioState *invader) {}

	/** Visit a COhioState object
* \param invader Invader we are visiting */
	virtual void VisitIowaInvader(CIowa *invader) {}

	/** Visit a Ball object
* \param ball ball we are visiting */
	virtual void VisitBall(CBall* ball) {}

/** Visit a Invader object
* \param invader Invader we are visiting */
	virtual void VisitInvader(CInvader* invader){}

	/** Visit a bunker object
	* \param bunker we are visiting 
	*/
	virtual void VisitBunker(CBunker* bunker) {}


	/** Visit a item object
* \param item Invader we are visiting */
	virtual void VisitItem(CItem* item) {
		//do nothing!
		// for ball, bunker, and everything else.
	}

/**
 * Visits endbutton
 *
 *\param item Item we will visit
 */
	virtual void VisitEndButton(CItem* item) {}

};

