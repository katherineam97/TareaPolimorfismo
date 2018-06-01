#include "Lista.h"
#include "Enterito.h"
#include<iostream>
using namespace std;

int main(){
  Lista * lista;
  Lista * otra;
  Enterito * diez = new Enterito(10); // Protipo
  Enterito * veinte = new Enterito(20); // Protipo

//  int n;
//  cout << "Digite cuantos enteritos hay en cada lista y despues digitelos: "; 
//  cin >> n;
//  cout << "\nDigite los valores de la lista 1:";
  lista = new Lista();

  *lista+= diez;
  *lista+= diez;
    
//  lista = new Lista(enterito , cin , n);
//  cout << "\nDigite los valores de la lista 2:";
//  otra = new Lista(enterito , cin , n);
  otra = new Lista();
  *otra+= veinte;
  *otra+= veinte;
  *otra+= veinte;
  *otra+= veinte;

  cout << "LISTA 1"<< endl;
  cout << lista << endl;
  cout << "LISTA 2"<< endl;  
  cout << otra << endl;
  
  Lista::Iterator finalLista = lista->end();
for( Lista::Iterator i = lista->begin(); i!= finalLista ; ++i){
	cout << "<text>" << *i << "</text>" << endl;
	
}
  
  cout << "\nDistancia entre ellas :" << lista->distancia(otra) << endl;
  
  Lista nula;

  nula+= &nula;
  nula+= &nula;
  nula+= &nula;
      
  cout << &nula << endl;
  
  delete lista;
  delete otra;
  delete diez;
  delete veinte;
  return 0;
}