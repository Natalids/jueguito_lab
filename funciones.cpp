#include <iostream>
#include <clocale>
using namespace std;
#include <cstring>
#include "funciones.h"

void menu(void){
	cout << "  MATHRIX" << endl;
	cout << "  ---------------------" << endl;
	cout << "  1 - JUGAR" << endl;
	cout << "  2 - ESTADÍSTICAS" << endl;
	cout << "  3 - CRÉDITOS" << endl;
	cout << "  ---------------------" << endl;
	cout << "  0 - SALIR" << endl << endl;
}

void creditos(void){
    cout << endl << "  CRÉDITOS" << endl << endl;
	cout << "  ---------------------" << endl;
    cout << "  EQUIPO 'LANA'" << endl << endl;
    cout << "  LEGAJO         APELLIDO Y NOMBRE" << endl;
    cout << "  24960          Della Savia Natalí" << endl;
    cout << "  25064          Taboada Lautaro" << endl;
	cout << "  ---------------------" << endl;
    cout << endl << "  Apretá alguna tecla para volver al menú principal";
}

/*void estadisticas(int puntaje, char 'nombre'){
    cout << endl << "  ESTADÍSTICAS" << endl << endl;
	cout << "  ---------------------" << endl;
    cout << "  MAYOR PUNTAJE        NOMBRE" << endl << endl;
    cout << "  " << puntaje << "                  " << nombre;
}*/
