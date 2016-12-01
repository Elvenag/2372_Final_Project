/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Player CLASS CPP FILE
*/
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(string& s):PlayerName(s),coins(0),MaxNumChains(2){
	/*PlayerChain.push_back(new Chain<Card*>);
	PlayerChain.push_back(new Chain<Card*>);*/
};

string Player::getName(){
	return PlayerName;
}

int Player::getNumCoins(){
	return coins;
}

int Player::getMaxNumChains(){
	return MaxNumChains;
}

Player& Player::operator+=(int num){
	coins += num;
	return *this;
}
/*
int Player::getNumChains(){
	int cntr = 0;
	for(list<Chain<Card*>>::iterator it = PlayerChain.begin(); i < PlayerChains.end() ; i++){
		if(!*it.empty()){
			cntr++;
		}
	}
	return cntr;
}*/
/*
void Player::buyThirdChain(){
	if(MaxNumChains == 2 && coins >= 2){
		MaxNumChains++;
		coins = coins - 2;
		PlayerChains.push_back(Chain<Card*>);
	}
}*/

void Player::printHand(ostream& os, bool b){
	if(b){
		os << PlayerHand;
	}else{
		os << PlayerHand.top();
	}
}
	
ostream& operator<<(ostream& os, const Player& p){
	os << p.PlayerName << p.coins << " coins" << endl;
	/*list<Chain<Card*>>::const_iterator it;
	for(it=p.PlayerChain.begin(); it!=p.PlayerChain.end(); it++){
		os << *it;
	}*/
	return os;
}
