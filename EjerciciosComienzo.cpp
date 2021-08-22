#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {

	for (unsigned int i = desde; i <= hasta; i++) {

		cout << i << '*' << tablaDel << '=' << i * tablaDel;

		if (i != hasta) {
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

	int numeroEsperado = 1;
	int cantidadSecuencias = 0;

	for (int i = 0; i < largo; i++) {

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


char* invertirCase(char* str)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
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
