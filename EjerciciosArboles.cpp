#include "EjerciciosArboles.h"

//Funciones auxiliares
void imprimirArbol(NodoAB* arbol) {

	if (arbol != NULL) {
		imprimirArbol(arbol->der);
		cout << arbol->dato << " -> ";
		imprimirArbol(arbol->izq);
	}
}

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

int obtenerYBorrarMenor(NodoAB*& a) {
	if (a->izq != NULL) {
		obtenerYBorrarMenor(a->izq);
	}
	else {
		int ret = a->dato;
		NodoAB* borrar = a;
		NodoAB* temp = a->der;
		delete borrar;
		a = temp;
		return ret;
	}
}

int auxSucesor(int a, int b) {
	if (a == -1 || b == -1) {
		return max(a, b);
	}
	else {
		return min(a, b);
	}
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
	// IMPLEMENTAR SOLUCION
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
	if (A->der == NULL) {
		NodoAB* borrar = A;
		A = A->izq;
		delete borrar;
	}
	else {
		int dato = obtenerYBorrarMenor(A->der);
		A->dato = dato;
	}
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (a != NULL) {
		if (a->dato <= n) {
			return sucesor(a->der, n);
		}
		else {
			return auxSucesor(a->dato, sucesor(a->izq, n));
		}
	}
	else {
		return -1;
	}
}

int cantNodosEnNivel(NodoAB* a, int k) {
	if (a == NULL) return 0;

	if (k == 1) return 1;
	else return cantNodosEnNivel(a->izq, k - 1) + cantNodosEnNivel(a->der, k - 1);
}
int nivelMasNodos(NodoAB* raiz, int nivelHasta) {

	int nivel = 1;
	int nivelMax = 0;
	int nodosMax = 0;

	while (nivel <= nivelHasta) {

		int temp = cantNodosEnNivel(raiz, nivel);

		if (temp > nodosMax) {
			nodosMax = temp;
			nivelMax = nivel;
		}

		nivel++;
	}

	return nivelMax;
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
	// pend
	return false;
}

NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {
	// pend
	return NULL;
}

int nodosEnNivel(NodoAG* a, int k) {
	if (a != NULL) {
		if (k == 1) return 1;
		else nodosEnNivel(a->ph, k - 1);
		nodosEnNivel(a->sh, k);
	}
}

int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	/*int maxNodos = 0;
	int contador = 1;
	int nivel;

	while (arbolGeneral != NULL) {
		int aux = nodosEnNivel(arbolGeneral);
		if (aux > maxNodos) {
			nivel = contador;
			contador++;
		}
		bajoDeNivel(arbolGeneral);
	}*/
	return 0;
}
