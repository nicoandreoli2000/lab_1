#include "EjerciciosComienzo.h"

// ----- Funciones auxiliares -----

unsigned int obtenerLargo(char* str) {
	unsigned int largo = 0;

	while (str[largo] != '\0') {
		largo++;
	}

	return largo;
}

char* copiarString(char* str) {
	unsigned int largo = obtenerLargo(str);
	char* copia = new char[largo + 1];
	copia[largo] = '\0';

	for (int i = 0; i < largo; i++) {
		copia[i] = str[i];
	}

	return copia;
}

// ----- Ejercicios -----

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {

	for (desde; desde <= hasta; desde++) {

		cout << desde << '*' << tablaDel << '=' << desde * tablaDel;

		if (desde != hasta) {
			cout << ';';
		}
	}
}

void simplificar(int n, int d) {

	if (n* d < 0) {
		cout << '-';
	}

	n = abs(n);
	d = abs(d);

	int minValAbs = n > d ? n : d;

	for (minValAbs; minValAbs > 1; minValAbs--) {
		if (n % minValAbs == 0 && d % minValAbs == 0) {
			n = n / minValAbs;
			d = d / minValAbs;
		}
	}

	cout << n << '/' << d;
}

int ocurrencias123Repetidos(int* vector, int largo) {

	unsigned int numeroEsperado = 1;
	unsigned int cantidadSecuencias = 0;

	for (unsigned int i = 0; i < largo; i++) {

		if (vector[i] == numeroEsperado) {
			numeroEsperado += 1;
		}
		else if (vector[i] != numeroEsperado - 1) {
			numeroEsperado = 1;
		}

		if (numeroEsperado == 4) {
			numeroEsperado = 1;
			cantidadSecuencias += 1;
		}
	}

	return cantidadSecuencias;
}

int maximoNumero(unsigned int n) {
	int max = INT_MIN;
	int aux;
	
	for (int i = 0; i < n; i++) {

		cin >> aux;
		
		if (aux > max) {
			max = aux;
		}
	}

    return max;
}

void ordenarVecInt(int *vec, int largoVec) {
	int aux;

	for (int i = 0; i < largoVec - 1; i++) {
		
		for (int j = i + 1; j < largoVec; j++) {

			if (vec[j] < vec[i]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

char* invertirCase(char* str) {

	char* copia = copiarString(str);

	unsigned int largo = obtenerLargo(str);
	unsigned int dif = 'a' - 'A';

	for (int i = 0; i < largo; i++) {

		if (copia[i] >= 'A' && copia[i] <= 'Z') {
			copia[i] += dif;
		}
		else if (copia[i] >= 'a' && copia[i] <= 'z') {
			copia[i] -= dif;
		}
	}

	return copia;
}

//NO
int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

//NO
unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

//NO
char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){

	unsigned int p1 = 0;
	unsigned int p2 = 0;
	unsigned int largo = l1 + l2;

	int* vec = largo != 0 ? new int[largo] : NULL;

	while (p1 + p2 < largo) {

		if (((p1 < l1) && (p2 < l2) && (v1[p1] <= v2[p2])) || (p2 == l2)) {
			vec[p1 + p2] = v1[p1];
			p1++;
		}
		else {
			vec[p1 + p2] = v2[p2];
			p2++;
		}
		
	}

	return vec;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
