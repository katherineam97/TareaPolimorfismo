#include "Lista.h"
#include "Enterito.h"
#include<iostream>
using namespace std;

int main(){
  Lista * lista;
  Lista * otra;
  Enterito * prototipo = new Enterito(0); // Protipo

  // En la tarea el formato de archivo es
  // numeritos.txt
  // 3  
  // 12
  // 20
  // 06
  // donde 3 es la cantidad de numeritos y luego viene un numerito en cada línea

  int n;
  cout << "Digite cuantos enteritos hay en cada lista y despues digitelos: "; 
  cin >> n;
  cout << "\nDigite los valores de la lista 1:";
  lista = new Lista(prototipo,cin,n);
  
  cout << "\nDigite los valores de la lista 2:";
  otra = new Lista(prototipo , cin , n);

  (*lista)+=otra;  
  (*lista)+=otra;  
  (*lista)+=lista;  
  
  (*otra)+= lista;
  
  cout << "LISTA 1"<< endl;
  cout << lista << endl;
  cout << "LISTA 2"<< endl;  
  cout << otra << endl;
  
  
  cout << "\nDistancia entre ellas :" << lista->distancia(otra) << endl;
  
  delete lista;
  delete otra;
  delete prototipo;
  return 0;
}