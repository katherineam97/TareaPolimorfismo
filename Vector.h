#ifndef _Vector
#define _Vector
#include <iostream>
#include "Elemento.h"

class Vector : public Elemento{
	private:
		double * vector;										// Vector a double que será el elemento
		int dimension;											// Entero que almacena la cantidad de numeros del elemento, su dimensión
		int cuenta_Numeros(const char *, const char *);			// Metodo que devuelve la cantidad de numeros de un elemento vector 
		
	protected:
		ostream & imprimir(ostream &);							// Método que imprime el elemento en pantalla
		istream & cargar(istream &);							// Método que carga el elemento con el istream o flujo de entrada
	public:
		Vector();												// Constructor de vector
		~Vector();												// Destructor
		Vector * clonar();										// Clonar que devuelve un puntero a Vector (una copia)
		//double distancia(Vector *);							
		void set_Dimension(int);								// Metodo que devuelve asigna la dimension de un vector
		double calculo_Norma();									// Metodo que se encarga de calcular la norma de un vector 
		double distancia(Elemento *);							// Metodo que retorna la distancia de cosenos
		double calculo_Distancia(Vector *);						// Metodo que realiza el calculo de la distancia entre 2 vectores
		int get_Dimension();									// Metodo que retorna la dimension del Vector
};
#endif