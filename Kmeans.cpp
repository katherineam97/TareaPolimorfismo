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
	tamanoL=tamano;
	return tamano;
}
/**Metodo que recorre la lista y va borrando todo lo que hay en ella, "la vacia"
 @param lista
*/
void Kmeans::reiniciarLista(Lista & lista){
	Lista::Iterator i = lista.begin();
   while(i != lista.end()){
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
int Kmeans::buscarMenor(double * vector, int tamano){
	int pos;
    double cero=0.0;
	double menor= vector[1];
	for(int a=0; a<tamano;++a){//busqueda del menor para centroide 1
		if(vector[a]<= menor && vector[a]!= cero){
			pos=a;
			menor= vector[a];
		}	
	}
    return pos;
}

Lista * Kmeans::agrupar( Lista * lista){
	int pos1=0;
	int pos2=0;
	
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
    Lista::Iterator * cent;
	Lista::Iterator * centr;
    
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
	
    
	pos1= matrizMenor(grupo1);
	pos2= matrizMenor(grupo2);

	delete []vector1;
	delete []vector2;
	vector1=0;
	vector2=0;
	cent = centroide(grupo1,pos1);
	centr = centroide(grupo2,pos2);
    matriz= matrizDistancias(lista,cent1  ,cent2  );
    reiniciarLista(*grupo1);//representa los elementos agrupados con el centroide1
	reiniciarLista(*grupo2);//representa los elementos agrupados con el centroide2

	delete cent;
	delete centr;
	cent=0;
	centr=0;
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
    grupo1=0;
    grupo2=0;
	return grupos;
	
	}else{//si solo hay un elemento en lista se retorna a ella misma
		
		return lista;
	
	}
	
}


/**Metodo que devuelve un iterador apuntando a una posicion que recibe de parametro 
 @param lista, pos
 @return iterador (nuevo)
*/
Lista::Iterator * Kmeans::centroide(Lista * lista, int pos){
	Lista::Iterator * nuevo; 
	Lista::Iterator i=lista->begin();
	for(int a=0; a<=pos && i!= lista->end() ;++i, ++a){
		if(a==pos){
			nuevo = new Lista::Iterator(i);
		}
	}
	return nuevo;

}

int  Kmeans::matrizMenor(Lista * lista){
	this->tamanoL=tamanoLista(lista);
   double * vector= new double[tamanoL];
   double ** matriz = new double * [tamanoL];
   
   for(int i=0; i < tamanoL ;++i){
   		matriz[i]= new double[tamanoL];
     }
     int f=0;
     int c=0;
    
    for(Lista::Iterator i=lista->begin(); i!=lista->end();++i){
        for(Lista::Iterator j=lista->begin(); j!=lista->end();++j){
           matriz[f][c]= (*i)->distancia(*j);
           ++c;
        }
        c=0;
        ++f;
    }

    double suma=0.0;
    int a=0;

    for(int i=0; i<tamanoL;++i){

    	for(int j =0; j<tamanoL;++j){
              suma+=matriz[i][j];
    	}
    	vector[a]=suma;
    	suma=0.0;
    	++a;
    }

    return buscarMenor(vector, tamanoL);

}
