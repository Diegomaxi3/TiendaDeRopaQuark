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
	int nroIdentificacion = vendedor->presentador->paso1();
	if (nroIdentificacion == 1) {
	 prenda = reservarCamisa(vendedor);
	 cantPrendas = prenda->getCantidad();
	}
	else {
		prenda = reservarCamisa(vendedor);
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
	resultado = vendedor->presentador->pasoCamisa2a();
	if (resultado != 3) resultado == 1 ? manga = CORTA : manga = CORTA;
	resultado = vendedor->presentador->pasoCamisa2b();
	if (resultado != 3) resultado == 1 ?  cuello = MAO: cuello = COMUN;
	resultado = vendedor->presentador->paso3();
	if (resultado != 3) resultado == 1 ? calidad = PREMIUM : calidad = STANDARD;
	double precio = vendedor->presentador->paso4();
	int cantidad =  vendedor->presentador-> paso5(buscarCantidadDePrendas(manga,cuello,calidad));

	return new Camisa(calidad, cantidad, precio, manga, cuello);
	// retar cantidad al total para presupuestos futuros ???
}

Prenda* Tienda::reservarPantalon(Vendedor* vendedor)
{
	ETipoManga manga;
	ETipoCuello cuello;
	Calidad calidad;

	int resultado;
	resultado = vendedor->presentador->pasoCamisa2a();
	if (resultado != 3) resultado == 1 ? manga = CORTA : manga = LARGA;
	resultado = vendedor->presentador->pasoCamisa2b();
	if (resultado != 3) resultado == 1 ? cuello = MAO : cuello = COMUN;
	resultado = vendedor->presentador->paso3();
	if (resultado != 3) resultado == 1 ? calidad = PREMIUM : calidad = STANDARD;
	double precio = vendedor->presentador->paso4();
	int cantidad = vendedor->presentador->paso5(buscarCantidadDePrendas(manga, cuello, calidad));

	return new Camisa(calidad, cantidad, precio, manga, cuello);
}

int Tienda::buscarCantidadDePrendas(ETipoManga manga, ETipoCuello cuello,Calidad calidad)
{
	int cantidad = 0;
	for (Prenda* prenda : listaDePrendas) {
		Camisa* a = dynamic_cast<Camisa*>(prenda);
		if (a->getTipoManga() == manga && a->getTipoCuello() == cuello && a->getCalidad() == calidad) {
			cantidad = a->getCantidad();
			break;
		}
	}
	return cantidad;
}

int Tienda::buscarCantidadDePrendas(ETipoPantalon pantalon, Calidad calidad)
{
	int cantidad = 0;
	return cantidad;
}