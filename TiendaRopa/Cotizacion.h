#pragma once
#include <iostream>
#include <ctime>
#include "Prenda.h"

#ifndef COTIZACION_H
#define COTIZACION_H
class Cotizacion {
	int NroIdentificacion;
	std::time_t fechaCotizacion;
	int nroVendedor;
	Prenda* prendaCotizada;
	int cantPrendas;
public:
	Cotizacion(int, std::time_t, int, Prenda*, int);
	int getNroIdentificacion();
	std::time_t getFechaCotizacion();
	int getNroVendedor();
	Prenda* getPrendaCotizada();
	int getCantPrendas();
	~Cotizacion();
};
#endif // !COTIZACION_H
