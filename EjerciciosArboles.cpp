#include "EjerciciosArboles.h"

//Funciones auxiliares
void auxCamino(NodoAB*& arbol, int x) {
	if (x < arbol->dato) {
		arbol = arbol->izq;
	}
	else if (x > arbol->dato) {
		arbol = arbol->der;
	}
	else {
		arbol = NULL;
	}
}

int auxSumaPorNiveles(NodoAG* raiz, int k) {
	if (raiz == NULL) return 0;

	if (k % 2) return -raiz->dato + auxSumaPorNiveles(raiz->sh, k) + auxSumaPorNiveles(raiz->ph, k + 1);
	else return raiz->dato + auxSumaPorNiveles(raiz->sh, k) + auxSumaPorNiveles(raiz->ph, k + 1);
}

//Ejercicios
int altura(NodoAB* raiz) {

	if (raiz == NULL) return 0;

	if (raiz->der == NULL && raiz->izq == NULL) return 1;

	int alturaDer = altura(raiz->der);
	int alturaIzq = altura(raiz->izq);
	int altura = alturaDer > alturaIzq ? alturaDer + 1 : alturaIzq + 1;

	return altura;
}

bool sonIguales(NodoAB* p, NodoAB* q) {

	if (p == NULL && q != NULL) return false;

	if (p != NULL && q == NULL) return false;

	if (p == NULL && q == NULL) return true;

	if (p->dato == q->dato) return sonIguales(p->der, q->der) && sonIguales(p->izq, q->izq);
	else return false;
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {

	//Solo entra en la primera iteración si el arbol es NULL

	if (raiz == NULL) return sum == 0;

	//Luego no le permito llamar a la funcion siendo raiz == NULL

	if (raiz->der == NULL && raiz->izq == NULL) return sum == raiz->dato;

	if (raiz->der != NULL && raiz->izq != NULL) return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);

	if (raiz->der == NULL) return existeCaminoConSuma(raiz->izq, sum - raiz->dato);

	if (raiz->izq == NULL) return existeCaminoConSuma(raiz->der, sum - raiz->dato);

	assert(false);
}

bool esArbolBalanceado(NodoAB* raiz) {

	if (raiz == NULL) return true;

	return abs(altura(raiz->der) - altura(raiz->izq)) <= 1 && esArbolBalanceado(raiz->der) && esArbolBalanceado(raiz->izq);
}

NodoLista* enNivel(NodoAB* a, int k) {
	/*if (a == NULL) return NULL;

	if (k == 1) {
		return new NodoLista(a->dato);
	}

	NodoLista* fin = enNivel(a->der, k-1);
	NodoLista* ppio = enNivel(a->izq, k - 1);

	if (ppio != NULL) {
		ppio->sig = fin;
		return ppio;
	} else {
		return fin;
	}*/
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB* arbol, int x) {

	NodoLista* res = new NodoLista(arbol->dato);
	NodoLista* aux = res;

	auxCamino(arbol, x);

	while (arbol != NULL) {

		aux->sig = new NodoLista(arbol->dato);
		aux = aux->sig;

		auxCamino(arbol, x);
	}

	return res;
}

NodoAB* invertirHastak(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB*& A) {
	// IMPLEMENTAR SOLUCION !!!
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	//while (a != NULL) {

	//	if (n < a->dato) {
	//		a = a->izq;
	//	}
	//	else if (n > a->dato) {
	//		a = a->der;
	//	}
	//	else {
	//		/*if (a->der != NULL && a->izq != NULL) {
	//			return min(a->der->dato, a->izq->dato);
	//		}
	//		if (a->der == NULL && a->izq == NULL) {
	//			return -1;
	//		}
	//		if (a->der == NULL) {
	//			return a->izq->dato;
	//		}
	//		if (a->izq == NULL) {
	//			return a->der->dato;
	//		}*/
	//	}
	//}

	return -1;
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION !!!
	return 0;
}

void borrarPares(NodoAB*& a) {
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	if (raiz == NULL) return 0;
	else return max(1 + alturaAG(raiz->ph), alturaAG(raiz->sh));
}

int sumaPorNiveles(NodoAG* raiz) {
	int res = auxSumaPorNiveles(raiz, 1);
	return res;
}

bool esPrefijo(NodoAG* a, NodoLista* l)
{
	// IMPLEMENTAR SOLUCION !!!
	return false;
}

NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION !!!
	return NULL;
}

int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	// IMPLEMENTAR SOLUCION !!!
	return 0;
}
