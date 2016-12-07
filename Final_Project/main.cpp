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
							if (answer == "done" || (t.GTS.numCards() != 0)) {
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
						/*for (std::size_t n = 0; n < p.getNumChains(); n++) {
							if ((p[n].cardType->getName()) == (c->getName())) {
								p[n] += c;
								played = true;
							}
						}*/
						if (played == false) {
							p.addCardAndMakeChain(c);
							
						}
						cout << "numchains: "<< p.getNumChains() << endl;
						cout << p << endl;
						cout << p.getName() << "'s hand: " << endl;
						p.printHand(cout, true);
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
					
					for (auto& n : t.GTS.area) {
						cout << t.GTS << endl;
						cout << "Trade for this card: " << n->getName() << "? (Y or N)" << endl;
						cin >> answer;
						if (answer == "Y") {
							cout << t.GTS.trade(n->getName())->getName() << endl;
							/*bool added = false;
							for (std::size_t j = 0; j < p.getNumChains(); j++) {
								if (typeid(p[j].cardType) == typeid(n)) {
									bool added = true;
									p[j] += n;
								}
							}
							if (!added) {
								p.addCardAndMakeChain(n);
							}*/
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

