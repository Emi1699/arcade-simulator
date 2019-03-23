#pragma once

#include<vector>
#include<iostream>
#include<conio.h>

using namespace std;

class x_si_0
{
public:
	x_si_0();

	int complet = 9;

	void arata_joc(); //arata tabelul cu x si 0
	void goleste_tabel(); //sterge tot din tabelul cu x si 0
	void pune_caracter_la(int i, int j); //plaseaza caracter la pozitiile indicate
	void plaseaza();
	void schimba_jucatori();
	void joaca();
	bool verifica_daca_valabil(int i, int j); // verificam daca pozitiile indicate sunt valabile/exista
	bool verifica_daca_castig();
	bool joaca_din_nou();
	void reseteaza();

private:
	char Matrice_X_O[3][3] = { ' ',' ',' ',
		' ',' ',' ',
		' ',' ',' '
	};
	char jucator = 'X';
	bool verifica = true;
	char castigator;
	bool gameOver = false;
};