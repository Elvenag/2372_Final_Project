/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Deck CLASS CPP FILE
*/

#include "Deck.h"
#include "CardFactory.h"
#include <algorithm>
#include <fstream>
#include <string>
/*
Deck::~Deck()
{
	Card * c;
	for (vector<Card *>::iterator it = begin(); it != end(); ++it) {
		c = *it;
		delete c;
	}
}*/

Card * Deck::draw()
{
	auto drawn = front();
	erase(begin());
	return drawn;
}

ostream & operator<<(ostream & os, const Deck& d)
{
	for (std::size_t i = 0; i < d.size(); i++) {
		os << d.at(i)->getName() << " ";
	}
	return os;
}

Deck::Deck(istream & in, CardFactory * cf)
{
	string s;
	getline(in,s);
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'Q'); i++) {
		this->push_back(new Quartz);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'H'); i++) {
		this->push_back(new Hematite);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'O'); i++) {
		this->push_back(new Obsidian);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'M'); i++) {
		this->push_back(new Malachite);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'T'); i++) {
		this->push_back(new Turquoise);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'R'); i++) {
		this->push_back(new Ruby);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'A'); i++) {
		this->push_back(new Amethyst);
	}
	for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'E'); i++) {
		this->push_back(new Emerald);
	}
	cf->gameDeck = *this;;
}


