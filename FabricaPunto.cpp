#include "FabricaPunto.h"
#include "Punto.h"

Producto * FabricaPunto::producir(){
   Punto * punto = new Punto();
   return punto;
}