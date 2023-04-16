#include "Vendedor.h"

Vendedor::Vendedor(std::string nombre, std::string apellido, int nroVendedor, Tienda* tienda) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->nroVendedor = nroVendedor;
	this->tienda = tienda;
}

std::string Vendedor::getNombre() {
	return this->nombre;
}

std::string Vendedor::getApellido() {
	return this->apellido;
}

int Vendedor::getNroVendedor() {
	return this->nroVendedor;
}

std::string Vendedor::getNombreTienda() {
	return this->tienda->getNombre();
}

std::string Vendedor::getDireccionTienda() {
	return this->tienda->getDireccion();
}

void Vendedor::setPresentador(Presentador* presentador) {
	this->presentador = presentador;
}
