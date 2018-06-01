#include<iostream>
#include <string.h>
#include "Elemento.h"
#include "Palabra.h"

 /*constructr por defecto de la clase palabra*/
 Palabra::Palabra(){
   
   palabra="";

 }

 /*constructor con parametros de la clase
 @param palabra
 */
 Palabra::Palabra(string palabra){
    this->palabra=palabra;
  
 }

/* metodo de ostream, que imprime el atributo de la clase palabra 
 @param salida
 @return salida
*/
ostream & Palabra::imprimir(ostream & salida){
  
 salida<< palabra;

 return salida;

}

/* metodo de istream, que carga una palabra, recibe una entrada y lal carga al atributo de palabra
@param entrada
@return salida
*/
istream & Palabra::cargar(istream & entrada){

   entrada >> palabra;

   return entrada;
}
	
Palabra::Palabra( const Palabra & otro){
 
 	this->palabra = otro.palabra;

} //EL CONSTRUCTOR VIRTUAL QUE EL PROFE CAMBIOOO

/* destructor de la clase palabra
*/
Palabra::~Palabra(){


}

/*metodo para clonar una palabra, devuelve una copia de si misma
@return copiaPtr
*/
Palabra * Palabra::clonar(){
	Palabra * copiaPtr = new Palabra(*this);
    return copiaPtr;
}

/*metodo para calcular la interseccion que existe entre dos palabras tipo string
@param palabra1
@param palabra2
*/
double Palabra::interseccion(string palabra1, string palabra2){
  char * vector1= new char[palabra1.length()];
  char * vector2= new char[palabra2.length()];
  strcpy(vector1, palabra1.c_str());
  strcpy(vector2, palabra2.c_str());
  int cardinalidadV1=0;
  int cardinalidadV2=0;
  char letra= vector1[0];
  int interseccion=0;
  double distancia=0.0;

  for(int i=0; i<strlen(vector1);++i){
      for(int j=i+1; j<strlen(vector1);++j){
         if(vector1[j]==letra && vector1[j]!='1'){
            vector1[j]='1';
         }
     }
         letra=vector1[i];
   }

   for(int i=0; i<strlen(vector1);++i){
	   if(vector1[i]!='1'){
		   ++cardinalidadV1;
	   }
   }


   letra= vector2[0];
   
     for(int i=0; i<strlen(vector2);++i){
      for(int j=i+1; j<strlen(vector2);++j){
         if(vector2[j]==letra && vector2[j]!='1'){
            vector2[j]='1';
         }
     }
         letra=vector2[i];

   }
   
    for(int i=0; i<strlen(vector2);++i){
	   if(vector2[i]!='1'){
		   ++cardinalidadV2;
	   }
   }
   

   for(int i=0; i<strlen(vector1);++i){
       	for(int j=0; j<strlen(vector2);++j){
       	 	 if(vector1[i]!='1'){
            	 if(vector1[i]==vector2[j] && vector2[j]!='1'){
                ++interseccion;
                }
            }

        }
    }
	
 	delete[]vector1;
 	delete[]vector2;
	distancia= 1 - ((double)interseccion/((double)cardinalidadV1 + (double)cardinalidadV2));

  return distancia;
}

/*metodo para calcular la distancia entre dos palabras el cual utiliza el coeficiente de DICE, recibe un elemento por puntero
@param palabra 
@return distancia
*/ 	  
double Palabra::distancia(Elemento * p){
	Palabra * palabra = new Palabra(dynamic_cast<Palabra & >(*p));
	double distancia=1.0;
	if(palabra){
	distancia= interseccion(palabra->palabra, this->palabra);
    delete palabra;
    palabra=0;
	}
    return distancia;
}
