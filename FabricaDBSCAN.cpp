#include "FabricaDBSCAN.h"
#include "Producto.h"
#include "DBSCAN.h"
#include "Fabrica.h"
FabricaDBSCAN::FabricaDBSCAN():Fabrica("agrupador","DBSCAN"){
	
}

// Implementacion del método producir perteneciente a la clase Fabrica, que devuelve una instancia de una clase DBSCAN
Producto * FabricaDBSCAN::producir()
{
	return dynamic_cast<Producto *> (dynamic_cast<Agrupador *>(new DBSCAN()));
}