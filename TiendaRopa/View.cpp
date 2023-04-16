#include "View.h"

using namespace std;

void View::gotoxy(int x, int y) {
	HANDLE hand;
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hand, dwPos);
}

std::string View::imprimirSeparador() {
	cout << "-------------------------------------------------------------------------";
}

std::string View::menuPrincipal(std::string nomTienda, std::string direTienda, std::string nomApeVendedor, std::string idVendedor) {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "MENU PRINCIPAL";
	gotoxy(20, 10 + 1); imprimirSeparador();
	gotoxy(20, 10 + 2); cout << nomTienda << " | " << direTienda;
	gotoxy(20, 10 + 3); imprimirSeparador();
	gotoxy(20, 10 + 4); cout << nomApeVendedor << " | " << idVendedor;
	gotoxy(20, 10 + 4); imprimirSeparador();

	gotoxy(20, 10 + 7); cout << "SELECCIONE UNA OPCIÓN DEL MENÚ: ";
	gotoxy(20, 10 + 9); cout << "1 - Historial de Cotizaciones: ";
	gotoxy(20, 10 + 10); cout << "2 - Realizar Cotización: ";
	gotoxy(20, 10 + 11); cout << "3 - Salir: ";
	gotoxy(20, 10 + 12); cout << "OPCION:  ";

}

void View::imprimirSalidaAlMenu(int x, int y) {
	gotoxy(x, y); imprimirSeparador();
	gotoxy(x + 1, y + 1); cout << "Presione 3 para volver al menu principal";
	gotoxy(x + 2, y + 2); imprimirSeparador();
}

std::string View::paso1() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "seleccione la prenda a utilizar: ";
	gotoxy(20, 10 + 7); cout << "1 - Camisa";
	gotoxy(20, 10 + 8); cout << "2 - Pantalon";
	gotoxy(20, 10 + 9); cout << "OPCION: ";
	gotoxy(20, 10 + 10);cout << imprimirSeparador();
}

std::string View::pasoCamisa2a() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "PASO 2.a: la camisa a cotizar, es manga corta? ";
	imprimirPregunta(20, 10 + 7);
	gotoxy(20, 10 + 9); cout << "OPCION: ";
	gotoxy(20, 10 + 10); cout << imprimirSeparador();
}

std::string View::pasoCamisa2b() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "PASO 2.b: la camisa a cotizar, es cuello mao? ";
    imprimirPregunta(20, 10 + 7);
	gotoxy(20, 10 + 9); cout << "OPCION: ";
	gotoxy(20, 10 + 10); cout << imprimirSeparador();
}

std::string View::pasoPantalon2() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "PASO 2: el pantalon a cotizar, es chupín? ";
	imprimirPregunta(20, 10 + 7);
	gotoxy(20, 10 + 9); cout << "OPCION: ";
	gotoxy(20, 10 + 10); cout << imprimirSeparador();
}

std::string View::paso3() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "seleccione la calidad de la prenda ";
	gotoxy(20, 10 + 7); cout << "1 - Estandar";
	gotoxy(20, 10 + 8); cout << "2 - Premium";
	gotoxy(20, 10 + 9); cout << "OPCION: ";
	gotoxy(20, 10 + 10); cout << imprimirSeparador();
}

std::string View::paso4() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "PASO 4: Ingrese el precio unitario de la prenda a utilizar:  ";
	gotoxy(20, 10 + 6); cout << "Precio: ";
	gotoxy(20, 10 + 7); cout << imprimirSeparador();
}

std::string View::paso5() {
	gotoxy(20, 10); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(20 + 1, 10 + 1);
	gotoxy(20, 10 + 5); cout << "PASO 4: Ingrese el precio unitario de la prenda a utilizar:  ";
	gotoxy(20, 10 + 6); cout << "Precio: ";
	gotoxy(20, 10 + 7); cout << imprimirSeparador();
}

void View::imprimirPregunta(int x, int y) {
	 gotoxy(x, y); 	 cout << "1 - SI";
	 gotoxy(x, y + 1); cout << "2 - NO";
}

