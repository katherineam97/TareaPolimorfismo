#ifndef _KMEANS 
#define _KMEANS
#include "Agrupador.h"
#include "Lista.h"

class Kmeans: public Agrupador{
	
	private:
		int tamanoL;//tamano de lista
	public:
		Kmeans();//constructor por defecto
        double ** matrizDistancias(Lista *,Lista::Iterator, Lista::Iterator);// calcula la distancia que existe entre los centroides y los otros elementos
        int distanciaMenor(double, double); // busca en la matriz la mayor distancia  
        Lista::Iterator centroide(Lista *, Lista::Iterator, Lista::Iterator);//busca centroides despues de la primera busqueda(que es al azar)
        Lista * agrupar(Lista *);//metodo final que devuelve la lista de los grupos realizados
	int tamanoLista(Lista *);//calcula el tamano de la lista
        void reiniciarLista(Lista &);               
};
#endif
