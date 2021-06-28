#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h" // Nuestro archivo de funciones
#include <cstring> // Para laburar/comparar las cadenas de texto
#include <ctime> // Sirve para disponer del dato de la fecha y hora para generar un primer número aleatorio. Se va a usar para los números de la matriz
#include "rlutil.h" // La librería para poner bonita la consola

int jugar(int *puntaje, char *nombre){ // El * es porque es por referencia
    char jugador[20], calculadora[20];
    int matriz[6][6], pilas=3, ronda=1;

    cout << endl << "  JUGAR" << endl;
	cout << "  ---------------------------------" << endl;
    cout << "  Ingrese nombre del jugador: ";
    cin.ignore();
    cin.getline(jugador, 20);
    strcpy(nombre, jugador);
    cout << "  Ingrese modelo de calculadora favorito: ";
    cin.getline(calculadora, 20);
    cout << endl << "  Ingresá un puntaje: "; // Esto no tiene que ir, es prueba de que "puntaje" se pasa a ESTADÍSTICA
    cin >> *puntaje; // Esto no tiene que ir, es prueba de que "puntaje" se pasa a ESTADÍSTICA

    rlutil::cls();

    datos(jugador, calculadora, pilas, ronda, *puntaje);

	cout << endl << "  ---------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "  Apretá alguna tecla para volver al menú principal";
}
