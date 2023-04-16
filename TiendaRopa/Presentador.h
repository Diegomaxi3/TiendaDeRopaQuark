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
	int paso(int, std::string,char,int);
	double paso();
};
#endif // !PRESENTADOR_H
