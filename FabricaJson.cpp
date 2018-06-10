#include "FabricaJson.h"
#include "Json.h"



FabricaJson::FabricaJson(){
	Fabrica("Visualizador","Json");
	
}
Producto * FabricaJson::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un visualizador Json
   return dynamic_cast<Producto * >(dynamic_cast<Visualizador * >(new Json()));
}