#include "FabricaXML.h"
#include "XML.h"

Producto * FabricaXML::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un visualizador XML
   XML * xml = new XML();
   return xml;
}