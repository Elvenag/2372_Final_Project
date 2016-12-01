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
			t.Players[0] = new Player(answer);
			cout << "Player 2's name: " << endl;
			cin >> answer;
			t.Players[1] = new Player(answer);
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
					//Display Table?
					if ((t.Players[i].getCoins() >= 3)&&(t.Players[i].getMaxNumChains == 2)){
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
				}
			}

		}
	}

	
}