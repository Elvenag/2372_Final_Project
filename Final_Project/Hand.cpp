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
