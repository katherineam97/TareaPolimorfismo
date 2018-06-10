#ifndef _FABRICA_PUNTO
#define _FABRICA_PUNTO
#include "Producto.h"
#include "Fabrica.h"
#include "Punto.h"
class FabricaPunto : public Fabrica{//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaPunto();

};

#endif