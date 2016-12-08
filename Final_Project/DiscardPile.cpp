/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
DiscardPile CLASS CPP FILE
*/

#include "DiscardPile.h"
#include <algorithm>
#include <fstream>
#include <string>
DiscardPile & DiscardPile::operator+=(Card * c)
{
	dp.push_back(c);
	return *this;
}

DiscardPile::~DiscardPile()
{
	for (auto c : dp) {
		delete c;
	}
}

Card * DiscardPile::pickUp()
{
	auto drawn = dp.back();
	dp.pop_back();
	return drawn;
}

Card * DiscardPile::top() const
{
	Card* top = dp.back();
	return top;
}

void DiscardPile::print(std::ostream & os)
{
	for (auto c : dp)
		os << c;
}

ostream& operator<<(ostream& os,const DiscardPile& Grave){
	if (Grave.dp.empty()) {
		os << "Empty discard pile";
		return os;
	}
	
	os <<"Discard Pile : " << Grave.top()->getName();
	return os;
}

DiscardPile::DiscardPile(std::istream& is, CardFactory* cf){
	string s;
	getline(is,s);
	if(!(s == "Empty discard pile")){
		if(s.substr(0,1) == "Q"){
   			this->dp.push_back(new Quartz);
  	 	} else if(s.substr(0,1) == "H"){
  	 		this->dp.push_back(new Hematite);
  	 	}else if(s.substr(0,1) == "O"){
  	 		this->dp.push_back(new Obsidian);
  	 	}else if(s.substr(0,1) == "M"){
  	 		this->dp.push_back(new Malachite);
  	 	}else if(s.substr(0,1) == "T"){
  	 		this->dp.push_back(new Turquoise);
   		}else if(s.substr(0,1) == "R"){
   			this->dp.push_back(new Ruby);
  	 	}else if(s.substr(0,1) == "A"){
  	 		this->dp.push_back(new Amethyst);
  	 	}else if(s.substr(0,1) == "E"){
  	 		this->dp.push_back(new Emerald);
   		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'Q'); i++) {
			this->dp.push_back(new Quartz);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'H'); i++) {
			this->dp.push_back(new Hematite);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'O'); i++) {
			this->dp.push_back(new Obsidian);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'M'); i++) {
			this->dp.push_back(new Malachite);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'T'); i++) {
			this->dp.push_back(new Turquoise);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'R'); i++) {
			this->dp.push_back(new Ruby);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'A'); i++) {
			this->dp.push_back(new Amethyst);
		}
		for (std::size_t i = 1; i < std::count(s.begin(), s.end(), 'E'); i++) {
			this->dp.push_back(new Emerald);
		}
	}
}
