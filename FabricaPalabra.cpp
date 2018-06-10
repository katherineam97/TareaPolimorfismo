#include "FabricaPalabra.h"
#include "Palabra.h"

FabricaPalabra::FabricaPalabra(){
	Fabrica("Elemento","Palabra");
	
}
Producto * FabricaPalabra::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  Palabra
   return dynamic_cast<Producto * >(dynamic_cast<Elemento * >(new Palabra()));
}