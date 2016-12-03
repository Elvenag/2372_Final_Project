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
				t.Players[0].PlayerHand += t.Library.draw();
				t.Players[1].PlayerHand += t.Library.draw();
			}
			break;
		}
		while (t.Library.size() > 0) {
			cout << "Type p to pause, anything else to continue." << endl;
			cin >> answer;
			if (answer == "p") {
				//TODO: save and quit
			}
			else {
				for (int i = 0; i < 2; i++){
					cout << t;
					if ((t.Players[i].getNumCoins() >= 3)&&(t.Players[i].getMaxNumChains() == 2)){
						cout << "Buy new chain? (Y or N)"<<endl;
						cin >> answer;
						while(true){
							if(answer == "Y"){
								t.Players[i].buyThirdChain();
								break;
							}
							if(answer == "N"){
								break;
							}
						}
					}
					t.Players[i].PlayerHand+= t.Library.draw();
					if (t.GTS.numCards() != 0) {
						cout << t.GTS;
						while (true) {
							cout << "Insert name of card you wish to trade for or done" << endl;
							cin >> answer;
							if (answer == "done") {
								break;
							}
							else {
								t.GTS.trade(answer);
							}
						}
					}
					bool played = false;
					auto c = t.Players[i].PlayerHand.play();
					for (std::size_t n = 0; n < t.Players[i].getNumChains(); i++) {
						if (typeid(t.Players[i][n].cardType) == typeid(c)) {
							t.Players[i][n] += c;
							played = true;
						}
					}
					if (played = false) {
						if (t.Players[i].getNumChains() < t.Players[i].getMaxNumChains()) 
						{
							Chain<Emerald> newChain;
							if (typeid(c) == typeid(new Quartz))
								Chain<Quartz> newChain;
							else if (typeid(c) == typeid(new Hematite))
								Chain<Hematite> newChain;
							else if (typeid(c) == typeid(new Obsidian))
								Chain<Obsidian> newChain;
							else if (typeid(c) == typeid(new Malachite))
								Chain<Malachite> newChain;
							else if (typeid(c) == typeid(new Turquoise))
								Chain<Turquoise> newChain;
							else if (typeid(c) == typeid(new Ruby))
								Chain<Ruby> newChain;
							else if (typeid(c) == typeid(new Amethyst))
								Chain<Amethyst> newChain;
							t.Players[i].PlayerChains.emplace_back(newChain);
						}
						else {
							cout << "Which chain will be sold? (1-" << t.Players[i].getNumChains() <<")" << endl;
							for (std::list<Chain<Card>>::iterator it = t.Players[i].PlayerChains.begin(); it != t.Players[i].PlayerChains.end(); ++it) {
								cout << ' ' << *it << endl;
							}
							cin >> answer;
							while (true) {
								int ianswer;
								if ((ianswer < t.Players[i].getMaxNumChains()) && (ianswer > 0)) {
									std::list<Chain<Card>>::iterator it = t.Players[i].PlayerChains.begin();
									advance(it, ianswer-1);
									it = t.Players[i].PlayerChains.erase(it);
								}
							}
						}
					}
				}
			}

		}
	}

	
}