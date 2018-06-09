#include "FabricaPalabra.h"
#include "Palabra.h"

Producto * FabricaPalabra::producir(){
   Palabra * palabra = new Palabra();
   return palabra;
}