#include "Spanzuratoarea.h"

Spanzuratoarea::Spanzuratoarea()
{
	//constructor
}

Spanzuratoarea::~Spanzuratoarea()
{
	//destructor
}

void Spanzuratoarea::afiseazaCuvant(int marime) {
	cout << "\n        ";
	for (int i = 0; i < marime; i++) { // afiseaza cuvantul
		cout << cuvant[i] << " ";
	}
}

char Spanzuratoarea::introduLitera() {
	char litGhicit;
	cout << "\n\nDati o litera: ";
	litGhicit = _getch();
	cout << litGhicit;
	Sleep(250);
	while (!(isalpha(litGhicit))) {
		system("cls");
		afiseazaCuvant(cuvant.size());
		afiseaza_Litere_Introduse();
		cout << "\n\nDati o litera! ";
		litGhicit = _getch();
		cout << litGhicit;
		Sleep(250);
		//Sleep(500);
	}

	return toupper(litGhicit);
}

bool Spanzuratoarea::JoacaDinNou() {
	char raspuns;
	cout << "\n\nVreti sa jucati din nou? (D/N)";
	while (true) {
		if (_kbhit()) {
			raspuns = _getch();
			if (raspuns == 'd' || raspuns == 'D')
				return true;
			else if (raspuns == 'n' || raspuns == 'N')
				return false;
			else continue;
		}
	}
}

void Spanzuratoarea::welcome() {
	cout << "**********************";
	cout << "    SPANZURATOAREA    ";
	cout << "**********************";
	cout << "\n******************************************************************\n\n"
		<< "Trebuie sa ghicesti un cuvant ales la intamplare, ghicind cate o litera, pe rand.\nAi " << nrVieti << " vieti. Fiecare litera ghicita gresit iti scade o viata.\n\nSucces!\n\n";
	cout << "* apasa orice tasta pentru a genera un cuvant... *\n\n";
	_getch();
	cout << "generare cuvant...\n";
	Sleep(2000);
	system("cls");
}

void Spanzuratoarea::Joaca() {
	system("cls");

	srand(time(NULL)); //functia are rand() nevoie de un seed (samanta) pentru a genera numere random. time(NULL) reprezinta numarul de secunde ce au trecut de la 1 Ianuarie
					   // 1970 (timp Unix)
	string cuvDeGhicit = ListaDeCuvinte[rand() % ListaDeCuvinte.size()]; //cuvantul ales random de computer

	for (int i = 0; i < cuvDeGhicit.size(); i++) { //pentru fiecare litera din cuvantul ales retine in vectorul 'cuvant' caracterul sirul -> "_ "
		cuvant.push_back('_');                    //ulterior acele spatii vor fi inlocuite cu litere pe care utilizatorul le alege
	}

	welcome();  //intampina jucatorul

	afiseazaCuvant(cuvant.size());

	char literaGhicita; //variabila in care tinem litera aleasa de user

	int complet = cuvDeGhicit.size(); //variabila cu ajutorul careia verificam daca am ghicit toate literele din cuvant
									  //marimea egala cu numarul de litere din cuvantul ales de computer
									  //cand se ghiceste o litera, facem complete--, pana ajungem la 0 (adica pana ghicim toate literele).

	bool check = false;


	while (complet > 0 && nrVieti > 0) {
		literaGhicita = introduLitera();
		for (int i = 0; i < cuvant.size(); i++) { //incepem sa iteram prin cuvant
			if (cuvant[i] == '_') {     //verificam daca pozitia la care ne aflam este un spatiu liber(fara litera)
				if (toupper(cuvDeGhicit[i]) == literaGhicita) {	 //daca ai ghicit o litera, inlocuieste linia din 'cuvant' cu litera respectiva.
					for (int p = i; p < cuvant.size(); p++) {			    // Urmeaza sa iteram 'din nou' prin cuvant. Motivul nu este urmatatorul: daca nu fac asta, nu se poate realiza
						if (toupper(cuvDeGhicit[p]) == literaGhicita) {	    // afisarea simultana a aceeasi litere in cuvant. Pe scurt, daca o litera apare de 2 ori in cuvant, ea se va afisa
							complet--;										// doar o singura data, deoarece primul 'for' trece la urmatorul caracter care e '_' si programul sare la pasul 'else'
							cuvant[p] = literaGhicita;						// corespunzator, programul afisand ca litera nu se afla in cuvant.
							system("cls");
							afiseazaCuvant(cuvant.size());
							adauga_litera(literaGhicita);
							afiseaza_Litere_Introduse();
						}
						if (complet == 0) {
							system("cls");
							afiseazaCuvant(cuvant.size());
							cout << "\n\nFelicitari! Ati ghicit cuvantul!";
							break;
						}
						else continue;
					}//al doilea for
					break;
				} //al doilea if
				else { // litera din cuvant != litera ghicita
					check = false;
					for (int j = i; j <cuvant.size(); j++) {
						if (cuvDeGhicit[j] == literaGhicita) {
							check = true;
							break;
						}
						else
							continue;
					}
					if (check == true)
						continue;
					else {
						nrVieti--;
						if (nrVieti == 0) {
							//system("cls");
							cout << "\n\nAi pierdut!";
							break;
						}
						else if (nrVieti == 1) cout << "\n\nLitera nu se afla in cuvant! Mai ai o viata.";
						else
							cout << "\n\nLitera nu se afla in cuvant! Mai ai " << nrVieti << " vieti.";
						_getch();
						system("cls");
						afiseazaCuvant(cuvant.size());
						adauga_litera(literaGhicita);
						afiseaza_Litere_Introduse();
						break;
					}
				}
			} //primul if
			else if (cuvant[i] == literaGhicita) { // verifica daca litera introdusa de utilizator se afla deja in cuvant
				cout << "\n\nLitera deja se afla in cuvant!";
				_getch();
				system("cls");
				afiseazaCuvant(cuvant.size());
				adauga_litera(literaGhicita);
				afiseaza_Litere_Introduse();
				break;
			}

		} //for
	}//while

	cuvant.clear(); //sterge totul din vectorul 'cuvant', astfel pregatindu-l pentru un joc nou
	litere_Ghicite.clear(); // sterge tot din el, ca sa fie liber pentru urmatoarele runde
	nrVieti = 15;   //reseteaza numarul de vieti
	check = false;
}

void Spanzuratoarea::afiseaza_Litere_Introduse() {
	//adauga_litera(litera);

	cout << "\n\nLitere introduse: ";
	for (int i = 0; i < litere_Ghicite.size(); i++) {
		cout << litere_Ghicite[i] << ", ";
	}
}

void Spanzuratoarea::adauga_litera(char litera) {
	bool check = false;
	for (int i = 0; i < litere_Ghicite.size(); i++) {
		if (litere_Ghicite[i] == litera) {
			check = true;
			break;
		}
	}
	if (check == false) {
		litere_Ghicite.push_back(litera);
	}
}