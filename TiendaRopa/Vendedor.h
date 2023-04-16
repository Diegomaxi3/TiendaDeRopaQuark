#pragma once
#include <iostream>
#include <vector>
#include "Cotizacion.h"
#include "Tienda.h"

#ifndef VENDEDOR_H
#define VENDEDOR_H

class Vendedor {
	std::string nombre;
	std::string apellido;
	std::string nroVendedor;
	Tienda* tienda;
public:
	Vendedor(std::string, std::string, std::string,Tienda*);
	std::string getNombre();
	std::string getApellido();
	std::string getNroVendedor();
	void crearCotizacion();
	void verHistorialCotizaciones();
	void imprimirCotizacion();
	~Vendedor();
};
#endif // !VENDEDOR_H
