#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h"
#include <cstring>
#include <ctime>
#include "rlutil.h"

int jugar(int *puntaje, char *nombre){
    char jugador[20], calculadora[20];
    int matriz[6][6], pilas=3, ronda=1, fila, columna, direccion, acumular, primerNumero, segundoNumero, tercerNumero, afuera, negativo;
    char operador;

    cout << endl << "  JUGAR" << endl;
	cout << "  ---------------------------------" << endl;
    cout << "  Ingrese nombre del jugador: ";
    cin.ignore();
    cin.getline(jugador, 20);
    strcpy(nombre, jugador);
    cout << "  Ingrese modelo de calculadora favorito: ";
    cin.getline(calculadora, 20);

    matrizAleatoria(matriz, 6);
    rlutil::cls();
    datos(jugador, calculadora, pilas, ronda, *puntaje);

    while(pilas!=0){
        afuera = 0;
        negativo = 0;
        imprimirMatriz(matriz, 6);
        ingresoDatos(&fila, &columna, &operador, &direccion);
        direcciones(matriz, 6, direccion, fila, columna, &primerNumero, &segundoNumero, &tercerNumero);
        salirseMatriz(fila, columna, direccion, &afuera);
        if(afuera == 1){
            cout << endl << "  Con ese movimiento te salís de la matriz. Perdiste una pila.";
            cout << endl << "  Apretá alguna tecla para continuar.";
            pilas--;
            rlutil::anykey();
        }else{
            celdaNegativo(int matriz [][6], int tam, int fila, int columna, int direccion, int &negativo);
            if(negativo == 1){
                cout << endl << "  Estás queriendo usar una celda bloqueada ('-1'). Perdiste una pila.";
                cout << endl << "  Apretá alguna tecla para continuar.";
                pilas--;
                rlutil::anykey();
            }
            else{
                ecuacion(operador, primerNumero, segundoNumero, tercerNumero, &acumular);
                if(acumular == 0){
                    cout << endl << "  La operación que realizaste no es correcta. Perdiste una pila.";
                    cout << endl << "  Apretá alguna tecla para continuar.";
                    pilas--;
                    rlutil::anykey();
                }
                else{
                    cout << endl << "  ¡Muy bien hecho! Acabas de sumar " << *puntaje << " puntos.";
                    cout << endl << "  Apretá alguna tecla para continuar.";
                    rlutil::anykey();
                    *puntaje += acumular;
                    cambioCeldas(matriz, 6, fila, columna, direccion);
                }
            }
        }

        ronda++;
        rlutil::cls();
        datos(jugador, calculadora, pilas, ronda, *puntaje);
    }

	cout << endl << "  ---------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "  ¡Te quedaste sin pilas! La partida finalizó.";
    cout << endl << endl << "  Apretá alguna tecla para volver al menú principal";
}
