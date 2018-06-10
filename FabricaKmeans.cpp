 #include "FabricaKmeans.h"
#include "Kmeans.h"

FabricaKmeans::FabricaKmeans(){
	Fabrica("Agrupador","Kmeans");
	
}
Producto * FabricaKmeans::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un agruapdor Kmeans
   return dynamic_cast<Producto * >(dynamic_cast<Agrupador * >(new Kmeans()));
}
