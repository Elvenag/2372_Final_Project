/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Chain CLASS HEADER FILE
*/
#ifndef Chain_H
#define Chain_H

#include "Gemstones.h"
#include "CardFactory.h"
#include <vector>
using std::vector;

//Need a Base_Chain

template <class T> class Chain : public vector<T*>{
	class T::value_type cardType;
public:
	Chain<T>& operator+=(Card* c);
	int sell();
	ostream& operator<<(ostream& os);
	Chain( std::istream& in, CardFactory* cf);
};

#endif

inline Chain<Card>& Chain<Card>::operator+=(Card* c)
{
	
	try {
		push_back(c);
	}
	catch(const std::invalid_argument& ia) {
		throw std::invalid_argument("Invalid type for this chain");
	}
	return *this;
}

inline int Chain<Card>::sell()
{
	return cardType.getCardsPerCoin(size());
}

template<class T>
inline ostream & Chain<Card>::operator<<(ostream & os)
{
	os << cardType.getName() << "      ";
	for (std::size_t i = 0; i < size(); i++)
		os << this->at(i) << " ";
}

inline Chain<Card>::Chain(std::istream & in, CardFactory * cf)
{
	//TODO
}
