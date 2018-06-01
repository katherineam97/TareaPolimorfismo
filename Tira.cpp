#include "Tira.h"
#include "Elemento.h"
#include<iostream>
using namespace std;
	ostream & Tira::imprimir(ostream & salida){
	   salida << "HOLA";
	   return salida;
	}
	istream & Tira::cargar(istream & entrada){
	   cout << "Cargo"<< endl;
	   return entrada;
	}
	
	// Tira& Tira::operator=(const Elemento & otro){
	   // cout << "Asigna otro a este"<< endl;
	   // return *this;
	// }
	
	Elemento * Tira::clonar(){
	   cout << "Clonado"<<endl;
	   return 0;
	}	   
	
 	double Tira::distancia(Elemento * otro){
	   cout << "Falta calcular distancia "<< endl;
	   return 1.0;
	}	   

