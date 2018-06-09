#ifndef _FABRICA_ABSTRACTA
#define _FABRICA_ABSTRACTA
#include <cstring>
#include "Producto.h"
class Fabrica {
	protected:
	//atributos de la clase fabrica
	   char  * nombreProducto;
	   char  * tipoProducto;
	   
	private:
	
	   void _initHilera(char ** atributoPtr, const char * nombre){//metodo para inicializar un atributo 
		      if(*atributoPtr){
			      delete [] *atributoPtr;
		      }		   
	          int tamanyo = strlen(nombre)+1;
			  *atributoPtr = new char [tamanyo];
		      strcpy(*atributoPtr,nombre);
			  (*atributoPtr)[tamanyo-1]='\0'; 
	   }

	public:
	   
	   void setTipoProducto(const char * nombre){//metodo que le asigna un tipo al producto 
		   if(nombre){
			   _initHilera(&(this->tipoProducto),nombre);
		   }
		   else {
			   _initHilera(&(this->tipoProducto),"SIN_TIPO");
		   }
	   }
	   
	   void setNombreProducto(const char * nombre){//metodo que le asigna un nombre al producto
		   if(nombre){
			   _initHilera(&(this->nombreProducto),nombre);
		   }
		   else {
			   _initHilera(&(this->nombreProducto),"SIN_NOMBRE");
		   }
	   }	
	   
	   Fabrica(const char * tipoProducto, const char * nombreProducto){//constructor con parametros 
		   this->tipoProducto = 0;
		   this->nombreProducto = 0;
           this->setNombreProducto(nombreProducto);
		   this->setTipoProducto(tipoProducto);
	   }
	   
	   virtual ~Fabrica(){//destuctor de fabrica
		   if(nombreProducto){
  		      delete [] nombreProducto;
		   }
		   if(tipoProducto){
  		      delete [] tipoProducto;
		   }
	   }

	   virtual const char * getNombreProducto(){//metodo que retorna el nombre del producto
		   return nombreProducto;	   
	   }

	   virtual const char * getTipoProducto(){//metodo que retorna el tipo del producto
		   return tipoProducto;	   
	   }
	   
   	   virtual Producto * producir()=0;//metodo que crea una instancia (produce) de un producto (devuelve un puntero a un producto)
	   
	   virtual int produce(const char * nombreProducto){//metodo que compara el nombre de dos productos (el mismo y el que recibe de parametro)
		   return strcmp(this->nombreProducto,nombreProducto)==0;		   
	   }
	   virtual int esTipo(const char * tipoProducto){//metodo que compara el tipo de dos productos (el mismo y el que recibe de parametro)
		   return strcmp(this->tipoProducto,tipoProducto)==0;		   		   
	   }	   

};

#endif