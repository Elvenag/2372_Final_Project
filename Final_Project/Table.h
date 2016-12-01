/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
Table CLASS HEADER FILE
*/

#ifndef Table_H
#define Table_H
#include "Player.h"
#include "CardFactory.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
using namespace std;

class Table{
	public:
		Table() = default;
		~Table();
		Player Players[2];
		Deck Library;
		DiscardPile Grave;
		TradeArea GTS;
		bool win(string& s);
		void print(ostream& os);
		friend ostream& operator<<(ostream& os, const Table& t);
		Table(istream& is, CardFactory* cf);
};
#endif
