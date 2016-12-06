/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
CardFactory CLASS CPP FILE
*/
#include "CardFactory.h"
#include <algorithm>
#include <random>
#include <chrono>

CardFactory* CardFactory::cf;

CardFactory::CardFactory()
{
	for (int i = 0; i < 20; i++) {
		Quartz* q = new Quartz();
		gameDeck.push_back(q);
	}
	for (int i = 0; i < 18; i++) {
		Hematite* h = new Hematite();
		gameDeck.push_back(h);
	}
	for (int i = 0; i < 16; i++) {
		Obsidian* o = new Obsidian();
		gameDeck.push_back(o);
	}
	for (int i = 0; i < 14; i++) {
		Malachite* m = new Malachite();
		gameDeck.push_back(m);
	}
	for (int i = 0; i < 12; i++) {
		Turquoise* t = new Turquoise();
		gameDeck.push_back(t);
	}
	for (int i = 0; i < 10; i++) {
		Ruby* r = new Ruby();
		gameDeck.push_back(r);
	}
	for (int i = 0; i < 8; i++) {
		Amethyst* a = new Amethyst();
		gameDeck.push_back(a);
	}
	for (int i = 0; i < 6; i++) {
		Emerald* e = new Emerald();
		gameDeck.push_back(e);
	}
	cf = this;
}

//CardFactory::~CardFactory()
//{
//	delete[] gameDeck;
//}

CardFactory * CardFactory::getFactory()
{
	if (!cf)
		cf = new CardFactory();
	return cf;
}

Deck CardFactory::getDeck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(gameDeck.begin(), gameDeck.end(), std::default_random_engine(seed));
	return gameDeck;
}
