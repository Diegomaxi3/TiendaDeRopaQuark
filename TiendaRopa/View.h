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
	void imprimirCotizacion(int, std::time_t, std::string, std::string, double, int);
	void menuPrincipal(std::string, std::string, std::string, int); 
	void paso1();
	void pasoCamisa2a();
	void pasoCamisa2b();
	void pasoPantalon2();
	void paso3();
	void paso4();
	void paso5(int cantidad);
	void error(std::string);
};
#endif // !VIEW_H
