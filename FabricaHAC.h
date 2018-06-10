#ifndef _FABRICA_HAC
#define _FABRICA_HAC
#include "Producto.h"
#include "Fabrica.h"
#include "HAC.h"
class FabricaHAC : public Fabrica{//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaHAC();

};

#endif