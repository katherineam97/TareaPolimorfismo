#ifndef _FABRICA_HAC
#define _FABRICA_HAC
#include "Producto.h"
#include "Fabrica.h"
#include "HAC.h"
class FabricaHAC : Fabrica{//hereda de la clase fabrica
	Producto * producir();

};

#endif