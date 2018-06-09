#include "FabricaJson.h"
#include "Json.h"

Producto * FabricaJson::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un visualizador Json
   Json * json = new XML();
   return json;
}