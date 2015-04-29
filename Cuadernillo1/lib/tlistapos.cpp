//============================================================================
// Name        : tlistapos.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tlistapos.h"

// Constructor por defecto
TListaPos::TListaPos()
{
	pos = NULL;
}
// Constructor de copia
TListaPos::TListaPos(const TListaPos &tlp)
{
	if(pos!=NULL)
	{
		delete pos;
	}
	else
	{
		this->pos = tlp.pos;
	}
	
}
// Destructor
TListaPos::~TListaPos()
{
	this->pos = NULL;
}
// Sobrecarga del operador asignación
TListaPos & TListaPos:: operator=(const TListaPos &tlp)
{
	if(this != &tlp)
	{

		this->pos = tlp.pos;
	}
	
	return *this;
}
// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos &tlp)
{
	if(&tlp.pos == &this->pos)
		return true;
	else 
		return false;
}
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos &tlp)
{
	return !(tlp.pos==this->pos);
}
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente()
{
	TListaPos aux;
	aux.pos = this->pos->siguiente;
	return aux;
}
// Posición vacía
bool TListaPos::EsVacia()
{
	if(pos==NULL)
		return true;
	else
		return false;
}
