#include "Kmeans.h"
#include "Lista.h"

/*constructor por omision de la clase*/
Kmeans::Kmeans(){
 tamanoL=0;

}


int Kmeans::tamanoLista(Lista * lista){
	int tamano=0;
	for(Lista::Iterator i = lista->begin(); i != lista->end(); ++i){
		++tamano;
	}
	return tamano;
}

void Kmeans::reiniciarLista(Lista & lista){
   for(Lista::Iterator i = lista.begin(); i != lista.end(); ++i){
	    lista.borrar(i);
	}	
}

double ** Kmeans::matrizDistancias(Lista * lista, Lista::Iterator cent1, Lista::Iterator cent2){
	this->tamanoL=tamanoLista(lista);
	
   double ** matriz = new double * [tamanoL];
   for(int i=0; i < tamanoL ;++i){
   		matriz[i]= new double[2];
     }

	 
   for( Lista::Iterator i=lista->begin(); i != lista->end(); ++i){
   		for(int x=0; x <tamanoL;++i){
   			for(int y=0; y < 2; ++i){
   				if(y==0){
   					matriz[x][y]= *i->distancia(*cent1); 
   				}else{
   					matriz[x][y]= *i->distancia(*cent2);

   				} 
   			}
   		}

   }

   return matriz;

}

int Kmeans::distanciaMenor(double distancia1, double distancia2){
	if(distancia1 > distancia2){
		return 1;

	}else{

		return 0;
	}
}

Lista * Kmeans::agrupar( Lista * lista){
	Lista::Iterator cent1=lista->begin();
	Lista::Iterator cent2= ++(lista->begin());
	double ** matriz= matrizDistancias(lista,cent1 ,cent2 );
	Lista * grupo1 = new Lista();
	Lista * grupo2 = new Lista();
	Lista * grupos = new Lista();
Lista::Iterator it= lista->begin();

	for(int x=0;  x < this->tamanoL && it!= lista->end() ; ++it, ++x){
		if(distanciaMenor(matriz[x][0], matriz[x][1])==0){
			grupo1 +=  *it;
		}else{
			grupo2+= *it;

		}

	}
        
	for(int n=0; n<50; ++n){
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
	for(a=0; a<tamanoLista(grupo2);++a){//busqueda del menor centroide 2
		if(vector2[a]< menor){
			pos2=a;
			menor= vector2[a];
		}	
	}

	delete []vector1;
	delete []vector2;
        vector1=0;
	vector2=0;
	
    matriz= matrizDistancias(lista,centroide(grupo1, pos1) , centroide(grupo2,pos2));
    
    reiniciarLista(*grupo1);
    reiniciarLista(*grupo2);
	
    for(int x=0, Lista::Iterator it= lista->begin();  x <this->tamanoL && it!= lista->end() ; ++it, ++x){
		if(distanciaMayor(matriz[x][0], matriz[x][1])==0){
			grupo1 +=  *it;
		}else{
			grupo2+= *it;

		}

	}
        }

	grupos+= grupo1;
	grupos+= grupo2;
	grupo1->~Lista();
	grupo2->~Lista();

	return grupos;
}

Lista::Iterator Kmeans::centroide(Lista * lista, int pos){
	Lista::Iterator nuevo; 
	for(int a=0, Lista::Iterator i=lista->begin(); a<pos ;++i){
		nuevo=i;
	}

	return nuevo;

}


