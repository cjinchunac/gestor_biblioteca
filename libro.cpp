#include"libro.h"
#include<iostream>
#include<string>
using namespace std;
void leerlibro(libro &lib, int id, string tit, string aut, string gen, int cant) {
    lib.ID = id;
    lib.titulo = tit;
    lib.autor = aut;
    lib.genero = gen;
    lib.cantidad = cant;
}
void imprimelibro(libro &lib) {
    cout << "ID: " << lib.ID << endl;
    cout << "Titulo: " << lib.titulo << endl;
    cout << "Autor: " << lib.autor << endl;
    cout << "Genero: " << lib.genero << endl;
    cout << "Disponibles: " << lib.cantidad << endl;
}
