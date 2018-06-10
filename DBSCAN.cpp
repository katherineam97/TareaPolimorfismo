#include "DBSCAN.h"
#include "lista.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>

/**Constructor por defecto de la clase DBSCAN
*/
DBSCAN::DBSCAN()
{
	this->cantidad_Elementos = 0;
	this->min_Points = 0;
	this->epsilum = 0.0;
}


/**Metodo que se encarga de agrupar la lista creada con los elementos 
*/
Lista * DBSCAN::agrupar(Lista * lista_agrupar)
{
	// Se asigna al atributo cantidad_Elementos el valor de retorno de la funcion cuenta_Elementos
	this->cantidad_Elementos = cuenta_Elementos(lista_agrupar);
	// Defino el valor del RADIO DE BUSQUEDA y de PUNTOS MINIMOS para definir los nucleos
	this->min_Points = 1;
	this->epsilum = 0.10;
	
	int num_Elementos = this->cantidad_Elementos;
	double ** distancias = new double*[num_Elementos];
	for (int i = 0; i < num_Elementos; ++i)						// Ciclo que recorre las filas
	{
		distancias[i] = new double [num_Elementos];
		for (int j = 0; j < num_Elementos; ++j)					// Ciclo que recorre las columnas
		{
			distancias[i][j] = 0.0;
		}
	}
	rellena_Matriz_Distancia(lista_agrupar, distancias);		// Se llama al metodo rellena_Matriz_Distancia 
	Lista * lista_Final = generar_Lista(lista_agrupar, distancias);
	
	// BORRA LA MATRIZ DE DISTANCIAS
	for(int i = 0; i < num_Elementos; ++i) 
	{
		delete [] distancias[i];
	}
	delete [] distancias;
	return lista_Final;			// Retorna la lista agrupada
}


/**Metodo que se encarga de controlar el agrupamiento por medio de ciclos y la invocación al método recursivo que 
devuelve los grupos de datos ya en su forma de "cluster"
@param lista_Inicial, que es el puntero a Lista que apunta a la lista original
@param distancias, que es la matriz tipo double que contiene las distancias entre los elementos ya calculadas
@return resultado, que es un puntero a Lista
*/
Lista * DBSCAN::generar_Lista(Lista * lista_Inicial, double ** distancias)
{
	int num_provisional = 0;
	int num_aleatorio = 0;
	Lista * resultado = new Lista();
	// Creo un vector necesario para el agrupamiento entre los elementos e inicializo sus valores en 0
	int * vec = new int[this->cantidad_Elementos];
	for(int k = 0; k < this->cantidad_Elementos; ++k){
		vec[k] = 0;
	}
	// Ciclo para recorrer todos los numeros de la lista para ver si se pueden agrupar o no
	do{
		if(vec[num_aleatorio] == 0 || vec[num_aleatorio] == 2)
		{
			if ((verifica_Min_Points(distancias, num_aleatorio) >= this->min_Points))		
			{	
				vec[num_aleatorio] = 1;										// Le asigno 1 al vector en la posicion num_aleatorio
				Lista * lista_Temporal = new Lista();
				unir_Elementos(lista_Inicial, lista_Temporal, distancias, vec, num_aleatorio);
				(*resultado) += lista_Temporal;
				delete lista_Temporal;
			}
			else
			{
				vec[num_aleatorio] = 2;				// Evaluado pero no es min_Point y aun no está incluido en lista
			}
		}
		num_aleatorio++;
	}while(num_aleatorio!=cantidad_Elementos);
	
	// AGREGAR LOS ELEMENTOS QUE TENGAN UN 2 COMO ELEMENTOS DE LA LISTA ORIGINAL
	for (int j = 0; j < this->cantidad_Elementos; ++j)
	{
		if(vec[j] == 2)
		{
			(*resultado) += retorna_Elemento(lista_Inicial, j);
		}
	}
	return (resultado);								// Retorna la lista ya actualizada mediante el algoritmo de agrupamiento
}


