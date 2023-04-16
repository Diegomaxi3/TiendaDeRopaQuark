#pragma once
#include <iostream>
#include <windows.h>

#ifndef VIEW_H
#define VIEW_H

class View {
private:
	void gotoxy(int x, int y);
	std::string imprimirSeparador();
	void imprimirSalidaAlMenu(int x, int y);
	void imprimirPregunta(int x,int y);
public:	
	View();
	std::string menuPrincipal(std::string, std::string, std::string, std::string);
	std::string imprimirHistorial(int, std::time_t, std::string, std::string, double, int);
	std::string paso1();
	std::string pasoCamisa2a();
	std::string pasoCamisa2b();
	std::string pasoPantalon2();
	std::string paso3();
	std::string paso4();
	std::string paso5();
};
#endif // !VIEW_H
