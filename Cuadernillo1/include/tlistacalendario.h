/*
 * TListaCalendario.h
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#ifndef TLISTACALENDARIO_H_
#define TTLISTACALENDARIO_H_

#include "tcalendario.h"
#include "tnodocalendario.h"
using namespace std;

class TListaCalendario 
{
  private:
	TNodoCalendario *primero;
  public:
	// Constructor por defecto
	TListaCalendario();
	// Constructor de copia
	TListaCalendario(const TListaCalendario &);
	//Destructor
	~TListaCalendario();
	// Sobrecarga del operador asignación
	TListaCalendario & operator=(const TListaCalendario &);

	// Sobrecarga del operador igualdad
	bool operator==(const TListaCalendario &);
	//Sobrecarga del operador suma
	TListaCalendario operator+ (const TListaCalendario &);
	//Sobrecarga del operador resta
	TListaCalendario operator- (const TListaCalendario &);
	// Inserta el elemento en la posición que le corresponda dentro de la lista
	bool Insertar(const TCalendario &);
	// Busca y borra el elemento
	bool Borrar(const TCalendario &);
	// Borra el elemento que ocupa la posición indicada
	//bool Borrar (TListaPos &);
	//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
	bool Borrar(int,int,int);
	// Devuelve true si la lista está vacía, false en caso contrario
	bool EsVacia();
	// Obtiene el elemento que ocupa la posición indicada
	//TCalendario Obtener(TListaPos &)
	// Devuelve true si el Calendario está en la lista.
	bool Buscar(TCalendario &);
	// Devuelve la longitud de la lista
	int Longitud();
	// Devuelve la primera posición en la lista
	//TListaPos Primera();
	// Devuelve la última posición en la lista
	//TListaPos Ultima();
	// Suma de dos sublistas en una nueva lista
	TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
	// Extraer un rango de nodos de la lista
	TListaCalendario ExtraerRango (int n1, int n2);
	//Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, TListaCalendario &);
	
	friend class TNodoCalendario;



};
#endif
