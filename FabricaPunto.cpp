#include "FabricaPunto.h"
#include "Punto.h"

FabricaPunto::FabricaPunto(){
	Fabrica("Elemento","Punto");
	
}
Producto * FabricaPunto::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  Punto
   return dynamic_cast<Producto * >(dynamic_cast<Elemento * >(new Punto()));
}