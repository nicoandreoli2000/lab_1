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
	}
	else {
		agregarFinal(l->sig, dato);
	}
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
	if (l == NULL) {
		return NULL;
	} else {
		NodoLista* copia = new NodoLista(l->dato);
		copia->sig = copiarLista(l->sig);
		return copia;
	}
}

void insertarOrdenado(NodoLista*& l, int dato) {
	
	if (l == NULL || dato <= l->dato) {
		agregarPpio(l, dato);
	} else {
		insertarOrdenado(l->sig, dato);
	}
}

// ----- Ejercicios -----

NodoLista* invertirParcial(NodoLista* l) 
{
	NodoLista* copia = copiarLista(l);
	borrarFinal(copia);

	NodoLista* invertida = NULL;

	while (copia != NULL) {
		agregarPpio(invertida, copia->dato);
		copia = copia->sig;
	}
	
	return invertida;
}

void eliminarNesimoDesdeElFinal(NodoLista* &lista, int &n) 
{
	if (n < 1) {
		return;
	}
	else {
		
		if (lista != NULL) {
			eliminarNesimoDesdeElFinal(lista->sig, n);
			
			if (n == 1) {
				NodoLista* aux = lista->sig;
				delete lista;
				lista = aux;
			}

			n--;
		}
	}
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
	NodoLista* rec = l;

	NodoLista* min;
	NodoLista* minRec;

	while (rec != NULL) {

		min = rec;
		minRec = rec;

		while (minRec->sig != NULL) {

			minRec = minRec->sig;

			if (minRec->dato < min->dato) {
				int aux = minRec->dato;
				minRec->dato = min->dato;
				min->dato = aux;
			}
		}

		rec = rec->sig;
	}	
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* res = NULL;

	while (l1 != NULL || l2 != NULL) {

		if (l1 != NULL && l2 != NULL) {

			if (l1->dato < l2->dato) {
				agregarFinal(res,l1->dato);
				l1 = l1->sig;
			}
			else {
				agregarFinal(res, l2->dato);
				l2 = l2->sig;
			}
		}
		else if (l2 != NULL) {
			agregarFinal(res, l2->dato);
			l2 = l2->sig;
		
		}
		else {
			agregarFinal(res, l1->dato);
			l1 = l1->sig;
		}
	}

	return res;
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
