#ifndef _FABRICA_SVG
#define _FABRICA_SVG
#include "Producto.h"
#include "Fabrica.h"
#include "SVG.h"
class FabricaSVG : public Fabrica{//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaSVG();

};

#endif