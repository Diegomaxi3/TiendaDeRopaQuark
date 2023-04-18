#pragma once
#include <iostream>
#include <vector>
#include "Presentador.h"
#include "Cotizacion.h"
#include "Tienda.h"

#ifndef VENDEDOR_H
#define VENDEDOR_H

class Presentador;
class Tienda;

class Vendedor {
	std::string nombre;
	std::string apellido;
	int nroVendedor;
	
public:
	Presentador *presentador;
	Tienda* tienda;

	Vendedor()=default;
	Vendedor(std::string, std::string, int,Tienda*);
	std::string getNombre();
	std::string getApellido();
	int getNroVendedor();
	std::string getNombreTienda();
	std::string getDireccionTienda();
	void setPresentador(Presentador* presentador);
	~Vendedor()=default;
};
#endif // !VENDEDOR_H
