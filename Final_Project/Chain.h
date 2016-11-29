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

