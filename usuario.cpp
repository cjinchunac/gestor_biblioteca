#include "usuario.h"
#include <iostream>

using namespace std;

// Funciones para usuarios
void leerUsuario(usuario &u, int dni, string nom, string email_user, string email_domain) {
    u.DNI = dni;
    u.nombre = nom;
    u.email.user = email_user;
    u.email.domain = email_domain;
}

void imprimirUsuario(usuario &u) {
    cout << "DNI: " << u.DNI << endl;
    cout << "Nombre: " << u.nombre << endl;
    cout << "Email: " << u.email.user << "@" << u.email.domain << endl;
}

void registrarUsuario(usuario usuarios[], int &n_usuarios) {
    int DNI;
    string nombre, email_user, email_domain;
    
    cout << "Ingrese DNI del usuario: ";
    cin >> DNI;
    
    // Verificar si el usuario ya existe
    for (int i = 0; i < n_usuarios; i++) {
        if (usuarios[i].DNI == DNI) {
            cout << "Ya existe un usuario con este DNI." << endl;
            return;
        }
    }
    
    cin.ignore();
    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Email (parte antes de @): ";
    cin >> email_user;
    cout << "Dominio (parte despues de @): ";
    cin >> email_domain;
    
    leerUsuario(usuarios[n_usuarios], DNI, nombre, email_user, email_domain);
    n_usuarios++;
    cout << "Usuario registrado con exito!" << endl;
}

void mostrarUsuarios(usuario usuarios[], int n_usuarios) {
    if (n_usuarios == 0) {
        cout << "No hay usuarios registrados." << endl;
        return;
    }
    
    cout << "\nUSUARIOS REGISTRADOS:" << endl;
    for (int i = 0; i < n_usuarios; i++) {
        cout << "---------------------" << endl;
        imprimirUsuario(usuarios[i]);
    }
    cout << "---------------------" << endl;
}
