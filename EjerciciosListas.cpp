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

void exorAux(NodoLista*& l1, NodoLista*& l2, NodoLista*& res) {}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	/*NodoLista* auxLista = l;
	bool elimineEnLaAnterior = false;
	bool casoBorde = true;

	mostrarLista(l);

	while (auxLista != NULL) {

		NodoLista* temp = auxLista->sig;
	
		if (temp != NULL && auxLista->dato == temp->dato) {
			delete auxLista;
			elimineEnLaAnterior = true;

			if (casoBorde) l = temp;
		}
		else {
			if (elimineEnLaAnterior) {
				delete auxLista;
				elimineEnLaAnterior = false;

				if (casoBorde) l = temp;
			}
			else {
				casoBorde = false;
			}
		}

		auxLista = temp;
	}*/
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	NodoLista* lista = l;
	NodoLista* sec = secuencia;
	
	unsigned int pos = 0;
	unsigned int counter = 0;

	while (lista != NULL && sec != NULL) {

		if (lista->dato == sec->dato) {
			sec = sec->sig;
		}
		else {

			sec = secuencia;
			
			if (pos != counter && lista->dato == sec->dato) {
				pos = counter;
				sec = sec->sig;
			}
			else {
				pos = counter + 1;

			}
		
		}

		counter++;
		lista = lista->sig;
	}

	if (sec == NULL) {
		sec = secuencia;
		lista = l;

		for (int i = 0; i < pos; i++) {
			lista = lista->sig;
		}

		while (sec != NULL) {

			if (pos != 0) {
				NodoLista* temp = lista->sig;
				delete lista;
				lista = temp;
				cout << endl << "asd";
			}
			else {
				borrarPpio(lista);
			}

			sec = sec->sig;
		}
		
		
	}
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
