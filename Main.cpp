#include<iostream>
using namespace std;
#include "ZonaFranca.h" // ZonaFranca.h y ZonaFranca.cpp
#include "Fabrica.h"
#include "Elemento.h"
#include "Agrupador.h"
#include "Visualizador.h"
#include "Lista.h"
#include<fstream>
int main( int argc, char ** argv){
   if(argc < 5){
      cout << "Uso: agrupador elemento algoritmoDeClustering visualizador datos.txt"<< endl;	   
   }
   else {
	  // Verificando entrada de datos
      for(int i=0;i < argc; ++i){
	      cout << argv[i]<< endl;
      }
 	  const char * nombreElemento = argv[1];
	  const char * nombreAgrupador = argv[2];
	  const char * nombreVisualizador = argv[3];
	  const char * nombreArchivo = argv[4];
	  
      ZonaFranca zonaFranca; // Solo pueden agregar Fabricas en constructor ZonaFranca() de ZonaFranca.cpp
	  // La Franca destruye la Fabricas
      Fabrica * elementos = zonaFranca.getFabrica("elemento",nombreElemento);
	  Fabrica * agrupadores = zonaFranca.getFabrica("agrupador",nombreAgrupador);  	  
	  Fabrica * visualizadores = zonaFranca.getFabrica("visualizador",nombreVisualizador);
		  
	  if(!elementos) {
		cout << "ERROR: No existe una fabrica de elementos llamados "<< nombreElemento << endl;  
	  }  
	  if(!agrupadores){
		cout << "ERROR: No existe una fabrica de agrupadores llamados "<< nombreAgrupador << endl;    
	  }
	  if(!visualizadores){
		cout << "ERROR: No existe una fabrica de visualizadores llamados "<< nombreVisualizador << endl;    
	  }
      if( elementos && agrupadores && visualizadores ){	  
		  Elemento * elemento = dynamic_cast<Elemento *>(elementos->producir());
		  Agrupador * agrupador = dynamic_cast<Agrupador *>(agrupadores->producir());
		  Visualizador * visualizador = dynamic_cast<Visualizador *>(visualizadores->producir());	  
		  
		  ifstream entrada(nombreArchivo);
		  
		  int n;
		  entrada >> n;
		  
		  // Insertar una copia de cada elemento obtenido desde el archivo nombreArchivo
		  Lista * lista = new Lista( elemento, entrada, n);

		  Lista * grupos = agrupador->agrupar(lista);
		  
		  visualizador->visualizar( grupos );  
		  
		  // Los productos y las listas son responsabilidad de ustedes
		  // La lista guarda copias de los elementos y debe destruirlos
		  delete grupos;
		  delete lista;
		  delete visualizador;
		  delete agrupador;
		  delete elemento;
			  
		  // LAS FABRICAS SON DESTRUIDAS POR LA ZONA FRANCA POR ESO CON CONST
		  // // delete visualizadores;
		  // delete agrupadores;
		  // delete elementos;
	   }
   }
   return 0;
}