#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

string result = "";

class Comparable
{
public:
	virtual bool less(Comparable&) = 0;
};

class Lab : public Comparable
{
public :
	int number = 0;
	string name;

	bool less(Comparable& c1)
	{
		Lab l = (Lab&)c1;
		if (this->number < l.number)
		{
			return true;
		}
		return false;
	}
};

bool operator< (Comparable& param1, Comparable& param2)
{
	if (param1.less(param2) == 0)
		return true;
	else
		return false;
}

void functie(string x)
{
	result += x + " ";
}

//ATENTIE!!!
//* Sunt punctate doar solutiile originale si individuale
//* Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//* Signatura functiilor se poate modifica doar pentru a realiza supradefinirea
//* Utilizarea valorilor din teste pentru a obtine rezultate fals pozitive este considerata frauda

//1. Supradefiniti metoda less in clasa Lab
//aceasta va compara doua laboratoare pe baza numarului (number)
//(true daca primul operand are number mai mic decat al doilea)

//2. Modificati supraincarcarea operatorului <
//astfel incat acesta sa se bazeze pe faptul ca
//functia less este una virtuala

//3. Modificati functia de mai jos, astfel incat vectorul alocat dinamic
// de obiecte de tip Lab sa fie transformat intr-un vector STL
vector<Lab> ArrayToVector(Lab* labs, int nbOfLabs)
{
	vector<Lab> v;
	for (int i = 0; i < nbOfLabs; i++)
	{
		v.push_back(labs[i]);
	}
	return v;

}

//4. Modificati functia de mai jos pentru a crea si returna un vector de obiecte
//de tip Lab ce au denumirile preluate din lista STL primita drept parametru
//campul number va fi initializat crescator incepand cu 1
//numarul de elemente al vectorului va fi egal cu numarul de elemente al listei
Lab* ListToLabArray(list<string> lista)
{
	Lab* labs = new Lab[lista.size()+1];
	int k = 0, i = 1;
	list<string>::iterator it;
	for (it = lista.begin(); it!=lista.end() ; it++)
	{
		labs[k].number = i;
		labs[k].name = *it;
		k++;
		i++;
	}
	it = --lista.end();
	labs[k].number = i;
	labs[k].name = *it;
	return labs;
	
}

//5. Modificati functia de mai jos astfel incat sa returneze un set
//ce contine drept elemente numele celor 3 obiecte primite drept parametri
set<string> ParametersToSet(Lab lab1, Lab lab2, Lab lab3)
{
	set<string> s;
	s.insert(lab1.name);
	s.insert(lab2.name);
	s.insert(lab3.name);
	return s;
}

//6. Modificati metoda de mai jos astfel incat sa returnati un map
//ce contine drept chei numele laboratoarelor si drept valori
//numarele aferente acelor laboratoare
map<string, int> ArrayToMap(Lab* labs, int nbOfLabs)
{
	map<string, int> m;
	for (int i = 0; i < nbOfLabs; i++)
	{
		m.insert(pair<string, int>(labs[i].name, labs[i].number));
	}
	return m;
}

//7. Functia de mai jos primeste drept parametru un vector STL cu nume de laboratoare
//returnati un iterator catre elementul corespunzator celui de-al doilea parametru
//daca acel element nu exista returnati un vector.end()
vector<string>::iterator FindInVector(vector<string>& names, const char* name)
{
	for (vector <string>::iterator it = names.begin(); it != names.end(); it++)
	{
		if (*it == name)
			return it;
	}
	return names.end();

}

//8. Functia de mai jos este asemanatoare cu cea de mai sus
//doar ca returneaza un reverse_iterator catre elementul dorit
vector<string>::reverse_iterator FindReverseInVector(vector<string>& names, const char* name)
{
	for (vector<string>::reverse_iterator it = names.rbegin(); it != names.rend(); ++it)
	{
		if (*it == name)
			return it;
	}
	return names.rend();
}

//9. In interiorul functiei de mai jos utilizati
//algoritmul for_each pentru a apela functia functie
//pentru fiecare element al obiectului de tip deque
void ForEachDeque(deque<string> d)
{
	for_each(d.begin(), d.end(), functie);
}

//10. Functia de mai jos primeste drept parametru un map cu perechi de tip
//cheie-valoare de tipul int-string
//returnati o stiva ce adapteaza vector ce contine valorile pentru cheile impare
stack<string, vector<string>> MapToStack(map<int, string> m)
{
	stack<string, vector<string>> s;
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->first % 2 == 1)
		{
			s.push(it->second);
		}
	}
	return s;
}

int main()
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}