/**Metodo recursivo encargado de ir obteniendo los clusters correspondientes con sus bordes y si encuentra un elemento al cual unirse
se llama recursivamente al mismo metodo pero con el otro dato como centro
@param lista_Inicial, que es un puntero a una Lista
@param distancias, que es la matriz que tiene ls ditancias calculadas entre los elementos
@param vec, que es un vector que contiene enteros, necesario para saber en cuales elementos ha revisado el algoritmo
@param numero, que es la posicion del elemento que está siendo núcleo del cluster en ese momento
*/
void DBSCAN::unir_Elementos(Lista * lista_Inicial, Lista * lista_temp, double ** distancias, int * vec, int numero)
{
	(*lista_temp) += retorna_Elemento(lista_Inicial, numero);
	
	for (int i = 0; i < this->cantidad_Elementos; ++i)		// Ciclo para recorrer el vector de elementos
	{
		if ( (distancias[numero][i] <= this->epsilum) && (numero!=i) && (vec[i] != 1) )			// Chequea si la distancia del centro es valida contra la de la posicion y si esta evaluando elementos distintos
		{
			vec[i] = 1;
			unir_Elementos(lista_Inicial, lista_temp, distancias, vec, i);		// Llamado recursivo al metodo
		}
	}
}


/**Metodo que retorna un elemento de la lista original, por medio de los iteradores
@param original, que es la lista original de los elementos que se están agrupando
@param vec, que es el vector de enteros que controla si ya han sido evaluados los puntos o no
@param num, que es el numero del elemento a devolver
@return *i, que es el elemento apuntador por el iterador creado localmente para el recorrido de la lista
*/
Elemento * DBSCAN::retorna_Elemento(Lista * original, int num)
{
	int contador = 0;															// Variable que cuenta por cual elemento voy contando
	Lista::Iterator finalLista = original->end();
	for(Lista::Iterator i = original->begin(); i!=finalLista; ++i)				// Recorre la lista por medio de un iterator
	{
		if (contador == num)			// Chequea si el contador es igual al parametro num, es decir, si estamos en el elemento deseado de la lista
		{
			return *i;					// Retorna el elemento apuntado por el Iterator
		}
		contador++;						// Aumenta contador
	}
}


/**Metodo que verifica si un potencial nucleo cumple con tener a su alrededor un minimo de points para su evaluación
*/
int DBSCAN::verifica_Min_Points(double ** distancia, int nucleo_evaluar)
{
	int points_asociados = 0;			// Variable que guardará la cantidad de los puntos asociados al elemento
	for (int i = 0; i < this->cantidad_Elementos; ++i)
	{
		if ((distancia[nucleo_evaluar][i] <= this->epsilum) && (nucleo_evaluar!=i))	// Chequea si la distancia en esa posicion es menor o igual que el radio escogido por defecto
		{
			points_asociados++;
		}
	}
	return points_asociados;			// Retorna el entero de los points_asociados
}


/**Metodo que cuenta la cantidad de elementos de la lista original mediante el uso de iterators, esto con el fin posterior
de crear una matriz con la distancia de cada elemento hacia los demás
@param elementos, que es un puntero a Lista que apunta a todos los elementos
@return contador, que es el entero que contiene la cantidad de elementos de la lista
*/ 
int DBSCAN::cuenta_Elementos(Lista * elementos)
{
	int contador = 0;
	// Se contará la cantidad de elementos de la lista 
	Lista::Iterator finalLista = elementos->end();
	for (Lista::Iterator cuenta = elementos->begin(); cuenta != finalLista; ++cuenta)
	{
		contador++;
	}
	return contador;	// Retorna el valor de la variable contador
}


/**Metodo o procedimiento que se encarga de calcular la distancia entre todos los elementos y almacenar estos resultados
en la matriz tipo double recibida como parametro
@param elementos, que es la lista con los elementos originales
@param matriz_Distancias, un puntero a puntero de double que contendrá las distancias de los elementos contra ellos mismos
*/
void DBSCAN::rellena_Matriz_Distancia(Lista * elementos, double ** matriz_Distancias)
{
	// Se definen variables para la ubicación de las posiciones de la matriz
	int x =0;
	int y =0;
	Lista::Iterator listaFinal = elementos->end();			// Se crea un iterator apuntando al final de la lista
	
	// Por medio de 2 iteradores que se iran desplazando, se logra acceder a las relaciones de cada elemento contra todos los
	// demas, para el respectivo calculo
	for (Lista::Iterator i = elementos->begin(); i!= listaFinal; ++i)	
	{
		for(Lista::Iterator j = elementos->begin(); j!= listaFinal; ++j)
		{
			if(x != y)	// Si el elemento no se compara contra sí mismo
			{
				matriz_Distancias[x][y] = (*i)->distancia(*j);		// Asigna el calculo de la distancia de los elementos apuntador por los Iteradores
			}
			else
			{
				matriz_Distancias[x][y] = 0.0;		// Ya que es la misma posicion, la distancia de un elemento consigo mismo es 0
			}
			++y;
		}
		y = 0;										// Reinicio la variable
		++x;
	}
}
