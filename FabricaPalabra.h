#ifndef _FABRICA_PALABRA
#define _FABRICA_PALABRA
#include "Producto.h"
#include "Fabrica.h"
#include "Palabra.h"
class FabricaPalabra : public Fabrica {//hereda de la clase fabrica
	Producto * producir();

};

#endif