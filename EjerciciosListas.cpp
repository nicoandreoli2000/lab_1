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

int obtenerLargo(NodoLista* l) {
	int count = 0;

	while (l != NULL) {
		count++;
		l = l->sig;
	}

	return count;
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

void agregarFinalOrdenUno(NodoLista*& l, NodoLista*& ptrFin, int dato) {
	if (l == NULL) {
		l = new NodoLista(dato);
		ptrFin = l;
		return;
	}
	ptrFin->sig = new NodoLista(dato);
	ptrFin = ptrFin->sig;
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

void borrarPpio(NodoLista*& l) {
	if (l == NULL) return;

	NodoLista* temp = l->sig;
	delete l;
	l = temp;
}

NodoLista* copiarLista(NodoLista* l) {
	if (l == NULL) {
		return NULL;
	}
	else {
		NodoLista* copia = new NodoLista(l->dato);
		copia->sig = copiarLista(l->sig);
		return copia;
	}
}

void insertarOrdenado(NodoLista*& l, int dato) {

	if (l == NULL || dato <= l->dato) {
		agregarPpio(l, dato);
	}
	else {
		insertarOrdenado(l->sig, dato);
	}
}

void eliminarDato(NodoLista*& l, int dato) {
	if (l == NULL) return;

	if (l->dato == dato) {
		borrarPpio(l);
		eliminarDato(l, dato);
	}
}

bool haySecuenciaAlInicio(NodoLista* l, NodoLista* sec) {

	while (l != NULL && sec != NULL) {
		if (l->dato == sec->dato) {
			l = l->sig;
			sec = sec->sig;
		}
		else {
			l = NULL;
		}
	}

	return sec == NULL;
}

// ----- Ejercicios -----

NodoLista* invertirParcial(NodoLista* l)
{
	NodoLista* rec = l;
	NodoLista* invertida = NULL;

	while (rec->sig != NULL) {
		agregarPpio(invertida, rec->dato);
		rec = rec->sig;
	}


	return invertida;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{
	if (n < 1) {
		return;
	}
	else {

		if (lista != NULL) {
			eliminarNesimoDesdeElFinal(lista->sig, n);

			if (n == 1) {
				borrarPpio(lista);
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
	NodoLista* fin = NULL;

	while (l1 != NULL || l2 != NULL) {

		if (l1 != NULL && l2 != NULL) {

			if (l1->dato < l2->dato) {
				agregarFinalOrdenUno(res, fin, l1->dato);
				l1 = l1->sig;
			}
			else {
				agregarFinalOrdenUno(res, fin, l2->dato);
				l2 = l2->sig;
			}
		}
		else if (l2 != NULL) {
			agregarFinalOrdenUno(res, fin, l2->dato);
			l2 = l2->sig;

		}
		else {
			agregarFinalOrdenUno(res, fin, l1->dato);
			l1 = l1->sig;
		}
	}

	return res;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	if (l1 == NULL && l2 == NULL) return NULL;

	NodoLista* res;

	if (l1 != NULL && l2 != NULL) {

		if (l1->dato < l2->dato) {
			res = new NodoLista(l1->dato);
			res->sig = intercalarRec(l1->sig, l2);
			return res;
		}
		else {
			res = new NodoLista(l2->dato);
			res->sig = intercalarRec(l1, l2->sig);
			return res;
		}
	}
	else if (l2 != NULL) {
		res = new NodoLista(l2->dato);
		res->sig = intercalarRec(l1, l2->sig);
		return res;
	}
	else {
		res = new NodoLista(l1->dato);
		res->sig = intercalarRec(l1->sig, l2);
		return res;
	}
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	NodoLista* res = NULL;
	NodoLista* fin = NULL;
	int aux = INT_MIN;

	while (l1 != NULL || l2 != NULL) {

		if (l1 != NULL && l2 != NULL) {

			if (l1->dato < l2->dato) {
				if (aux != l1->dato) {
					agregarFinalOrdenUno(res, fin, l1->dato);
					aux = l1->dato;
				}
				l1 = l1->sig;

			}
			else if (l1->dato > l2->dato) {
				if (aux != l2->dato) {
					agregarFinalOrdenUno(res, fin, l2->dato);
					aux = l2->dato;
				}
				l2 = l2->sig;
			}
			else {
				aux = l1->dato;
				l2 = l2->sig;
				l1 = l1->sig;
			}
		}
		else if (l2 != NULL) {
			if (aux != l2->dato) {
				agregarFinalOrdenUno(res, fin, l2->dato);
				aux = l2->dato;
			}
			l2 = l2->sig;
		}
		else {
			if (aux != l1->dato) {
				agregarFinalOrdenUno(res, fin, l1->dato);
				aux = l1->dato;
			}
			l1 = l1->sig;
		}
	}

	return res;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l)
{
	if (l == NULL) return;

	if (l->sig != NULL) {

		if (l->dato == l->sig->dato) {
			eliminarDato(l, l->dato);
			eliminarDuplicadosListaOrdenadaDos(l);
		}
		else {
			eliminarDuplicadosListaOrdenadaDos(l->sig);
		}

	}
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia)
{
	if (l == NULL) return;

	if (haySecuenciaAlInicio(l, secuencia)) {
		while (secuencia != NULL) {
			borrarPpio(l);
			secuencia = secuencia->sig;
		}
	}
	else {
		eliminarSecuencia(l->sig, secuencia);
	}
}



void moverNodo(NodoLista*& lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
