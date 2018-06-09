#include "FabricaXML.h"
#include "XML.h"

Producto * FabricaXML::producir(){
   XML * xml = new XML();
   return xml;
}