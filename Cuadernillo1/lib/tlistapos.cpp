//============================================================================
// Name        : tlistapos.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tlistapos.h"

// Constructor por defecto
TListaPos::TListaPos();
// Constructor de copia
TListaPos::TListaPos(const TListaPos &);
// Destructor
TListaPos::~TListaPos();
// Sobrecarga del operador asignación
TListaPos & TListaPos:: operator=(const TListaPos &);
// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos &);
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos &);
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente();
// Posición vacía
bool TListaPos::EsVacia()
{
	if(pos==NULL)
		return true;
	else
		return false;
}
