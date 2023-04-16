#include "Tienda.h"
#include "Vendedor.h"
#include <ctime>


Tienda::Tienda(std::string nombre, std::string direccion, std::vector<Prenda*> prendas) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->listaDePrendas = prendas;
}

std::string Tienda::getNombre() {
	return this->nombre;
}

std::string Tienda::getDireccion(){
	return this->direccion;
}

std::vector<Prenda*> Tienda::getListadoPrendas() {
	return this->listaDePrendas;
}

std::vector<Cotizacion*> Tienda::verHistorialCotizaciones() {
	return this->listaDeCotizaciones;
}

Tienda::~Tienda() {
	for (Cotizacion* cotizacion : listaDeCotizaciones) {
		delete cotizacion;
	}
	for (Prenda* prenda : listaDePrendas) {
		delete prenda;
	}
}

void Tienda::crearCotizacion(Vendedor* vendedor) {
	Prenda* prenda;
	int cantPrendas;
	int nroVendedor = vendedor->getNroVendedor();
	int nroIdentificacion = vendedor->presentador->paso(1,"",0,0);
	if (nroIdentificacion == 1) {
	 prenda = reservarCamisa(vendedor);
	 cantPrendas = prenda->getCantidad();
	}
	else {
		prenda = reservarPantalon(vendedor);
		cantPrendas = prenda->getCantidad();
	}
	std::time_t fechaHora = std::time(nullptr);
	Cotizacion* cotizacion = new Cotizacion(nroIdentificacion,fechaHora,nroVendedor,prenda,cantPrendas);
	listaDeCotizaciones.push_back(cotizacion);
}

Prenda* Tienda::reservarCamisa(Vendedor* vendedor)
{
	ETipoManga manga;
	ETipoCuello cuello;
	Calidad calidad;

	int resultado;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'a', 0);
	if (resultado != 3) resultado == 1 ? manga = CORTA : manga = CORTA;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'b', 0);
	if (resultado != 3) resultado == 1 ?  cuello = MAO: cuello = COMUN;
	resultado = vendedor->presentador->paso(3, "", 0, 0);
	if (resultado != 3) resultado == 1 ? calidad = PREMIUM : calidad = STANDARD;
	double precio = vendedor->presentador->paso();
	int cantidad =  vendedor->presentador->paso(5, "", 0,buscarCantidadDePrendas(manga,cuello,calidad));

	return new Camisa(calidad, cantidad, precio, manga, cuello);
	// retar cantidad al total para presupuestos futuros ???
}

Prenda* Tienda::reservarPantalon(Vendedor* vendedor)
{
	ETipoPantalon pantalon;
	Calidad calidad;

	int resultado;
	resultado = vendedor->presentador->paso(2, "PANTALON", 0, 0);
	if (resultado != 3) resultado == 1 ? pantalon = CHUPINES : pantalon = COMUNES;
	resultado = vendedor->presentador->paso(3, "", 0, 0);
	if (resultado != 3) resultado == 1 ? calidad = PREMIUM : calidad = STANDARD;
	double precio = vendedor->presentador->paso();;
	int cantidad = vendedor->presentador->paso(5, "", 0,buscarCantidadDePrendas( pantalon, calidad));

	return new Pantalon(calidad, cantidad, precio, pantalon);
}

int Tienda::buscarCantidadDePrendas(ETipoManga manga, ETipoCuello cuello,Calidad calidad)
{
	int cantidad = 0;
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Camisa*>(prenda) != NULL) {
			Camisa* a = dynamic_cast<Camisa*>(prenda);
			if (a->getTipoManga() == manga && a->getTipoCuello() == cuello && a->getCalidad() == calidad) {
				cantidad = a->getCantidad();
				break;
			}
		}
	}
	return cantidad;
}

int Tienda::buscarCantidadDePrendas(ETipoPantalon pantalon, Calidad calidad)
{
	int cantidad = 0;
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Pantalon*>(prenda) != NULL) {
			Pantalon* a = dynamic_cast<Pantalon*>(prenda);
			if (a->getCalidad() == calidad && a->getTipoPantalon() == pantalon) {
				cantidad = a->getCantidad();
				break;
			}
		}
	}
	return cantidad;
}