#pragma once
#include <iostream>
#include "Prenda.h"
#include "ETipoPantalon.h"

#ifndef PANTALON_H
#define PANTALON

class Pantalon:Prenda {
	Calidad calidad;
	int stock;
	std::string nombre;
	double precioUnitario;
	ETipoPantalon tipoPantalon;
public:
	Pantalon(Calidad, std::string, int,double, ETipoPantalon);
	double getPrecio();
	std::string toString();
	~Pantalon() = default;
};
#endif // !PANTALON_H
