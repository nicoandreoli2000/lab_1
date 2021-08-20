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
	if (d != 0) {

		bool signoNegativo = n * d < 0 ? true : false;

		n = abs(n);
		d = abs(d);

		int minValAbs = n > d ? n : d;

		for (minValAbs; minValAbs > 1; minValAbs--) {
			if (n % minValAbs == 0 && d % minValAbs == 0) {
				n = n / minValAbs;
				d = d / minValAbs;
			}
		}
		
		if (signoNegativo) {
			cout << '-';
		}

		cout << n << '/' << d;
	}
	else {
		cout << n << '/' << d;
	}
}

int ocurrencias123Repetidos(int* vector, int largo) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

int maximoNumero(unsigned int n) {
	// IMPLEMENTAR SOLUCION
    return 0;
}

void ordenarVecInt(int *vec, int largoVec) {
	// IMPLEMENTAR SOLUCION
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
