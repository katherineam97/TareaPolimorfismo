#include "Kmeans.h"
#include "Lista.h"

Kmeans::Kmeans(){
 tamanoLista=0;

}


int kmeans::tamanoLista(Lista * lista){
	int tamano=0;
	for(lista::Iterador i = lista->begin(); i != lista->end(); ++i){
		++tamano;
	}
	return tamano;
}

double ** Kmeans::matrizDistancias(Lista * lista, Lista::Iterador cent1, Lista::Iterador cent2){
	tamanoLista=tamanoLista(lista);
	
   double ** matriz = new double * [tamanoLista];
   for(i=0; i < tamanoLista ;++i){
   		matriz[i]= new double[2];
     }

   for(lista::Iterador i = lista->begin(); i != lista->end(); ++i){
   		for(int x=0; x <tamanoLista;++i){
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

Lista * Kmeans::juntar( Lista * lista){
	Lista::Iterador cent1=lista->begin();
	Lista::Iterador cent2= ++cent1;
	double ** matriz= matrizDistancias(lista,cent1 ,cent2 );
	Lista * grupo1 = new Lista();
	Lista * grupo2 = new Lista();
	Lista * grupos = new Lista();
	
	for(int x=0, Lista::Iterador i= lista->begin();  x <tamanoLista && i!= lista->end() ; ++i, ++x){
		if(distanciaMenor(matriz[x][0], matriz[x][1])==0){
			grupo1 +=  *i;
		}else{
			grupo2+= *i;

		}

	}
	
	//DENTRO DEL WHILE
	double * vector1= new double[grupo1->tamanoLista()];
	double * vector2= new double[grupo2->tamanoLista()];
	int i=0;
	int j=0;
	for(int x=0, Lista::Iterador i= lista->begin();  x < lista->tamanoLista() && i!= lista->end() ; ++i, ++x){
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
	for(int a=0; a<grupo1->tamanoLista();++a){
		if(vector1[a]< menor){
			pos1=a;
			menor= vector1[a];
		}	
	}
	
	menor=vector2[0];
	for(a=0; a<grupo2->tamanoLista();++a){
		if(vector2[a]< menor){
			pos2=a;
			menor= vector2[a];
		}	
	}
	//BORRAR VECTORES
	
    matriz= matrizDistancias(lista,centroide(grupo1, pos1) , centroide(grupo2,pos2));
    //Hay que reiniciar las listas de grupo1 y grupo2
	//REPETIR PROCESO UTILIZANDO EL METODO DE BUSCAR CENTROIDES PERO A PARTIR DE LA SEGUNDA ITERACION LA ANTERIOR ES LA PRIMERA
     
    /*for(int x=0, lista->Lista::Iterador i;  x <tamanoLista && i!= lista->end() ; ++i, ++x){
		if(distanciaMayor(matriz[x][0], matriz[x][1])==0){
			grupo1 +=  i.getElemento();
		}else{
			grupo2+= i.getElemento();

		}

	}*/

	grupos+= grupo1;
	grupos+= grupo2;
	return grupos;
}

Lista::Iterador Kmeans::centroide(Lista * lista, int pos){
	Lista::Iterator nuevo; 
	for(int a=0, Lista::Iterator i=lista->begin(); a<pos ;++i){
		nuevo=i;
	}

	return nuevo;

}

Lista * Kmeans::agrupar(Lista * lista){




}