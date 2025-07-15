#ifndef prestamo_H
#define prestamo_H

#include "libro.h"
#include "usuario.h"

#include <iostream>
#include <string>
using namespace std;

struct prestamo {
    libro libroPrestado;
    usuario usuarioPrestamo;
    int fecha_prestamo[3];
    int fecha_devolucion[3];
    int devuelto;
};


int puedePrestarMas(prestamo prestamos[], int n_prestamos, int DNI);
void registrarPrestamo(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos, usuario usuarios[], int n_usuarios);
void mostrarPrestamosUsuario(prestamo prestamos[], int n_prestamos);
void devolverLibro(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos);

#endif