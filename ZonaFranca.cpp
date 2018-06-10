#include "Fabrica.h"
#define MAXIMO 100  
#include "ZonaFranca.h"

#include "FabricaVector.h"
#include "FabricaPunto.h"
#include "FabricaPalabra.h"
#include "FabricaHAC.h"
#include "FabricaKmeans.h"
// #include "FabricaAgrupador_HAPPYFACE_INICIALES.h"
#include "FabricaSVG.h"
#include "FabricaXML.h"
 #include "FabricaJson.h"

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

	agregar(new FabricaHAC());
	agregar(new FabricaKmeans());
	
	agregar(new FabricaPalabra());
	agregar(new FabricaPunto());
	agregar(new FabricaVector());
	
	agregar(new FabricaJson());
	agregar(new FabricaXML());
	agregar(new FabricaSVG());
	
	
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
