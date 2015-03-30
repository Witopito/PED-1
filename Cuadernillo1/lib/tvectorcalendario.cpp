/*
 * TVectorCalendario.cpp
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#include "tvectorcalendario.h"

// Constructor por defecto
TVectorCalendario::TVectorCalendario()
{
	this->tamano = 0;
	this->c = NULL;
	this->error = TCalendario();
}

// Constructor a partir de un tamaño
TVectorCalendario::TVectorCalendario(int n)
{
	if(n<0)
	{
		this->tamano = 0;
		this->c = NULL;
	}
	else
	{
		this->tamano = n;
		this->c=new TCalendario[n];
	}

	this->error = TCalendario();
}
// Constructor de copia
TVectorCalendario::TVectorCalendario(const TVectorCalendario &TV)
{
	this->tamano=TV.tamano;
	this->c=TV.c;
	this->error=TV.error;
}
// Destructor
TVectorCalendario::~TVectorCalendario()
{
	this->tamano = 0;
	delete []c;
	this->c = NULL;
}
// Sobrecarga del operador asignación
TVectorCalendario & TVectorCalendario::operator=(const TVectorCalendario &TV)
{
	if (this != &TV)
	{
		if(TV.tamano>0) // NO ES VACIO
		{
			this->~TVectorCalendario();
			this->tamano=TV.tamano;
			this->c= new TCalendario[TV.tamano]; // REDIMENSIONAMOS
			this->error = TCalendario();

			for(int i=0;i<TV.tamano;i++) // COPIAMOS
			{
				this->c[i] = TV.c[i];
			}
		}
		else
		{
			this->tamano = 0;
			this->c = NULL;
			this->error = TCalendario();
		}
	}
	return *this;
}
// Sobrecarga del operador igualdad
bool TVectorCalendario::operator==(const TVectorCalendario &TV)
{
	bool iguales = true;
	// COMPROBAMOS DIMENSIONES
	if(this->tamano != TV.tamano)
		iguales = false;
	else
	{
		for(int j=0;j<tamano;j++)
		{
			if(TV.c[j]==c[j])
			{
				iguales = false;
			}
		}
	}

	return iguales;
}
// Sobrecarga del operador desigualdad
bool TVectorCalendario::operator!=(const TVectorCalendario &TV)
{
	return !(*this == TV);
}

// Sobrecarga del operador corchete (parte IZQUIERDA)
TCalendario & TVectorCalendario::operator[](int n)
{
	TCalendario *dato = NULL;

	if(n>0 && n<=tamano)
	{
		dato = &c[n-1];
	}
	else
	{
		dato = &error;
	}

	return *dato;

}
// Sobrecarga del operador corchete (parte DERECHA)
TCalendario TVectorCalendario::operator[](int indice) const
{
	if(indice>0 && indice<=tamano)
	{
		return c[indice-1];
	}
	else
	{
		return error;
	}
}
// Tamaño del vector (posiciones TOTALES)
int TVectorCalendario::Tamano(){return this->tamano;}

// Cantidad de posiciones OCUPADAS (no vacías) en el vector
int TVectorCalendario::Ocupadas()
{
	int contador = 0;

	for(int i=0;i<tamano;i++)
	{
		if(!(c[i].EsVacio()))
			contador++;

	}
	return contador;
}

// Devuelve true si existe el calendario en el vector
bool TVectorCalendario::ExisteCal(TCalendario &TC)
{
	bool existe = false;

	for(int i=0;i<tamano;i++)
	{
		if(c[i]==TC)
			existe = true;

	}

	return existe;
}

// Mostrar por pantalla mensajes de TCalendario en el vector, de fecha IGUAL O POSTERIOR a la pasada
void TVectorCalendario::MostrarMensajes(int dia,int mes,int anyo)
{
	TCalendario t(dia,mes,anyo,"");
	for(int i=0;i<tamano;i++)
	{
		if(t<c[i] || t==c[i])
			cout << c[i].Mensaje() <<endl;

	}


}
		
// REDIMENSIONAR el vectorde TCalendario
bool TVectorCalendario::Redimensionar(int nTam)
{
	if(nTam<=0 || nTam == this->tamano) // IGUAL TAMAÑO
		return false;
	if(nTam>0 && nTam<this->tamano) // MENOR QUe EL ORIGINAL
	{
		
		TVectorCalendario aux(nTam);

		// COPIAMOS A AUXILIAR
		for(int i=0;i<nTam;i++)
		{
			aux[i] = c[i];
		}
		// BORRAMOS
		delete[] this->c;

		// CREAMOS DE NUEVO
		this->c = new TCalendario[nTam];

		*this=aux;
		(aux).~TVectorCalendario();	

	}
	if(nTam>0 && nTam>this->tamano) // MAYOR QUE EL TAMANO ORIGINAL
	{
		// AUXILIAR
		TVectorCalendario aux(nTam);

		// COPIAMOS A AUXILIAR
		for(int i=0;i<nTam;i++)
		{
			aux[i] = c[i];
		}
		// BORRAMOS
		delete[] this->c;

		// CREAMOS DE NUEVO
		this->c = new TCalendario[nTam];

		for(int i=0;i<nTam;i++)
		{
			if(i>tamano)
				c[i] = TCalendario(); 
			else
				c[i] = aux[i];
		}
		
		*this=aux;
		(aux).~TVectorCalendario();	
	}
	return true;
}

ostream & operator<<(ostream &s, TVectorCalendario &TV)
{
	s <<"[";
	for(int i=1;i<=TV.Ocupadas();i++)
	{
		s << "(" << i << ") " << TV[i-1];

		if(i<TV.Ocupadas())
			s<< ", ";
	}

	s <<"]";

	return s;
}
