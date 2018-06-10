#include <fstream>
#include <iostream>
#include "Json.h"
using namespace std;

/**Metodo que se encarga de crear el código necesario para la visualización en formato Json de 
los elementos ya agrupados de la lista
@param objetos, que es la lista que contiene los objetos a agrupar
*/
void Json::visualizar(Lista * objetos)
{
	
	ofstream archivo;
	archivo.open("elementosVisualizados.Json", ios::out);
	if (archivo.fail()){
		cout << "No se pudo crear el visualizador" << endl;
	}
	else{
		
		archivo<< "{ "<<endl;
		archivo<<"\"grupos\" : {"<<endl;
		for(Lista::Iterator i = objetos->begin(); i != objetos->end(); ++i){
			
			if(dynamic_cast<Lista *>(*i)){
				
				archivo<<"\"grupo\" : {"<<endl;
				archivo<<"\"elemento\" : ";
				archivo<<"\""<<*i<<"\"";	
				archivo<<endl;	
				archivo<<"}"<<endl;
				
				
			}else{
				archivo<<"\"elemento\" : ";
				archivo<<"\""<<*i<<"\"";	
				archivo<<endl;
			}
			
		}
		archivo<< "}"<<endl;
		archivo<< "}"<<endl;
		
		
		
	}
}