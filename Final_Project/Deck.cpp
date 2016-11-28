/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Deck CLASS CPP FILE
*/

#include "Deck.h"
#include "CardFactory.h"

Card * Deck::draw()
{
	auto drawn = front();
	erase(++(begin()));
	return drawn;
}

ostream & Deck::operator<<(ostream & os)
{
	for (std::size_t i = 0; i < size(); i++) {
		os << this->at(i);
	}
	return os;
}

Deck::Deck(istream & in, CardFactory * cf)
{
	//TODO
}


