 #include "FabricaKmeans.h"
#include "Kmeans.h"

Producto * FabricaKmeans::producir(){//implementacion del metodo producir() perteneciente a la clase fabrica, devuelve una instancia de un agruapdor KMEANS
   Kmeans * kmeans = new Kmeans();
   return kmeans;
}
