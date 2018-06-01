#ifndef _KMEANS 
#define _KMEANS
#include "Agrupador.h"
#include "Lista.h"

class Kmeans: public Agrupador{
	
	private:
		int tamanoLista;
	public:
		Kmeans();//constructor por defecto
        double ** matrizDistancias(Lista *);// calcula la distancia que existe entre los centroides y los otros elementos
        int distanciaMayor(double, double); // busca en la matriz la mayor distancia 
        Lista * juntar(Lista *);//agrupa conn respecto a las distancias de la matriz 
        Lista::Iterador centroide(Lista *, Lista::Iterador, Lista::Iterador);//busca centroides despues de la primera busqueda(que es al azar)
        Lista * agrupar(Lista *);//metodo final que devuelve la lista de los grupos realizados
		int tamanoLista(Lista * lista);//calcula el tamano de la lista
};
#endif