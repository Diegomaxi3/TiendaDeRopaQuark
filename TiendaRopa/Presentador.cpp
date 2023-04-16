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
	} while (getchar() != 3);
}

void Presentador::validarOpcion(int op) {
	switch (op) {
	case 1: vendedor->tienda->verHistorialCotizaciones(); break;
	case 2: vendedor->tienda->crearCotizacion(vendedor);break;
	case 3:break;
	default:break;
	}
}

int Presentador::paso1() {
	view->paso1();
	int resp;
	std::cin >> resp;
	return resp;
}

int Presentador::pasoCamisa2a() {
	view->pasoCamisa2a();
	int resp;
	std::cin >> resp;
	return resp;
}

int Presentador::pasoCamisa2b() {
	view->pasoCamisa2b();
	int resp;
	std::cin >> resp;
	return resp;
}

int Presentador::paso3() {
	view->paso3();
	int resp;
	std::cin >> resp;
	return resp;
}
double Presentador::paso4() {
	view->paso4();
	int resp;
	std::cin >> resp;
	return resp;
}

int Presentador::paso5(int cantidadaDisponible) {
	view->paso5(cantidadaDisponible);
	int resp;
	std::cin >> resp;
	return resp;
}



