#include "Presentador.h"

//CONSTRUCTOR DE CLASE
Presentador::Presentador(Vendedor* vendedor, View* view) 
{
	this->vendedor = vendedor;
	//LE ENCORPORAMOS UN PUNTERO DEL PRESENTADOR A EL VENDEDOR
	this->vendedor->setPresentador(this);
	this->view = view;
	//EMPIEZA EL PROGRAMA
	menuPrincipal();
}

void Presentador::menuPrincipal() {
	//SE LLAMA LA VISTA PARA MOSTRAR MENU Y SE ESPERA REPUESTA
	std::string op;
	do {
		view->menuPrincipal(vendedor->getNombreTienda(), vendedor->getDireccionTienda(), vendedor->getNombre()+ " "  + 
			vendedor->getApellido(), vendedor->getNroVendedor());
		getline(std::cin,op);		
		validarOpcion(parseInt(op)); //VALIDMOS LA OPCION ELEJIDA POR EL USUARIO
	} while (op._Equal("3")==0);     //SI ES # SALIMOS DEL SISTEMA
}

void Presentador::validarOpcion(int op) {
	switch (op) {
	case 1: imprimirHistorial(); break; 
	case 2: {	
		try {
			Cotizacion* cot = vendedor->tienda->crearCotizacion(vendedor); // SE CREA COTIZACION
			view->limpiarPantalla(); // ACTUALIZAMOS LA PANTALLA
			imprimirCotizacion(cot, 10); // ULTIMO PASO DE LA COTIZACION, MOSTRAR TERMINADA
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

//PASOS PARA INGRESAR LOS CRITERIO DE LA PRENDA
int Presentador::paso(int op, std::string tipo, char letra) {
	std::string resp;
	do {
		switch (op) {
		case 1:view->paso1();  break;
		case 2:
		{
			//SI LA OPCION ES CAMISA CONSULTO LA LETRA PARA SABER SI ESTMOS EN EL PASO |2A| o |2B|
			if (tipo == "CAMISA") letra == 'a' ? view->pasoCamisa2a() : view->pasoCamisa2b();
			//SINNO SE INGRESA A EL PASO 2 DEL PANTALON
			else view->pasoPantalon2();
		}break;
		case 3:view->paso3(); break;
		}
		getline(std::cin,resp);
		if (toUpper(resp).compare("S") == 0) throw(3); // POR LA NATURALEZA DEL MENU CREADO - TIRO UNA EXCEPCION PARA VOLVER AL MENU INICIAL
		if (resp.compare("1")!= 0 && resp.compare("2")!= 0) { //SE VALIDA QUE SE AYA INGRESADO UNA OPCION VALIDA
			view->error("La opción ingresada es incorrecta.");
			std::string b;//SE USAN PARA ESPERA EN PANTALLA
			getline(std::cin, b);		
		}
	} while (resp._Equal("1") == 0 && resp._Equal("2") == 0);
	return parseInt(resp);
}

//
double Presentador::paso() {
	std::string resp;
	do {
		view->paso4();	
		getline(std::cin, resp);
		if (toUpper(resp).compare("S") == 0) throw(3); // POR LA NATURALEZA DEL MENU CREADO - TIRO UNA EXCEPCION PARA VOLVER AL MENU INICIAL
		if (!parseDouble(resp)) {
			view->error("Ingrese un Valor valida!");
			std::string b;//SE USAN PARA ESPERA EN PANTALLA
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
		if (toUpper(resp).compare("S") == 0) throw(3); // POR LA NATURALEZA DEL MENU CREADO - TIRO UNA EXCEPCION PARA VOLVER AL MENU INICIAL
		if (!parseInt(resp) || parseInt(resp) > cantidadDisponible) {
			view->error("Ingrese una cantidad valida!");
			std::string b;//SE USAN PARA ESPERA EN PANTALLA
			getline(std::cin, b);
		}
	} while (!parseInt(resp) || parseInt(resp) > cantidadDisponible);

	return parseInt(resp);
}

//CONVERTIDOR DE STRING A INT
int Presentador::parseInt(std::string op) {
	std::stringstream aux;
	aux << op;
	int respuesta = 0;
	aux >> respuesta;
	return respuesta;
}

//CONVERTIDOR DE STRING A DOUBLE
double Presentador::parseDouble(std::string op) {
	std::stringstream aux;
	aux << op;
	double respuesta = 0;
	aux >> respuesta;
	return respuesta;
}

//CONVERTIDOR DE INT A STRING
std::string Presentador::parseString(int num) {
	std::stringstream aux;
	aux << num;
	std::string respuesta = "";
	return aux.str();
}

//SE CONSULTA LA LISTA DE COTIZACIONES DE LA TIENDA Y SE IMPRIME UNA A UNA
//SE MUESTRAN TODAS EN PANTALLA
void Presentador::imprimirHistorial(){
	int y = 2;
	view->limpiarPantalla();
	if (vendedor->tienda->verHistorialCotizaciones().size() > 0) {
		for (Cotizacion* cot : vendedor->tienda->verHistorialCotizaciones()) {
			y = imprimirCotizacion(cot, y);
		}
	}
	else { view->error("El Historial aun esta vacio!");	} //SI NO EXISTE NINGUAN SE AVISA POR PANTALLA
	std::string b;
	getline(std::cin, b);
}

//SE IMPRIME UNA COTIZACION POR PANTALLA
int Presentador::imprimirCotizacion(Cotizacion* cot,int y) {
	y = view->imprimirCotizacion(cot->getNroIdentificacion(), cot->getFechaCotizacion(), cot->getNroVendedor(), cot->prendaCotizada->toString(),
	cot->prendaCotizada->getPrecio(), cot->prendaCotizada->getCantidad(),y);	
	return y;
}

//SE LE AGREGA UN 0 EN STRING PARA DARLE FORMATO A LA HORA DE LA FECHA DE CADA COTIZACION
std::string Presentador::dateFormat(int num) {
	if (num < 10) {
		return "0" + parseString(num);
	}
	return parseString(num);
}

//SE DEVUELVE LA PALABRA EB MAYUSCOLAS PARA CONTROLES DE INGRESO DE DATOS
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
