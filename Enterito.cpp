
#include "Enterito.h"
#include<iostream>

using namespace std;

ostream & Enterito::imprimir(ostream & salida){
   salida << x;	
   return salida;
}
       
istream & Enterito::cargar(istream & entrada){
	entrada >> x;
	x = x % 100;
	return entrada;
}
	   
Enterito::Enterito(int x){
   this->x = x % 100;   
}

Elemento * Enterito::clonar(){
	Enterito * nuevo = new Enterito( x );
	return nuevo;
}	   
 	   
double Enterito::distancia(Elemento * otro){
	double dist = 1.0;
	Enterito * otroEnterito = dynamic_cast<Enterito *>(otro);
	if(otroEnterito){
		dist = (this->x - otroEnterito->x) / 100.0;
		if(dist < 0){
			dist*= -1.0;
		}
	}
	return dist;
}	   
