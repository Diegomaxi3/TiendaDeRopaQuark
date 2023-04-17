#include "Tienda.h"
#include "Vendedor.h"
#include <ctime>

int Tienda::nroCotizacion = 0;

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

Cotizacion* Tienda::crearCotizacion(Vendedor* vendedor) {
	Prenda* prenda;
	int cantPrendas;
	int nroVendedor = vendedor->getNroVendedor();

		if (vendedor->presentador->paso(1, "", 0) == 1) {
			prenda = reservarCamisa(vendedor);
			cantPrendas = prenda->getCantidad();
		}
		else {		
			prenda = reservarPantalon(vendedor);
			cantPrendas = prenda->getCantidad();
		}
		std::time_t fechaHora = time(&fechaHora);
		struct tm newtime;
		localtime_s(&newtime, &fechaHora);
		std::string fecha = vendedor->presentador->parseString(newtime.tm_mday) + "/"
			+ vendedor->presentador->parseString(newtime.tm_mon + 1) + "/" +
			vendedor->presentador->parseString(1900 + newtime.tm_year) + " " +
			vendedor->presentador->dateFormat(newtime.tm_hour) + ":" +
			vendedor->presentador->dateFormat(newtime.tm_min);

		int nroIdentificacion = vendedor->tienda->nroCotizacion + 1;
		vendedor->tienda->nroCotizacion = nroIdentificacion;
		Cotizacion* cotizacion = new Cotizacion(nroIdentificacion, fecha, nroVendedor, prenda, cantPrendas);
		listaDeCotizaciones.push_back(cotizacion);
	
	return cotizacion;
}

Prenda* Tienda::reservarCamisa(Vendedor* vendedor)
{
	ETipoManga manga;
	ETipoCuello cuello;
	Calidad calidad;

	int resultado;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'a');
	if (resultado != 3) resultado == 1 ? manga = CORTA : manga = LARGA;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'b');
	if (resultado != 3) resultado == 1 ?  cuello = MAO: cuello = COMUN;
	resultado = vendedor->presentador->paso(3, "", 0);
	if (resultado != 3) resultado == 1 ? calidad = STANDARD : calidad = PREMIUM;
	double precio = vendedor->presentador->paso();
	Prenda* prenda = buscarCantidadDePrendas(manga, cuello, calidad);
	int cantidad =  vendedor->presentador->paso(prenda->getCantidad());

	prenda->setCantidad(prenda->getCantidad() - cantidad);
	return new Camisa(calidad, cantidad, precio, manga, cuello);
	// retar cantidad al total para presupuestos futuros ???
}

Prenda* Tienda::reservarPantalon(Vendedor* vendedor)
{
	ETipoPantalon pantalon;
	Calidad calidad;

	int resultado;
	resultado = vendedor->presentador->paso(2, "PANTALON", 0);
	if (resultado != 3) resultado == 1 ? pantalon = CHUPINES : pantalon = COMUNES;
	resultado = vendedor->presentador->paso(3, "", 0);
	if (resultado != 3) resultado == 1 ? calidad = PREMIUM : calidad = STANDARD;
	double precio = vendedor->presentador->paso();
	Prenda* prenda = buscarCantidadDePrendas(pantalon, calidad);
	int cantidad = vendedor->presentador->paso(prenda->getCantidad());

	prenda->setCantidad(prenda->getCantidad() - cantidad);
	return new Pantalon(calidad, cantidad, precio, pantalon);
}

Prenda* Tienda::buscarCantidadDePrendas(ETipoManga manga, ETipoCuello cuello,Calidad calidad)
{
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Camisa*>(prenda) != NULL) {
			Camisa* a = dynamic_cast<Camisa*>(prenda);
			if (a->getTipoManga() == manga && a->getTipoCuello() == cuello && a->getCalidad() == calidad) {
				return prenda;
				break;
			}
		}
	}
}


Prenda* Tienda::buscarCantidadDePrendas(ETipoPantalon pantalon, Calidad calidad)
{
	int cantidad = 0;
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Pantalon*>(prenda) != NULL) {
			Pantalon* a = dynamic_cast<Pantalon*>(prenda);
			if (a->getCalidad() == calidad && a->getTipoPantalon() == pantalon) {
				return prenda;
			}
		}
	}
}
