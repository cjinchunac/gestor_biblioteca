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
void devolverLibro(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos) {
    if (n_prestamos == 0) {
        cout << "No hay prestamos registrados para devolver." << endl;
        return;
    }
    
    int DNI, ID;
    cout << "Ingrese DNI del usuario: ";
    cin >> DNI;
    cout << "Ingrese ID del libro a devolver: ";
    cin >> ID;
    
    int encontrado = 0;
    
    for (int i = 0; i < n_prestamos; i++) {
        if (prestamos[i].usuarioPrestamo.DNI == DNI && 
            prestamos[i].libroPrestado.ID == ID && 
            prestamos[i].devuelto == 0) {
            
            prestamos[i].devuelto = 1;
            
            for (int j = 0; j < n_libros; j++) {
                if (lista_libros[j].ID == ID) {
                    lista_libros[j].cantidad++;
                    break;
                }
            }
            
            cout << "Libro devuelto con exito!" << endl;
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro un prestamo activo con esos datos." << endl;
    }
}