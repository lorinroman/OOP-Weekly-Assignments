#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
static int v[] = { 0, 5, 7, 9, 12, 99, 100 };

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. v este un vector global alocat static
//returnati numarul de elemente al acestui vector
int numar_elemente() 
{
	return std::size(v);
}

//2. Functia de mai jos returneaza maximul dintr-un vector
//alocat dinamic primit ca parametru (alaturi de dimensiune)
//daca vectorul este null sau dimensiunea <= 0
//atunci functia returneaza 0
float maxim_vector(float* vector, int dimensiune) 
{
	if (vector == nullptr || dimensiune <= 0) {
		return 0;
	}
	float maxim = vector[0];
	for (int i = 1; i < dimensiune; i++){
		if (vector[i] > maxim) {
			maxim = vector[i];
		}
	}
	return maxim;
}

//3. Returnati o copie a vectorului de caractere
//primit drept parametru
char* returnare_copie_vector_caractere(char* sir) 
{
	char* copie = new char[strlen(sir) + 1];
	strcpy(copie, sir);
	return copie;
}

//4. Functia de mai jos primeste ca si parametri doua stringuri
//returnati lungimea totala a celor doua stringuri
int returnare_lungime_stringuri(string s1, string s2) 
{
	return s1.length() + s2.length();
}

//5. Functia de mai jos primeste ca si parametrii un string si un char*
//si returneaza true daca cele doua siruri de caractere au acelasi continut
bool siruri_egale(string sir1, char* sir2) 
{
	long lungime = sir1.length();
	char* sir1C = new char[lungime + 1];
	strcpy(sir1C, sir1.c_str());
	if (strcmp(sir1C, sir2) == 0) {
		return true;
	}
	return false;
}

//6. Functia de mai jos primeste ca si parametri o matrice alocata dinamic,
//precum si numarul de linii si de coloane
//functia returneaza true daca matricea primita ca parametru este matrice unitate
//(este patratica, iar pe diagonala principala are doar 1, iar restul elementelor sunt 0)
bool matrice_unitate(int** matrice, int linii, int coloane)
{
	if (linii != coloane)
		return false;

	for (int i = 0; i < linii; i++) {
		for (int j = 0; j < coloane; j++) {
			if (i == j) {
				if (matrice[i][j] != 1) {
					return false;
				}
			}
			else {
				if (matrice[i][j] != 0) {
					return false;
				}
			}
		}
	}
	return true;
}

//7. Functia de mai jos returneaza un vector ce contine
//minimul de pe fiecare linie al unei matrice primita ca parametru
//vectorul este alocat dinamic si va contine atatea elemente cate linii are matricea
int* returnare_minim_pe_linii(int** matrice, int linii, int coloane)
{
	int min, dim = 0;
	int* minimPerLinie = new int[linii+1];
	for (int i = 0; i < linii; i++) {
		min = matrice[i][0];
		for (int j = 0; j < coloane; j++) {
			if (matrice[i][j] < min) {
				min = matrice[i][j];
			}
		}
		minimPerLinie[dim++] = min;
	}
	return minimPerLinie;
}

//8. Functia de mai jos este asemanatoare celei de mai sus, doar ca transforma
//elementele vectorului intr-un sir de caractere de tip char* folosind spatii
//ex: daca vectorul returnat mai sus este 1, 2, -2, atunci rezultatul va fi "1 2 -2"
char* returnare_minim_pe_linii_ca_sir(int** matrice, int linii, int coloane)
{
	char* sir = new char[3*linii+1];
	int  dimSir = 0;
	int* vector = returnare_minim_pe_linii(matrice, linii, coloane);
	for (int i = 0; i < linii; i++) {
		
			if (vector[i] >= 0) {
				sir[dimSir++] = vector[i] + '0';
			}
			else {
				sir[dimSir++] = '-';
				sir[dimSir++] = -vector[i] + '0';
			}
			if (i != linii - 1) {
				sir[dimSir++] = ' ';
			}
	}
			
	sir[dimSir] = '\0';
	return sir;
}

//9. Functia de mai jos primeste drept parametri un vector alocat dinamic,
//dimensiunea sa si elementul ce se doreste a fi sters
//si returneaza vectorul obtinut prin stergerea elementului
int* sterge_element(int* vector, int dimensiune, int element)
{
	int ok = 0;
	if (vector != nullptr && dimensiune > 0) {
		
		int* aux = new int[dimensiune - 1];
		int dim = 0;
		for (int i = 0; i < dimensiune; i++) {
			if (vector[i] != element) {
				aux[dim++] = vector[i];
			}
		}
		return aux;
	}
	return nullptr;
}

//10. Functia de mai jos arhiveaza un sir de caractere primit ca parametru
//arhivarea unui sir de caractere se face prin notarea numarului de repetari
//ale unui caracter atunci cand acesta apare de mai mult (sau egal) de 2 ori consecutiv
//ex1: pentru sirul AAABBC, versiunea arhivata este 3A2BC
//ex2: pentru sirul XYYYYYYYZTTT, versiunea arhivata este X7YZ3T
//precizare: sirul contine doar caractere uppercase (litere mari)
char* arhivare_sir(char* sir) 
{
	char* arhiva = new char[2*strlen(sir)+2];
	int dim = 0;
	unsigned int i = 0;
	while(i<strlen(sir)) {
		int nrRepetari = 1;
		char caracter = sir[i];
		while (i < (strlen(sir)-1) && caracter == sir[i + 1] ) {
			i++;
			nrRepetari++;
		}
		if (nrRepetari == 1) {
			arhiva[dim++] = caracter;
		}
		else {
			arhiva[dim++] = nrRepetari + '0';
			arhiva[dim++] = caracter;
		}
		i++;
	}
	arhiva[dim] = '\0';
	return arhiva;
}

int main() 
{
	
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}