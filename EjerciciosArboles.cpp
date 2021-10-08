#include "EjerciciosArboles.h"


int altura(NodoAB* raiz) {

	if (raiz == NULL) return 0;

	if (raiz->der == NULL && raiz->izq == NULL) return 1;

	int alturaDer = altura(raiz->der);
	int alturaIzq = altura(raiz->izq);
	int altura = alturaDer > alturaIzq ? alturaDer + 1 : alturaIzq + 1;

	return altura;
}

bool sonIguales(NodoAB* p, NodoAB* q) {

	if (p == NULL && q != NULL) {
		return false;
	}

	if (p != NULL && q == NULL) {
		return false;
	}

	if (p == NULL && q == NULL) {
		return true;
	}

	if (p->dato == q->dato) {
		return sonIguales(p->der, q->der) && sonIguales(p->izq, q->izq);
	}
	else {
		return false;
	}
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {

	//Solo entra en la primera iteración si el arbol es NULL
	
	if (raiz == NULL) {
		return sum == 0;
	}


	//Luego no le permito llamar a la funcion siendo raiz == NULL

	if (raiz->der == NULL && raiz->izq == NULL) {
		return sum == raiz->dato;
	}

	if (raiz->der != NULL && raiz->izq != NULL) {
		return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}

	if (raiz->der == NULL) {
		return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	}

	if (raiz->izq == NULL) {
		return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	}
}

bool esArbolBalanceado(NodoAB* raiz) {
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* enNivel(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB* arbol, int x) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoAB* invertirHastak(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB*& A) {
	// IMPLEMENTAR SOLUCION
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB*& a) {
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int sumaPorNiveles(NodoAG* raiz) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG* a, NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
