/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
Player CLASS HEADER FILE
*/

#ifndef Player_H
#define Player_H
#include <string>
#include <iostream>
#include <list>
#include "Hand.h"
#include "Chain.h"
using namespace std;

class Player{
	string PlayerName;
	int coins;
	int MaxNumChains;
	Hand PlayerHand;
	list<Chain<Card*>> PlayerChain;
	public:
		Player(string& s);
		//Player(istream & is, CardFactory* cf)
		string getName();
		int getNumCoins();
		Player& operator+=(int num);
		int getMaxNumChains();
		//int getNumChains();
		//Chain_Base& operator[](int i);
		void buyThirdChain();
		void printHand(ostream& os, bool b);
		friend ostream& operator<<(ostream& os, const Player& p);
};

#endif
