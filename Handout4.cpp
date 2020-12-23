#include <iostream>
#include <string>
using namespace std;

class Autoturism
{
private:
	string marca;
	string model;
	int putere;
	double pret;
	float* distanteParcurse;
	int nrDrumuri; //nr de elemente al vectorului de mai sus
	char* taraDeProductie;

public:
	Autoturism()
	{
		this->marca = "Necunoscuta";
		this->model = "Necunoscut";
		this->putere = 0;
		this->pret = 5000;
		this->distanteParcurse = nullptr;
		this->nrDrumuri = 0;
		this->taraDeProductie = nullptr;
	}

	Autoturism(string marca, string model, int putere) : Autoturism()
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
	}

	Autoturism(string marca, string model, float* distante, int nrDrumuri) : Autoturism()
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
		
		if (distante != nullptr && nrDrumuri > 0)
		{
			this->nrDrumuri = nrDrumuri;
			this->distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++)
			{
				this->distanteParcurse[i] = distante[i];
			}
		}
	}

	Autoturism(const Autoturism& a)
	{
		this->marca = a.marca;
		this->model = a.model;
		this->pret = a.pret;
		this->putere = a.putere;
		if (a.distanteParcurse != nullptr && a.nrDrumuri > 0)
		{
			this->nrDrumuri = a.nrDrumuri;
			this->distanteParcurse = new float[a.nrDrumuri];
			for (int i = 0; i < a.nrDrumuri; i++)
			{
				this->distanteParcurse[i] = a.distanteParcurse[i];
			}
		}
		if (a.taraDeProductie != nullptr)
		{
			this->taraDeProductie = new char[strlen(a.taraDeProductie) + 1];
			strcpy_s(this->taraDeProductie, strlen(a.taraDeProductie) + 1, a.taraDeProductie);

		}
	}
	~Autoturism()
	{
		if (distanteParcurse != nullptr)
		{
			delete[] distanteParcurse;
		}
		if (taraDeProductie != nullptr)
		{
			delete[] taraDeProductie; 
		}
	}
	string getMarca()
	{
		return this->marca;
	}

	void setMarca(string marca)
	{
		if (marca.size() >= 3)
		{
			this->marca = marca;
		}
	}

	int getNrDrumuri()
	{
		return this->nrDrumuri;
	}

	float* getDistanteParcurse()
	{
		if (distanteParcurse != nullptr)
		{
			float* copie = new float[nrDrumuri];
			for(int i= 0 ; i<nrDrumuri; i++)
			{
				copie[i] = distanteParcurse[i];
			}
			return copie;
		}
		return nullptr;
	}

	void setDistante(float* distanteParcurse, int nrDrumuri)
	{
		if (distanteParcurse != nullptr && nrDrumuri > 0)
		{
			this->nrDrumuri = nrDrumuri;
			this->distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++)
			{
				this->distanteParcurse[i] = distanteParcurse[i];
			}

		}

	}

	char* getTaraDeProductie()
	{
		if (taraDeProductie != nullptr)
		{
			int k = 0;
			char* copie = new char[strlen(taraDeProductie) + 1];
			for (int i = 0; i < strlen(taraDeProductie); i++)
			{
				copie[k++] = taraDeProductie[i];
			}
			copie[k] = '\0';
			return copie;
		}
		return nullptr;
	}

	void setTaraDeProductie(const char* tara)
	{
		if (tara != nullptr)
		{
			this->taraDeProductie = new char[strlen(tara) + 1];
			strcpy_s(taraDeProductie,strlen(tara)+1, tara);
			
		}
	}

	char* AdresaInceputTaraDeProductie()
	{
		return this->taraDeProductie;
	}
};

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. Modificati constructorul implicit din clasa Autoturism de mai sus
//acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
//puterea cu 0, pretul cu 5000, vectorul de distante cu NULL si nrDrumuri cu 0

//2. Modificati constructorul cu 3 parametri: marca, model, putere
//acesta va initializa cele 3 atribute cu valorile primite
//restul de atribute nu trebuie sa ramana neinitializate si vor folosi aceleasi valori implicite ca mai sus

//3. Modificati constructorul cu 4 parametri pentru a copia valorile
//primite drept parametri in atributele clasei
//constructorul nu va lasa atribute neinitializate

//4. Adaugati un destructor in clasa care sterge zonele de memorie anterior alocate
//acesta va seta pointerii pe NULL dupa ce face stergerea

//5. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor

//6. Modificati metodele de acces (getteri si setteri) pentru atributul marca
//Setterul va accepta denumiri de marci cu o lungime
//mai mare sau egala de 3 caractere
//in caz contrar marca ramane cea existenta

//7. Modificati getter-ul pentru vectorul de distante parcurse
//Getter-ul va returna o copie a vectorului din clasa
//Modificati getter-ul si pentru numarul de drumuri

//8. Modificati setter-ul pentru vectorul de distante
//acesta va modifica simultan vectorul si numarul de elemente
//si nu va accepta decat vectori nenuli si numar de elemente mai mare decat 0

//9. Adaugati un camp de tip char* in clasa numit taraDeProductie
//modificati getter-ul si setter-ul din clasa pentru a returna,
//respectiv a modifica valoarea acestui camp
//Metoda AdresaInceputTaraDeProductie intoarce adresa primului element din tara de productie
//(da, nu e neaparat safe, dar e necesar pentru test)

//10. Modificati constructorii, destructorul si alte metode necesare
//astfel incat clasa sa gestioneze corect noul camp

int main() 
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}