/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Deck CLASS CPP FILE
*/
#ifndef Deck_H
#define Deck_H
#include "Gemstones.h"
#include <iostream>
using std::istream;
#include <vector>
using std::vector;
class CardFactory;

class Deck : public vector<Card*>{
public:
	Deck() = default;
	Card* draw();
	ostream& operator<<(ostream& os);
	Deck(istream& in, CardFactory* cf);
};
#endif