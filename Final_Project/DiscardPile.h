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
	DiscardPile() = default;
	DiscardPile& operator +=(Card* c);
	~DiscardPile();
	Card* pickUp();
	Card* top() const;
	void print(std::ostream& os);
	friend ostream& operator<<(ostream& os, const DiscardPile& Grave);
	DiscardPile(std::istream& is, CardFactory* cf);
};

#endif // !DISCARD_PILE_H
