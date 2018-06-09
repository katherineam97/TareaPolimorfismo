#ifndef _FABRICA_JSON
#define _FABRICA_JSON
#include "Producto.h"
#include "Fabrica.h"
#include "Json.h"
class FabricaJson : Fabrica{//hereda de la clase fabrica
	Producto * producir();

};

#endif