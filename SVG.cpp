#include <fstream>
#include <iostream>
#include "SVG.h"
using namespace std;

/**Metodo que se encarga de crear el código necesario para la visualización en imagen vectorial (SVG) de 
los elementos ya agrupados de la lista
@param objetos, que es la lista que contiene los objetos a agrupar
*/
void SVG::visualizar(Lista * objetos)
{
	// Creación del archivo SVG
	ofstream archivo;
	archivo.open("elementosVisualizados.svg", ios::out);
	if (archivo.fail()){
		cout << "No se pudo crear el visualizador" << endl;
	}
	else{
		// Determino las dimensiones de la imagen SVG
		this->alto_Imagen = 1080;
		this->ancho_Imagen = 1400;
		
		// Inicia con la escritura del codigo XML
		archivo << "<?xml version='1.0' encoding='UTF-8' ?> " << endl;
		archivo << "<svg xmlns='http://www.w3.org/2000/svg' version='1.1' width='"<<ancho_Imagen<<"px' height='"<< alto_Imagen <<"px'> " << endl;
		// Se realiza en la linea siguiente el formato del texto a desplejar en pantalla
		archivo << "<text x = '200' y = '200' font-family='Sans-serif' font-size='30' fill='blue'> " ;
		archivo << objetos << endl;					// Manda en el flujo de datos la lista a incluir en el codigo svg
		archivo << " </text>";
		
		// archivo << "<rect x='500' y='400' width='825' height='30' fill='white' stroke-width='3' stroke='blue' /> " << endl;
		
		archivo << "</svg>" << endl;				// Se cierra el svg del archivo 
	}
}
