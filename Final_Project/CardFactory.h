/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
CardFactory CLASS HEADER FILE
*/

#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include "Deck.h"

class CardFactory {
	static CardFactory* cf;
public:
	Deck gameDeck;
	CardFactory();
	~CardFactory();
	Deck getDeck();
	static CardFactory* getFactory();
};

#endif 
