#include "FabricaXML.h"
#include "XML.h"

FabricaXML::FabricaXML(){
	Fabrica("Visualizador","XML");
	
}
Producto * FabricaXML::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un  XML
   return dynamic_cast<Producto * >(dynamic_cast<Visualizador * >(new XML()));
}