#include "FabricaHAC.h"
#include "HAC.h"

Producto * FabricaHAC::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un agruapdor HAC
   HAC * hac = new HAC();
   return hac;
}