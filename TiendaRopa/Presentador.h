#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Vendedor.h"
#include "View.h"
#include "Cotizacion.h"

#ifndef PRESENTADOR_H
#define PRESENTADOR_H

class Vendedor;

class Presentador {
	Vendedor* vendedor;
	View* view;

	//Metodos propios
	void esperarRespuesta();
	void validarOpcion(int op);
public:
	//Metodos propios
	Presentador(Vendedor*,  View*);
	int parseInt(std::string);


	// Metodos del view
	void menuPrincipal();
	void imprimirHistorial(int, std::time_t, std::string, std::string, double, int);

	// nuevos para agregar al diagrama de clases//
	int paso(int, std::string,char,int);
	double paso();
	int paso(int cantidadDisponible);
};
#endif // !PRESENTADOR_H
