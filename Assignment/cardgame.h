#include <iostream>
#include "carddeck.h"
#include "gameFunctions.h"

#ifndef _CARDGAME_H
#define _CARDGAME_H

using namespace std;


class CardGame
{
	public:
		virtual int deal(CardDeck * cardDeck, int deckPosition)= 0;
		virtual int displayInitialBoard() = 0;
		virtual int startGame(CardDeck * cardDeck) = 0; 
	protected:

};


class Solitaire : public CardGame
{
	public:
		Solitaire();
		~Solitaire();
		int deal(CardDeck * cardDeck, int deckPosition);
		int displayInitialBoard();
		int startGame(CardDeck * cardDeck);
		int displayBoard(CardDeck * cardDeck, int deckPosition);
		char getTailColour(int position);
		int getTailNumber(int position);
		char getFaceColour(int position);
		int getFace(int position);
		int moveCard(int starting, int ending);
		int moveDeck(Card * starting, int ending);
	private:
		ArrayList * solitaireBoard; 
};

