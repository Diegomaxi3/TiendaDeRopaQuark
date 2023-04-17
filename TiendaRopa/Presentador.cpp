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
	case 1: imprimirHistorial(); break;
	case 2: {	
		try {
			Cotizacion* cot = vendedor->tienda->crearCotizacion(vendedor);
			view->limpiarPantalla();
			imprimirCotizacion(cot, 10);
			std::string b;
			getline(std::cin, b);
		}
		catch (int num) {};
		break;
	}
	case 3:break;
	default: {
		view->error("La opción ingresada no existe."); 
		std::string b;
		getline(std::cin, b);
		break;
	    }
	}
}


int Presentador::paso(int op, std::string tipo, char letra) {
	std::string resp;
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
		getline(std::cin,resp);
		if (toUpper(resp).compare("S") == 0) throw(3);
		if (resp.compare("1")!= 0 && resp.compare("2")!= 0) {
			view->error("La opción ingresada es incorrecta.");
			std::string b;
			getline(std::cin, b);		
		}
	} while (resp._Equal("1") == 0 && resp._Equal("2") == 0);
	return parseInt(resp);
}

double Presentador::paso() {
	std::string resp;
	do {
		view->paso4();	
		getline(std::cin, resp);
		if (toUpper(resp).compare("S") == 0) throw(3);
		if (!parseDouble(resp)) {
			view->error("Ingrese un Valor valida!");
			std::string b;
			getline(std::cin, b);
		}
	} while (!parseDouble(resp));
	return parseDouble(resp);
}

int Presentador::paso(int cantidadDisponible) {
	std::string resp;
	do {
		view->paso5(cantidadDisponible);
		getline(std::cin, resp);
		if (toUpper(resp).compare("S") == 0) throw(3);
		if (!parseInt(resp) || parseInt(resp) > cantidadDisponible) {
			view->error("Ingrese una cantidad valida!");
			std::string b;
			getline(std::cin, b);
		}
	} while (!parseInt(resp) || parseInt(resp) > cantidadDisponible);

	return parseInt(resp);
}

int Presentador::parseInt(std::string op) {
	std::stringstream aux;
	aux << op;
	int respuesta = 0;
	aux >> respuesta;
	return respuesta;
}

double Presentador::parseDouble(std::string op) {
	std::stringstream aux;
	aux << op;
	double respuesta = 0;
	aux >> respuesta;
	return respuesta;
}

std::string Presentador::parseString(int num) {
	std::stringstream aux;
	aux << num;
	std::string respuesta = "";
	return aux.str();
}

void Presentador::imprimirHistorial(){
	int y = 2;
	view->limpiarPantalla();
	if (vendedor->tienda->verHistorialCotizaciones().size() > 0) {
		for (Cotizacion* cot : vendedor->tienda->verHistorialCotizaciones()) {
			y = imprimirCotizacion(cot, y);
		}
	}
	else { view->error("El Historial aun esta vacio!");	}
	std::string b;
	getline(std::cin, b);
}
int Presentador::imprimirCotizacion(Cotizacion* cot,int y) {
	y = view->imprimirCotizacion(cot->getNroIdentificacion(), cot->getFechaCotizacion(), cot->getNroVendedor(), cot->prendaCotizada->toString(),
	cot->prendaCotizada->getPrecio(), cot->prendaCotizada->getCantidad(),y);	
	return y;
}

std::string Presentador::dateFormat(int num) {
	if (num < 10) {
		return "0" + parseString(num);
	}
	return parseString(num);
}

std::string Presentador::toUpper(std::string dato) {
	std::string retorno = dato;
	int cont = 0;
	for (char letra : dato) {
		char letra1 = std::toupper(letra);
		retorno[cont] = letra1;
		cont++;
	}
	return retorno;
}
