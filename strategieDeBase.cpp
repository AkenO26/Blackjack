#include <iostream>
#include <sstream> 

//int tirage()
//{
//
//}


void dv() {
	std::cout << "Diviser votre main" << '\n';
}
void r() {
	std::cout << "Rester" << '\n';
}
void d() {
	std::cout << "Doubler votre main" << '\n';
}
void t() {
	std::cout << "Tirer" << '\n';
}

void tirage(int carte1, int carte2, int croupier)
{
	char tirerEncore{ 'O' };
	int x{};
	int array[11]{};
	while (tirerEncore == 'O'|| tirerEncore == 'o') {
		std::cout << "Carte que vous avez tiree ? ";
		std::string cardValue;
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
		int carteTirer;
		if (cardValue != "a") {

			carteTirer = std::stoi(cardValue);
		}
		else    carteTirer = 1;
		if (carteTirer == 1) {
			std::cout << "L'as vaut 1 ou 11 ? ";
			int reponse{};
			bool errorb{ false };
			while (errorb==false) {
				std::cin >> reponse;                          /////////////// demande si l'as est un 1 ou un 11 et verrifie la qualité de la réponse///////////////////////////////
				if (reponse == 11) {
					carteTirer = 11;
					errorb = true;
				}
				else carteTirer = 1;
				errorb = true;
			}
		}

		array[x] = carteTirer;
		//std::cout << array[x] << '\n';
		x++;
		int score{};
		for (int p = 0; p < 11; p++) {
			//std::cout << array[p] << '\n';
			score += array[p];
		} /*Alors, ici il faut faire en sorte que ton arrray sadditionne avec les dcartes deja présente et apres il faut les évaluer en vue du tableau*/
		score = score + carte1 + carte2;
		std::cout << "Total : "<<score<<'\n';

			if (score >= 5 && score <= 8) {
				t();
			}
			else if (score == 9) {
				if (croupier >= 3 && croupier <= 5) {
					d();
				}
				else t();
			}
			else if (score == 10) {
				if (croupier == 10 || croupier == 1) {
					t();
				}
				else d();
			}
			else if (score == 11) {
				if (croupier == 1) {
					t();
				}
				else d();
			}
			else if (score == 12) {
				if (croupier >= 4 && croupier <= 6) {
					r();
				}
				else t();
			}
			else if (score >= 13 && score <= 16) {
				if (croupier >= 2 && croupier <= 6) {
					r();
				}
				else t();
			}
			else if (score >= 17) {
				r();
			}
			std::cout << "Tirer encore ? (O/N)";
			std::cin >> tirerEncore;
	}
}


