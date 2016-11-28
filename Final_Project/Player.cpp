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
	Chain c1,c2;
	PlayerChains.push_back(c1);
	PlayerChains.push_back(c2);
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
/*
int Player::getNumChains(){
	int cntr = 0;
	for(int i = 0; i < PlayerChains.length() ; i++){
		if(!PlayerChain[i].empty){
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
		Chain c;
		PlayerChains.push_back(c);
	}
}*/

void Player::printHand(ostream& os, bool b){
	if(b){
		os << PlayerHand;
	}else{
		os << PlayerHand.top();
	}
}
	
