#ifndef _ElementoAgrupable
#define _ElementoAgrupable
#include<iostream>
#include "Producto.h"
// EN PROCESO DE DISEÑO
using namespace std;

class Elemento : public Producto {//hereda de producto
	
    friend istream& operator>>(istream & entrada, Elemento * elemento){//metodo sobrecargado para cargar
		return elemento->cargar(entrada); // invoca al método polimorfico
	}
	
	friend ostream& operator<<(ostream & salida, Elemento * elemento){//metodo sobrecargado para imprimir
		return elemento->imprimir(salida); // invoca al método polimorfico
	}	

    protected:
	   virtual ostream & imprimir(ostream &)=0;//metodo que para imprimir, devuelve el mismo flujo que recibe de parametro y es virtual puro por lo que todos los hijos de elemento deberan implementarlo
	   virtual istream & cargar(istream &)=0;//metodo que para cargar, devuelve el mismo flujo que recibe de parametro y es virtual puro por lo que todos los hijos de elemento deberan implementarlo
	
	public:
	   virtual ~Elemento(){};//destructor de elemento, metodo virtual con una implementacion vacia (todos los hijos lo implementaron)
	   virtual Elemento * clonar()=0;//metodo en el que un elemento se clona a el mismo y devuelve un puntero de su copia	   
 	   virtual double distancia(Elemento *)=0;//metodo para calcular la distancia entre dos elementos,es virtual puro por lo que todos los hijos de elemento deberan implementarlo   
};
#endif