/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
Hand CLASS HEADER FILE
*/

#ifndef Hand_H
#define Hand_H
#include <string>
#include <iostream>
#include <queue>
#include "Gemstones.h"
#include "CardFactory.h"

using namespace std;

class Hand{
	public:
		queue <Card*> PlayHand;	
		Hand(istream& is, CardFactory* cf);
		Hand() = default;
		Hand& operator+=(Card* c);
		Card* play();
		Card* top();
		Card* operator[](int i);
		~Hand();
		friend ostream& operator<<(ostream& os, const Hand& h);
};
#endif
