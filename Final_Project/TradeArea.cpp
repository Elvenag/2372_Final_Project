/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
TradeArea CLASS CPP FILE
*/

#include <string>
#include <iostream>
#include "TradeArea.h"

using namespace std;

TradeArea& TradeArea::operator+=(Card* c){
	area.push_front(c);
	return *this;
}

bool TradeArea::legal(Card* c){
	for(auto& i : area){
		if(i->getName() == c->getName()){
			return true;
		}
	}
	return false;
}

Card* TradeArea::trade(string s){
	list<Card*>::iterator it;
	Card* c;
	for(it=area.begin(); it!=area.end(); it++){
		Card* temp = *it;
		if(temp->getName() == s){
			c = *it;
			area.erase(it);
			break;
		}
	}
	return c;
}

int TradeArea::numCards(){
	return area.size();
}

ostream& operator<<(ostream &os,const TradeArea& ta){
	for(int i = 0;i < ta.area.size(); i++){
		os << 1 << " ";
	}
		return os;
}

TradeArea::~TradeArea(){
	while(!area.empty()){
		area.pop_front();
	}
}
