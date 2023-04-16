#pragma once
#include <iostream>
#include <vector>
#include "Vendedor.h"
#include "View.h"
#include "Cotizacion.h"

#ifndef PRESENTADOR_H
#define PRESENTADOR_H

class Presentador {
	Vendedor vendedor;
	View view;

	//Metodos propios
	void esperarRespuesta();
	void validarOpcion();
public:
	//Metodos propios
	Presentador(Vendedor,  View);


	// Metodos del view
	void menuPrincipla(std::string, std::string, std::string, std::string);
	void imprimirHistorial(int, std::time_t, std::string, std::string, double, int);
	void imprimirPregunta(std::string);

	//Metodos del vendedor
	void crearCotizacion();


};
#endif // !PRESENTADOR_H
