#ifndef _DBSCAN
#define _DBSCAN
#include "lista.h"
#include "Agrupador.h"
#include <cmath>
#include <stdio.h>
#include <fstream>

class DBSCAN : public Agrupador
{
	private:
		int cantidad_Elementos;											// Se define una variable para la cantidad de elementos de la lista original
		int min_Points;													// Se define una variable para la cantidad de puntos mínimos necesarios para el agrupamiento
		double epsilum;													// Se define una variable que servirá como medida de cercanía para 2 elementos
		
	public:
		DBSCAN();															// Constructor por omision						
		Lista * agrupar(Lista *);											// Metodo que se encarga de agrupar la lista y devolverla por puntero
		int cuenta_Elementos(Lista *);										// Metodo que se encarga de contar la cantidad de elementos de la lista
		void rellena_Matriz_Distancia(Lista *, double**);					// Procedimiento que rellena una matriz de double con la distancia entre todos los elementos
		Lista * generar_Lista(Lista *, double **);							// Metodo que retorna la lista ejecutada con los algoritmos de agrupamiento
		void unir_Elementos(Lista *, Lista *, double **, int* , int);		// Metodo que se encarga de unir los elementos en las listas y sublistas que se generarán
		Elemento * retorna_Elemento (Lista*, int);							// Metodo que retorna el elemento apuntador por un interator de Lista
		int verifica_Min_Points(double **, int);							// Metodo que devuelve el numero de elementos que estan asociados al nucleo seleccionado
};
#endif