#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TrainRoute
{
private:
	string departure;
	string destination;

	int nbOfStops;
	//distances between stops
	//it has nbOfStops-1 elements
	int* distances;

	char* trainCode;

public:
	TrainRoute(string departure, string destination)
	{
		this->departure = departure;
		this->destination = destination;
		this->nbOfStops = 0;
		this->distances = nullptr;
		this->trainCode = nullptr;
	}

	~TrainRoute()
	{
		if (distances != nullptr)
		{
			delete[] distances;
		}
		if (trainCode != nullptr)
		{
			delete[] trainCode;
		}
	}

	TrainRoute(const TrainRoute& tr)
	{
		this->departure = tr.departure;
		this->destination = tr.destination;
		if (tr.distances != nullptr && tr.nbOfStops != 0)
		{
			this->nbOfStops = tr.nbOfStops;
			this->distances = new int[tr.nbOfStops - 1];
			for (int i = 0; i < nbOfStops - 1; i++)
			{
				this->distances[i] = tr.distances[i];
			}
		}
		else
		{
			this->nbOfStops = 0;
			this->distances = nullptr;
		}
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
		if (distances != nullptr)
		{
			delete[] distances;
		}
		if (trainCode != nullptr)
		{
			delete[] trainCode;
		}
		this->departure = tr.departure;
		this->destination = tr.destination;
		if (tr.distances != nullptr && tr.nbOfStops != 0)
		{
			this->nbOfStops = tr.nbOfStops;
			this->distances = new int[tr.nbOfStops - 1];
			for (int i = 0; i < nbOfStops - 1; i++)
			{
				this->distances[i] = tr.distances[i];
			}
		}
		else
		{
			this->nbOfStops = 0;
			this->distances = nullptr;
		}
		if (tr.trainCode != nullptr)
		{
			this->trainCode = new char[strlen(tr.trainCode) + 1];
			strcpy_s(this->trainCode, strlen(tr.trainCode) + 1, tr.trainCode);
		}
		else
		{
			this->trainCode = nullptr;
		}

		return *this;
	}

	string getDeparture()
	{
		return this->departure;
	}

	string getDestination()
	{
		return this->destination;
	}

	int getNbOfStops()
	{
		return this->nbOfStops;
	}

	int* getDistances()
	{
		return this->distances;
	}

	char* getTrainCode()
	{
		return this->trainCode;
	}

	void setTrip(int* distances, int nbOfStops)
	{
		if (distances != nullptr && nbOfStops != 0)
		{
			this->nbOfStops = nbOfStops;
			if (this->distances != nullptr)
			{
				delete[] this->distances;
			}
			this->distances = new int[nbOfStops - 1];
			for (int i = 0; i < nbOfStops - 1; i++)
			{
				this->distances[i] = distances[i];
			}
		}

	}

	void setTrainCode(const char* trainCode)
	{
		if (trainCode != nullptr)
		{
			this->trainCode = new char[strlen(trainCode) + 1];
			strcpy_s(this->trainCode, strlen(trainCode) + 1, trainCode);
		}
	}

	bool operator<(TrainRoute t)
	{
		int distance1 = 0, distance2 = 0;
		for (int i = 0; i < nbOfStops - 1; i++)
		{
			distance1 += distances[i];
		}
		for (int i = 0; i < t.nbOfStops - 1; i++)
		{
			distance2 += t.distances[i];
		}

		return distance1 < distance2 ? true : false;
	}

	void operator+=(int distance)
	{
		/*if (distances != nullptr)
		{
			int* aux = new int[nbOfStops - 1];
			for (int i = 0; i < nbOfStops - 1; i++)
			{
				aux[i] = distances[i];
			}
			delete[] distances;
			
			distances = new int[nbOfStops];
			for (int i = 0; i < nbOfStops - 1; i++)
			{
				distances[i] = aux[i];
			}
			distances[nbOfStops-1] = distance;
			nbOfStops++;
			delete[] aux;
		}
		*/

	}

	void serialize(string fileName)
	{
		fstream f(fileName, ios::binary);
		int length = departure.length();
		f.write((char*)&length, sizeof(length));
		f.write(departure.c_str(), length + 1);
		length = destination.length();
		f.write((char*)&length, sizeof(length));
		f.write(destination.c_str(), length + 1);
		f.write((char*)&nbOfStops, sizeof(nbOfStops));
		length = strlen(trainCode);
		f.write((char*)&length, sizeof(length));
		f.write(trainCode, length + 1);
		f.write((char*)&nbOfStops, sizeof(nbOfStops));
		int i;
		for (i = 0; i < nbOfStops - 1; i++);
		{
			f.write((char*)&distances[i], sizeof(distances[i]));
		}
		f.close();
	}

	void deserialize(string fileName)
	{

	}

	friend ostream& operator<<(ostream&, TrainRoute);
	friend istream& operator>>(istream&, TrainRoute&);
	friend ofstream& operator<<(ofstream&, TrainRoute);
	friend ifstream& operator>>(ifstream&, TrainRoute&);
};

