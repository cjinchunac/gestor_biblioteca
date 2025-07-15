#ifndef libro_H
#define libro_H
#include<iostream>
#include<string>
struct libro {
    int ID;
    string titulo;
    string autor;
    string genero;
    int cantidad;
};
void leerlibro(libro &lib, int id, string tit, string aut, string gen, int cant);
void imprimelibro(libro &lib);
void modificardatolibro(libro &lib);
void borrarlibro(libro lista_libros[], int &n);
void buscarPorAutor(libro lista_libros[], int n);
void buscarPorGenero(libro lista_libros[], int n);
#endif