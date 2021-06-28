#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Declaración de las funciones

void menu(void);
void creditos(void);
void estadisticas(int, int, char const *nombre); // El * es porque es por referencia
int jugar(int *, char *); // El * es porque es por referencia
void datos(char const *, char const *, int, int, int);

#endif // FUNCIONES_H_INCLUDED

