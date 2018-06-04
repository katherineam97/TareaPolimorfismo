#include "Fabrica.h"
#define MAXIMO 100  // SOLO PUEDEN CAMBIAR 
#include "ZonaFranca.h"
// DEBE HABER UN .H PARA CADA FABRICA 3 DE CADA TIPO
// Por cada Fabrica que implementen deben incluir su .h 
// #include "FabricaVectorEC.h"
// #include "FabricaHilera_OPCIONAL_INICIALES.h"
// #include "FabricaPalabra_INICIALES.h"
// #include "FabricaHAC_INICIALES.h"
// #include "FabricaKMeans_INICIALES.h"
// #include "FabricaAgrupador_HAPPYFACE_INICIALES.h"
// #include "FabricaSVG_INICIALES.h"
// #include "FabricaXML_INICIALES.h"
// #include "FabricaJSON_INICIALES.h"

void ZonaFranca::agregar(Fabrica * fabrica){
	if(cantidadDeFabricas < MAXIMO){
       fabricas[cantidadDeFabricas++]= fabrica;	   
	}
}

ZonaFranca::ZonaFranca(){
	fabricas = new Fabrica * [MAXIMO];
	for(int i=0;i<MAXIMO; ++i){
		fabricas[i]=0;
	}
	cantidadDeFabricas=0;
	// SI HAY MAS QUE LO QUE INDICA EL VALOR "MAXIMO" DEBE AUMENTARLO EN EL .H
    // USTED AGREGAR INSTANCIAS DE FABRICA ESPECIFICAS 
	//agregar(new FabricaVectorEC());
	//agregar(new FabricaHAC());
	//agregar(new FabricaSVG());
	// 3 Fabricas de Elemento
	// 3 Fabricas de Agrupador
	// 3 Fabricas de Visualizador
	
}

ZonaFranca::~ZonaFranca(){
	for(int i=0; i< cantidadDeFabricas;++i){
		delete fabricas[i];
	}
	delete [] fabricas;
}

Fabrica * ZonaFranca::getFabrica(const char * tipo, const char * nombre){
	int i=0;
	Fabrica * fabricaRetornada = 0;
	while(!fabricaRetornada && i< cantidadDeFabricas){
		if(fabricas[i]->esTipo(tipo) && fabricas[i]->produce(nombre)){
			fabricaRetornada = fabricas[i];			
		}
        ++i;
	}	
	return fabricaRetornada;
}
