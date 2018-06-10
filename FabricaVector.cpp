#include "FabricaVector.h"
#include "Vector.h"

FabricaVector::FabricaVector(){
	Fabrica("Elemento","Vector");
	
}
Producto * FabricaVector::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  Vector
   return dynamic_cast<Producto * >(dynamic_cast<Elemento * >(new Vector()));
}