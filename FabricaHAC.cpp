#include "FabricaHAC.h"
#include "HAC.h"


FabricaHAC::FabricaHAC(){
	Fabrica("Agrupador","HAC");
	
}
Producto * FabricaHAC::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un agruapdor HAC
   return dynamic_cast<Producto * >(dynamic_cast<Agrupador * >(new HAC()));
}