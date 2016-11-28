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
	Card* c = playhand.front();
	playhand.pop();
	return c;
}

Card* Hand::top(){
	return playhand.front();
}

Hand& Hand::operator+=(Card* c){
	playhand.push(c);
	return *this;
}

Card* Hand::operator[](int i){
	queue <Card*> temphand;
	Card* elem;
	for(int j = 0 ; j < i ; j++){
		temphand.push(playhand.front());
		playhand.pop();
	}
	elem = playhand.front();
	playhand.pop();
	for(int j = 0; j < playhand.size() ; j++){
		temphand.push(playhand.front());
		playhand.pop();
	}
	playhand = temphand;
	return elem;
}

ostream& operator<<(ostream &os,const Hand& h){
	queue <Card*> temphand;
	temphand = h.playhand;
    for(int i = 0; i < h.playhand.size();i++){
    	os << temphand.front() << " ";
    	temphand.pop();
    }
    return os;
}
