#include "Cotizacion.h"

Cotizacion::Cotizacion(int nroIdentificacion, std::string fechaHora, int nroVendedor, Prenda* prenda, int cantPrendas) {
	this->NroIdentificacion = nroIdentificacion;
	this->fechaCotizacion = fechaHora;
	this->nroVendedor = nroVendedor;
	this->prendaCotizada = prenda;
	this->cantPrendas = cantPrendas;
}

int Cotizacion::getNroIdentificacion() {
	return this->NroIdentificacion;
}

std::string Cotizacion::getFechaCotizacion() {
	return this->fechaCotizacion;
}

int Cotizacion::getNroVendedor() {
	return nroVendedor;
}

Prenda* Cotizacion::getPrendaCotizada() {
	return this->prendaCotizada;
}

int Cotizacion::getCantPrendas() {
	return this->cantPrendas;
}

Cotizacion::~Cotizacion() {
	delete this->prendaCotizada;
}