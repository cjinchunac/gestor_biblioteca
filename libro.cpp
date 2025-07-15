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
void modificardatolibro(libro &lib) {
    cout << "Ingrese nuevos datos del libro:" << endl;
    cout << "ID: "; cin >> lib.ID;
    cin.ignore();
    cout << "Nombre del libro: "; getline(cin, lib.titulo);
    cout << "Autor: "; getline(cin, lib.autor);
    cout << "Genero: "; getline(cin, lib.genero);
    cout << "Cantidad disponible: "; cin >> lib.cantidad;
    cout << "Libro modificado correctamente!" << endl;
}
void borrarlibro(libro lista_libros[], int &n) {
    int ID, contador = 0;
    cout << "Ingrese ID del libro a borrar: ";
    cin >> ID;
    
    for (int i = 0; i < n; i++) {
        if (lista_libros[i].ID == ID) {
            cout << "\nDatos del libro a borrar:" << endl;
            imprimelibro(lista_libros[i]);
            
            for (int j = i; j < n-1; j++) {
                lista_libros[j] = lista_libros[j+1];
            }
            contador++;
            n--;
            cout << "Libro eliminado correctamente!" << endl;
            break;
        }
    }
    
    if (contador == 0)
        cout << "No se encontro libro con esa ID" << endl;
}
