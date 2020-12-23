#define NULL 0
static int variabila = 99;

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor

//1. Pentru a testa proiectul de teste unitare, scrieti corpul aceste functii
//astfel incat sa returneze corect suma dintre parametrii x si y
long suma(int x, int y)
{
	return x + y;
}

//2. Definiti un pointer la float si initializati-l cu NULL
//returnati acest pointer
float* returnare_pointer_null()
{
	float* pointer = nullptr;
	return pointer;
}


//3. Definiti un pointer la int si initializati-l cu adresa
//variabilei globale variabila, returnati acest pointer
int* returnare_pointer_adresa()
{
	int* x = &variabila;
	return x;
}

//4. Functia de mai jos primeste ca si parametru un pointer la double
//returnati valoarea aflata la acea adresa
double returnare_valoare_de_la_adresa(double* pointer)
{
	return *pointer;
}

//5. Functia de mai jos primeste ca si parametru un pointer la int
//returnati adresa urmatorului intreg utilizand operatori specifici pointerilor
int* returnare_adresa_intreg_urmator(int* pointer)
{
	return pointer + 1;
}

//6. Functia de mai jos primeste ca si parametru un pointer la long
//returnati valoarea de la adresa mai mica cu 2 * sizeof(long) fata de aceasta
//utilizand operatori specific pointerilor
long returnare_adresa_long_precedent(long* pointer)
{
	long* q = pointer - 2;
	return *q;
}

//7. Functia de mai jos primeste ca si parametrii 2 pointeri la int
//returnati numarul de intregi care incap intre cele doua adrese de memorie
//8. Asigurati-va ca rezultatul este tot timpul unul pozitiv
int returnare_diferenta_pointeri(int* pointer1, int* pointer2)
{
	if (pointer1 > pointer2) {
		return pointer1 - pointer2;
	}
	else {
		return pointer2 - pointer1;
	}
}

//9. Functia de mai jos primeste ca si parametru un pointer la pointer la int
//acesta reprezinta adresa unei adrese la care se gaseste un intreg
//returnati acel intreg
int returnare_valoare_adresa_de_adresa(int** pointer)
{
	return **pointer;
}

//10. Functia de mai jos este similara functiei de mai sus cu o mica diferenta
//all doilea parametru ne spune tipul de pointer => I pentru intreg sau L pentru long
//transformati pointerul primit ca parametru in tipul corespunzator
//si apoi returnati valoarea obtinuta la fel ca in functia de mai sus
long returneaza_valoarea_adresa_de_adresa_void(void** pointer, char tip_pointer)
{
	if (tip_pointer == 'I'){
		
		return *(int*)pointer;
	}
	else {
		return *(long*)pointer;
	}
}

int main()
{
	//Playgroud
	//Testati aici functiile dorite si folositi debugger-ul pentru eventualele probleme
}