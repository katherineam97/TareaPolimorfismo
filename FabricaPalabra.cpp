#include "FabricaPalabra.h"
#include "Palabra.h"

Producto * FabricaPalabra::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia del elemento palabra
   Palabra * palabra = new Palabra();
   return palabra;
}