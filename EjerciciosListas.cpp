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

NodoLista* copiarLista(NodoLista* l) {

	return NULL;
}
// ----- Ejercicios -----

NodoLista* invertirParcial(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
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
