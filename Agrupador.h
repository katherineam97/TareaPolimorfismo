#ifndef _AGRUPADOR_ABSTRACTO
#define _AGRUPADOR_ABSTRACTO
#include "Producto.h"
#include "Lista.h"
class Agrupador : public Producto {//hereda de producto
	public:
   	   virtual Lista * agrupar(Lista *)=0;//metodo para agrupar los elementos dentro de una lista que recibe de parametro,es virtual puro por lo que todos los hijos de elemento deberan implementarlo
};

#endif