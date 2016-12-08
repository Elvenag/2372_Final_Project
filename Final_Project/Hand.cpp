/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Hand CLASS CPP FILE
*/
#include "Hand.h"
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

Card* Hand::play(){
	Card* c = PlayHand.front();
	PlayHand.pop_front();
	return c;
}

Card* Hand::top(){
	return PlayHand.front();
}

Hand& Hand::operator+=(Card* c){
	PlayHand.push_back(c);
	return *this;
}

Card* Hand::operator[](int i){
	Card* elem = PlayHand.at(i);
	PlayHand.erase(PlayHand.begin()+(i));
	return elem;
}

ostream& operator<<(ostream &os,const Hand& h){
    for(int i = 0; i < h.PlayHand.size();i++){
    	os << h.PlayHand.at(i)->getName() << " ";
    }
    return os;
}

Hand::~Hand(){
	while(!PlayHand.empty()){
		PlayHand.pop_front();
	}
}

Hand::Hand(istream& is, CardFactory* cf){
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'Q'); i++) {
		this->PlayHand.push_back(new Quartz);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'H'); i++) {
		this->PlayHand.push_back(new Hematite);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'O'); i++) {
		this->PlayHand.push_back(new Obsidian);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'M'); i++) {
		this->PlayHand.push_back(new Malachite);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'T'); i++) {
		this->PlayHand.push_back(new Turquoise);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'R'); i++) {
		this->PlayHand.push_back(new Ruby);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'A'); i++) {
		this->PlayHand.push_back(new Amethyst);
	}
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'E'); i++) {
		this->PlayHand.push_back(new Emerald);
	}
}
