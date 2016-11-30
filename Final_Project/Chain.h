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
	T cardType;
public:
	Chain_Base<T>& operator+=(Card* c);
	ostream& operator<<(ostream& os);
};

template<class Card> class Chain : public Chain_Base<Card> {};

template<> class Chain<Ruby> : public Chain_Base<Ruby> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);	
};

template<> class Chain<Quartz> : public Chain_Base<Quartz> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);
	
};

template<> class Chain<Hematite> : public Chain_Base<Hematite> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Obsidian> : public Chain_Base<Obsidian> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain < Malachite > : public Chain_Base<Malachite> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Turquoise> : public Chain_Base<Turquoise> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Amethyst> : public Chain_Base<Amethyst> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

template<> class Chain<Emerald> : public Chain_Base<Emerald> {
public:
	int sell();
	Chain(istream& is, CardFactory* cf);

};

#endif

template<class T>
inline Chain_Base<T>& Chain_Base<T>::operator+=(Card * c)
{
	try {
		if (typeid(c) == typeid(T))
			push_back(c);
		else {
			throw IllegalType("Card type does not match Chain type.");
		}
	}
	catch (IllegalType i) {
		cout << i.getMsg();
	}
	return *this;
}

template<class Card>
inline ostream & Chain_Base<Card>::operator<<(ostream & os)
{
	os << cardType.getName();
	for (std::size_t i = 0; i < size(); i++) {
		os << " ";
		cardType.print(os);
	}
	return os;
}

inline int Chain<Ruby>::sell()
{
	return 0;
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
