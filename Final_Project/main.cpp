#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include"Table.h"

int main(){
	string answer;
	Table t;
	while (true) {
		cout << "Load game or new? (load or new)" << endl;
		cin >> answer;
		if (answer == "load") {
			//TODO: load game
			break;
		}
		else if (answer == "new") {
			cout << "Player 1's name: " << endl;
			cin >> answer;
			Player p1 = Player(answer);
			t.Players[0] = p1;
			cout << "Player 2's name: " << endl;
			cin >> answer;
			Player p2 = Player(answer);
			t.Players[1] = p2;
			CardFactory cf;
			t.Library = cf.getDeck();
			for (int i = 1; i <= 5; i++) {
				if(t.Library.size()>0){
					t.Players[0].PlayerHand += t.Library.draw();
				}else{
					string winner;
					t.win(winner);
				}
				if(t.Library.size()>0){
					t.Players[1].PlayerHand += t.Library.draw();
				}else{
					string winner;
					t.win(winner);
				}
			}
		}
		while (t.Library.size() > 0) {
			cout << "Type p to pause, anything else to continue." << endl;
			cin >> answer;
			if (answer == "p") {
				//TODO: save and quit
			}
			else {
				for (int i = 0; i < 2; i++) {
					Player& p = t.Players[i];
					cout << t;
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
					p.PlayerHand += t.Library.draw();
					cout << p.getName() << "'s hand: " << endl;
					p.printHand(cout, true);
					cout << endl;
					if (t.GTS.numCards() != 0) {
						while (true) {
							cout << t.GTS << endl;
							cout << "Insert name of card you wish to trade for or done" << endl;
							cin >> answer;
							if (answer == "done" || (t.GTS.numCards() == 0)) {
								int gtssize = t.GTS.area.size();
								for(int i = 0; i < gtssize;i++){
									string discarded = t.GTS.area.front()->getName();
									t.Grave+= t.GTS.trade(discarded);
								}
								cout<< t.Grave << endl;
								break;
							}
							else {
								t.GTS.trade(answer);
							}
						}
					}
					while (true) {
						if(p.PlayerHand.PlayHand.size() == 0){
							cout<< "No play : No more Cards in Hand" << endl;
							break;
						}
						bool played = false;
						Card* c = p.PlayerHand.play();
						for (std::size_t n = 0; n < p.getNumChains(); n++) {
							if ((p[n].cardType) == (c->getName())) {
								p[n] += c;
								played = true;
							}
						}
						if (played == false) {
							p.addCardAndMakeChain(c);
							
						}
						cout << "numchains: "<< t.Players[i].getNumChains() << endl;
						cout << t.Players[i] << endl;
						cout << t.Players[i].getName() << "'s hand: " << endl;
						t.Players[i].printHand(cout, true);
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
							if ((ianswer <= p.PlayerHand.PlayHand.size())&&(ianswer > 0)&&(ianswer <= p.PlayerHand.PlayHand.size())) {
								discarded = p.PlayerHand[ianswer-1];
							}
							cout<< "elem discaded " << discarded->getName() << endl;
							t.Grave += discarded;
						}else{
							cout << "No Cards in hand" << endl;
							break;
						}
					}else{
						break;
					}

					}
					if(t.Library.size() > 0){
						t.GTS += t.Library.draw();
					}else{
						string winner;
						t.win(winner);
					}
					if(t.Library.size() > 0){
						t.GTS += t.Library.draw();
					}else{
						string winner;
						t.win(winner);
					}if(t.Library.size() > 0){
						t.GTS += t.Library.draw();
					}else{
						string winner;
						t.win(winner);
					}
					while ((t.Grave.dp.size() > 0) && (t.GTS.legal(t.Grave.top()))) {
						t.GTS += t.Grave.pickUp();
					}
					list<Card*> temparea = t.GTS.area;
					for (list<Card*>::iterator n=temparea.begin();n != temparea.end();n++) {
						Card* trading = *n;
						cout << p << endl;
						cout << t.GTS << endl;
						cout << "Trade for this card: " << trading->getName() << "? (Y or N)" << endl;
						cin >> answer;
						if (answer == "Y") {
							cout << t.GTS.trade(trading->getName())->getName() << endl;
							bool added = false;
							for (int j = 0; j < p.getNumChains(); j++) {
								if (p[j].cardType == trading->getName()) {
									bool added = true;
									p[j] += trading;
								}
							}
							if (!added) {
								p.addCardAndMakeChain(trading);
							}
						}
					}
					if(t.Library.size() > 0){
						p.PlayerHand += t.Library.draw();
					}else{
						string winner;
						t.win(winner);
					}
					if(t.Library.size() > 0){
						p.PlayerHand += t.Library.draw();
					}else{
						string winner;
						t.win(winner);
					}
				}
			}

		}
		
		string winner;
		t.win(winner);
		break;
	}

}

