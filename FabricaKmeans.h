#ifndef _FABRICA_KMEANS
#define _FABRICA_KMEANS
#include "Producto.h"
#include "Fabrica.h"
#include "Kmeans.h"
class FabricaKmeans : Fabrica {
	Producto * producir();

};

#endif