void strategieDeBase(std::string card1, std::string card2, std::string croupier1)
{
	int carte1{}, carte2{}, croupier{};
	if (card1 != "a") {

		carte1 = std::stoi(card1);
	}
	else    carte1 = 1;
	if (card2 != "a") {

		carte2 = std::stoi(card2);
	}
	else  carte2 = 1;
	if (croupier1 != "a") {

		croupier = std::stoi(croupier1);
	}
	else  croupier = 1;

	if (carte1 == 1) {
		std::cout << "L'as vaut 1 ou 11 ? ";
		int reponse{};
		bool errorb{ false };
		while (errorb == false) {
			std::cin >> reponse;                          /////////////// demande si l'as est un 1 ou un 11 et verrifie la qualité de la réponse///////////////////////////////
			if (reponse == 11) {
				carte1 = 11;
				errorb = true;
			}
			else carte1 = 1;
			errorb = true;
		}
	}

	if (carte2 == 1) {
		std::cout << "L'as vaut 1 ou 11 ? ";
		int reponse{};
		bool errorb{ false };
		while (errorb == false) {
			std::cin >> reponse;                          /////////////// demande si l'as est un 1 ou un 11 et verrifie la qualité de la réponse///////////////////////////////
			if (reponse == 11) {
				carte2 = 11;
				errorb = true;
			}
			else carte2 = 1;
			errorb = true;
		}
	}

	if (carte1 == carte2) {
		if (carte1 == 2 || carte1 == 3) {
			if (croupier <= 7 && croupier > 1) {
				dv();
				std::cout << "Premiere carte : " << carte1<<'\n';
				tirage(carte1, 0, croupier);
				std::cout << "Deuxieme carte : " << carte2<<'\n';
				tirage(0, carte2, croupier);
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 4) {
			if (croupier == 5 || croupier == 6) {
				dv();
				std::cout << "Premiere carte : " << carte1 << '\n';
				tirage(carte1, 0, croupier);
				std::cout << "Deuxieme carte : " << carte2 << '\n';
				tirage(0, carte2, croupier);
			}
			else t();
		}
		else if (carte1 == 5) {
			if (croupier >= 2 && croupier <= 9) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 6) {
			if (croupier >= 2 && croupier <= 6) {
				dv();
				std::cout << "Premiere carte : " << carte1 << '\n';
				tirage(carte1, 0, croupier);
				std::cout << "Deuxieme carte : " << carte2 << '\n';
				tirage(0, carte2, croupier);
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 7) {
			if (croupier <= 7 && croupier >= 2) {
				dv();
				std::cout << "Premiere carte : " << carte1 << '\n';
				tirage(carte1, 0, croupier);
				std::cout << "Deuxieme carte : " << carte2 << '\n';
				tirage(0, carte2, croupier);
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 9) {
			if (croupier == 7 || croupier == 10 || croupier == 1) {
				r();
			}
			else {
				dv();
				std::cout << "Premiere carte : " << carte1 << '\n';
				tirage(carte1, 0, croupier);
				std::cout << "Deuxieme carte : " << carte2 << '\n';
				tirage(0, carte2, croupier);
			}
		}
		else if (carte1 == 10) {
			r();
		}
		else if (carte1 == 1 || carte1 == 8) {
			dv();
			std::cout << "Premiere carte : " << carte1 << '\n';
			tirage(carte1, 0, croupier);
			std::cout << "Deuxieme carte : " << carte2 << '\n';
			tirage(0, carte2, croupier);
		}
	}
	else if (carte1 == 1 || carte2 == 1) {
		if (carte1 == 2 || carte2 == 2) {
			if (croupier == 5 || croupier == 6) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 3 || carte2 == 3) {
			if (croupier == 5 || croupier == 6) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 4 || carte2 == 4) {
			if (croupier == 5 || croupier == 6 || croupier == 4) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 5 || carte2 == 5) {
			if (croupier == 5 || croupier == 6) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 6 || carte2 == 6) {
			if (croupier >= 3 && croupier <= 6) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 7 || carte2 == 7) {
			if (croupier >= 3 && croupier <= 6) {
				d();
			}
			else if (croupier == 2 || croupier == 7 || croupier == 8) {
				r();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 == 8 || carte2 == 8) {
			r();
		}
		else if (carte1 == 9 || carte2 == 9) {
			r();
		}
		else if (carte1 == 10 || carte2 == 10) {
			r();
		}
	}
	else {
		if (carte1 + carte2 >= 5 && carte1 + carte2 <= 8) {
			t();
			tirage(carte1, carte2, croupier);
		}
		else if (carte1 + carte2 == 9) {
			if (croupier >= 3 && croupier <= 5) {
				d();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 + carte2 == 10) {
			if (croupier == 10 || croupier == 1) {
				t();
				tirage(carte1, carte2, croupier);
			}
			else d();
		}
		else if (carte1 + carte2 == 11) {
			if (croupier == 1) {
				t();
				tirage(carte1, carte2, croupier);
			}
			else d();
		}
		else if (carte1 + carte2 == 12) {
			if (croupier >= 4 && croupier <= 6) {
				r();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 + carte2 >= 13 && carte1 + carte2 <= 16) {
			if (croupier >= 2 && croupier <= 6) {
				r();
			}
			else {
				t();
				tirage(carte1, carte2, croupier);
			}
		}
		else if (carte1 + carte2 >= 17) {
			r();
		}
	}
}

