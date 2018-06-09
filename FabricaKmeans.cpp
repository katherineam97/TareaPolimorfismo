 #include "FabricaKmeans.h"
#include "Kmeans.h"

Producto * FabricaKmeans::producir(){
   Kmeans * kmeans = new Kmeans();
   return kmeans;
}
