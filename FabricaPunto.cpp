#include "FabricaPunto.h"
#include "Punto.h"

Producto * FabricaPunto::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un elemento punto
   Punto * punto = new Punto();
   return punto;
}