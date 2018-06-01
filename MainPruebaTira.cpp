#include "Tira.h"
#include "Elemento.h"
#include<iostream>
using namespace std;
int main(){
   Elemento * e = new Tira();
 //  Tira e2((const Elemento) *e);
   cin >> e;
   cout << e;
 //  *e = e2;
   Elemento * e3 = e->clonar();
   cout << "Distancia e2 a e3"<< e->distancia(e3)<< endl;
   
   return 0;
}