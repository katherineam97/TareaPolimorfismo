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
 y encuentra la posicion de los elemento mas cercanos entre ellos (los de menor distancia)
 @param lista
 @return matriz 
*/
void HAC::matrizDistancias(Lista * lista){
	int tamanoL=tamanoLista(lista);
	
   double ** matriz = new double * [tamanoL];
   for(int i=0; i < tamanoL ;++i){
   		matriz[i]= new double[tamanoL];
    }
	
	
	int x=0;
	int y=0;
	for(Lista::Iterator i = lista->begin(); i != lista->end() && x<tamanoL ; ++i, ++x){
		for(Lista::Iterator it = lista->begin();it != lista->end() && y<tamanoL; ++it, ++y){			
			matriz[x][y]= (*i)->distancia(*it);
				
		}
		y=0;
	}
	
	
	//encuentra el menor dentro de la matriz creada
	//cada vez que se cree la matriz ya se sabe cuales son las posiciones(i,j) del menor
	
	double menor = matriz[0][1];
	i=0;
	j=1;
	
	for(int x=0; x <tamanoL ; ++x){
   		for(int y=0; y < tamanoL; ++y){
			
		if (x!=y && matriz[x][y]< menor ){
			menor=matriz[x][y];
			this->i=x;
			this->j=y;
			
		}
		}
	}

	
	for(int n=0; n <tamanoL ; ++n){
	delete [] matriz[n];
	}
	
	matriz=0;
	
}


/**Metodo que crea un vector que almacena las distancias de cada uno de los elementos de la lista con un elemento que sera una lista (lista2) 
y encuentra la posicion del elemento mas cercano (el de la distancia menor)
 @param lista1, lista2
 @return vector 
*/
int HAC::vectorDistancias(Lista * lista1, Lista * lista2){
	int pos=0;
	int tamanoL=tamanoLista(lista1);
	
    double * vector = new double [tamanoL];

	 
	int x=0;
	
   for(Lista::Iterator i = lista1->begin(); i != lista1->end() && x<tamanoL ; ++i, ++x){
			vector[x]= lista2->distancia(*i);
   		
   	}
	
	
	//encuentra el menor dentro de el vector creada
	//cada vez que se cree el vector ya se sabe cuales son las posiciones(i,j) del menor
	double menor = vector[0];
	pos=0;
	
	for(int y=0; y < tamanoL; ++y){
			
		if ( vector[y]< menor ){
			menor=vector[y];
			pos=y;
			
		}
		}
   		
   delete [] vector;
   vector=0;
	return pos;
}

/**Metodo que recorre la lista y va borrando todo lo que hay en ella, "la vacia"
 @param lista
*/
void HAC::reiniciarLista(Lista & lista){
	Lista::Iterator i= lista.begin();
   while(i != lista.end()){
	    lista.borrar(i);
	}	
	
}

 
/**Metodo que devuelve un iterador apuntando a una posicion que recibe de parametro 
 @param lista, pos
 @return iterador (nuevo)
*/
Lista::Iterator HAC::buscarIterador(Lista * lista, int pos){
	
	Lista::Iterator i=lista->begin();
	for(int a=0; a<pos ;++a){
		++i;
	}

	return i;

} 
 
        
Lista * HAC::agrupar(Lista * lista){
	
	if ( ++(lista->begin()) != NULL){//si hay mas de un elemento en la lista
		Lista * lista1 = new Lista();
		Lista * lista2 = new Lista();
		
		matrizDistancias(lista);//calcula la posicion de los dos elementos mas cercanos en lista. i, j son atributos de la clase y son "llenados" en este metodo
		
		*lista1 += *buscarIterador(lista, i);//agrega los dos mas cercanos, busca el elemento en la posicion i de la lista
		*lista1 += *buscarIterador(lista, j);//agrega los dos mas cercanos, busca el elemento en la posicion j de la lista
		
		Lista::Iterator nuevo= buscarIterador(lista,i);
		
		Lista::Iterator nuevo2= buscarIterador(lista,j);
		
		lista->borrar(nuevo);//borra en la lista original los elementos que ya fueron agregados 
		
		lista->borrar(nuevo2);//borra en la lista original los elementos que ya fueron agregados 
				
		while(lista->begin() != NULL){
			
			*lista2 += lista1; //agrega lo que hay en la lista1
			
			this->i=vectorDistancias(lista,lista1);//este metodo encuentra la posicion del mas cercano con lista1. Distancia entre todos los elementos de lista con el elemento lista1
			
			
			*lista2 += *buscarIterador(lista, i);//agrega el elemento que calculo vector distancias como el mas cercano a lista1
			
			nuevo= buscarIterador(lista,i);
			
			lista->borrar(nuevo);//se borra lo que ya se agrego
			
			reiniciarLista(*lista1);
				
			*lista1 += lista2;
			reiniciarLista(*lista2);	
						
		}
		
		lista2->~Lista();
		
		return lista1;
		
	}else{//si solo habia un elemento en lista se retorna la misma que recibe 
		
		return lista;
	}
		
		
}






