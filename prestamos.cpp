#include "prestamo.h"
#include <iostream>
#include <string>
using namespace std;

int puedePrestarMas(prestamo prestamos[], int n_prestamos, int DNI) {
    int contador = 0;
    for (int i = 0; i < n_prestamos; i++) {
        if (prestamos[i].usuarioPrestamo.DNI == DNI && prestamos[i].devuelto == 0) {
            contador++;
            if (contador >= 3) {
                return 0;
            }
        }
    }
    return 1;
}