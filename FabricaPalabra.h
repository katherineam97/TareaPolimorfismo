#ifndef _FABRICA_PALABRA
#define _FABRICA_PALABRA
#include "Producto.h"
#include "Fabrica.h"
#include "Palabra.h"
class FabricaPalabra : Fabrica {
	Producto * producir();

};

#endif