
#include<conio.h>
#include<string>
#include<vector>
#include<time.h>
#include<iostream>
#include<Windows.h>

#include "Spanzuratoarea.h"
#include "x_si_0.h"

using namespace std;

void alege(Spanzuratoarea &Joc1, x_si_0 &Joc2);

int main() {

	Spanzuratoarea spz;
	x_si_0 XO;

	alege(spz, XO);  //loop-ul jocului

	cout << "\n\n          La revedere! :)";

	cout << ("\n\nApasa orice tasta pentru a iesi...");
	_getch();

	return 0;
}


void alege(Spanzuratoarea &Joc1, x_si_0 &Joc2) {

	cout << "Aceasta aplicatie contine 2 jocuri foarte populare: 'Spanzuratoarea' si 'X si O'.\n";
	cout << "Din meniul de mai jos poti selecta jocul dorit. Succes!";
	Sleep(6500);

	bool terminat = 0;

repeta:
	while (!terminat) {
		char alegere;

		do {
			system("cls");
			cout << "Alege joc:\n\n 1. Spanzuratoarea";
			cout << endl << " 2. X si 0";
			cout << endl << " 3. Iesire";
			alegere = _getch();

		} while ((alegere != '1') && (alegere != '2') && alegere != '3');

		switch (alegere) {
		case '1': {
			while (true) {
				Joc1.Joaca();
				bool vrea_Sa_Joace_Din_NoU = Joc1.JoacaDinNou();   //intrebam userul daca vrea sa joace din nou
				if (vrea_Sa_Joace_Din_NoU) continue;
				else goto repeta;
			}
		}
		case '2': {
			system("cls");
			cout << "Acesta este jocul 'X si O'! Regulile sunt (probabil) cunoscute de toata lumea!\nSucces!\n\n\n";
			system("pause");
			Joc2.joaca();
			goto repeta;
		}
		case '3': terminat = 1;
		}
	}
}