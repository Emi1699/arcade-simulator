#pragma once

#ifndef SPANZURATOAREA_H
#define SPANZURATOAREA_H

#include<conio.h>
#include<string>
#include<vector>
#include<time.h>
#include<iostream>
#include<Windows.h>

using namespace std;

class Spanzuratoarea
{
public:
	Spanzuratoarea();

	vector < string > ListaDeCuvinte = { "PORUMB","CARTOFI","CUPTOR","ARAGAZ","CASETOFON", "MAMALIGA", "CALCULATOR", "URANIU", "LITERATURA", "PESTE", "AMATOR",
										"ARMAMENT", "STERNOCLEIDOMASTOIDIAN", "CHANEL", "Clavicula", "Melc", "ASTRONOMIE", "GEAM", "IMPRIMANTA",
										"INTRARE", "MULTIME","MANER", "PARALELIPIPED", "PNEUMONOULTRAMICROSCOPICSILICOVULCANIOCONIOZA" };
	vector < char > cuvant; //aici va fi memorat cuvantul 'ales' de computer(random) - initial fiecare litera e inlocuita de  ' _ ' (spatiu)
	vector < char > litere_Ghicite; //se vor memora literele apasate. O SINGURA DATA! (nu vor fi 2 litere la fel in acest vector)

	int nrVieti = 15;

	//  prototipuri ale functiilor pentru jocul 'Spanzuratoarea'
	void afiseazaCuvant(int marime);
	char introduLitera(); //returneaza litera introdusa de utilizator, transformata intotdeauna in _UPPERCASE_
	bool JoacaDinNou();   //la sfarsitul jocului, intreaba userul daca vrea sa joace din nou
	void welcome(); //intampina jucatorul
	void Joaca();
	void afiseaza_Litere_Introduse();//va afisa literele pe care utilizatorul le-a introdus deja
	void adauga_litera(char litera); // adauga litera in vectorul de litere utilizate

	~Spanzuratoarea();
};


#endif // SPANZURATOAREA_H