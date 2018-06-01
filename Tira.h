#ifndef _Tira
#define _Tira
#include<iostream>
#include "Elemento.h"
// EN PROCESO DE DISEÑO
using namespace std;

class Tira : public Elemento{
	
	ostream & imprimir(ostream &);
	istream & cargar(istream &);
	
	// Tira& operator=(const Elemento &);
	
	Elemento * clonar();	   
	
 	double distancia(Elemento *);	   

};
#endif