#include <iostream>
using namespace std;

struct correo {
    string user;
    string domain;
};



struct usuario {
    int DNI;
    string nombre;
    correo email; 
};

struct prestamo {
    libro libroPrestado;
    usuario usuarioPrestamo;
    int fecha_prestamo[3];
    int fecha_devolucion[3];
    int devuelto;
};



void leerUsuario(usuario &u, int dni, string nom, string email_user, string email_domain);
void imprimirUsuario(usuario &u);
void registrarUsuario(usuario usuarios[], int &n_usuarios);
void mostrarUsuarios(usuario usuarios[], int n_usuarios);

int puedePrestarMas(prestamo prestamos[], int n_prestamos, int DNI);
void registrarPrestamo(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos, usuario usuarios[], int n_usuarios);
void mostrarPrestamosUsuario(prestamo prestamos[], int n_prestamos);
void devolverLibro(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos);


int main() {
    libro lista_libros[100];
    usuario usuarios[100];
    prestamo prestamos[100];
    int n_libros = 0, n_usuarios = 0, n_prestamos = 0;
    int op;
    
    do {
        system("cls");
        cout << "SISTEMA DE BIBLIOTECA" << endl;
        cout << "---------------------" << endl;
        cout << "1. Registrar libro" << endl;
        cout << "2. Mostrar libros" << endl;
        cout << "3. Modificar libro" << endl;
        cout << "4. Borrar libro" << endl;
        cout << "5. Buscar por autor" << endl;
        cout << "6. Buscar por genero" << endl;
        cout << "7. Registrar usuario" << endl;
        cout << "8. Mostrar usuarios" << endl;
        cout << "9. Registrar prestamo" << endl;
        cout << "10. Mostrar prestamos" << endl;
        cout << "11. Devolver libro" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;

        switch(op) {
            case 1: {
                int ID, cantidad;
                string titulo, autor, genero;
                
                cout << "ID: "; cin >> ID;
                cin.ignore();
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "Genero: "; getline(cin, genero);
                cout << "Cantidad: "; cin >> cantidad;
                
                leerlibro(lista_libros[n_libros], ID, titulo, autor, genero, cantidad);
                n_libros++;
                break;
            }
            case 2:
                if (n_libros == 0) {
                    cout << "No hay libros registrados." << endl;
                } else {
                    cout << "\nLISTA DE LIBROS:" << endl;
                    for (int i = 0; i < n_libros; i++) {
                        cout << "---------------------" << endl;
                        imprimelibro(lista_libros[i]);
                    }
                }
                break;
            case 3:
                if (n_libros == 0) {
                    cout << "No hay libros registrados." << endl;
                } else {
                    int ID;
                    cout << "Ingrese ID del libro a modificar: ";
                    cin >> ID;
                    
                    int encontrado = 0;
                    for (int i = 0; i < n_libros; i++) {
                        if (lista_libros[i].ID == ID) {
                            modificardatolibro(lista_libros[i]);
                            encontrado = 1;
                            break;
                        }
                    }
                    
                    if (!encontrado) {
                        cout << "No se encontro libro con ese ID." << endl;
                    }
                }
                break;
            case 4:
                if (n_libros == 0) {
                    cout << "No hay libros registrados." << endl;
                } else {
                    borrarlibro(lista_libros, n_libros);
                }
                break;
            case 5:
                buscarPorAutor(lista_libros, n_libros);
                break;
            case 6:
                buscarPorGenero(lista_libros, n_libros);
                break;
            case 7: {
                registrarUsuario(usuarios, n_usuarios);
                break;
            }
            case 8:
                mostrarUsuarios(usuarios, n_usuarios);
                break;
            case 9:
                registrarPrestamo(lista_libros, n_libros, prestamos, n_prestamos, usuarios, n_usuarios);
                break;
            case 10:
                mostrarPrestamosUsuario(prestamos, n_prestamos);
                break;
            case 11:
                devolverLibro(lista_libros, n_libros, prestamos, n_prestamos);
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
        
        if (op != 0) {
            system("pause");
        }
    } while (op != 0);
    
    return 0;
}
