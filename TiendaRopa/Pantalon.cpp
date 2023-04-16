#include "Pantalon.h"

Pantalon::Pantalon(Calidad calidad, int stock, double precio, ETipoPantalon tipo) {
	this->calidad = calidad;
	this->stock = stock;
	this->precioUnitario = precio;
	this->tipoPantalon = tipo;
	this->nombre = "Pantalon";
}

double Pantalon::getPrecio() {
	return this->precioUnitario;
}

std::string Pantalon::toString() {
	return nombre + " - " + (tipoPantalon == CHUPINES ? "Tipo chupin" : "tipo clasico") + " - " + (calidad == PREMIUM ? "Premium" : "Standard");
}

Calidad Pantalon::getCalidad() {
	return this->calidad;
}

int Pantalon::getCantidad(){
	return this->stock;
}