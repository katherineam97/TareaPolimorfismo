#include "HAC.h"
#include "Lista.h"


/**Metodo constructor por omision de la clase*/
HAC::HAC(){
	i=0;
	j=0;
}

/**Metodo que recorre la lista para saber su tamano
 @param lista
 @return tamano
*/
int HAC::tamanoLista(Lista * lista){
	int tamano=0;
	for(Lista::Iterator i = lista->begin(); i != lista->end(); ++i){
		++tamano;
	}
	return tamano;
}


/**Metodo que crea una matriz que almacena las distancias de cada uno de los elementos de la lista con todos ellos 
 @param lista
 @return matriz 
*/
double ** HAC::matrizDistancias(Lista * lista){
	int tamanoL=tamanoLista(lista);
	
   double ** matriz = new double * [tamanoL];
   for(int i=0; i < tamanoL ;++i){
   		matriz[i]= new double[tamanoL];
    }
	
	int x=0;
	int y=0;
	for(Lista::Iterator i = lista->begin(); i != lista->end() && x<tamanoL ; ++i, ++x){
		for(Lista::Iterator it = lista->begin(); i != lista->end() && y<tamanoL; ++i, ++y){			
			matriz[x][y]= (*i)->distancia(*it);
				
		}
		y=0;
	}
	
	//encuentra el menor dentro de la matriz creada
	//cada vez que se cree la matriz ya se sabe cuales son las posiciones(i,j) del menor
	int menor =matriz[0][0];
	for(int x=0; x <tamanoL ; ++x){
   		for(int y=0; y < tamanoL; ++y){
		if (matriz[x][y]< menor){
			menor=matriz[x][y];
			this->i=x;
			this->j=y;
			
		}
		}
	}

	return matriz;

}


/**Metodo que crea un vector que almacena las distancias de cada uno de los elementos de la lista con un elemento que sera una lista (lista2) 
 @param lista1, lista2
 @return vector 
*/
double * HAC::vectorDistancias(Lista * lista1, Lista * lista2){
	int tamanoL=tamanoLista(lista1);
	
   double * vector = new double [tamanoL];

	 
	Lista::Iterator i=lista1->begin();
   	for(int x=0; x <tamanoL &&  i != lista1->end(); ++x, ++i){
   		
			vector[x]= (*i)->distancia(lista2);

   		
   	}
	
	
	//encuentra el menor dentro de el vector creada
	//cada vez que se cree el vector ya se sabe cuales son las posiciones(i,j) del menor
	int menor =vector[0];
	for(int x=0; x <tamanoL ; ++x){
   		
		if (vector[x]< menor){
			menor=vector[x];
			this->i=x;
			this->j=x;
		}
	}
   		
   return vector;
	
}

/**Metodo que recorre la lista y va borrando todo lo que hay en ella, "la vacia"
 @param lista
*/
void HAC::reiniciarLista(Lista & lista){
   for(Lista::Iterator i = lista.begin(); i != lista.end(); ++i){
	    lista.borrar(i);
	}	
}

 
        
Lista * HAC::agrupar(Lista * lista){
	
		
}