ostream& operator<<(ostream& out, TrainRoute r)
{
	out << "Departure: " << r.departure << endl;
	out << "Destination: " << r.destination << endl;
	out << "Train code: ";
	if (r.trainCode != nullptr)
	{
		out << r.trainCode << endl;
	}
	out << "Number of stops: " << r.nbOfStops << endl;
	out << "Distances between stops: ";
	for (int i = 0; i < r.nbOfStops - 1; i++)
	{
		out << r.distances[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, TrainRoute& r)
{
	cout << "Departure: ";
	in >> ws;
	getline(in, r.departure);

	cout << "Destination: ";
	in >> ws;
	getline(in, r.destination);

	char buffer[100];
	cout << "Train code: ";
	in >> ws;
	in.getline(buffer, 99);
	if (r.trainCode != nullptr)
	{
		delete[] r.trainCode;
	}
	r.trainCode = new char[strlen(buffer) + 1];
	strcpy_s(r.trainCode, strlen(buffer) + 1, buffer);

	cout << "Number of stops: ";
	in >> r.nbOfStops;

	if (r.distances != nullptr)
	{
		delete[] r.distances;
	}
	r.distances = new int[r.nbOfStops - 1];
	for (int i = 0; i < r.nbOfStops - 1; i++)
	{
		in >> r.distances[i];
	}
	return in;
}
ofstream& operator<<(ofstream& out, TrainRoute r)
{
	out << "Departure: " << r.departure << endl;
	out << "Destination: " << r.destination << endl;
	out << "Train code: ";
	if (r.trainCode != nullptr)
	{
		out << r.trainCode << endl;
	}
	else
	{
		out << "N/A";
	}
	out << "Number of stops: " << r.nbOfStops << endl;
	out << "Distances between stops: ";
	for (int i = 0; i < r.nbOfStops - 1; i++)
	{
		out << r.distances[i] << " ";
	}
	return out;
}

ifstream& operator>>(ifstream& in, TrainRoute r)
{
	in >> ws;
	getline(in, r.getDeparture());
	in >> ws;
	getline(in, r.getDestination());
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	if (r.getTrainCode() != nullptr)
	{
		delete[] r.getTrainCode();
	}
	r.getTrainCode() = new char[strlen(buffer) + 1];
	strcpy_s(r.getTrainCode(), strlen(buffer) + 1, buffer);
	in >> r.getNbOfStops();
	if (r.getDistances() != nullptr)
	{
		delete[] r.getDistances();
	}
	r.getDistances() = new int[r.getNbOfStops() - 1];
	for (int i = 0; i < r.getNbOfStops() - 1; i++)
	{
		in >> r.getDistances()[i];
	}
	return in;
}

//ATENTIE!!!
//* Sunt punctate doar solutiile originale si individuale
//* Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//* Signatura functiilor nu se poate modifica, doar continului lor
//* Utilizarea valorilor din teste pentru a obtine rezultate fals pozitive este considerata frauda

//1. Modificati constructorul cu parametri pentru a initializa
//statia de plecare si statia de sosire
//numarul de opriri va fi initializat cu 0, iar cei doi vectori
//(vectorul de distante si codul trenului) cu null

//2. Modificati metoda setTrip astfel incat vectorul existent de distante
//sa fie inlocuit de cel primit drept parametru
//nu uitati faptul ca vectorul are cu un element mai putin decat numarul de statii

//3. Modificati metoda setTrainCode pentru a inlocui codul existent
//cu cel primit drept parametru

//4. Respectati "regula celor 3" in cadrul clasei de mai sus

//5. Modificati supraincarcarea operatorului <
//acesta va returna true daca distanta totala a rutei reprezentata de primul operand
//este mai mica decat distanta totala a rutei reprezentate de al doilea operand

//6. Modificati operatorul += pentru a adauga un element in vectorul de distante
//numarul de statii va fi de asemenea incrementat

//7. Modificati operatorul de scriere la consola pentru a afisa informatiile despre ruta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Departure: departure
//Destination: destination
//Train code: trainCode
//Number of stops: nbOfStops
//Distances between stops: distance1 distance2 distance3 etc

//8. Modificati operatorul de citire de la consola pentru a citi informatii despre ruta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//Departure
//Destination
//Train code
//Number of stops
//distance 1
//distance 2
//distance 3
//etc
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//9. Supraincarcati operatorii de scriere si citire din fisiere text
//operatorii functioneaza pe fisiere text deschise deja

//10. Modificati metodele serialize si deserialize pentru a scrie
//si a citi obiectul curent de clasa TrainRoute intr-un/dintr-un fisier binar
//se vor serializa toate campurile (ordinea nu conteaza)
//numele fisierului este primit drept parametru
//metodele deschid si inchid fisierele specificate

int main()
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}
