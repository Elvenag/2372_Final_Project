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
#include <vector>
using std::vector;

//Chain_Base

template<class T> class Chain_Base: public vector<T*>{	
public:
	Chain_Base() : vector(int, T) {};
	T cardType;
	Chain_Base<T>& operator+=(Card* c);
	friend ostream& operator<<(ostream& os,const Chain_Base<Card>& c);
	int sell();
};

template<class Card> class Chain : public Chain_Base<Card> {};

template<> class Chain<Ruby> : public Chain_Base<Ruby> {
public:
	Chain() : Chain_Base() {};
	Chain(istream& is, CardFactory* cf);	
};

template<> class Chain<Quartz> : public Chain_Base<Quartz> {
public:
	Chain() : Chain_Base() {};
	Chain(istream& is, CardFactory* cf);
	
};

template<> class Chain<Hematite> : public Chain_Base<Hematite> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Obsidian> : public Chain_Base<Obsidian> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain < Malachite > : public Chain_Base<Malachite> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Turquoise> : public Chain_Base<Turquoise> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Amethyst> : public Chain_Base<Amethyst> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Emerald> : public Chain_Base<Emerald> {
public:
	Chain() : Chain_Base() {};
	//int sell();
	Chain(istream& is, CardFactory* cf);

};

#endif

template<class Card>
inline int Chain_Base<Card>::sell()
{
	int cards = 0;
	int result = 0;
	for (int i = 0; i <= 4; i++) {
		cards = cardType.getCardsPerCoin(i);
		if (cards > this->size()) {
			break;
		}
		else {
			result = cards;
		}
	}
	return result;
}

template<class T>
inline Chain_Base<T>& Chain_Base<T>::operator+=(Card * c)
{
	try {
		if (typeid(c) == typeid(T))
			this->push_back(c);
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
inline ostream& operator<<(ostream & os,const Chain_Base<Card*>& c)
{
	os << c.cardType->getName();
	for (std::size_t i = 0; i < c.size(); i++) {
		os << " ";
		c.cardType->print(os);
	}
	return os;
}

/*
inline int Chain<Ruby>::sell()
{
	int cards = 0;
	int result = 0;
	for (int i = 0; i <= 4; i++) {
		cards = cardType.getCardsPerCoin(i);
		if (cards > size()) {
			break;
		}
		else {
			result = cards;
		}
	}
	return result;
}


inline int Chain<Quartz>::sell() 
{
	return 0;
}

inline int Chain<Hematite>::sell()
{
	return 0;
}

inline int Chain<Obsidian>::sell()
{
	return 0;
}

inline int Chain<Malachite>::sell()
{
	return 0;
}

inline int Chain<Turquoise>::sell()
{
	return 0;
}

inline int Chain<Amethyst>::sell()
{
	return 0;
}

inline int Chain <Emerald> ::sell()
{
	
	return 0;
}
*/
