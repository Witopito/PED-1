/*
 * main.cpp
 *
 *  Created on: 16/2/2015
 *      Author: Diego
 */

#define _TADCALENDARIO_
#ifdef _TADCALENDARIO_
#include <iostream>
#include "../include/tcalendario.h"
#include <string.h>
using namespace std;

int main(void){
	TCalendario prueba1;

	TCalendario prueba2(13,3,1986,"Fecha Random");

	prueba2 = TCalendario(1,2,1899,"Algo");
	prueba2 =TCalendario(13,3,1986,"Fecha Random");

	TCalendario prueba3(prueba2);

	prueba3 = TCalendario(1,2,1893,"Algo");

	prueba3 = TCalendario(prueba2);
	TCalendario prueba4;
	prueba4.ModFecha(13,03,1986);
	TCalendario prueba5 = TCalendario(prueba4);

	prueba1 = prueba2;

	prueba2 = prueba1+1;

	prueba2 = prueba1-2;

	prueba2 = prueba1++;

	prueba2 = ++prueba1;

	prueba2 = prueba1--;

	prueba2 = --prueba1;

	prueba2.ModFecha(27,2,1987);

	prueba1 = prueba2;
	prueba1 = prueba3;


	/* PRUEBA 15 */
	cout<<endl<<"operator> :"<<endl;
	prueba1 = TCalendario(1,1,2000,"Fecha1");
	prueba2 = TCalendario(3,4,2003,"Fecha2");
	cout<<"1 - "<<(prueba2>prueba1)<<endl;
	cout<<"0 - "<<(prueba1>prueba2)<<endl;
	cout<<"0 - "<<(prueba1>prueba1)<<endl;
	prueba4 = TCalendario();
	prueba5 = TCalendario();
	prueba5.ModMensaje("");
	cout<<"1 - "<<(prueba2>prueba4)<<endl;
	cout<<"0 - "<<(prueba4>prueba5)<<endl;
	cout<<"1 - "<<(prueba5>prueba4)<<endl;
	cout<<"0 - "<<(prueba4>prueba4)<<endl;
	prueba4.ModFecha(3,1,2000);
	prueba5.ModFecha(2,2,1901);
	cout<<"1 - "<<(prueba4>prueba5)<<endl;
	cout<<"0 - "<<(prueba5>prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(2,2,2000);
	cout<<"1 - "<<(prueba4>prueba5)<<endl;
	cout<<"0 - "<<(prueba5>prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(2,3,2000);
	cout<<"1 - "<<(prueba4>prueba5)<<endl;
	cout<<"0 - "<<(prueba5>prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(3,3,2000);
	prueba4.ModMensaje("holz");
	prueba5.ModMensaje("holo");
	cout<<"1 - "<<(prueba4>prueba5)<<endl;
	cout<<"0 - "<<(prueba5>prueba4)<<endl;

	/* PRUEBA 16 */
	cout<<endl<<"operator< :"<<endl;
	prueba1 = TCalendario(1,1,2000,"Fecha1");
	prueba2 = TCalendario(3,4,2003,"Fecha2");
	cout<<"0 - "<<(prueba2<prueba1)<<endl;
	cout<<"1 - "<<(prueba1<prueba2)<<endl;
	cout<<"0 - "<<(prueba1<prueba1)<<endl;
	prueba4 = TCalendario();
	prueba5 = TCalendario();
	prueba5.ModMensaje("");
	cout<<"0 - "<<(prueba2<prueba4)<<endl;
	cout<<"1 - "<<(prueba4<prueba5)<<endl;
	cout<<"0 - "<<(prueba5<prueba4)<<endl;
	cout<<"0 - "<<(prueba4<prueba4)<<endl;
	prueba4.ModFecha(3,1,2000);
	prueba5.ModFecha(2,2,1901);
	cout<<"0 - "<<(prueba4<prueba5)<<endl;
	cout<<"1 - "<<(prueba5<prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(2,2,2000);
	cout<<"0 - "<<(prueba4<prueba5)<<endl;
	cout<<"1 - "<<(prueba5<prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(2,3,2000);
	cout<<"0 - "<<(prueba4<prueba5)<<endl;
	cout<<"1 - "<<(prueba5<prueba4)<<endl;
	prueba4.ModFecha(3,3,2000);
	prueba5.ModFecha(3,3,2000);
	prueba4.ModMensaje("holz");
	prueba5.ModMensaje("holo");
	cout<<"0 - "<<(prueba4<prueba5)<<endl;
	cout<<"1 - "<<(prueba5<prueba4)<<endl;

	
}
#endif
