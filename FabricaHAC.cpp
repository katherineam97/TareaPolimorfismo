#include "FabricaHAC.h"
#include "HAC.h"

Producto * FabricaHAC::producir(){
   HAC * hac = new HAC();
   return hac;
}