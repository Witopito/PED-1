/*
 * TNodoCalendario.h
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#ifndef TNODOCALENDARIO_H_
#define TNODOCALENDARIO_H_

#include "tcalendario.h"
using namespace std;

class TNodoCalendario
{
  private:
	TCalendario c; // Uso de LAYERING sobre la clase
	TNodoCalendario *siguiente;

  public:
	// Constructor por defecto
	TNodoCalendario ();
	// Constructor de copia
	TNodoCalendario (const TNodoCalendario &);
	// Destructor
	~ TNodoCalendario ();
	// Sobrecarga del operador asignación
	TNodoCalendario & operator=(const TNodoCalendario &);
	
	friend class TListaCalendario;


};
#endif

