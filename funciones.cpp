#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h" // Nuestro archivo de funciones
#include <cstring> // Para laburar/comparar las cadenas de texto
#include <ctime> // Es la librería del 'tiempo'. Sirve para disponer del dato de la fecha y hora para generar un primer número aleatorio. Se va a usar para los números de la matriz
#include "rlutil.h" // La librería para poner bonita la consola

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
    cout << endl << "  CRÉDITOS" << endl;
	cout << "  ---------------------------------" << endl;
    cout << "  EQUIPO 'LANA'" << endl << endl;
    cout << "  LEGAJO         APELLIDO Y NOMBRE" << endl;
    cout << "  24960          Della Savia Natalí" << endl;
    cout << "  25064          Taboada Lautaro" << endl;
	cout << "  ---------------------------------" << endl;
    cout << endl << "  Apretá alguna tecla para volver al menú principal";
}

void estadisticas(int puntaje, int vueltaUno, char const *nombre){ // El * es porque es por referencia
    int mayorPuntaje;
    char mayorNombre[20]={"-"};

    if(vueltaUno==0){
        mayorPuntaje = puntaje;
        strcpy(mayorNombre, nombre);
    }
    else{
        if(puntaje>mayorPuntaje){
            mayorPuntaje = puntaje;
            strcpy(mayorNombre, nombre);
        }
    }

    cout << endl << "  ESTADÍSTICAS" << endl;
	cout << "  -------------------------------" << endl;
    cout << "  MAYOR PUNTAJE        NOMBRE" << endl;
    cout << "  " << mayorPuntaje << "                  " << mayorNombre << endl;
	cout << "  ----------------------------------" << endl;
    cout << endl << "  Apretá alguna tecla para volver al menú principal";
}

void datos(char const *jugador, char const *calculadora, int pilas, int ronda, int puntaje){ // Barra de arriba de todo del juego
    cout << endl << "  JUGADOR/A: " << jugador << "  |  CALCULADORA: " << calculadora << "  |  PILAS: " << pilas << "  |  Nº RONDA: " << ronda << "  |  PUNTAJE: " << puntaje;
}
