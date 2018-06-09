#ifndef _VISUALIZADOR_ABSTRACTO
#define _VISUALIZADOR_ABSTRACTO
#include "Producto.h"
#include "Lista.h"

class Visualizador : public Producto {
   	   virtual void visualizar( Lista * )=0;//metodo para visualizar los elemento de la lista que recibe de parametro en unformato especifico implementado en cada clase que herede de agrupador
};

#endif