#include "Tienda.h"
#include "Vendedor.h"
#include <ctime>

int Tienda::nroCotizacion = 0;

Tienda::Tienda(std::string nombre, std::string direccion, std::vector<Prenda*> prendas) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->listaDePrendas = prendas;
}

std::string Tienda::getNombre() {
	return this->nombre;
}

std::string Tienda::getDireccion(){
	return this->direccion;
}

std::vector<Prenda*> Tienda::getListadoPrendas() {
	return this->listaDePrendas;
}

std::vector<Cotizacion*> Tienda::verHistorialCotizaciones() {
	return this->listaDeCotizaciones;
}

//DESTURTOR - SACAMOS DE MOMORIA TODAS LAS COTIZACIONES Y PRENSAR EN LAS LISTAS
Tienda::~Tienda() {
	for (Cotizacion* cotizacion : listaDeCotizaciones) {
		delete cotizacion;
	}
	for (Prenda* prenda : listaDePrendas) {
		delete prenda;
	}
}

//SE CREAN LAS COTIZACIONES
Cotizacion* Tienda::crearCotizacion(Vendedor* vendedor) {
	Prenda* prenda;
	int cantPrendas;
	int nroVendedor = vendedor->getNroVendedor();

		if (vendedor->presentador->paso(1, "", 0) == 1) {
			//SI ES CAMISA ENTRA AQUI
			prenda = reservarCamisa(vendedor);
			cantPrendas = prenda->getCantidad();
		}
		else {	
			//SINO ES PANTALON ENTA AQUI
			prenda = reservarPantalon(vendedor);
			cantPrendas = prenda->getCantidad();
		}

		///CALCULO FECHA ACTUAL Y LA GUARDAMOS EUN STRING 
		std::time_t fechaHora = time(&fechaHora);
		struct tm newtime;
		localtime_s(&newtime, &fechaHora);
		std::string fecha = vendedor->presentador->parseString(newtime.tm_mday) + "/"
			+ vendedor->presentador->parseString(newtime.tm_mon + 1) + "/" +
			vendedor->presentador->parseString(1900 + newtime.tm_year) + " " +
			vendedor->presentador->dateFormat(newtime.tm_hour) + ":" +
			vendedor->presentador->dateFormat(newtime.tm_min);


		//SE UTILIZA UNA VARIABLE STATIC PARA EL ID DE COTIZACIONES
		int nroIdentificacion = vendedor->tienda->nroCotizacion + 1;
		vendedor->tienda->nroCotizacion = nroIdentificacion;
		Cotizacion* cotizacion = new Cotizacion(nroIdentificacion, fecha, nroVendedor, prenda, cantPrendas);
		listaDeCotizaciones.push_back(cotizacion);
	
	return cotizacion;
}

Prenda* Tienda::reservarCamisa(Vendedor* vendedor)
{
	//INIZIALIZAMOS CON VALORES POR DEFECTO
	ETipoManga manga = LARGA;
	ETipoCuello cuello= COMUN;
	Calidad calidad = STANDARD;

	//PREGUANTAMOS LOS CRITERIOS DEL PANTALON
	int resultado;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'a');
	if (resultado != 3) resultado == 1 ? manga = CORTA : manga = LARGA;
	resultado = vendedor->presentador->paso(2, "CAMISA", 'b');
	if (resultado != 3) resultado == 1 ?  cuello = MAO: cuello = COMUN;
	resultado = vendedor->presentador->paso(3, "", 0);
	if (resultado != 3) resultado == 1 ? calidad = STANDARD : calidad = PREMIUM;

	//SE PREGUNA EL PRECIO	
	double precio = vendedor->presentador->paso();

	//ACTUALIZAMOS PRECIOS SEGUN CRITERIOS 
	manga == CORTA ? precio *= 0.9 : precio = precio;
	cuello == MAO ? precio *= 1.03 : precio = precio;
	calidad == PREMIUM ? precio *= 1.3 : precio = precio;

	//BUSCAMOS LA CANTIDAD DE STOCK
	Prenda* prenda = buscarCantidadDePrendas(manga, cuello, calidad);

	///SE ACTUALIZA CANTIDA DE STOCK
	//LO ACTUALIZO PARA PROBAR LA FUNCIONABILIDAD EN CAIDA DE STOCK
	//NO SE ESTA SEGURO DE RESERVAR STOCK EN UNA COTIZACION
	int cantidad =  vendedor->presentador->paso(prenda->getCantidad());
	prenda->setCantidad(prenda->getCantidad() - cantidad);

	//RETORNAMOS  LA PRENDA CON LAS CARECTERISTICAS DADAS PARA COTIZAR
	return new Camisa(calidad, cantidad, precio, manga, cuello);
	// retar cantidad al total para presupuestos futuros ???
}

Prenda* Tienda::reservarPantalon(Vendedor* vendedor)
{
	//INIZIALIZAMOS CON VALORES POR DEFECTO
	ETipoPantalon pantalon = COMUNES;
	Calidad calidad = STANDARD;

	//PREGUANTAMOS LOS CRITERIOS DEL PANTALON
	int resultado;
	resultado = vendedor->presentador->paso(2, "PANTALON", 0);
	if (resultado != 3) resultado == 1 ? pantalon = CHUPINES : pantalon = COMUNES;
	resultado = vendedor->presentador->paso(3, "", 0);
	if (resultado != 3) resultado == 1 ? calidad = STANDARD : calidad = PREMIUM;

	//SE PREGUNA EL PRECIO	
	double precio = vendedor->presentador->paso();

	//ACTUALIZAMOS PRECIOS SEGUN CRITERIOS 
	pantalon == CHUPINES ? precio *= 0.88 : precio = precio;
	calidad == PREMIUM ? precio *= 1.3 : precio = precio;
	//

	//BUSCAMOS LA CANTIDAD DE STOCK
	Prenda* prenda = buscarCantidadDePrendas(pantalon, calidad);
	int cantidad = vendedor->presentador->paso(prenda->getCantidad());

	///SE ACTUALIZA CANTIDA DE STOCK
	//LO ACTUALIZO PARA PROBAR LA FUNCIONABILIDAD EN CAIDA DE STOCK
	//NO SE ESTA SEGURO DE RESERVAR STOCK EN UNA COTIZACION
	prenda->setCantidad(prenda->getCantidad() - cantidad);

	//RETORNAMOS  LA PRENDA CON LAS CARECTERISTICAS DADAS PARA COTIZAR
	return new Pantalon(calidad, cantidad, precio, pantalon);
}


/// DOS METODOS DE BUSQUEDA UNO PARA LA CAMISA Y OTRO PARA EL PANTALON

Prenda* Tienda::buscarCantidadDePrendas(ETipoManga manga, ETipoCuello cuello,Calidad calidad)
{
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Camisa*>(prenda) != NULL) {
			Camisa* a = dynamic_cast<Camisa*>(prenda);
			if (a->getTipoManga() == manga && a->getTipoCuello() == cuello && a->getCalidad() == calidad) {
				return prenda;
				break;
			}
		}
	}
}

//SEGUNDO BUSCADOR
Prenda* Tienda::buscarCantidadDePrendas(ETipoPantalon pantalon, Calidad calidad)
{
	int cantidad = 0;
	for (Prenda* prenda : listaDePrendas) {
		if (dynamic_cast<Pantalon*>(prenda) != NULL) {
			Pantalon* a = dynamic_cast<Pantalon*>(prenda);
			if (a->getCalidad() == calidad && a->getTipoPantalon() == pantalon) {
				return prenda;
			}
		}
	}
}
