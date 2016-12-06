/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Hand CLASS CPP FILE
*/
#include "Hand.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

Card* Hand::play(){
	Card* c = PlayHand.front();
	PlayHand.pop();
	return c;
}

Card* Hand::top(){
	return PlayHand.front();
}

Hand& Hand::operator+=(Card* c){
	PlayHand.push(c);
	return *this;
}

Card* Hand::operator[](int i){
	queue <Card*> temphand;
	Card* elem;
	for(int j = 0 ; j < i ; j++){
		temphand.push(PlayHand.front());
		PlayHand.pop();
	}
	elem = PlayHand.front();
	PlayHand.pop();
	for(int j = 0; j < PlayHand.size() ; j++){
		temphand.push(PlayHand.front());
		PlayHand.pop();
	}
	PlayHand = temphand;
	return elem;
}

ostream& operator<<(ostream &os,const Hand& h){
	queue <Card*> temphand;
	temphand = h.PlayHand;
    for(int i = 0; i < h.PlayHand.size();i++){
    	os << temphand.front()->getName() << " ";
    	temphand.pop();
    }
    return os;
}

Hand::~Hand(){
	while(!PlayHand.empty()){
		PlayHand.pop();
	}
}
