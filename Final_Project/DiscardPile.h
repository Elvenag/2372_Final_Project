/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
DiscardPile CLASS HEADER FILE
*/

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

#include "Gemstones.h"
#include "CardFactory.h"
#include<vector>
using std::vector;

class DiscardPile {
	vector<Card*> dp;
public:
	DiscardPile& operator +=(Card* c);
	~DiscardPile();
	Card* pickUp();
	Card* top();
	void print(std::ostream& os);
	ostream& operator<<(ostream& os);
	DiscardPile(std::istream& is, CardFactory* cf);
};

#endif // !DISCARD_PILE_H
