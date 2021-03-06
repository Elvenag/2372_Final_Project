/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Player CLASS CPP FILE
*/
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Player::Player(string& s):PlayerName(s),coins(0),MaxNumChains(2){
}

Player::Player(istream & is, CardFactory * cf)
{
	string s;
	getline(is,s);
	stringstream converter;
	
	size_t pos = s.find(" ");
	converter << s.substr(0, pos);
	converter >> this->MaxNumChains;

	stringstream converter2;	
	size_t pos2 = s.find(" ", pos+1);
	converter2 << s.substr(pos, pos2);
	int currentnumchains; 
	converter2 >> currentnumchains;

	pos = s.find(" ", pos2+1);
	this->PlayerName = s.substr(pos2+1, pos-pos2-1);
	stringstream converter3;
	pos2 = s.find(" ",pos+1);
	converter3 << s.substr(pos,pos2-pos);
	converter3 >> this->coins;
	
	for(int k = 0; k < currentnumchains;k++){
		getline(is,s);
		if(s.front() == 'Q'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'Q'); i++) {
				if(i == 1){
					this->addChain(new Quartz);
				}else{
					this->PlayerChains[k]+= (new Quartz);
				}
			}
		}else if(s.front() == 'H'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'H'); i++) {
				if(i == 1){
					this->addChain(new Hematite);
				}else{
					this->PlayerChains[k]+= (new Hematite);
				}
			}
		} else if(s.front() == 'O'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'O'); i++) {
				if(i == 1){
					this->addChain(new Obsidian);
				}else{
					this->PlayerChains[k]+= (new Obsidian);
				}
			}
		}else if(s.front() == 'M'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'M'); i++) {
				if(i == 1){
					this->addChain(new Malachite);
				}else{
					this->PlayerChains[k]+= (new Malachite);
				}
			}
		}else if(s.front() == 'T'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'T'); i++) {
				if(i == 1){
					this->addChain(new Turquoise);
				}else{
					this->PlayerChains[k]+= (new Turquoise);
				}
			}
		}else if(s.front() == 'R'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'R'); i++) {
				if(i == 1){
					this->addChain(new Ruby);
				}else{
					this->PlayerChains[k]+= (new Ruby);
				}
			}
		}else if(s.front() == 'A'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'A'); i++) {
				if(i == 1){
					this->addChain(new Amethyst);
				}else{
					this->PlayerChains[k]+= (new Amethyst);
				}
			}
		}else if(s.front() == 'E'){
			for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'E'); i++) {
				if(i == 1){
					this->addChain(new Emerald);
				}else{
					this->PlayerChains[k]+= (new Emerald);
				}
			}
		}
	}
	string loadhand;
	while(getline(is,s)){
		loadhand+=s;
		loadhand.push_back('\n');
	}
	istringstream handing(loadhand);
	this->PlayerHand = Hand(handing,cf);
}

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
	}else{
		cout << "Not Enough coins" << endl;
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
	for(int i = 0; i < p.PlayerChains.size(); i++){
		os << p.PlayerChains.at(i) << endl;
	}
	return os;
}

//Adds a chain to the player
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

//Adds sells a chain if the player has already max chain
void Player::addCardAndMakeChain(Card* c) {
	if (getNumChains() < getMaxNumChains()) {
		addChain(c);
	}
	else {
		cout << "Which chain will be sold? (1-" << getNumChains() << ")" << endl;
		for (std::size_t i = 0; i < PlayerChains.size(); i++) {
			cout << ' ' << PlayerChains[i] << endl;
		}
		while (true) {
			int ianswer;
			cin >> ianswer;
			if ((ianswer <= getMaxNumChains()) && (ianswer > 0)) {
				*this += PlayerChains[ianswer-1].sell();
				PlayerChains.erase(PlayerChains.begin() + ianswer - 1);
				break;
			}
		}
		addChain(c);
	}
}
