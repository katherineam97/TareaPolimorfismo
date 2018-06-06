 #ifndef PUNTO
#define PUNTO
#include<iostream>
#include <stdio.h>
#include <math.h>
#include<cstring>
#include "Elemento.h"
using namespace std;

/** clase Punto, hereda de elemento 
**/
class Punto : public Elemento {

    private:
        //coordenadas de un punto (atributos)
        int x;
		int y;

    protected:
	   ostream & imprimir(ostream &);//metodo para imprimir una Punto 
	   istream & cargar(istream &);//metodo para cargar una Punto
	
	public:
		
	   Punto();// constructor por omision 
	   Punto(int , int  );//constructor con params
	   Punto( const Punto &); //constructor por copia 
	   ~Punto(); //destructor de Punto
	   Punto * clonar(); //clona un Punto   
 	   double distancia(Elemento *); //metodo que calcula la distancia entre dos Punto mediante la formula de la distancia Euclidiana

};
#endif