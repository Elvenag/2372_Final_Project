/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Chain CLASS HEADER FILE
*/
#ifndef Chain_H
#define Chain_H

#include "CardFactory.h"
#include <vector>
using std::vector;

//Chain_Base

template<class T> class Chain_Base: private vector<T*>{
public:
	Chain_Base<T>& operator+=(Card* c);
};

template<class Card> class Chain {};

template<> class Chain<Ruby> : public Chain_Base<Ruby> {
public:
	int sell();
};

template<> class Chain<Quartz> : public Chain_Base<Quartz> {
public:
	int sell();
};

template<> class Chain<Hematite> : public Chain_Base<Hematite> {
public:
	int sell();
};

template<> class Chain<Obsidian> : public Chain_Base<Obsidian> {
public:
	int sell();
};

template<> class Chain < Malachite > : public Chain_Base<Malachite> {
public:
	int sell();
};

template<> class Chain<Turquoise> : public Chain_Base<Turquoise> {
public:
	int sell();
};

template<> class Chain<Amethyst> : public Chain_Base<Amethyst> {
public:
	int sell();
};

template<> class Chain<Emerald> : public Chain_Base<Emerald> {
public:
	int sell();
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