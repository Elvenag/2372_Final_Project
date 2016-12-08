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
//	PlayerChains.push_back(Chain<Card>());
//	PlayerChains.push_back(Chain<Card>());
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

int Player::getNumChains(){
	return PlayerChains.size();
}

Chain_Base<Card>& Player::operator[](int i){
	return PlayerChains[i];
}

void Player::buyThirdChain(){
	if(MaxNumChains == 2 && coins >= 2){
		MaxNumChains++;
		coins -= 2;
		PlayerChains.push_back(Chain<Card>());
	}
}

void Player::printHand(ostream& os, bool b){
	if(b){
		os << PlayerHand;
	}else{
		os << PlayerHand.top();
	}
}

ostream& operator<<(ostream& os,const Player& p){
	os << p.PlayerName << " " << p.coins << " coins" << endl;
	/*list<Chain<Card>>::const_iterator it=p.PlayerChains.begin();
	for(it=p.PlayerChains.begin(); it!=p.PlayerChains.end(); it++){
		Chain<class Card> elem = *it;
		os << typeid(elem).name() <<endl;
	}*/
	for(int i = 0; i < p.PlayerChains.size(); i++){
//		Card* c = p.PlayerChains[i].cardType;
		os << p.PlayerChains.at(i) << endl;
	}
	return os;
}

void Player::addChain(Card* c) {
	Chain<class Card> newChain;
	Quartz q;
	Hematite h;
	Obsidian o;
	Malachite m;
	Turquoise t;
	Ruby r;
	Amethyst a;
	Card * cardType;
	if (c->getName() == q.getName()) {
		Chain<Quartz> newChain;
		cardType = &q;
	}
	else if (c->getName() == h.getName()) {
		Chain<Hematite> newChain;
		cardType = &h;
	}
	else if (c->getName() == o.getName()) {
		Chain<Obsidian> newChain;
		cardType = &o;
	}
	else if (c->getName() == m.getName()) {
		Chain<Malachite> newChain;
		cardType = &m;
	}
	else if (c->getName() == t.getName()) {
		Chain<Turquoise> newChain;
		cardType = &t;
	}
	else if (c->getName() == r.getName()) {
		Chain<Ruby> newChain;
		cardType = &r;
	}
	else if (c->getName() == a.getName()) {
		Chain<Amethyst> newChain;
		cardType = &a;
	}
	else {
		Chain<Emerald> newChain;
		cardType = new Emerald;
	}
	newChain.cardType = cardType->getName();
	newChain+=c;
	PlayerChains.push_back(newChain);
}

void Player::addCardAndMakeChain(Card* c) {
	if (getNumChains() < getMaxNumChains()) {
		addChain(c);
	}
	/*else {
		cout << "Which chain will be sold? (1-" << getNumChains() << ")" << endl;
		for (std::list<Chain<Card>>::iterator it = PlayerChains.begin(); it != PlayerChains.end(); ++it) {
			cout << ' ' << *it << endl;
		}
		while (true) {
			int ianswer;
			cin >> ianswer;
			if ((ianswer < getMaxNumChains()) && (ianswer > 0)) {
				std::list<Chain<Card>>::iterator it = PlayerChains.begin();
				advance(it, ianswer);
				*this += it->sell();
				it = PlayerChains.erase(it);
				break;
			}else{
				break;
			}
		}
		addChain(c);
	}*/
}
