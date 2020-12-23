#include <iostream>
#include <string>
using namespace std;

class TrainRoute
{
private:
	string departure;
	string destination;
	char* trainCode;

public:
	
	TrainRoute(string departure, string destination, const char* trainCode)
	{
		this->departure = departure;
		this->destination = destination;
		if (trainCode != nullptr)
		{
			this->trainCode = new char[strlen(trainCode)+1];
			strcpy_s(this->trainCode, strlen(trainCode)+1, trainCode);
		}
	}

	TrainRoute(const TrainRoute& tr)
	{
		this->departure = tr.departure;
		this->destination = tr.destination;
		if (tr.trainCode != nullptr)
		{
			this->trainCode = new char[strlen(tr.trainCode) + 1];
			strcpy_s(this->trainCode, strlen(tr.trainCode) + 1, tr.trainCode);
		}
		else
		{
			this->trainCode = nullptr;
		}
	}

	TrainRoute& operator=(const TrainRoute& tr)
	{
		if (trainCode != nullptr)
		{
			delete[] trainCode;
		}
		
		departure = tr.departure;
		destination = tr.destination;
		if (tr.trainCode != nullptr)
		{
			trainCode = new char[strlen(tr.trainCode) + 1];
			strcpy_s(trainCode, strlen(tr.trainCode) + 1, tr.trainCode);
		}
		else
		{
			trainCode = nullptr;
		}
		return *this;
	}

	virtual ~TrainRoute()
	{
		if (this->trainCode != nullptr)
		{
			delete[] this->trainCode;
		}
	}

	int totalWeight()
	{
		return 100;
	}

	friend ostream& operator<<(ostream&, TrainRoute);
	friend istream& operator>>(istream&, TrainRoute&);
};

class FreightTrainRoute : public TrainRoute
{
private:
	int nbOfWagons;
	float* weigthPerWagon;

public:
	FreightTrainRoute() : TrainRoute("", "", "Necunoscut")
	{
		this->nbOfWagons = 0;
		this->weigthPerWagon = nullptr;
	}

	FreightTrainRoute(string departure, string destination, const char* trainCode) :
		TrainRoute(departure, destination, trainCode)
	{
		this->nbOfWagons = 0;
		this->weigthPerWagon = nullptr;
	}

	void setWeigth(int nbOfWagons, float* weightPerWagon)
	{
		this->nbOfWagons = nbOfWagons;
		if (this->weigthPerWagon != nullptr)
		{
			delete[] this->weigthPerWagon;
		}
		this->weigthPerWagon = new float[nbOfWagons];
		for (int i = 0; i < nbOfWagons; i++)
		{
			this->weigthPerWagon[i] = weightPerWagon[i];
		}
	}

	FreightTrainRoute(const FreightTrainRoute& ftr) : TrainRoute(ftr)
	{
		
		if (this->weigthPerWagon != nullptr)
		{
			delete[] this->weigthPerWagon;
		}

		if (ftr.weigthPerWagon != nullptr && ftr.nbOfWagons > 0)
		{
			this->nbOfWagons = ftr.nbOfWagons;
			this->weigthPerWagon = new float[ftr.nbOfWagons];
			for (int i = 0; i < ftr.nbOfWagons; i++)
			{
				this->weigthPerWagon[i] = ftr.weigthPerWagon[i];
			}
		}
		
	}

	FreightTrainRoute operator=(const FreightTrainRoute& ftr)
	{
		TrainRoute::operator=(ftr);
		
		if (this->weigthPerWagon != nullptr)
		{
			delete[] this->weigthPerWagon;
		}

		if (ftr.weigthPerWagon != nullptr && ftr.nbOfWagons > 0)
		{
			this->nbOfWagons = ftr.nbOfWagons;
			this->weigthPerWagon = new float[ftr.nbOfWagons];
			for (int i = 0; i < ftr.nbOfWagons; i++)
			{
				this->weigthPerWagon[i] = ftr.weigthPerWagon[i];
			}
		}
		
		
		return *this;
	}

