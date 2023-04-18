#pragma once
#include <iostream>
#include <ctime>
#include "Prenda.h"

#ifndef COTIZACION_H
#define COTIZACION_H
class Cotizacion {
	int NroIdentificacion;
	std::string fechaCotizacion;
	int nroVendedor;	
	int cantPrendas;
public:
	Prenda* prendaCotizada;
	Cotizacion(int, std::string, int, Prenda*, int);
	int getNroIdentificacion();
	std::string getFechaCotizacion();
	int getNroVendedor();
	Prenda* getPrendaCotizada();
	int getCantPrendas();
	~Cotizacion();
};
#endif // !COTIZACION_H
