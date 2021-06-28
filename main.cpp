#include <iostream>
#include <clocale>
using namespace std;
#include "funciones.h" // Nuestro archivo de funciones
#include <cstring> // Para laburar/comparar las cadenas de texto
#include <ctime> // Es la librer�a del 'tiempo'. Sirve para disponer del dato de la fecha y hora para generar un primer n�mero aleatorio. Se va a usar para los n�meros de la matriz
#include "rlutil.h" // La librer�a para poner bonita la consola

int main(void){
   	setlocale(LC_ALL, "Spanish");

   	srand(time(NULL));

	int num, salir=1, puntaje=0, vueltaUno=0;
	char rta[3], afirmativo[3]={'s','i'}, nombre[20];

	while(salir!=0){
        rlutil::cls();
        menu();
        cout << endl << "  Por favor eleg� la opci�n que quieras realizar: ";
        cin >> num;

		if(num == 1){
            rlutil::cls();
            jugar(&puntaje, nombre); // El & es porque es por referencia
            rlutil::anykey();
		}
		else{
			if(num == 2){
                rlutil::cls();
                estadisticas(puntaje, vueltaUno, nombre);
                vueltaUno = 1;
                rlutil::anykey();
			}
			else{
				if(num == 3){
                    rlutil::cls();
                    creditos();
                    rlutil::anykey();
				}
				else{
                    if(num == 0){
                        rlutil::cls();
                        cout << endl << "  �Est�s seguro que quer�s salir? (escribir si - no): ";
                        cin >> rta;
                        salir = strcasecmp(rta, afirmativo);

                        if(salir==0){
                            rlutil::cls();
                            cout << endl << "  Gracias por jugar a MATHRIX, �esperamos que lo hayas disfrutado!" << endl;
                        }
                        else{
                            rlutil::cls();
                            cout << endl << "  �Que bueno que decidiste quedarte!" << endl;
                        }
                    }
				}
			}
		}
	}

	return 0;
}
