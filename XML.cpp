#include <fstream>
#include <iostream>
#include "XML.h"
using namespace std;

/**Metodo que se encarga de crear el código necesario para la visualización en formato XML de 
los elementos ya agrupados de la lista
@param objetos, que es la lista que contiene los objetos a agrupar
*/
void XML::visualizar(Lista * objetos)
{
	
	ofstream archivo;
	archivo.open("elementosVisualizados.xml", ios::out);
	if (archivo.fail()){
		cout << "No se pudo crear el visualizador" << endl;
	}
	else{
		
		// Inicia con la escritura del codigo XML
		archivo<<"<?xml version='1.0' encoding='UTF-8' standalone="yes"?>"<<endl;
		archivo<< "<grupos>"<<endl;
		for(Lista::Iterator i = objetos->begin(); i != objetos->end(); ++i){
			
			if(dynamic_cast<Lista *>(*i)){
				
				archivo<<"<grupo>"<<endl;
				archivo<<"<elemento>";
				archivo<<*i;	
				archivo<<"</elemento>"<<endl;	
				archivo<<"</grupo>"<<endl;
				
				
			}else{
				archivo<<"<elemento>";
				archivo<<*i;	
				archivo<<"</elemento>"<<endl;
			}
			
		}
		archivo<< "</grupos>"<<endl;
		
		
		
		
	}
}
