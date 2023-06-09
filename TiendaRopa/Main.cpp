#include "Presentador.h"
#include "Camisa.h"
#include "Pantalon.h"

int main() {
	setlocale(LC_ALL, "");//SE UTILIZA FORMATO ESPA�OL

	//CREACION DE UNA LISTA DE PRENDAS PARA INGRESAR A LA TIENDA
	std::vector<Prenda*> lsPrendas;
	lsPrendas.push_back(new Camisa(STANDARD, 100, 2000, CORTA, MAO));
	lsPrendas.push_back(new Camisa(PREMIUM, 100, 2000, CORTA, MAO));
	lsPrendas.push_back(new Camisa(STANDARD, 150, 2000, CORTA, COMUN));
	lsPrendas.push_back(new Camisa(PREMIUM, 150, 2000, CORTA, COMUN));
	lsPrendas.push_back(new Camisa(STANDARD, 75, 2000, LARGA, MAO));
	lsPrendas.push_back(new Camisa(PREMIUM, 75, 2000, LARGA, MAO));
	lsPrendas.push_back(new Camisa(STANDARD, 175, 2000, LARGA, COMUN));
	lsPrendas.push_back(new Camisa(PREMIUM, 175, 2000, LARGA, COMUN));

	lsPrendas.push_back(new Pantalon(STANDARD, 750, 3000, CHUPINES));
	lsPrendas.push_back(new Pantalon(PREMIUM, 750, 3000, CHUPINES));
	lsPrendas.push_back(new Pantalon(STANDARD, 250, 3000, COMUNES));
	lsPrendas.push_back(new Pantalon(PREMIUM, 250, 3000, COMUNES));
	
	//CREACION DE AL TIENDA
	Tienda* tienda =new Tienda("Expreso Ropitas", "av.Maipu 2320", lsPrendas);

	//CREAMOS LA VISATA PARA INCORPORAR AL PRESENTADOR
	View view = View(); 

	//CREAMOS EL VENDEDOR
	Vendedor vendedor = Vendedor("Diego", "Cuiti�o", 01, tienda);

	//FINAL MENTE CREAMOS EL PRESENTADOR
	//NO SE SI ES REALMENTE NECESARIO -- SE PODRIA HABER USADO EL VENDEDOR COMO PRESENTADOR �?
	Presentador presentador = Presentador(&vendedor, &view);

	delete tienda;
	
}