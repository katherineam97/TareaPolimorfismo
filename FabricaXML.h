#ifndef _FABRICA_XML
#define _FABRICA_XML
#include "Producto.h"
#include "Fabrica.h"
#include "XML.h"
class FabricaXML : public Fabrica{//hereda de la clase fabrica
	public:
	Producto * producir();
	FabricaXML();

};

#endif