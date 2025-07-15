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

