//============================================================================
// Name        : TABBCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tabbcalendario.h"


// Constructor por defecto
TABBCalendario::TABBCalendario ()
{
	raiz = NULL;
}

// METODO AUXILIAR PARA COPIAR
void TABBCalendario:: Copiar(const TABBCalendario & t)
{
	if (t.raiz != NULL){
		TNodoABB *aux = new TNodoABB();
		aux->item = t.raiz->item;
		raiz = aux;
		(raiz->iz).Copiar(t.raiz->iz);
		(raiz->de).Copiar(t.raiz->de);
	}
	else 
		raiz = NULL;
}
// Constructor de copia
TABBCalendario:: TABBCalendario (const TABBCalendario &t)
{
	Copiar(t);
}

// Destructor
TABBCalendario:: ~TABBCalendario ()
{
	if (raiz != NULL)
	{
		delete raiz;
		raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TABBCalendario &  TABBCalendario:: operator=(const TABBCalendario &t)
{
	this->~TABBCalendario();
	Copiar(t);
	return *this;
}
// Sobrecarga del operador igualdad
bool TABBCalendario:: operator==(TABBCalendario &t)
{
	return true;
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBCalendario:: EsVacio()
{
	return (raiz==NULL);
}

void TABBCalendario:: Enraizar(TABBCalendario &iz, TCalendario c,TABBCalendario &de)
{
	TNodoABB *aux = new TNodoABB();
	aux->item = c;
	(aux->de).raiz = de.raiz;
	(aux->iz).raiz = iz.raiz;
	iz.raiz = de.raiz = NULL;
	this-> ~TABBCalendario();
	raiz = aux;
	
	
}
// Inserta el elemento en el árbol
bool TABBCalendario:: Insertar(TCalendario &t)
{
	// LLAMAR A LA FUNCION BUSCAR PARA COMPROBAR QUE ESTE EN EL ARBOL
	return true;
}
// Borra el elemento en el árbol
//bool Borrar(TCalendario &);
// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
//bool Buscar(TCalendario &);
// Devuelve el elemento en la raíz del árbol
TCalendario TABBCalendario:: Raiz()
{
	if(raiz != NULL)
		return raiz->item;
	else
		return TCalendario(); // DEVOLVER EEEEERRRRROOOOORRR
}
// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBCalendario:: Altura()
{
	int a1, a2;
	
	if(raiz != NULL)
	{
		a1=(raiz->iz).Altura();
		a2=(raiz->de).Altura();
		return (1+ (a1<a2 ? a2 : a1)); // MAX
	}
	else
		return 0;
}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
//int Nodos();
// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
//int NodosHoja();
// Devuelve el recorrido en inorden sobre un vector
//TVectorCalendario Inorden();
// Devuelve el recorrido en preorden sobre un vector
//TVectorCalendario Preorden();
// Devuelve el recorrido en postorden sobre un vector
//TVectorCalendario Postorden();
// Devuelve el recorrido en niveles
//TVectorCalendario Niveles();
// Sobrecarga del operador salida
//friend ostream & operator<<(ostream &, TABBCalendario &);
// Suma de dos ABB
//TABBCalendario operator+( TABBCalendario &);
// Resta de dos ABB
//TABBCalendario operator-( TABBCalendario &);


////////////////////////// TNODOABB //////////////////////////////////////////////

//Constructor por defecto
TNodoABB::TNodoABB ()
{
	this->item = TCalendario();

}
//Constructor copia
TNodoABB:: TNodoABB (TNodoABB &t)
{
	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;
}
//Destructor
TNodoABB:: ~TNodoABB ()
{
	this->item = TCalendario();
}
// Sobrecarga del operador asignación
TNodoABB& TNodoABB:: operator=(const TNodoABB &t)
{
	if (this != &t)
	{
		this->~TNodoABB();
		
		item = t.item;
		iz = t.iz;
		de = t.de;
	}
	
	return (*this);
}



