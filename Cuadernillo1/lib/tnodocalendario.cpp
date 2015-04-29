//============================================================================
// Name        : TCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tnodocalendario.h"
using namespace std;

// Constructor por defecto
TNodoCalendario::TNodoCalendario ()
{
	this->c = TCalendario();
	this->siguiente = NULL;
}

// Constructor de copia
TNodoCalendario::TNodoCalendario (const TNodoCalendario &t)
{
	if(siguiente!=NULL)
	{
		delete siguiente;
	}	
	
	c=t.c;
	
	siguiente = t.siguiente;
}
// Destructor
TNodoCalendario::~TNodoCalendario ()
{
	this->c = TCalendario();
	this->siguiente = NULL;
}
// Sobrecarga del operador asignación
TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &t)
{
	if (siguiente!=NULL)
    {
		delete siguiente;
    }
       
    if (this!=NULL)
    {
		c=t.c;
        siguiente=t.siguiente;
    }

	return *this;
}


