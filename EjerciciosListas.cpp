#include "EjerciciosListas.h"

// ----- Funciones auxiliares -----

void mostrarLista(NodoLista* l) {
	cout << endl;
	while (l != NULL) {
		cout << l->dato << " -> ";
		l = l->sig;
	}
	cout << "NULL" << endl;
}

void agregarPpio(NodoLista*& l, int dato) {
	NodoLista* aux = l;
	l = new NodoLista(dato);
	l->sig = aux;
}

void agregarFinal(NodoLista*& l, int dato) {
	if (l == NULL) {
		agregarPpio(l, dato);
		return;
	}

	NodoLista* aux = l;

	while (aux->sig != NULL) {
		aux = aux->sig;
	}

	aux->sig = new NodoLista(dato);
}


void borrarFinal(NodoLista*& l) {
	if (l == NULL) return;

	if (l->sig == NULL) {
		delete l;
		l = NULL;
		return;
	}

	borrarFinal(l->sig);
}

NodoLista* copiarLista(NodoLista* l) {
	if (l == NULL) return NULL;
	else {
		NodoLista* copia = new NodoLista(l->dato);
		copia->sig = copiarLista(l->sig);
		return copia;
	}
}

void insertarOrdenado(NodoLista*& l, int dato) {
	
	if (l == NULL) {
		agregarPpio(l, dato);
	} else {
		if (dato <= l->dato) {
			agregarPpio(l, dato);
		} else {
			insertarOrdenado(l->sig, dato);
		}
	}
}

// ----- Ejercicios -----

NodoLista* invertirParcial(NodoLista* l) 
{
	NodoLista* copia = copiarLista(l);

	borrarFinal(copia);

	if (copia != NULL) {
	
		NodoLista* invertida = new NodoLista(copia->dato);
	
		while (copia->sig != NULL) {
			copia = copia->sig;
			agregarPpio(invertida, copia->dato);
		}

		return invertida;
	
	} else {
		return NULL;
	}	
}

void eliminarNesimoDesdeElFinal(NodoLista* &lista, int &n) 
{
	//if (n < 1) {
	//	return;
	//}
	//else {
	//	
	//	if (n > 0 && lista != NULL) {
	//		eliminarNesimoDesdeElFinal(lista->sig, n-1);
	//	}
	//	else {
	//		return;
	//	}
	//}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	NodoLista* listaRet = NULL;

	while (l != NULL) {
		insertarOrdenado(listaRet, l->dato);
		l = l->sig;
	}

	return listaRet;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
