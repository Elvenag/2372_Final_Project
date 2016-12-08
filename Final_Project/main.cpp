#include <iostream>
#include <string>
#include"Table.h"
#include <fstream>
using namespace std;

int main(){
	string answer;
	Table* t;
	while (true) {
		cout << "Load game or new? (load or new)" << endl;
		cin >> answer;
		if (answer == "load") {
			CardFactory cf;
			ifstream fileload("save.txt");
			t =new Table(fileload,&cf);
			cout << "Game loaded with table:" << endl;
			cout << *t << endl;
		}
		else if (answer == "new") {
			t = new Table();
			cout << "Player 1's name: " << endl;
			cin >> answer;
			Player p1 = Player(answer);
			t->Players[0] = p1;
			cout << "Player 2's name: " << endl;
			cin >> answer;
			Player p2 = Player(answer);
			t->Players[1] = p2;
			CardFactory cf;
			t->Library = cf.getDeck();
			for (int i = 1; i <= 5; i++) {
				if(t->Library.size()>0){
					t->Players[0].PlayerHand += t->Library.draw();
				}else{
					string winner;
					t->win(winner);
				}
				if(t->Library.size()>0){
					t->Players[1].PlayerHand += t->Library.draw();
				}else{
					string winner;
					t->win(winner);
				}
			}
		}
		while (t->Library.size() > 0) {
			cout << "Type p to pause, anything else to continue." << endl;
			cin >> answer;
			if (answer == "p") {
				ofstream save;
				save.open("save.txt");
				t->print(save);
				break;
			}
			else {
				for (int i = 0; i < 2; i++) {
					Player& p = t->Players[i];
					cout << *t <<endl;
					cout << t->Players[i].getName() << "'s turn"<<endl;
					if ((p.getNumCoins() >= 3) && (p.getMaxNumChains() == 2)) {
						cout << "Buy new chain? (Y or N)" << endl;
						cin >> answer;
						while (true) {
							if (answer == "Y") {
								p.buyThirdChain();
								break;
							}
							if (answer == "N") {
								break;
							}
						}
					}
					cout << endl;
					p.PlayerHand += t->Library.draw();
					if (t->GTS.numCards() != 0) {
						while (true) {
							cout << t->Players[i] << endl;
							cout << p.getName() << "'s hand: ";
							p.printHand(cout, true);
							cout << endl;
							cout << t->GTS << endl;
							cout << "Insert name of card you wish to trade for or done" << endl;
							cin >> answer;
							if (answer == "done" || (t->GTS.numCards() == 0)) {
								int gtssize = t->GTS.area.size();
								for(int i = 0; i < gtssize;i++){
									string discarded = t->GTS.area.front()->getName();
									t->Grave+= t->GTS.trade(discarded);
								}
								cout<< t->Grave << endl;
								break;
							}
							else {
								bool* added = new bool(false);
								for (int j = 0; j < p.getNumChains(); j++) {
									if (p[j].cardType == answer) {
										*added = true;
										p[j] += t->GTS.trade(answer);
									}
								}
								if (!*added) {
									p.addCardAndMakeChain(t->GTS.trade(answer));
								}
							}
						}
					}
					while (true) {
						if(p.PlayerHand.PlayHand.size() == 0){
							cout<< "No play : No more Cards in Hand" << endl;
							break;
						}
						bool* played = new bool(false);
						Card* c = p.PlayerHand.play();
						for (std::size_t n = 0; n < p.getNumChains(); n++) {
							if ((p[n].cardType) == (c->getName())) {
								p[n] += c;
								*played = true;
							}
						}
						if (*played == false) {
							p.addCardAndMakeChain(c);
							
						}
						cout << t->Players[i] << endl;
						cout << t->Players[i].getName() << "'s hand: ";
						t->Players[i].printHand(cout, true);
						cout << endl;
						cout << "Play next card? (Y or N)" << endl;
						cin >> answer;
						if (answer != "Y") {
							break;
						}
					}
					while (true) {
					cout << p.getName() << "'s hand: ";
					p.printHand(cout, true);
					cout<< endl;
					cout << "Discard a card? (Y or N)" << endl;
					cin >> answer;
					if ((answer == "Y") && (!p.PlayerHand.PlayHand.empty())) {
						if(!p.PlayerHand.PlayHand.empty()){
							Card* discarded;
							cout << endl;
							int ianswer;
							cout << "Choose a card number to discard (1-" << p.PlayerHand.PlayHand.size() << ")" << endl;
							cin >> ianswer;
							if ((ianswer <= p.PlayerHand.PlayHand.size())&&(ianswer > 0)) {
								discarded = p.PlayerHand[ianswer-1];
							}
							cout<< discarded->getName() << " discarded" << endl;
							t->Grave += discarded;
						}else{
							cout << "No Cards in hand" << endl;
							break;
						}
					}else{
						break;
					}

					}
					if(t->Library.size() > 0){
						t->GTS += t->Library.draw();
					}else{
						string winner;
						t->win(winner);
					}
					if(t->Library.size() > 0){
						t->GTS += t->Library.draw();
					}else{
						string winner;
						t->win(winner);
					}if(t->Library.size() > 0){
						t->GTS += t->Library.draw();
					}else{
						string winner;
						t->win(winner);
					}
					while ((t->Grave.dp.size() > 0) && (t->GTS.legal(t->Grave.top()))) {
						t->GTS += t->Grave.pickUp();
					}
					list<Card*> temparea = t->GTS.area;
					for (list<Card*>::iterator n=temparea.begin();n != temparea.end();n++) {
						Card* trading = *n;
						cout << p << endl;
						cout << t->GTS << endl;
						cout << "Trade for this card: " << trading->getName() << "? (Y or N)" << endl;
						cin >> answer;
						if (answer == "Y") {
							cout << t->GTS.trade(trading->getName())->getName() << endl;
							bool* added = new bool(false);
							for (int j = 0; j < p.getNumChains(); j++) {
								if (p[j].cardType == trading->getName()) {
									*added = true;
									p[j] += trading;
								}
							}
							if (!*added) {
								p.addCardAndMakeChain(trading);
							}
						}
					}
					if(t->Library.size() > 0){
						p.PlayerHand += t->Library.draw();
					}else{
						string winner;
						t->win(winner);
					}
					if(t->Library.size() > 0){
						p.PlayerHand += t->Library.draw();
					}else{
						string winner;
						t->win(winner);
					}
				}
			}

		}
		
		string winner;
		t->win(winner);
		break;
	}

}

