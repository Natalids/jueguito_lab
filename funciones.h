
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menu(void);
void creditos(void);
void estadisticas(int, int, char const *nombre); // El * es porque es por referencia
int jugar(int *, char *); // El * es porque es por referencia
void datos(char const *, char const *, int, int, int);
void matrizAleatoria (int[][6], int);
void imprimirMatriz (int [][6], int);
int direcciones(int[][6], int, int, int, int, int *, int *, int *);
int ecuacion(char, int, int, int, int *);
int ingresoDatos(int *, int *, char *, int *);
int cambioCeldas(int [][6], int, int, int, int);
int salirseMatriz(int, int, int, int *);
int celdaNegativo(int [][6], int, int, int, int, int *);

#endif // FUNCIONES_H_INCLUDED

