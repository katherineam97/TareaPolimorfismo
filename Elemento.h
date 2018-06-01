#ifndef _ElementoAgrupable
#define _ElementoAgrupable
#include<iostream>
#include "Producto.h"
// EN PROCESO DE DISEÑO
using namespace std;

class Elemento : public Producto {
	
    friend istream& operator>>(istream & entrada, Elemento * elemento){
		return elemento->cargar(entrada); // invoca al método polimorfico
	}
	
	friend ostream& operator<<(ostream & salida, Elemento * elemento){
		return elemento->imprimir(salida); // invoca al método polimorfico
	}	

    protected:
	   virtual ostream & imprimir(ostream &)=0;
	   virtual istream & cargar(istream &)=0;
	
	public:
	   virtual ~Elemento(){};
	   virtual Elemento * clonar()=0;	   
 	   virtual double distancia(Elemento *)=0;	   
};
#endif