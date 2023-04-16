#pragma once
#include <iostream>
#ifndef MENU_H
#define MENU_H

class Menu {
private:
	void imprimirSeparador();
	void imprimirSalidaAlMenu();
	void imprimirPregunta();
public:
	void menuPrincipal(std::string,std::string,std::string,std::string);
	void imprimirHistorial(int, std::time_t, std::string, std::string, double, int);
	void imprimirPregunta(std::string);
};


#endif // !MENU_H
