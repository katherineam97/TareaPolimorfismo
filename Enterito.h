#ifndef _Enterito
#define _Enterito
#include<iostream>
#include "Elemento.h"

// EN PROCESO DE DISEÑO

class Enterito : public Elemento {
   private:
      int x;	
	public:
       std::ostream & imprimir(std::ostream &);
       std::istream & cargar(std::istream &);
	   Enterito(int);
	   Elemento * clonar();	   
 	   double distancia(Elemento *);	   
};
#endif