#pragma once
#include <iostream>
#include "Prenda.h"
#include "ETipoCuello.h"
#include "ETipoManga.h"

#ifndef CAMISA_H
#define CAMISA_H
class Camisa:public Prenda {
	Calidad calidad;
	int stock;
	std::string nombre;
	double precioUnitario;
	ETipoManga tipoManga;
	ETipoCuello tipoCuello;

public:
	Camisa(Calidad, int, double, ETipoManga, ETipoCuello);
	double getPrecio();
	std::string toString();
	ETipoManga getTipoManga();
	ETipoCuello getTipoCuello();
	Calidad getCalidad();
	void setCantidad(int cantidad);
	int getCantidad();
	~Camisa() = default;
};
#endif // !CAMISA_H
