#include "Presentador.h"
#include <string>

Presentador::Presentador(Vendedor* vendedor, View* view) 
{
	this->vendedor = vendedor;
	this->vendedor->setPresentador(this);
	this->view = view;
	menuPrincipal();
}

void Presentador::menuPrincipal() {
	int op;
	do {
		view->menuPrincipal(vendedor->getNombreTienda(), vendedor->getDireccionTienda(), vendedor->getNombre()+ " "  + 
			vendedor->getApellido(), vendedor->getNroVendedor());
		std::cin >> op;
		validarOpcion(op);
	} while (op != 3);
}

void Presentador::validarOpcion(int op) {
	switch (op) {
	case 1: vendedor->tienda->verHistorialCotizaciones(); break;
	case 2: vendedor->tienda->crearCotizacion(vendedor);break;
	case 3:break;
	default:break;
	}
}


int Presentador::paso(int op, std::string tipo, char letra,int cantidadDisponible) {
	int resp;
	switch (op) {
	case 1:view->paso1();  break;
	case 2: 
	{
		if (tipo == "CAMISA") letra == 'a' ? view->pasoCamisa2a() : view->pasoCamisa2b();
		else view->pasoPantalon2();	
	}break;
	case 3:view->paso3(); break;
	case 5:view->paso5(cantidadDisponible); break;
	}
	std::cin >> resp;
	return resp;
}

double Presentador::paso() {
	view->paso4();
	int resp;
	std::cin >> resp;
	return resp;
}



