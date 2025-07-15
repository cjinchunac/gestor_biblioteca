#ifndef prestamo_H
#define prestamo_H
#include "usuario.h"
#include "libro.h"
#include<iostream>
#include<string>
using namespace std;

int puedePrestarMas(prestamo prestamos[], int n_prestamos, int DNI);
void registrarPrestamo(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos, usuario usuarios[], int n_usuarios);
void mostrarPrestamosUsuario(prestamo prestamos[], int n_prestamos);
void devolverLibro(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos);

#endif