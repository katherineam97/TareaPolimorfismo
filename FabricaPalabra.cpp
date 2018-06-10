#include "FabricaPalabra.h"
#include "Palabra.h"
#include "Producto.h"
#include "Fabrica.h"
FabricaPalabra::FabricaPalabra():Fabrica("elemento","Palabra"){
	
}
Producto * FabricaPalabra::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  Palabra
   return dynamic_cast<Producto * >(dynamic_cast<Elemento * >(new Palabra()));
}