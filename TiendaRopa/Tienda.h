#pragma once
#include <iostream>
#include <vector>
#include "Prenda.h"
#include "Cotizacion.h"
#include "Vendedor.h"
#include "Pantalon.h"
#include "Camisa.h"

#ifndef TIENDA_H
#define TIENDA_H
class Vendedor;

class Tienda {
	std::string nombre;
	std::string direccion;
	std::vector<Prenda*> listaDePrendas;
	std::vector<Cotizacion*> listaDeCotizaciones;
	static int nroCotizacion;
public:
	Tienda(std::string, std::string, std::vector<Prenda*>);
	std::string getNombre();
	std::string getDireccion();
	std::vector<Prenda*> getListadoPrendas();
	std::vector<Cotizacion*> verHistorialCotizaciones();
	void imprimirCotizacion();

	Cotizacion* crearCotizacion(Vendedor *vendedor);
	Prenda* reservarCamisa(Vendedor* vendedor) ;
	Prenda* reservarPantalon(Vendedor* vendedor) ;
	Prenda* buscarCantidadDePrendas(ETipoManga, ETipoCuello, Calidad) ;
	Prenda* buscarCantidadDePrendas(ETipoPantalon, Calidad) ;
	~Tienda();
};

#endif // !TIENDA_H
