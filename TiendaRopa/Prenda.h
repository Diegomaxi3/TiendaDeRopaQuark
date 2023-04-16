#pragma once
#include <iostream>
#include "ECalidad.h"

#ifndef PRENDA_H
#define PRENDA_H

class Prenda{
public:
	virtual double getPrecio() = 0;
	virtual std::string toString() = 0;
	virtual Calidad getCalidad() = 0;
	virtual int getCantidad() = 0;
	virtual ~Prenda() = default;
};
#endif // !PRENDA_H
