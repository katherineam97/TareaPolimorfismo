#ifndef _FABRICA_ABSTRACTA
#define _FABRICA_ABSTRACTA
#include <cstring>
#include "Producto.h"
class Fabrica {
	protected:
	   char  * nombreProducto;
	   char  * tipoProducto;
	   
	private:
	
	   void _initHilera(char ** atributoPtr, const char * nombre){
		      if(*atributoPtr){
			      delete [] *atributoPtr;
		      }		   
	          int tamanyo = strlen(nombre)+1;
			  *atributoPtr = new char [tamanyo];
		      strcpy(*atributoPtr,nombre);
			  (*atributoPtr)[tamanyo-1]='\0'; 
	   }

	public:
	   
	   void setTipoProducto(const char * nombre){
		   if(nombre){
			   _initHilera(&(this->tipoProducto),nombre);
		   }
		   else {
			   _initHilera(&(this->tipoProducto),"SIN_TIPO");
		   }
	   }
	   
	   void setNombreProducto(const char * nombre){
		   if(nombre){
			   _initHilera(&(this->nombreProducto),nombre);
		   }
		   else {
			   _initHilera(&(this->nombreProducto),"SIN_NOMBRE");
		   }
	   }	
	   
	   Fabrica(const char * tipoProducto, const char * nombreProducto){
		   this->tipoProducto = 0;
		   this->nombreProducto = 0;
           this->setNombreProducto(nombreProducto);
		   this->setTipoProducto(tipoProducto);
	   }
	   
	   virtual ~Fabrica(){
		   if(nombreProducto){
  		      delete [] nombreProducto;
		   }
		   if(tipoProducto){
  		      delete [] tipoProducto;
		   }
	   }

	   virtual const char * getNombreProducto(){
		   return nombreProducto;	   
	   }

	   virtual const char * getTipoProducto(){
		   return tipoProducto;	   
	   }
	   
   	   virtual Producto * producir()=0;
	   
	   virtual int produce(const char * nombreProducto){
		   return strcmp(this->nombreProducto,nombreProducto)==0;		   
	   }
	   virtual int esTipo(const char * tipoProducto){
		   return strcmp(this->tipoProducto,tipoProducto)==0;		   		   
	   }	   

};

#endif