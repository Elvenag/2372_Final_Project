/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Chain CLASS HEADER FILE
*/
#ifndef Chain_H
#define Chain_H
#include <typeinfo>
#include "CardFactory.h"
#include <algorithm>
#include <vector>
using std::vector;

//Chain_Base

template<class T> class Chain_Base: public vector<T*>{	
public:
	string cardType;
	using std::vector<T*>::vector;
	Chain_Base<T>& operator+=(Card* c);
	friend ostream& operator<<(ostream& os,const Chain_Base<Card>& c);
	int sell();
	~Chain_Base() = default;
};

template<class Card> class Chain : public Chain_Base<Card> {};

template<> class Chain<Ruby> : public Chain_Base<Ruby> {
public:
	Chain() : Chain_Base() { cardType = "Ruby"; };
	Chain(istream& is, CardFactory* cf);
};

template<> class Chain<Quartz> : public Chain_Base<Quartz> {
public:
	Chain() : Chain_Base() { cardType = "Quartz"; };
	Chain(istream& is, CardFactory* cf);
	
};

template<> class Chain<Hematite> : public Chain_Base<Hematite> {
public:
	Chain() : Chain_Base() { cardType = "Hematite"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Obsidian> : public Chain_Base<Obsidian> {
public:
	Chain() : Chain_Base() { cardType = "Obsidian"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Malachite> : public Chain_Base<Malachite> {
public:
	Chain() : Chain_Base() { cardType = "Malachite"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Turquoise> : public Chain_Base<Turquoise> {
public:
	Chain() : Chain_Base() { cardType = "Turquoise"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Amethyst> : public Chain_Base<Amethyst> {
public:
	Chain() : Chain_Base() { cardType = "Amethyst"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Emerald> : public Chain_Base<Emerald> {
public:
	Chain() : Chain_Base() { cardType = "Emerald"; };
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

#endif

template<class Card>
inline int Chain_Base<Card>::sell()
{
	if (this->size() < 1)
		return 0;
	else {
		Card* card = this->at(0);
		int cards = 0;
		int result = 0;
		for (int i = 1; i <= 4; i++) {
			cards = card->getCardsPerCoin(i);
			if (cards > this->size()) {
				break;
			}
			else {
				result = i;
			}
		}
		return result;
	}
}

template<class T>
inline Chain_Base<T>& Chain_Base<T>::operator+=(Card * c)
{
	try {
		if (c->getName() == cardType) {
			auto a=static_cast<T*>(c);
			this->push_back(a);
		}
		else {
			throw IllegalType("Card type does not match Chain type.");
		}
	}
	catch (IllegalType i) {
		cout << i.getMsg();
	}
	return *this;
}


//template<class Card*>
inline ostream& operator<<(ostream & os,const Chain_Base<Card>& c)
{
	if (c.size() == 0) {
		os << "";
		return os;
	}
	os << c.cardType;
	for (std::size_t i = 0; i < c.size(); i++) {
		 os << " ";
		 c.at(i)->print(os);
		
	}
	return os;
}

inline Chain<Ruby>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'R'); i++) {
		this->push_back(new Ruby);
	}
	cardType = "Ruby";
}

inline Chain<Quartz>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'Q'); i++) {
		this->push_back(new Quartz);
	}
	cardType = "Quartz";
}

inline Chain<Hematite>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'H'); i++) {
		this->push_back(new Hematite);
	}
	cardType = "Hematite";
}

inline Chain<Obsidian>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'O'); i++) {
		this->push_back(new Obsidian);
	}
	cardType = "Obsidian";
}

inline Chain<Malachite>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'M'); i++) {
		this->push_back(new Malachite);
	}
	cardType = "Malachite";
}

inline Chain<Turquoise>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'T'); i++) {
		this->push_back(new Turquoise);
	}
	cardType = "Turquoise";
}

inline Chain<Amethyst>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'A'); i++) {
		this->push_back(new Amethyst);
	}
	cardType = "Amethyst";
}

inline Chain<Emerald>::Chain(istream & is, CardFactory * cf)
{
	string s;
	is >> s;
	for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'E'); i++) {
		this->push_back(new Emerald);
	}
	cardType = "Emerald";
}
