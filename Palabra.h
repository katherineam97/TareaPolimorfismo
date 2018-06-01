#ifndef _Palabra
#define _Palabra
#include<iostream>
#include <string.h>
#include "Elemento.h"
using namespace std;

/** clase palabra la cual hereda de elemento 
**/
class Palabra : public Elemento {

    private:
        
        string palabra; //atributo privado de la clase

    protected:
	   ostream & imprimir(ostream &);//metodo para imprimir una palabra 
	   istream & cargar(istream &);//metodo para cargar una palabra
	
	public:
		
	   Palabra();// constructor por omision de la clase
	   Palabra(string palabra);//constructor con parametro de la clase
	   Palabra( const Palabra &); //constructor por copia de la clase
	   ~Palabra(); //destructor de la clase palabra
	   Palabra * clonar();	//metodo que clona una palabra   
 	   double distancia(Elemento *); //metodo que calcula la distancia entre una palabra y otra, utilizando la formula  
 	   //del coeficiente de DICE
 	   double interseccion(string, string);//metodo para calcular la interseccion que existe entre una palabra y otra	   

};
#endif