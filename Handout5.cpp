#include <iostream>
#include <string>
using namespace std;

class Cartus
{
private:
	string producator;
	int nrTotalPagini;

public:
	string getProducator()
	{
		return producator;
	}
	int getNrTotalPagini()
	{
		return nrTotalPagini;
	}
	void setProducator(string prod)
	{
		producator = prod;
	}
	void setNrTotalPagini(int nr)
	{
		nrTotalPagini = nr;
	}
};

class Imprimanta
{
private:
	const int serialNumber;
	char* producator;
	int nrPaginiPrintate;
	static string tipImprimanta;
	Cartus cartus;

	Imprimanta() : serialNumber(1)
	{
		this->producator = new char[1];
		strcpy_s(this->producator, 1, "");
		this->nrPaginiPrintate = 0;
	}

	Imprimanta(int serialNumber,char* producator, int nrPaginiPrintate) :  serialNumber(serialNumber)
	{
		
		if (producator != nullptr)
		{
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		this->nrPaginiPrintate = nrPaginiPrintate;
	}

	//destructor
	~Imprimanta()
	{
		if (this->producator != nullptr)
		{
			delete[] producator;
		}
	}

	//constructor de copiere
	Imprimanta(const Imprimanta& i) : serialNumber(i.serialNumber)
	{
		if (i.producator != nullptr)
		{
			this->producator = new char[strlen(i.producator) + 1];
			strcpy_s(this->producator, strlen(i.producator) + 1, i.producator);
		}
		this->nrPaginiPrintate = i.nrPaginiPrintate;
	}

	//supraincarcarea operatorului =
	Imprimanta& operator=(const Imprimanta& i)
	{
		if (producator != nullptr)
		{
			delete[] producator;
		}
		if (i.producator != nullptr)
		{
			producator = new char[strlen(i.producator) + 1];
			strcpy_s(producator, strlen(i.producator) + 1, i.producator);
		}
		else
		{
			producator = nullptr;
		}
		nrPaginiPrintate = i.nrPaginiPrintate;
		return *this;
	}

	static string getTipImprimanta()
	{
		return Imprimanta::tipImprimanta;
	}

	static void setTipImprimanta(string tipImprimanta)
	{
		Imprimanta::tipImprimanta = tipImprimanta;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, char* producator)
	{
		int total = 0;
		if (imprimante != nullptr && nrImprimante > 0)
		{
			for (int i = 0; i < nrImprimante; i++)
			{
				if (strcmp(producator, imprimante[i].producator) == 0)
				{
					total += imprimante[i].nrPaginiPrintate;
				}
			}
		}
		return total;
	}

	void setCartus(Cartus c)
	{
		if (c.getProducator() != "" && c.getNrTotalPagini() != 0)
		{
			cartus.setProducator(c.getProducator());
			cartus.setNrTotalPagini(c.getNrTotalPagini());
		}
	}

	Cartus getCartus()
	{
		return cartus;
	}

	int getNumarPaginiRamase()
	{	
		int nr = cartus.getNrTotalPagini() - this->nrPaginiPrintate;
		if (nr <= 0)
		{
			return 0;
		}
		return nr;
	}
};

//initializare membru static
string Imprimanta::tipImprimanta = "Cerneala";

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim 
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
	
}