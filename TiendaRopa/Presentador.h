#pragma once
#include <iostream>
#include <vector>
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


	// Metodos del view
	void menuPrincipal();
	void imprimirHistorial(int, std::time_t, std::string, std::string, double, int);
	void imprimirPregunta(std::string);

	// nuevos para agregar al diagrama de clases//
	int paso1();
	int pasoCamisa2a();
	int pasoCamisa2b();
	int pasoPantalon2();
	int paso3();
	double paso4();
	int paso5(int cantidad);

};
#endif // !PRESENTADOR_H
