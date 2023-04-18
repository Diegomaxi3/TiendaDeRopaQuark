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
	void validarOpcion(int op);
public:
	//Metodos propios
	Presentador(Vendedor*,  View*);
	int parseInt(std::string);
	double parseDouble(std::string op);
	std::string parseString(int);
	std::string dateFormat(int);
	std::string toUpper(std::string);

	// Metodos del view
	void menuPrincipal();
	void imprimirHistorial();
	int imprimirCotizacion(Cotizacion*, int);

	// nuevos para agregar al diagrama de clases//
	int paso(int, std::string,char);
	double paso();
	int paso(int cantidadDisponible);
};
#endif // !PRESENTADOR_H
