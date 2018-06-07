#ifndef _JSON
#define _JSON
#include "Visualizador.h"
#include <fstream> 

class Json : public Visualizador {
		
	public:		
		void visualizar(Lista *);							// Metodo encargado de crear el archivo en .XML para la visualizacion de los elementos
		
};
#endif
