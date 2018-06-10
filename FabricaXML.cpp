#include "FabricaXML.h"
#include "XML.h"
#include "Producto.h"
#include "Fabrica.h"

FabricaXML::FabricaXML():Fabrica("visualizador","XML"){
	
}
	

Producto * FabricaXML::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  XML
   return dynamic_cast<Producto * >(dynamic_cast<Visualizador * >(new XML()));
}