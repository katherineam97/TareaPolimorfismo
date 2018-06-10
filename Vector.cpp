#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include "Vector.h"
using namespace std;

/**Metodo que sirve de constructor de la clase Vector
*/
Vector::Vector()
{
	this->vector = 0;
	this->dimension = 0;
	//this->cargar(entrada);
}


/**Metodo destructor de la clase Vector
*/
Vector::~Vector()
{
	if (this->vector != 0)	// Si vector es distinto de 0.0
	{
		delete [] this->vector;		// Libera la memoria
		this->vector = 0;
		this->dimension = 0;
	}
}


/**Metodo que asigna la dimension al Vector
@param dimension, que es el entero que contiene la cantidad de numeros que componen el vector
*/ 
void Vector::set_Dimension(int dimension)
{
	this->dimension = dimension;			// Se asigna al atributo la dimension recibida
}


/**Metodo que retorna la cantidad de numeros presentes en el vector (la dimensión)
@return dimension, que es el atributo de la clase 
*/
int Vector::get_Dimension()
{
	return this->dimension;
}


/**Metodo que imprime cada posicion o elemento del vector
@param salida, que es el flujo de datos de salida tipo ostream 
@return salida, el mismo flujo pero ya con los valores del vector
*/
ostream & Vector::imprimir(ostream & salida)
{
	if (this->vector != 0)			// Chequea si el vector es distinto de nulo
	{
		salida << "[ " ;
		// Ciclo que recorre el vector
		for (int i = 0; i < this->dimension; ++i)
		{
			//salida << i << " "; 
			salida << vector[i];
			
			if(i< this->dimension-1){
				salida << ", ";
			}
		}
		salida << "]" << endl;
	}
	return salida;					// Retorna el ostream salida
}


/**Metodo que se encarga de cargar en el vector de double los datos de la linea del archivo
@param entrada, que es un flujo de datos de un archivo
@return entrada
*/
istream & Vector::cargar(istream & entrada) //SUPONGO QUE AQUI RECIBE EL ISTREAM DEL ARCHIVO y el datosVector.txt tal como en el ejemplo
{
	int i = 0;										// Variable para manejar la posicion del vector
	entrada >> i;									// Obtengo la dimension
	this->set_Dimension(i);
	this->vector = new double[this->dimension];
	// Recorre el puntero a double llenandolo con el flujo del fstream entrada
	for(int index = 0; index < this->dimension; ++index)
	{
		entrada >> this->vector[index];
	}
	return entrada;
}


/**Metodo que se encarga de retornar la distancia del vector con otro elemento tipo vector, 
por medio de la distancia de cosenos
@param element, que es un puntero a Elemento, es decir un elemento al cual se le aplicará la distancia con el elemento actual
@return distancia, que es un double que contiene la distancia de un elemento con otro
*/
double Vector::distancia(Elemento * element)
{
	Vector * otro = new Vector(dynamic_cast<Vector &>(*element));
	double distancia = 0.0;
	// CALCULO DE LA DISTANCIA
	
	if(this->dimension != otro->dimension)		// Si tienen dimensión distinta la distancia es practicamente infinita
	{
		distancia = 1.0;
	}
	else
	{
		distancia = calculo_Distancia(otro);	// Se llama al metodo calculo_Distancia
	}
	// Elimino el vector creado
	delete otro;
	otro = 0;
	return distancia;			// Retorno la variable distancia
}


/**Metodo que realiza el calculo de la distancia entre 2 vectores, tomando como referencia cada uno de sus elementos
@param otro, que es un puntero a un elemento tipo Vector
@return calculo, que es el calculo de la distancia propia
*/
double Vector::calculo_Distancia(Vector * otro)
{
	double calculo = 0.0;
	double producto_punto = 0.0;
	double producto_norma = 0.0;
	// Ciclo para recorrer todas las posiciones de cada uno de los vectores, esto para realizar su suma
	for(int vec_position = 0; vec_position < this->dimension; ++vec_position)
	{
		producto_punto += (this->vector[vec_position] * otro->vector[vec_position]);					// Va sumando las multiplicaciones
	}
	if(producto_punto < 0)			// Se valida contra que el producto punto sea negativo
	{
		producto_punto *= -1;
	}
	producto_norma = this->calculo_Norma() * otro->calculo_Norma();				// Se calcula el producto de las normas de los vectores
	calculo = producto_punto / producto_norma;									// Se realiza el calculo de la distancia entre los cocientes
	return calculo;
}


/**Metodo que se encarga de calcular la magnitud o norma de un vector, esto para el posterior cálculo de su distancia
contra otros elementos tipo Vector o listas tipo Vector
@return norma, que es un double que contiene el valor en numero real de la norma del vector
*/
double Vector::calculo_Norma()
{
	double norma = 0.0;						// Se define la variable a almacenar la norma calculada
	for(int vec_position = 0; vec_position < this->dimension; ++vec_position)
	{
		// Se usa la funcion pow para elevar a un exponente el numero que deseamos, en este caso elevando al cuadrado
		norma += pow(this->vector[vec_position],2.0);
	}
	norma = sqrt(norma);					// Se calcula la raíz cuadrada de la suma de los elementos del vector
	return norma;							// Retorna la variable norma con el calculo realizado
}


/**Metodo que toma una linea del archivo (un vector) y lo va descomponiendo hasta obtener el contador con la cantidad de numeros
almacenados en ese vector
@param vector, que es un const char * con la linea o vector a contar, separator que es un const char * que delimita
la separacion de un numero de otro
@return contador, que es la variable que indica la cantidad de numeros que contiene un vector
*/
int Vector::cuenta_Numeros(const char * vector, const char * separator){
	int contador = 0;							// Definimos variable llamada contador
	// Se crea un char * que contendrá la linea ya preparada para segmentar
	char * hileraVector = strtok((char *) vector, separator);
	while(hileraVector!=NULL)					// Mientras la hilera sea distinta de Null
	{
		contador++;								
		hileraVector = strtok(NULL, separator);
	}
	return contador;							// Retorno la variable contador
}


/**Metodo que retorna una copia del Vector con todos sus elementos
@return copia, que es un puntero a Vector
*/
Vector * Vector::clonar()
{
	Vector * copia = new Vector();							// Se crea por omision el vector a copia
	copia->set_Dimension(this->get_Dimension());			// Se establece la dimension de copia
	copia->vector = new double[this->get_Dimension()];		// Se guarda el espacio en memoria para almacenar los doubles
	//Ciclo que recorre el vector para copiar cada uno de los datos
	for(int vec_position = 0; vec_position < this->dimension; ++vec_position)
	{
		copia->vector[vec_position] = this->vector[vec_position];
	}
	return copia;											// Retorna la copia
}