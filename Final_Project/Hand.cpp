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

//printing the hand
string Hand::printHand(){
	string h;
    for(int i = 0; i < PlayHand.size();i++){
    	h+= PlayHand.at(i)->getName();
    	if(i <PlayHand.size()-1){
    		h.push_back('\n');
    	}
    }
    return h;
}

Hand::~Hand(){
	while(!PlayHand.empty()){
		PlayHand.pop_front();
	}
}

Hand::Hand(istream& is, CardFactory* cf){
	string s;
	while(getline(is, s)){
	if(s.front() == 'Q') {
		this->PlayHand.push_back(new Quartz);
		}
		else if(s.front() == 'H') {
			this->PlayHand.push_back(new Hematite);
		}
		else if(s.front() == 'O') {
			this->PlayHand.push_back(new Obsidian);
		}
		else if(s.front() == 'M') {
			this->PlayHand.push_back(new Malachite);
		}
		else if(s.front() == 'T') {
			this->PlayHand.push_back(new Turquoise);
		}
		else if(s.front() == 'R') {
			this->PlayHand.push_back(new Ruby);
		}
		else if(s.front() == 'A') {
			this->PlayHand.push_back(new Amethyst);
		}
		else if(s.front() == 'E') {
			this->PlayHand.push_back(new Emerald);
		}
	}
}
