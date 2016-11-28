#include "DiscardPile.h"

DiscardPile & DiscardPile::operator+=(Card * c)
{
	dp.push_back(c);
	return *this;
}

Card * DiscardPile::pickUp()
{
	auto drawn = dp.back();
	dp.pop_back();
	return drawn;
}

Card * DiscardPile::top()
{
	auto top = dp.back();
	return top;
}

void DiscardPile::print(std::ostream & os)
{
	for (auto c : dp)
		os << c;
}

ostream & DiscardPile::operator<<(ostream & os)
{
	os << top();
	return os;
}
