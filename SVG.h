#ifndef _SVG
#define _SVG
#include "Visualizador.h"
#include <fstream> 

class SVG : public Visualizador {
	
	private:
		int ancho_Imagen = 0;
		int alto_Imagen = 0;
	public:
		void setDimensiones();								// Metodo encargado de asignar las dimensiones de la imagen .SVG
		void visualizar(Lista *);							// Metodo encargado de crear el archivo en .svg para la visualizacion de los elementos
		
};
#endif
