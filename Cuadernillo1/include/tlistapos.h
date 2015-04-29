/*
 * TListaPos.h
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#ifndef TLISTAPOS_H_
#define TLISTAPOS_H_

#include "tcalendario.h"
#include "tnodocalendario.h"

using namespace std;

class TListaPos
{
	friend class TNodoCalendario;
	friend class TListaCalendario;
	private:
		// Para implementar la POSICIÓN a NODO de la LISTA de TCalendario
		TNodoCalendario *pos;
	public:
		// Constructor por defecto
		TListaPos();
		// Constructor de copia
		TListaPos(const TListaPos &);
		// Destructor
		~TListaPos();
		// Sobrecarga del operador asignación
		TListaPos & operator=(const TListaPos &);
		// Sobrecarga del operador igualdad
		bool operator==(const TListaPos &);
		// Sobrecarga del operador desigualdad
		bool operator!=(const TListaPos &);
		// Devuelve la posición siguiente
		TListaPos Siguiente();
		// Posición vacía
		bool EsVacia();
		
		

};
#endif
