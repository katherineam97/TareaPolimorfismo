#ifndef _AGRUPADOR_ABSTRACTO
#define _AGRUPADOR_ABSTRACTO
#include "Producto.h"
#include "Lista.h"
class Agrupador : public Producto {
	public:
   	   virtual Lista * agrupar(Lista *)=0;
};

#endif