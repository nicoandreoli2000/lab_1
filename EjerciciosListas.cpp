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

void intercalarAux(NodoLista*& l1, NodoLista*& l2, NodoLista*& res) {

	if (l1 == NULL && l2 == NULL) return;

	if (l1 != NULL && l2 != NULL) {

		if (l1->dato < l2->dato) {
			intercalarAux(l1->sig, l2, res);
			agregarPpio(res, l1->dato);
		}
		else {
			intercalarAux(l1, l2->sig, res);
			agregarPpio(res, l2->dato);
		}
	}
	else if (l2 != NULL) {
		intercalarAux(l1, l2->sig, res);
		agregarPpio(res, l2->dato);
	}
	else {
		intercalarAux(l1->sig, l2, res);
		agregarPpio(res, l1->dato);
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
	NodoLista* res = NULL;

	intercalarAux(l1, l2, res);

	return res;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	NodoLista* res = NULL;
	int aux = INT_MIN;

	while (l1 != NULL || l2 != NULL) {

		if (l1 != NULL && l2 != NULL) {

			if (l1->dato < l2->dato) {
				if (aux != l1->dato) {
					agregarFinal(res, l1->dato);
					aux = l1->dato;
				}
				l1 = l1->sig;

			} else if (l1->dato > l2->dato) {
				if (aux != l2->dato) {
					agregarFinal(res, l2->dato);
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
				agregarFinal(res, l2->dato);
				aux = l2->dato;
			}
			l2 = l2->sig;
		}
		else {
			if (aux != l1->dato) {
				agregarFinal(res, l1->dato);
				aux = l1->dato;
			}
			l1 = l1->sig;
		}
	}

	return res;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecAux(NodoLista* l, NodoLista* sec, int aux) {

}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	NodoLista* rec = l;
	NodoLista* sec = secuencia;
	NodoLista* aux = NULL;

	while (rec != NULL && sec != NULL) {

		if (rec->dato == sec->dato) {
			sec = sec->sig;
		}
		else {
			aux = rec;
			sec = secuencia;
		}

		rec = rec->sig;
	}

	if (sec == NULL) {
		sec = secuencia;
		if (aux == NULL) {
			while (sec != NULL) {
				borrarPpio(l);
				sec = sec->sig;
			}
		}
		else {
			while (sec != NULL) {
				rec = aux->sig;
				aux->sig = rec->sig;
				delete rec;
				sec = sec->sig;
			}
			
		}
		
	}
}



void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
