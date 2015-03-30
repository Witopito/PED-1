//============================================================================
// Name        : TCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tlistacalendario.h"
using namespace std;
// Constructor por defecto
TListaCalendario::TListaCalendario()
{
	this->primero = NULL;
}
// Constructor de copia
TListaCalendario::TListaCalendario(const TListaCalendario &l)
{
	this->primero = l.primero;
}
//Destructor
TListaCalendario::~TListaCalendario()
{
	this->primero = NULL;
}
// Sobrecarga del operador asignación
/*TListaCalendario& TListaCalendario:: operator=(const TListaCalendario &t)
{
	if(!(this ==t))
	{
		this->primero = t.primero;
	}
	return *this;
}*/

// Sobrecarga del operador igualdad
bool TListaCalendario::operator==(const TListaCalendario &l) // RECORREMOS HASTA QUE LOS DOS DEJEN DE APUNTAR AL SIGUIENTE
{
	bool distintos = true;
	
	TNodoCalendario* aux = this->primero;
	TNodoCalendario* auxL = l.primero;
	
	while((aux != NULL && l.primero != NULL) || distintos == true)
	{
		
		if(aux != auxL)
		{
			distintos =  false;
		}
		/*else
		{
			aux.primero =  siguiente;
			auxL.primero = auxL.siguiente;
				
		}*/
	}
	
	return distintos;
}
//Sobrecarga del operador suma
/*TListaCalendario TListaCalendario::operator+ (const TListaCalendario &);
//Sobrecarga del operador resta
TListaCalendario TListaCalendario::operator- (const TListaCalendario &);
// Inserta el elemento en la posición que le corresponda dentro de la lista
bool TListaCalendario:: Insertar(const TCalendario &);
// Busca y borra el elemento
bool TListaCalenario:: Borrar(const TCalendario &);
// Borra el elemento que ocupa la posición indicada
//bool Borrar (TListaPos &);
//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
bool TListaCalendario:: Borrar(int,int,int);
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCalendario:: EsVacia();
// Obtiene el elemento que ocupa la posición indicada
//TCalendario Obtener(TListaPos &)
// Devuelve true si el Calendario está en la lista.
bool TListaCalendario:: Buscar(TCalendario &);
// Devuelve la longitud de la lista
int TListaCalenadio:: Longitud();
// Devuelve la primera posición en la lista
//TListaPos Primera();
// Devuelve la última posición en la lista
//TListaPos Ultima();
// Suma de dos sublistas en una nueva lista
TListaCalendario TListaCalendario:: SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
// Extraer un rango de nodos de la lista
TListaCalendario TListaCalendario:: ExtraerRango (int n1, int n2);
//Sobrecarga del operador salida
friend ostream & operator<<(ostream &, TListaCalendario &);

*/
