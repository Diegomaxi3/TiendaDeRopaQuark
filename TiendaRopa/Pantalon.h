#pragma once
#include <iostream>
#include "Prenda.h"
#include "ETipoPantalon.h"

#ifndef PANTALON_H
#define PANTALON

class Pantalon:public Prenda {
	Calidad calidad;
	int stock;
	std::string nombre;
	double precioUnitario;
	ETipoPantalon tipoPantalon;
public:
	Pantalon(Calidad, int,double, ETipoPantalon);
	double getPrecio();
	Calidad getCalidad();
	int getCantidad();
	ETipoPantalon getTipoPantalon();
	void setCantidad(int cantidad);
	std::string toString();
	~Pantalon() = default;
};
#endif // !PANTALON_H
