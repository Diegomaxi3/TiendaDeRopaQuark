#pragma once
#include <iostream>
#include <vector>
#include "Prenda.h"
#include "Cotizacion.h"

#ifndef TIENDA_H
#define TIENDA_H

class Tienda {
	std::string nombre;
	std::string direccion;
	std::vector<Prenda*> listaDePrendas;
	std::vector<Cotizacion*> listaDeCotizaciones;
public:
	Tienda(std::string, std::string, std::vector<Prenda*>);
	std::string getNombre();
	std::string getDireccion();
	std::vector<Prenda*> getListadoPrendas();
	std::vector<Cotizacion*> verHistorialCotizaciones();
	~Tienda();
};

#endif // !TIENDA_H
