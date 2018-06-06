#ifndef _HAC 
#define _HAC
#include "Agrupador.h"
#include "Lista.h"

class HAC: public Agrupador{

	private:
	int i;
	int j;

	public:
		HAC(); //constructor por defecto
        void matrizDistancias(Lista *);// calcula la distancia que existe entre todos los elementos de una lista y da la posicion de los mas cercanos
		void vectorDistancias(Lista *, Lista *);//calcula la distancia entre los elementos de una lista y otra lista y da la posicion del mas cercano 
        Lista::Iterator buscarIterador(Lista *, int);//busca el iterador de la lista basado en la posicion que se le indica
        Lista * agrupar(Lista *);//metodo final que devuelve la lista de los grupos realizados
		int tamanoLista(Lista *);//calcula el tamano de la lista
        void reiniciarLista(Lista &); // vacia una lista que recibe por referencia 
	
};
#endif