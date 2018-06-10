#ifndef _FABRICA_JSON
#define _FABRICA_JSON
#include "Producto.h"
#include "Fabrica.h"
#include "Json.h"
class FabricaJson : public Fabrica{//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaJson();
};

#endif