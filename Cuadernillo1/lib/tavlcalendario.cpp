//============================================================================
// Name        : TABBCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tavlcalendario.h"

// Constructor por defecto
TAVLCalendario::TAVLCalendario ()
{
	raiz = NULL;
}

// METODO AUXILIAR PARA COPIAR
void TAVLCalendario:: Copiar(const TAVLCalendario &t)
{
	if (t.raiz != NULL){
		TNodoAVL *aux = new TNodoAVL();
		aux->item = t.raiz->item;
		aux->fe = t.raiz->fe;
		raiz = aux;
		(raiz->iz).Copiar(t.raiz->iz);
		(raiz->de).Copiar(t.raiz->de);
	}
	else 
		raiz = NULL;
}
// Constructor de copia
TAVLCalendario:: TAVLCalendario (const TAVLCalendario &t)
{
	Copiar(t);
}

// Destructor
TAVLCalendario:: ~TAVLCalendario ()
{
	if (raiz != NULL)
	{
		delete raiz;
		raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TAVLCalendario &  TAVLCalendario:: operator=(const TAVLCalendario &t)
{
	this->~TAVLCalendario();
	Copiar(t);
	return *this;
}


// Sobrecarga del operador igualdad
bool TAVLCalendario:: operator==(const TAVLCalendario &t)
{
	if(raiz==NULL && t.raiz==NULL)
		return true;
	if(Nodos() != t.Nodos())
		return false;
	return true;
}

bool TAVLCalendario:: operator!=(const TAVLCalendario &t)
{
	return false;
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLCalendario:: EsVacio()
{
	return (raiz==NULL);
}

void TAVLCalendario::rotacionII(TAVLCalendario &tavl)
{
	TNodoAVL *aux = new TNodoAVL();
	
	aux = tavl.raiz;
		
	tavl.raiz = aux;
	
	tavl.raiz->de = aux;
	tavl.raiz->iz = aux->iz->iz;
	tavl.raiz->de->iz = aux->iz->de;
}

void TAVLCalendario::rotacionDD(TAVLCalendario &tavl)
{
	TNodoAVL *aux = new TNodoAVL();
	
	aux = tavl.raiz;
	
	tavl.raiz->de = aux->de->de;
	tavl.raiz = aux->de;
	tavl.raiz->iz = aux;
	tavl.raiz->iz->de = aux->de->iz;
}


void TAVLCalendario::rotacionID(TAVLCalendario &tavl)
{
	TNodoAVL *aux = new TNodoAVL();
	
	aux = tavl.raiz;
	
	tavl.raiz = aux->iz->de;
	tavl.raiz->de = aux;
	tavl.raiz->de->iz = aux->iz->de->de;
	tavl.raiz->iz->de = aux->iz->de->iz;
	
}

void TAVLCalendario::rotacionDI(TAVLCalendario &tavl)
{
	TNodoAVL *aux = new TNodoAVL();
	
	aux = tavl.raiz;
	
	raiz->iz = aux;
	raiz->iz->de = aux->de->iz->iz;
	raiz->de->iz = aux->de->iz->de;
	tavl.raiz = aux->de->iz;
}


// Inserta el elemento en el árbol
bool TAVLCalendario:: Insertar(TCalendario &t)
{
	if(this->Buscar(t)) // COMPROBAMOS SI EXISTE O NO
	{
		//cout << cerr << "ERROR: El elemento ya existe"  <<endl;
		return false;
	}
	else
	{
		this->InsertarAux(t);
		return true;
	}
}

bool TAVLCalendario:: InsertarAux(TCalendario &t)
{
	
	if(raiz==NULL)
	{
		TNodoAVL *aux = new TNodoAVL();
		aux->item = t;
		raiz = aux;
		// equilibrado
		return true;
	}
    else if(t < raiz->item)
		(raiz->iz).InsertarAux(t);
    else if(t > raiz->item)
		(raiz->de).InsertarAux(t);
	else
		return false;
}

void TAVLCalendario ::
/*
// Borra el elemento en el árbol
bool TACalendario:: Borrar(TCalendario &t)
{
	if(raiz==NULL)
		return false;
	else if(raiz->item == t)
	{
		if(raiz->de.EsVacio() || raiz->iz.EsVacio()) // EL NODO TIENE UN HIJO O NINGUNO
		{
			if(raiz->de.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux = raiz->iz.raiz;
				raiz = aux;
			}
			else if(raiz->iz.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux = raiz->de.raiz;
				raiz = aux;
			}
			else // NO TIENE HIJOS
				raiz == NULL;
		}	
		else // TIENE 2 HIJOS 
		{ 
			TNodoABB *aux = new TNodoABB(raiz->iz.Maximo()); // MAXIMO DEL ARBOL IZQUIERDO
			
			aux->de = raiz->de; // COPIAMOS DERECHA
			aux->iz = raiz->iz; // COPIAMOS IZQUIERDA
			raiz = aux; // CAMBIAMOS POR LA RAIZ A BORRAR
			aux == NULL; // ELIMINAMOS PUNTERO
		}
		
		return true;
	}		
	else if(t<raiz->item)
		return (raiz->iz).Borrar(t);
	else if(t>raiz->item)
		return (raiz->de).Borrar(t);
}

TNodoABB TABBCalendario:: Maximo()
{
	TNodoABB *aux = new TNodoABB();
	if(EsVacio())
	{
		return *aux;
	}
	if(raiz->de.EsVacio())
	{
		aux=raiz;
		Borrar(aux->item); // VOLVEMOS A LLAMAR  BORRAR PARA ELIMINAR EL NODO 
		return *aux;
	}
	else
	{
		aux=new TNodoABB(raiz->de.Maximo());
		
		return *aux;
	}

}*/
// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TAVLCalendario::Buscar(TCalendario &c)
{
	if(raiz==NULL)
		return false;
	else if(c<raiz->item)
		return (raiz->iz).Buscar(c);
	else if(c>raiz->item)
		return (raiz->de).Buscar(c);
	else
		return true;
	
}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLCalendario:: Altura() const
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
int TAVLCalendario:: Nodos() const
{
	if(raiz!=NULL)
	{
		return (1 + (raiz->iz).Nodos() + (raiz->de).Nodos());
	}
	else
		return 0;
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCalendario:: NodosHoja() const 
{
	if(raiz == NULL)
		return 0;
	else if((raiz->iz).EsVacio() && raiz->de.EsVacio())
		return 1;
	else
		return ((raiz->iz).NodosHoja() + (raiz->de).NodosHoja());
		
}

// Devuelve el recorrido en inorden
TVectorCalendario TAVLCalendario::Inorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	InordenAux(v, posicion);

	return v;
}
// Devuelve el recorrido en inorden sobre un vector
void TAVLCalendario:: InordenAux(const TVectorCalendario& v,int& posicion) const
{
	if(raiz != NULL)
	{
		(raiz->iz).InordenAux(v,posicion);
		v[posicion] = raiz->item;
		posicion++;
		(raiz->de).InordenAux(v,posicion);
		
	}
}
// Devuelve el recorrido en preorden sobre un vector
TVectorCalendario TAVLCalendario:: Preorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

void TAVLCalendario:: PreordenAux(const TVectorCalendario& v,int& posicion) const
{
	if(raiz != NULL)
	{
		int nuevaPos = posicion;
		v[posicion] = raiz->item;
		posicion++;
		(raiz->iz).PreordenAux(v,posicion);
		(raiz->de).PreordenAux(v,posicion);
	}
}

// Devuelve el recorrido en postorden sobre un vector
TVectorCalendario TAVLCalendario:: Postorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

void TAVLCalendario:: PostordenAux(const TVectorCalendario& v, int& posicion)const
{
	if(raiz != NULL)
	{
		int nuevaPos = posicion;
		(raiz->iz).PostordenAux(v,posicion);
		(raiz->de).PostordenAux(v,posicion);
		v[posicion] = raiz->item;
		posicion++;
	}
}

// Devuelve el elemento en la raíz del árbol
TCalendario TAVLCalendario:: Raiz()
{
	if(raiz != NULL)
		return raiz->item;
	else
	{
		// cout << cerr << "ERROR: No existe ninǵun dato en el árbol" <<endl;
		return TCalendario(); 
	}
}


// Sobrecarga del operador salida
ostream & operator<<(ostream &s,TAVLCalendario & tavl)
{
	TVectorCalendario v(tavl.Nodos());
	v = tavl.Inorden();
	s << v;
	return s;
}



////////////////////////// TNODOABB //////////////////////////////////////////////

//Constructor por defecto
TNodoAVL::TNodoAVL ()
{
	this->item = TCalendario();

}
//Constructor copia
TNodoAVL:: TNodoAVL (const TNodoAVL &t)
{
	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;
	this->fe = t.fe;
}
//Destructor
TNodoAVL:: ~TNodoAVL ()
{
	this->item = TCalendario();
}
// Sobrecarga del operador asignación
TNodoAVL& TNodoAVL:: operator=(const TNodoAVL &t)
{
	if (this != &t)
	{
		this->~TNodoAVL();
		
		item = t.item;
		iz = t.iz;
		de = t.de;
		fe = t.fe;
	}
	
	return (*this);
}



