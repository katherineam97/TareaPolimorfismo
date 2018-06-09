#ifndef _FABRICA_PUNTO
#define _FABRICA_PUNTO
#include "Producto.h"
#include "Fabrica.h"
#include "Punto.h"
class FabricaPunto : Fabrica{
	Producto * producir();

};

#endif