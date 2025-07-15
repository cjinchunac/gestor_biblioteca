#ifndef usuario_H
#define usuario_H

#include <string>
using namespace std;

struct usuario {
    int DNI;
    string nombre;
    correo email; 
};

struct correo {
    string user;
    string domain;
};

void leerUsuario(usuario &u, int dni, string nom, string email_user, string email_domain);
void imprimirUsuario(usuario &u);
void registrarUsuario(usuario usuarios[], int &n_usuarios);
void mostrarUsuarios(usuario usuarios[], int n_usuarios);

#endif //fin de guarda