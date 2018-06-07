#ifndef _XML
#define _XML
#include "Visualizador.h"
#include <fstream> 

class XML : public Visualizador {
		
	public:		
		void visualizar(Lista *);							// Metodo encargado de crear el archivo en .XML para la visualizacion de los elementos
		
};
#endif
