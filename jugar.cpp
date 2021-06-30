#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h" // Nuestro archivo de funciones
#include <cstring> // Para laburar/comparar las cadenas de texto
#include <ctime> // Sirve para disponer del dato de la fecha y hora para generar un primer número aleatorio. Se va a usar para los números de la matriz
#include "rlutil.h" // La librería para poner bonita la consola

int jugar(int *puntaje, char *nombre){ // El * es porque es por referencia
    char jugador[20], calculadora[20], operador;
    int matriz[6][6];
    int pilas=3, ronda=0, fila, columna;

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

    while(pilas>0){ /* IMPORTANTE ESTO:
        La condición que nos corta el juego es cuando pilas sea 0.
        Entonces lo que podemos hacer es que cuando pase algo como "se excedió de la matriz"
        o "quiso usar una celda que no estaba disponible", ponemos pila=0 y ya sale de la función y corta el programa. */

        ronda++;
        rlutil::cls();
        datos(jugador, calculadora, pilas, ronda, *puntaje);

        if(ronda==1){ // Esta condición la puse para que UNA UNICA VEZ haga la matriz aleatoria. Sino, debe volver a imprimir la misma matriz.
            matrizAleatoria(matriz, 6);
        }
        else{
            imprimirMatriz(matriz, 6);
        }

        cout << endl << endl << "  A continuación tenés que elegir la celda por la que querés empezar." << endl << "  Fila: ";
        cin >> fila;
        cout << "  Columna: ";
        cin >> columna;
        cout << "  El número elegido es: " << matriz[fila-1][columna-1];

        cout << endl << "  Vamos a cambiarlo ... (esto es para probar)";
        matriz[fila-1][columna-1] = -1; // Estoy probando cambiar los valores de la matriz a -1

        cout << endl << endl << "  Ahora ingresá el operador que quieras (+, -, *, /, %): ";
        cin >> operador; // Falta desarrollar

        pilas--;
    }

    rlutil::cls();
    cout << endl << "  La matriz quedó de la siguiente manera: ";
    imprimirMatriz(matriz, 6);

	cout << endl << "  ---------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "  Apretá alguna tecla para volver al menú principal";
}
