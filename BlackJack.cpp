#include <iostream>
#include "BlackJack.h"
#include < stdlib.h >


std::string cardValue;
void userInput()
{
	bool error{ false };
	while (error == false) {
		//std::cout << "Rentrer carte : ";
		//std::string cardValue;
		std::cin >> cardValue;
		if (cardValue.length() <= 2) {
			if (cardValue == "a" || cardValue == "2" || cardValue == "3"
				|| cardValue == "4" || cardValue == "5" || cardValue == "6" ||
				cardValue == "7"
				|| cardValue == "8" || cardValue == "9" || cardValue == "10" || cardValue
				== "11") {
				/*std::cout << "c'est bon " << '\n';*/
				error = true;
			}
			else
				std::cout << "Carte invalide \nReessayee : " << '\n';
		}
		else
			std::cout << "Erreur, deux caracteres maximum attendus. \nReessayee : " << '\n';
	}
}

int main()
{
	std::cout << "Jouer comporte des risques : endettement, dependance... "
		<<"Appelez le 09-74-75-13-13 (appel non surtaxe)."<<'\n';
	system("PAUSE");
	system("cls");
	cardArt();
	std::cout << "Lorsque vous avez un as, indiquez \"a\", pour les autres" 
		<<" cartes indiquez le chiffre correspondant a celui sur la carte."<<'\n';
	char continuer = 'O';
	while (continuer == 'O') {
		std::cout << "Rentrer votre premiere carte : ";
		userInput();
		std::string card1 = cardValue;
		std::cout << "Rentrer votre deuxieme carte : ";
		userInput();
		std::string card2 = cardValue;
		std::cout << "Rentrer la carte du croupier : ";
		userInput();
		std::string card3 = cardValue;
		std::cout << "Votre main : " << card1 << " et " << card2 << '\n' << "carte du crou"
			<< "pier : " << card3 << '\n';
		strategieDeBase(card1, card2, card3);
		system("PAUSE");
		system("cls");
	}
	return 0;
}