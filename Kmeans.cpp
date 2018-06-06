#include "Kmeans.h"
#include "Lista.h"

/**Metodo constructor por omision de la clase*/
Kmeans::Kmeans(){
 tamanoL=0;

}

/**Metodo que recorre la lista para saber su tamano
 @param lista
 @return tamano
*/
int Kmeans::tamanoLista(Lista * lista){
	int tamano=0;
	for(Lista::Iterator i = lista->begin(); i != lista->end(); ++i){
		++tamano;
	}
	return tamano;
}
/**Metodo que recorre la lista y va borrando todo lo que hay en ella, "la vacia"
 @param lista
*/
void Kmeans::reiniciarLista(Lista & lista){
   for(Lista::Iterator i = lista.begin(); i != lista.end(); ++i){
	    lista.borrar(i);
	}	
}


/**Metodo que crea un matriz con las distancias de todos los elementos de una lista con dos centroides
 @param lista, centroide1, centroide2
 @return matriz
*/
double ** Kmeans::matrizDistancias(Lista * lista, Lista::Iterator cent1, Lista::Iterator cent2){
	this->tamanoL=tamanoLista(lista);
	
   double ** matriz = new double * [tamanoL];
   for(int i=0; i < tamanoL ;++i){
   		matriz[i]= new double[2];
     }

//CAMBIE EL RECORRIDO, QUITE UN FOR Y AHORA ITERADOR AVANZA IGUAL QUE X
	Lista::Iterator i=lista->begin(); 
   		for(int x=0; x <tamanoL && i != lista->end();++x,++i){
   			for(int y=0; y < 2; ++y){
   				if(y==0){
   					matriz[x][y]= (*i)->distancia(*cent1); 
   				}else{
   					matriz[x][y]= (*i)->distancia(*cent2);

   				} 
   			}
			
   		}

   

   return matriz;

}


/**Metodo que encuentra la menor entre dos distancias
 @param distancia1,distancia2
 @return 1 si distancia2 es menor, 0 si distancia1 es la menor 
*/
int Kmeans::distanciaMenor(double distancia1, double distancia2){
	if(distancia1 > distancia2){
		return 1;

	}else{

		return 0;
	}
}


/**Metodo que agrupa basado en el algoritmo de kmeans
 @param lista
 @return lista
*/
Lista * Kmeans::agrupar( Lista * lista){
	
	
	if ( ++(lista->begin()) != NULL){//si hay mas de un elementoen lista
	//se escogen los dos primeros centroides de manera aleatoria
	Lista::Iterator cent1=lista->begin();
	Lista::Iterator cent2= ++(lista->begin());
	
	double ** matriz= matrizDistancias(lista,cent1 ,cent2 ); 
	Lista * grupo1 = new Lista();//representa los elementos agrupados con el centroide1
	Lista * grupo2 = new Lista();//representa los elementos agrupados con el centroide2
	Lista * grupos = new Lista();//lista final, cuando ya se hayan agrupado los dos grupos finales estos se agregaran a esta lista 
	

	Lista::Iterator it= lista->begin();
	for(int x=0;  x < this->tamanoL && it!= lista->end() ; ++it, ++x){// se agrupa basado en cual centroide se esta mas cerca el elemento
		if(distanciaMenor(matriz[x][0], matriz[x][1])==0){
			*grupo1 +=  (*it);
		}else{
			*grupo2 += (*it);

		}

	}
        
	for(int n=0; n<50; ++n){//se puso como condicion de parada un numero definido de iteraciones (50)
	//empieza la busqueda de los centroides
	double * vector1= new double[tamanoLista(grupo1)];// se inicializan vectores para encontrar la posicion del mas cercano al centroide anterior
	double * vector2= new double[tamanoLista(grupo2)];
	int i=0;
	int j=0;
	it= lista->begin();
	for(int x=0;  x < tamanoLista(lista) && it!= lista->end() ; ++it, ++x){
		if(distanciaMenor(matriz[x][0], matriz[x][1])==0){
			vector1[i]=matriz[x][0];
			++i;
		}else{
			vector2[j]=matriz[x][1];
			++j;

		}

	}
	
	int pos1=0;
	int pos2=0;
	double menor= vector1[0];
	for(int a=0; a<tamanoLista(grupo1);++a){//busqueda del menor para centroide 1
		if(vector1[a]< menor){
			pos1=a;
			menor= vector1[a];
		}	
	}
	
	menor=vector2[0];
	for(int a=0; a<tamanoLista(grupo2);++a){//busqueda del menor centroide 2
		if(vector2[a]< menor){
			pos2=a;
			menor= vector2[a];
		}	
	}

	delete []vector1;
	delete []vector2;
    vector1=0;
	vector2=0;
	
    matriz= matrizDistancias(lista, centroide(grupo1,pos1) , centroide(grupo2,pos2) );
    
    reiniciarLista(*grupo1);
    reiniciarLista(*grupo2);
	
	it= lista->begin();
    for(int x=0; x <this->tamanoL && it!= lista->end() ; ++it, ++x){
		if(distanciaMenor(matriz[x][0], matriz[x][1])==0){
			*grupo1 +=  (*it);
		}else{
			*grupo2+= (*it);

		}

	}
        } //terminan las 50 iteraciones

	*grupos += grupo1;
	*grupos += grupo2;
	grupo1->~Lista();
	grupo2->~Lista();

	return grupos;
	
	}else{//si solo hay un elemento en lista se retorna a ella misma
		
		return lista;
	
	}
	
}


/**Metodo que devuelve un iterador apuntando a una posicion que recibe de parametro 
 @param lista, pos
 @return iterador (nuevo)
*/
Lista::Iterator Kmeans::centroide(Lista * lista, int pos){
	Lista::Iterator nuevo; 
	Lista::Iterator i=lista->begin();
	for(int a=0; a<pos && i!= lista->end() ;++i){
		nuevo=i;
	}

	return nuevo;

}


