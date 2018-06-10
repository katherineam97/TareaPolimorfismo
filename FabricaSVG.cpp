#include "FabricaSVG.h"
#include "SVG.h"
#include "Producto.h"
#include "Fabrica.h"
FabricaSVG::FabricaSVG():Fabrica("visualizador","SVG"){
	
}
Producto * FabricaSVG::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  SVG
   return dynamic_cast<Producto * >(dynamic_cast<Visualizador * >(new SVG()));
}