#ifndef _FABRICA_VECTOR
#define _FABRICA_VECTOR
#include "Producto.h"
#include "Fabrica.h"
#include "Vector.h"
class FabricaVector : public Fabrica {//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaVector();

};

#endif