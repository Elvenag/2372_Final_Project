/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 
Card CLASS HEADER FILE
*/

#ifndef Gemstones_H
#define Gemstones_H
#include <string>
#include <iostream>

using namespace std;

class Card{
	public:
		virtual int getCardsPerCoin(int coins) = 0;
		virtual string getName() const = 0;
		virtual void print(ostream& out) = 0;
};

class Quartz : public Card{
	public:
		Quartz();
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Hematite : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Obsidian : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Malachite : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Turquoise : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Ruby : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Amethyst : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

class Emerald : public Card{
	public:
		int getCardsPerCoin(int coins);
		string getName() const;
		void print(ostream& out);
		friend ostream& operator<<(ostream& os, const Card& c);
};

#endif
