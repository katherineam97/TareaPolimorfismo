#ifndef _ZONA_FRANCA
#define _ZONA_FRANCA
#include "Fabrica.h"

class ZonaFranca {
	private:
	   int cantidadDeFabricas; // 
	   void agregar(Fabrica *);
	protected:
	   Fabrica ** fabricas;
	public:   
	   ZonaFranca(); 
	   ~ZonaFranca();
       Fabrica * getFabrica(const char *, const char *);
};

#endif