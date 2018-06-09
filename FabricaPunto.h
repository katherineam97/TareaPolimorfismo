#ifndef _FABRICA_PUNTO
#define _FABRICA_PUNTO
#include "Producto.h"
#include "Fabrica.h"
#include "Punto.h"
class FabricaPunto : Fabrica{//hereda de la clase fabrica
	Producto * producir();

};

#endif