	virtual ~FreightTrainRoute()
	{
		if (weigthPerWagon != nullptr)
		{
			delete[] weigthPerWagon;
		}
	}
	
	int totalWeight()
	{
		float total = 0;
		for (int i = 0; i < nbOfWagons; i++)
		{
			total += weigthPerWagon[i];
		}
		return (int)total;
	}

	

	friend ostream& operator<<(ostream& o, FreightTrainRoute ftr)
	{
		o << (TrainRoute)ftr << endl;
		o << "Nb of wagons: " << ftr.nbOfWagons << endl;
		o << "Weigth per wagon: ";
		if (ftr.weigthPerWagon != nullptr)
		{
			for (int i = 0; i < ftr.nbOfWagons; i++)
			{
				o << (int)ftr.weigthPerWagon[i] << " ";
			}
		}
		o << endl;
		return o;
	}
	

};

ostream& operator<<(ostream& o, TrainRoute t)
{
	o << "Departure: " << t.departure << endl;
	o << "Destination: " << t.destination << endl;
	o << "Train code: " << t.trainCode << endl;

	return o;
}

istream& operator>>(istream& i, TrainRoute& t)
{	
	i >> ws;
	getline(i, t.departure);
	i >> ws;
	getline(i, t.destination);
	string buffer;
	i >> ws;
	getline(i, buffer);
	if (t.trainCode != nullptr)
	{
		delete[] t.trainCode;
	}
	t.trainCode = new char[buffer.length() + 1];
	strcpy_s(t.trainCode, buffer.length() + 1, buffer.c_str());
	return i;
}



//ATENTIE!!!
//* Sunt punctate doar solutiile originale si individuale
//* Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//* Signatura functiilor se poate modifica doar pentru a realiza supradefinirea
//* Utilizarea valorilor din teste pentru a obtine rezultate fals pozitive este considerata frauda

//1. Modificati constructorul cu parametri din clasa TrainRoute pentru a initializa
//statia de plecare, statia de sosire si codul trenului

//2. Respectati "regula celor 3" in cadrul clasei TrainRoute

//3. Modificati operatorul de scriere la consola pentru a afisa informatiile despre ruta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Departure: departure
//Destination: destination
//Train code: trainCode

//Modificati operatorul de citire de la consola pentru a citi informatii despre ruta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//Departure
//Destination
//Train code
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//4. Modificati constructorul implicit al clasei FreightTrainRoute
//acesta va initializa numarul de vagoane cu 0 si vectorul de greutati cu nullptr
//statia de plecare si destinatia vor fi initializate cu un sir vid
//codul trenului va fi "Necunoscut"

//5. Modificati constructorului cu parametri al clasei FreightTrainRoute
//astfel incat sa initializeze corect statia de plecare, destinatia si codul trenului
//numarul de vagoane si vectorul de greutati vor ramane 0, respectiv nullptr
//clasa TrainCode nu se poate modifica pentru a contine constructor implicit

//6. Modificati metoda setWeigth astfel incat sa se poata modifica
//vectorul de greutati si numarul de vagoane

//7. Aplicati "regula celor 3" si in clasa derivata

//8. Supraincarcati operatorii de citire si afisare pentru clasa derivata
//cel de afisarea arata in plus urmatoarele linii la consola
//Nb of wagons: nbOfWagons
//Weigth per wagon: weigth1 weigth2 etc.
//se va afisa doar partea intreaga a greutatilor (fara zecimale)
//cel de citire va citi in continuare numarul de vagoane de pe o linie noua
//si greutatile separate prin spatii

//9. Supradefiniti metoda totalWeight in clasa FreightTrainRoute
//astfel incat sa returneze greutatea totala a trenului ca intreg
//prin trunchiere (se ignora zecimalele rezultatului final)

//10. Evitati memory leaks generate odata cu virtualizarea

int main()
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}