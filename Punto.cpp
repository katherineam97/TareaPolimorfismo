#include<iostream>
#include <stdio.h>
#include <math.h>
#include<cstring>
#include "Elemento.h"
#include "Punto.h"

 /*Metodo constructor por omision*/
 Punto::Punto(){
	this->x=0;
	this->y=0;
 }

 /*Metodo constructor con parametros 
 @param x, y
 */
 Punto::Punto(int x, int y){
    this->x=x;
	this->y=y;
  
 }
 
  /*Metodo constructor por copia 
 @param &punto
 */
 Punto::Punto( const Punto & punto){
	this->x=punto.x;
	this->y=punto.y;	
}
 
/* Metodo destructor 
*/
Punto::~Punto(){
	x=0;
	y=0;

}


/* Metodo que imprime un punto (coordenadas) 
 @param salida
 @return salida
*/
ostream & Punto::imprimir(ostream & salida){
  
 salida<< "(" << x <<","<< y <<")"<< endl ;

 return salida;

}

/* Metodo que carga un Punto
@param entrada
@return salida
*/
istream & Punto::cargar(istream & entrada){
	string cad;
	const char separador[2] = ",";
	getline(entrada, cad);
	char * tira = strtok((char *)cad.c_str(), separador);							
	this->x = stoi(tira);				
	tira = strtok(NULL, separador);		
	this->y=stoi(tira);
	
   return entrada;
}
	


/*metodo en el que un punto se clona a si mismo y devuelve una copia igual a el 
@return copia	 
*/
Punto * Punto::clonar(){
	Punto * copia = new Punto(this->x,this->y);
    return copia;
}

double Punto::distancia(Elemento * p){
	Punto * punto= new Punto(dynamic_cast<Punto & >(*p));
	double distancia=1.0;
	if(punto){
	
	double num= 0.0;
	double denom =0.0;
	double numero=0.0;
	
	num= sqrt(pow((punto->x - this->x),2)  + pow((punto->y - this->y),2));
	
	denom=sqrt((pow(this->x,2) + (pow(this->y,2)))) +  sqrt((pow(punto->x,2) + (pow(punto->y,2))));
	
	numero= num/denom;
	
	distancia= numero;
	
	delete punto;
	punto=0;
	
	}
	
	return distancia;	
}

