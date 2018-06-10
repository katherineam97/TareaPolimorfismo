#ifndef _FABRICA_KMEANS
#define _FABRICA_KMEANS
#include "Producto.h"
#include "Fabrica.h"
#include "Kmeans.h"
class FabricaKmeans : public Fabrica {//hereda de la clase fabrica
	Producto * producir();

};

#endif