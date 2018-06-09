#include "FabricaJson.h"
#include "Json.h"

Producto * FabricaJson::producir(){
   Json * json = new XML();
   return json;
}