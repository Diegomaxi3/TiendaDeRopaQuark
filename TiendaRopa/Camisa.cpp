#include "Camisa.h"

Camisa::Camisa(Calidad calidad, int stock, double precio, ETipoManga manga, ETipoCuello cuello) {
	this->calidad = calidad;
	this->stock = stock;
	this->nombre = "Camisa";
	this->tipoManga = manga;
	this->tipoCuello = cuello;
	this->precioUnitario = precio;
}

double Camisa::getPrecio() {
	return this->precioUnitario;
}

ETipoManga Camisa::getTipoManga()
{
	return this->tipoManga;
}
ETipoCuello Camisa::getTipoCuello()
{
	return this->tipoCuello;
}

Calidad Camisa::getCalidad() {
	return this->calidad;
}

int Camisa::getCantidad() {
	return this->stock;
}

void Camisa::setCantidad(int cantidad) {
	this->stock = cantidad;
}

std::string Camisa::toString() {
	return nombre + " - " + (tipoManga == CORTA ? "Manga corta" : "Manga larga") + " - " + 
		(tipoCuello == MAO ? "Cuello mao" : "Cuello clásico") + " - " +  (calidad == PREMIUM ? "Premium" : "Standard");
}