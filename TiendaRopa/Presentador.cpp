#include "Presentador.h"


Presentador::Presentador(Vendedor* vendedor, View* view) 
{
	this->vendedor = vendedor;
	this->vendedor->setPresentador(this);
	this->view = view;
	menuPrincipal();
}

void Presentador::menuPrincipal() {
	std::string op;
	do {
		view->menuPrincipal(vendedor->getNombreTienda(), vendedor->getDireccionTienda(), vendedor->getNombre()+ " "  + 
			vendedor->getApellido(), vendedor->getNroVendedor());
		getline(std::cin,op);
		validarOpcion(parseInt(op));
	} while (op._Equal("3")==0);
}

void Presentador::validarOpcion(int op) {
	switch (op) {
	case 1: vendedor->tienda->verHistorialCotizaciones(); break;
	case 2: vendedor->tienda->crearCotizacion(vendedor);break;
	case 3:break;
	default: {
		view->error("La opción ingresada no existe."); 
		std::string b;
		getline(std::cin, b);
		break;
	    }
	}
}


int Presentador::paso(int op, std::string tipo, char letra,int cantidadDisponible) {
	int resp;
	do {
		switch (op) {
		case 1:view->paso1();  break;
		case 2:
		{
			if (tipo == "CAMISA") letra == 'a' ? view->pasoCamisa2a() : view->pasoCamisa2b();
			else view->pasoPantalon2();
		}break;
		case 3:view->paso3(); break;
		}
		std::cin >> resp;
	} while (resp != 1 && resp != 2);
	std::string b;
	getline(std::cin, b);
	return resp;
}

double Presentador::paso() {
	view->paso4();
	int resp;
	std::cin >> resp;
	std::string a;
	std::getline(std::cin, a);
	return resp;
}

int Presentador::paso(int cantidadDisponible) {
	view->paso5(cantidadDisponible);
	int resp;
	std::cin >> resp;
	std::string b;
	getline(std::cin, b);
	return resp;
}

int Presentador::parseInt(std::string op) {
	std::stringstream aux;
	aux << op;
	int respuesta;
	aux >> respuesta;
	return respuesta;
}



