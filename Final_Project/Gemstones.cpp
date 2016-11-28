/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Card CLASS CPP FILE
*/
#include "Gemstones.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator<<(ostream &os,const Card& c){
    return os << c.getName().front();
}

//Quartz
Quartz::Quartz() = default;

int Quartz::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 4;
    		break;
    	case 2 :
			return 6;
			break;
		case 3 :
			return 8;
			break;
		case 4 :
			return 10;
			break;
		default :
			return 0;
	}
}

string Quartz::getName() const{
	return "Quartz";
}

void Quartz::print(ostream& out){
	out << this;
}

//Hematite
int Hematite::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 3;
    		break;
    	case 2 :
			return 6;
			break;
		case 3 :
			return 8;
			break;
		case 4 :
			return 9;
			break;
		default :
			return 0;
	}
}

string Hematite::getName() const{
	return "Hematite";
}

void Hematite::print(ostream& out){
	out << this;
}

//Obsidian
int Obsidian::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 3;
    		break;
    	case 2 :
			return 5;
			break;
		case 3 :
			return 7;
			break;
		case 4 :
			return 8;
			break;
		default :
			return 0;
	}
}

string Obsidian::getName() const{
	return "Obsidian";
}

void Obsidian::print(ostream& out){
	out << this;
}

//Malachite
int Malachite::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 3;
    		break;
    	case 2 :
			return 5;
			break;
		case 3 :
			return 6;
			break;
		case 4 :
			return 7;
			break;
		default :
			return 0;
	}
}

string Malachite::getName() const{
	return "Malachite";
}

void Malachite::print(ostream& out){
	out << this;
}

//Turquoise
int Turquoise::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 2;
    		break;
    	case 2 :
			return 4;
			break;
		case 3 :
			return 6;
			break;
		case 4 :
			return 7;
			break;
		default :
			return 0;
	}
}

string Turquoise::getName() const{
	return "Turquoise";
}

void Turquoise::print(ostream& out){
	out << this;
}

//Ruby
int Ruby::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 2;
    		break;
    	case 2 :
			return 4;
			break;
		case 3 :
			return 5;
			break;
		case 4 :
			return 6;
			break;
		default :
			return 0;
	}
}

string Ruby::getName() const{
	return "Ruby";
}

void Ruby::print(ostream& out){
	out << this;
}

//Amethyst
int Amethyst::getCardsPerCoin(int coins){
    switch(coins){
    	case 1 :
    		return 2;
    		break;
    	case 2 :
			return 3;
			break;
		case 3 :
			return 4;
			break;
		case 4 :
			return 5;
			break;
		default :
			return 0;
	}
}

string Amethyst::getName() const{
	return "Amethyst";
}

void Amethyst::print(ostream& out){
	out << this;
}

//Emerald
int Emerald::getCardsPerCoin(int coins){
    switch(coins){
    	case 2 :
			return 2;
			break;
		case 3 :
			return 3;
			break;
		default :
			return 0;
	}
}

string Emerald::getName() const{
	return "Emerald";
}

void Emerald::print(ostream& out){
	out << this;
}
