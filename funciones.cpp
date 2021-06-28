#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h" // Nuestro archivo de funciones
#include <cstring> // Para laburar/comparar las cadenas de texto
#include <ctime> // Es la librer�a del 'tiempo'. Sirve para disponer del dato de la fecha y hora para generar un primer n�mero aleatorio. Se va a usar para los n�meros de la matriz
#include "rlutil.h" // La librer�a para poner bonita la consola

void menu(void){
	cout << "  MATHRIX" << endl;
	cout << "  ---------------------" << endl;
	cout << "  1 - JUGAR" << endl;
	cout << "  2 - ESTAD�STICAS" << endl;
	cout << "  3 - CR�DITOS" << endl;
	cout << "  ---------------------" << endl;
	cout << "  0 - SALIR" << endl << endl;
}

void creditos(void){
    cout << endl << "  CR�DITOS" << endl;
	cout << "  ---------------------------------" << endl;
    cout << "  EQUIPO 'LANA'" << endl << endl;
    cout << "  LEGAJO         APELLIDO Y NOMBRE" << endl;
    cout << "  24960          Della Savia Natal�" << endl;
    cout << "  25064          Taboada Lautaro" << endl;
	cout << "  ---------------------------------" << endl;
    cout << endl << "  Apret� alguna tecla para volver al men� principal";
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

    cout << endl << "  ESTAD�STICAS" << endl;
	cout << "  -------------------------------" << endl;
    cout << "  MAYOR PUNTAJE        NOMBRE" << endl;
    cout << "  " << mayorPuntaje << "                  " << mayorNombre << endl;
	cout << "  ----------------------------------" << endl;
    cout << endl << "  Apret� alguna tecla para volver al men� principal";
}

void datos(char const *jugador, char const *calculadora, int pilas, int ronda, int puntaje){ // Barra de arriba de todo del juego
    cout << endl << "  JUGADOR/A: " << jugador << "  |  CALCULADORA: " << calculadora << "  |  PILAS: " << pilas << "  |  N� RONDA: " << ronda << "  |  PUNTAJE: " << puntaje;
}
