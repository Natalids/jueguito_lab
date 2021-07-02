#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h"
#include <cstring>
#include <ctime>
#include "rlutil.h"

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

void estadisticas(int puntaje, int vueltaUno, char const *nombre){
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

void datos(char const *jugador, char const *calculadora, int pilas, int ronda, int puntaje){ // Barra de arriba de todo de 'jugar'.
    cout << endl << "  JUGADOR/A: " << jugador << "  |  CALCULADORA: " << calculadora << "  |  PILAS: " << pilas << "  |  Nº RONDA: " << ronda << "  |  PUNTAJE: " << puntaje;
}

void matrizAleatoria(int matriz[][6], int tam){
    int i, x;
    for (i=0; i<6; i++){
        for (x=0; x<6; x++){
            matriz[i][x] = rand()%10;
        }
    }
}

void imprimirMatriz(int matriz[][6], int tam){
    int i, x;
    cout << endl << endl;
    for (int i=0; i<tam; i++){
        for(int x=0; x<tam; x++){
            if(matriz[i][x]==-1){
                cout << matriz[i][x] << " ";
            }
            else{
                cout << " " << matriz[i][x] << " ";
            }
        }
        cout << endl;
    }
}

int ingresoDatos(int *fila, int *columna, char *operador, int *direccion){
    cout << endl << "  Ingresá los valores correspondientes: ";
    cout << endl << "  Nº FILA: ";
    cin >> *fila;
    cout << "  Nº COLUMNA: ";
    cin >> *columna;
    *fila = *fila-1;
    *columna = *columna-1;
    cout << "  Operación: (+) SUMAR | (-) RESTAR | (/) DIVIDIR | (*) MULTIPLICAR | (%) RESTO: ";
    cin >> *operador;
    cout << "  Dirección: (8) ARRIBA | (2) ABAJO  | (4) IZQUIERDA | (6) DERECHA: ";
    cin >> *direccion;
}

int direcciones(int matriz [][6], int tam, int direccion, int fila, int columna, int *primerNumero, int *segundoNumero, int *tercerNumero){
    *primerNumero = matriz[fila][columna];

    if(direccion == 8){ // ARRIBA
        *segundoNumero = matriz[fila-1][columna];
        *tercerNumero = matriz[fila-2][columna];
    }
    else{
        if(direccion == 2){ // ABAJO
            *segundoNumero = matriz[fila+1][columna];
            *tercerNumero = matriz[fila+2][columna];
        }
        else{
            if(direccion == 4){ // IZQUIERDA
                *segundoNumero = matriz[fila][columna-1];
                *tercerNumero = matriz[fila][columna-2];
            }
            else{
                if (direccion == 6){ // DERECHA
                    *segundoNumero = matriz[fila][columna+1];
                    *tercerNumero = matriz[fila][columna+2];
                }
            }
        }
    }
}

int ecuacion(char operador, int primerNumero, int segundoNumero, int tercerNumero, int *acumular){
    int resultado;

    if(operador == '+'){
        resultado = primerNumero + segundoNumero;
    }
    else{
        if(operador == '-'){
            resultado = primerNumero - segundoNumero;
        }
        else{
            if(operador == '*') {
                resultado = primerNumero * segundoNumero;
            }
            else{
                if(operador == '/'){
                    resultado = primerNumero / segundoNumero;
                }
                else{
                    if(operador == '%'){
                        resultado = primerNumero % segundoNumero;
                    }
                }
            }
        }
    }

    if(resultado==tercerNumero){
        *acumular = primerNumero + segundoNumero + tercerNumero;
    }
    else{
        *acumular = 0;
    }
}

int cambioCeldas(int matriz [][6], int tam, int fila, int columna, int direccion){
    if(direccion == 8){ // ARRIBA
        matriz[fila][columna] = -1;
        matriz[fila-1][columna] = -1;
        matriz[fila-2][columna] = -1;
    }
    else{
        if(direccion == 2){ // ABAJO
            matriz[fila][columna] = -1;
            matriz[fila+1][columna] = -1;
            matriz[fila+2][columna] = -1;
        }
        else{
            if(direccion == 4){ // IZQUIERDA
                matriz[fila][columna] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila][columna-2] = -1;
            }
            else{
                if(direccion == 6){ // DERECHA
                    matriz[fila][columna] = -1;
                    matriz[fila][columna+1] = -1;
                    matriz[fila][columna+2] = -1;
                }
            }
        }
    }
}

int salirseMatriz(int fila, int columna, int direccion, int *afuera){
    if(fila==1 && direccion==8 || fila==2 && direccion==8){
        *afuera = 1;
    }
    else{
        if(fila==5 && direccion==2 || fila==6 && direccion==2){
            *afuera = 1;
        }
        else{
            if(columna==1 && direccion==4 || columna==2 && direccion==4){
                *afuera = 1;
            }
            else{
                if(columna==5 && direccion==6 || columna==6 && direccion==6){
                    *afuera = 1;
                }
            }
        }
    }
}

int celdaNegativo(int matriz [][6], int tam, int fila, int columna, int direccion, int *negativo){
    if(direccion == 8){
        /*num1 = matriz[fila][columna];
        num2 = matriz[fila-1][columna];
        num3 = matriz[fila-2][columna];*/
        if(matriz[fila][columna] == -1 || matriz[fila-1][columna] == -1 || matriz[fila-2][columna] == -1){
           *negativo = 1;
        }
    }
    else{
        if(direccion == 2){
            if(matriz[fila][columna] == -1 || matriz[fila+1][columna] == -1 || matriz[fila+2][columna] == -1){
            *negativo = 1;
            }
        }
        else{
            if(direccion == 4){
                if(matriz[fila][columna] == -1 ||matriz[fila][columna-1] == -1 || matriz[fila][columna-2] == -1){
                    *negativo = 1;
                }
            }
            else{
                if(direccion == 6){
                    if(matriz[fila][columna] == -1 || matriz[fila][columna+1] == -1 || matriz[fila][columna+2] == -1){
                        *negativo = 1;
                    }
                }
            }
        }
    }
}

