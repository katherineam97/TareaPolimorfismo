#include "FabricaVector.h"
#include "Vector.h"
#include "Producto.h"
#include "Fabrica.h"

FabricaVector::FabricaVector():Fabrica("elemento","Vector"){
	
}
Producto * FabricaVector::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  Vector
   return dynamic_cast<Producto * >(dynamic_cast<Elemento * >(new Vector()));
}