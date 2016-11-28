/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
Table CLASS CPP FILE
*/
#include "Table.h"
#include <iostream>
#include <string>


bool Table::win(std::string& s){
	if(Library.empty()){
		if(Players[0].getNumCoins() > Players[1].getNumCoins()){
			s = Players[0].getName();
			return true;
		}else if(Players[0].getNumCoins() < Players[1].getNumCoins()){
			s = Players[1].getName();
			return true;
		}else{
			s = Players[0].getName() +" and "+ Players[1].getName();
		}
	}
}

/*
void Table::print(ostream& os){
	for(auto i : t.Players){
		os << i << endl;
	}
	os << t.Library << endl;
	os << t.Grave << endl;
	os << t.GTS << endl;
}
*/

/*
ostream& operator<<(ostream &os,const Table& t){
	for(auto i : t.Players){
		os << i << endl;
	}
	os << t.Grave << endl;
	os << t.GTS << endl;
	return os;
}
*/
