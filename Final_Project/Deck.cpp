/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Deck CLASS CPP FILE
*/

#include "Deck.h"
#include "CardFactory.h"

Deck::~Deck()
{
	for (std::size_t i = 0; i < size(); i++)
		delete at(i);
}

Card * Deck::draw()
{
	auto drawn = front();
	erase(++(begin()));
	return drawn;
}

ostream & operator<<(ostream & os, const Deck d)
{
	for (std::size_t i = 0; i < d.size(); i++) {
		os << d.at(i);
	}
	return os;
}

Deck::Deck(istream & in, CardFactory * cf)
{
	//TODO
}


