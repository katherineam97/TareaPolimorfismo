#ifndef _FABRICANDBSCAN
#define _FABRICADBSCAN
#include "Producto.h"
#include "Fabrica.h"
#include "DBSCAN.h"

class FabricaDBSCAN : public Fabrica{	// Hereda de la clase Fabrica
	public:
		Producto * producir();
		FabricaDBSCAN();
};
#endif