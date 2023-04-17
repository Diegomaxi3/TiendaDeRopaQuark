#pragma once
#include <iostream>
#include <windows.h>

#ifndef VIEW_H
#define VIEW_H

class View {
private:
	void gotoxy(int x, int y);
	void imprimirSeparador();
	void imprimirSalidaAlMenu(int x, int y);
	void imprimirPregunta(int x,int y);
public:	
	View()=default;
	int imprimirCotizacion(int, std::string, int, std::string, double, int,int);
	void menuPrincipal(std::string, std::string, std::string, int); 
	void paso1();
	void pasoCamisa2a();
	void pasoCamisa2b();
	void pasoPantalon2();
	void paso3();
	void paso4();
	void paso5(int cantidad);
	void error(std::string);
	void limpiarPantalla();
};
#endif // !VIEW_H
