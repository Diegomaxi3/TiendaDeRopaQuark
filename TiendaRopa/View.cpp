#include "View.h"
#define POSX 35
#define POSY 10
#define SALIR "S"


using namespace std;

void View::gotoxy(int x, int y) {
	HANDLE hand;
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hand, dwPos);
}

void View::imprimirSeparador() {
	std::cout << "-------------------------------------------------------------------------";
}

void View::menuPrincipal(std::string nomTienda, std::string direTienda, std::string nomApeVendedor, int idVendedor) {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "MENU PRINCIPAL";
	gotoxy(POSX, POSY + 1); imprimirSeparador();
	gotoxy(POSX, POSY + 2); cout << nomTienda << " | " << direTienda;
	gotoxy(POSX, POSY + 3); imprimirSeparador();
	gotoxy(POSX, POSY + 4); cout << nomApeVendedor << " | " << idVendedor;
	gotoxy(POSX, POSY + 5); imprimirSeparador();

	gotoxy(POSX, POSY + 7); cout << "SELECCIONE UNA OPCIÓN DEL MENÚ: ";
	gotoxy(POSX, POSY + 9); cout << "1 - Historial de Cotizaciones: ";
	gotoxy(POSX, POSY + 10); cout << "2 - Realizar Cotización: ";
	gotoxy(POSX, POSY + 11); cout << "3 - Salir: ";
	gotoxy(POSX, POSY + 12); cout << "OPCION:  ";

}

void View::imprimirSalidaAlMenu(int x, int y) {
	gotoxy(x, y); imprimirSeparador();
	gotoxy(x + 1, y + 1); cout << "Presione | "  SALIR  " | para volver al menu principal";
	gotoxy(x, y + 2); imprimirSeparador();
}

void View::paso1() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "seleccione la prenda a utilizar: ";
	gotoxy(POSX, POSY + 7); cout << "1 - Camisa";
	gotoxy(POSX, POSY + 8); cout << "2 - Pantalon";
	gotoxy(POSX, POSY + 9); imprimirSeparador();
	gotoxy(POSX, POSY + 10); cout << "OPCION: ";
}

void View::pasoCamisa2a() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "PASO 2.a: la camisa a cotizar, es manga corta? ";
	imprimirPregunta(POSX, POSY + 7);
	gotoxy(POSX, POSY + 9); imprimirSeparador();
	gotoxy(POSX, POSY + 10); cout << "OPCION: ";
}

void View::pasoCamisa2b() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "PASO 2.b: la camisa a cotizar, es cuello mao? ";
    imprimirPregunta(POSX, POSY + 7);
	gotoxy(POSX, POSY + 9); imprimirSeparador();
	gotoxy(POSX, POSY + 10); cout << "OPCION: ";
}

void View::pasoPantalon2() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "PASO 2: el pantalon a cotizar, es chupín? ";
	imprimirPregunta(POSX, POSY + 7);
	gotoxy(POSX, POSY + 9); imprimirSeparador();
	gotoxy(POSX, POSY + 10); cout << "OPCION: ";;
}

void View::paso3() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "seleccione la calidad de la prenda ";
	gotoxy(POSX, POSY + 7); cout << "1 - Estandar";
	gotoxy(POSX, POSY + 8); cout << "2 - Premium";
	gotoxy(POSX, POSY + 9); imprimirSeparador();
	gotoxy(POSX, POSY + 10); cout << "OPCION: ";
}

void View::paso4() {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "PASO 4: Ingrese el precio unitario de la prenda a utilizar:  ";
	gotoxy(POSX, POSY + 6); imprimirSeparador();
	gotoxy(POSX, POSY + 7); cout << "Precio: ";
}

void View::paso5(int cantidad) {
	system("cls");
	gotoxy(POSX, POSY); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, POSY + 1);
	gotoxy(POSX, POSY + 5); cout << "INFORMACIÓN:  ";
	gotoxy(POSX, POSY + 6); cout << "EXISTE " << cantidad << " DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA";
	gotoxy(POSX, POSY + 7); cout << "PASO 5: seleccione la cantidad de unidades a cotizar:";
	gotoxy(POSX, POSY + 8);imprimirSeparador();
	gotoxy(POSX, POSY + 9); cout << "Cantidad: ";
}

int View::imprimirCotizacion(int numIdentificacion, std::string fecha, int codVen, std::string prenda, double precio, int cant,int y) {
	gotoxy(POSX, y); cout << "COTIZACIONES EXPRESS" << " | " << "COTIZAR";
	imprimirSalidaAlMenu(POSX, y + 1);
	gotoxy(POSX, y + 5); cout << "Número de identificación:  " << numIdentificacion;
	gotoxy(POSX, y + 6); cout << "Fecha y hora de la cotización:  " << fecha;
	gotoxy(POSX, y + 7); cout << "Código de vendedor:  " << codVen;
	gotoxy(POSX, y + 8); cout << "Prenda cotizada:  " << prenda;
	gotoxy(POSX, y + 9); cout << "Precio unitario:  " << precio;
	gotoxy(POSX, y + 10); cout << "Cantidad de unidades cotizadas:  " << cant;
	gotoxy(POSX, y + 11); cout << "Precio final:  " << precio * cant;
	imprimirSalidaAlMenu(POSX, y + 13);
	return y + 18;
}


void View::imprimirPregunta(int x, int y) {
	gotoxy(x, y); 	 cout << "1 - SI";
	gotoxy(x, y + 1); cout << "2 - NO";
}

void View::error(std::string error) {
	system("cls");
	gotoxy(30, 15); cout << error;
	gotoxy(30, 40); cout << "Presione una tecla para continuar...";
}

void View::limpiarPantalla() {
	system("cls");
}

