/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
TradeArea CLASS CPP FILE
*/

#include <string>
#include <iostream>
#include "TradeArea.h"
#include <algorithm>
#include <fstream>

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

//printing to file print function
ostream& TradeArea::printTrade(ostream &os){
	if(area.size() == 0){
		os << "Empty Trade Area" <<endl;
		return os;
	}else {
		list<Card*>::const_iterator it;
		for(it=area.begin(); it!=area.end(); it++){
			Card* temp= *it;
			os << temp->getName() << " ";
		}
		return os;
	}
}

ostream& operator<<(ostream &os,const TradeArea& ta){
	if(ta.area.size() == 0){
		os << "Empty Trade Area" <<endl;
		return os;
	}else {
		os << "Trade Area : ";
		list<Card*>::const_iterator it;
		for(it=ta.area.begin(); it!=ta.area.end(); it++){
			Card* temp= *it;
			os << temp->getName() << " ";
		}
		return os;
	}
}

TradeArea::~TradeArea(){
	while(!area.empty()){
		area.pop_front();
	}
}

TradeArea::TradeArea(istream& is, CardFactory* cf){
	string s;
	getline(is,s);
	if(!(s == "Empty Trade Area")){
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'Q'); i++) {
			*this+=(new Quartz);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'H'); i++) {
			*this+=(new Hematite);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'O'); i++) {
			*this+=(new Obsidian);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'M'); i++) {
			*this+=(new Malachite);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'T'); i++) {
			*this+=(new Turquoise);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'R'); i++) {
			*this+=(new Ruby);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'A'); i++) {
			*this+=(new Amethyst);
		}
		for (std::size_t i = 0; i < std::count(s.begin(), s.end(), 'E'); i++) {
			*this+=(new Emerald);
		}
	}
}
