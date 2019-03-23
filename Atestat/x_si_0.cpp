#include "x_si_0.h"

x_si_0::x_si_0() {}

void x_si_0::arata_joc() {
	cout << "    1    2    3" << endl;
	cout << "   ............." << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "  | " << Matrice_X_O[i][0] << " | " << Matrice_X_O[i][1] << " | " << Matrice_X_O[i][2] << " | " << endl;
		cout << "   .............";
		if (i == 0)
			cout << "  " << jucator << endl;
		else
			cout << endl;
	}
}

void x_si_0::goleste_tabel() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Matrice_X_O[i][j] = ' ';
		}
	}
}

void x_si_0::pune_caracter_la(int i, int j) {
	Matrice_X_O[i][j] = jucator;
}

void x_si_0::plaseaza() {
	int x, y;
	cout << "Pe care linie doresti sa fie plasat " << jucator << "? ";
	cin >> x;
	cout << "Pe care coloana? ";
	cin >> y;
	if (x < 1 || y < 1 || x>3 || y>3)
		verifica = false;
	bool bun = verifica_daca_valabil(x - 1, y - 1);
	if (bun) {
		pune_caracter_la(x - 1, y - 1);
		complet--;
	}
	else
		verifica = false;
}

void x_si_0::schimba_jucatori() {
	if (jucator == 'X')
		jucator = 'O';
	else
		jucator = 'X';
}

void x_si_0::joaca() {
	while (true) {
		system("cls");
		arata_joc();
		plaseaza();
		if (verifica == false) {
			verifica = true;
			continue;
		}
		if (verifica_daca_castig()) {
			system("cls");
			arata_joc();
			cout << "\n\nCastigatorul este " << castigator << " !";
			if (joaca_din_nou()) {
				reseteaza();
				joaca();
			}
			else {
				//cout << "\n\nLa revedere!\n\n";
				gameOver = true;
				break;
			}
		}
		if (gameOver)
			return;
		else
			schimba_jucatori();
	}
}

bool x_si_0::verifica_daca_valabil(int i, int j) {
	if (Matrice_X_O[i][j] != ' ') {
		if ((i >= 0) && (i <= 2) && (j >= 0) && (j <= 2)) {
			cout << "   " << Matrice_X_O[i][j] << " este deja acolo";
			system("pause>nul");
			return false;
		}
	}
	return true;
}

bool x_si_0::verifica_daca_castig() {
	//verificam daca nimeni nu a castigat
	if (complet == 0) {
		cout << "Nimeni nu a castigat. ";
		if (joaca_din_nou()) {
			reseteaza();
			joaca();
		}
		else {
			gameOver = true;
			cout << "\n\nLa revedere!\n\n";
			//break;
			return false;
		}
	}
	//randuri
	for (int i = 0; i < 3; i++) {
		if (Matrice_X_O[i][0] != ' ') {
			if (Matrice_X_O[i][0] == Matrice_X_O[i][1] && Matrice_X_O[i][0] == Matrice_X_O[i][2]) {
				castigator = Matrice_X_O[i][0];
				return true;
			}
		}
	}
	//colums
	for (int j = 0; j < 3; j++) {
		if (Matrice_X_O[0][j] != ' ') {
			if (Matrice_X_O[0][j] == Matrice_X_O[1][j] && Matrice_X_O[0][j] == Matrice_X_O[2][j]) {
				castigator = Matrice_X_O[0][j];
				return true;
			}
		}
	}
	//diagonal
	for (int i = 0; i < 3; i++) {
		if (Matrice_X_O[i][0] != ' ') {
			if (Matrice_X_O[i][0] == Matrice_X_O[i + 1][1] && Matrice_X_O[i][0] == Matrice_X_O[i + 2][2]) {
				castigator = Matrice_X_O[i][0];
				return true;
			}
		}
		if (Matrice_X_O[i][2] != ' ') {
			if (Matrice_X_O[i][2] == Matrice_X_O[i + 1][1] && Matrice_X_O[i][2] == Matrice_X_O[i + 2][0]) {
				castigator = Matrice_X_O[i][2];
				return true;
			}
		}
	}
	return false;
}

bool x_si_0::joaca_din_nou() {
	char raspuns;
	cout << "\n\nVrei sa joci din nou? (Y/N)";
	while (true) {
		raspuns = _getch();
		if (raspuns == 'Y' || raspuns == 'y') {
			//	break;
			return true;
		}
		else if (raspuns == 'N' || raspuns == 'n') {
			break;
			//	return false;
		}
		else {
			continue;
		}
	}
	return false;
}

void x_si_0::reseteaza() {
	goleste_tabel();
	jucator = 'X';
	verifica = true;
	gameOver = false;
	complet = 9;
}