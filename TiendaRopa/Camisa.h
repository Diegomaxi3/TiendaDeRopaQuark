#pragma once
#include <iostream>
#include "Prenda.h"
#include "ETipoCuello.h"
#include "ETipoManga.h"

#ifndef CAMISA_H
#define CAMISA_H
class Camisa:Prenda {
	Calidad calidad;
	int stock;
	std::string nombre;
	double precioUnitario;
	ETipoManga tipoManga;
	ETipoCuello tipoCuello;

public:
	Camisa(Calidad, int, std::string, double, ETipoManga, ETipoCuello);
	double getPrecio();
	std::string toString();
	~Camisa() = default;
};
#endif // !CAMISA_H
