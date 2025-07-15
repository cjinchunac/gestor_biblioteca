#include "prestamo.h"
#include <iostream>
#include <string>
using namespace std;

int puedePrestarMas(prestamo prestamos[], int n_prestamos, int DNI) {
    int contador = 0;
    for (int i = 0; i < n_prestamos; i++) {
        if (prestamos[i].usuarioPrestamo.DNI == DNI && prestamos[i].devuelto == 0) {
            contador++;
            if (contador >= 3) {
                return 0;
            }
        }
    }
    return 1;
}

void registrarPrestamo(libro lista_libros[], int n_libros, prestamo prestamos[], int &n_prestamos, usuario usuarios[], int n_usuarios) {
    if (n_usuarios == 0) {
        cout << "No hay usuarios registrados. Registre al menos un usuario primero." << endl;
        return;
    }
    
    if (n_libros == 0) {
        cout << "No hay libros registrados. Registre al menos un libro primero." << endl;
        return;
    }
    
    int ID, DNI, dia, mes, anio;
    int usuario_index = -1, libro_index = -1;
    
    cout << "Ingrese DNI del usuario: ";
    cin >> DNI;
    
    // Buscar usuario
    for (int i = 0; i < n_usuarios; i++) {
        if (usuarios[i].DNI == DNI) {
            usuario_index = i;
            break;
        }
    }
    
    if (usuario_index == -1) {
        cout << "Usuario no encontrado. Registre al usuario primero." << endl;
        return;
    }
    
    if (!puedePrestarMas(prestamos, n_prestamos, DNI)) {
        cout << "Este usuario ya tiene 3 prestamos activos. No puede pedir mas libros." << endl;
        return;
    }
    
    cout << "\nLibros disponibles:" << endl;
    for (int i = 0; i < n_libros; i++) {
        if (lista_libros[i].cantidad > 0) {
            cout << "ID: " << lista_libros[i].ID << " - " << lista_libros[i].titulo;
            cout << " (" << lista_libros[i].cantidad << " disponibles)" << endl;
        }
    }
    
    cout << "\nIngrese ID del libro a prestar: ";
    cin >> ID;
    
    for (int i = 0; i < n_libros; i++) {
        if (lista_libros[i].ID == ID && lista_libros[i].cantidad > 0) {
            libro_index = i;
            break;
        }
    }
    
    if (libro_index == -1) {
        cout << "ID de libro no valido o no hay ejemplares disponibles." << endl;
        return;
    }
    
    cout << "Ingrese fecha de prestamo (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    
    prestamos[n_prestamos].libroPrestado = lista_libros[libro_index];
    prestamos[n_prestamos].usuarioPrestamo = usuarios[usuario_index];
    prestamos[n_prestamos].fecha_prestamo[0] = dia;
    prestamos[n_prestamos].fecha_prestamo[1] = mes;
    prestamos[n_prestamos].fecha_prestamo[2] = anio;
    
    // Calcular fecha de devolucion (7 dias despues)
    prestamos[n_prestamos].fecha_devolucion[0] = dia + 7;
    prestamos[n_prestamos].fecha_devolucion[1] = mes;
    prestamos[n_prestamos].fecha_devolucion[2] = anio;
    
    // Ajustar si pasamos de 31 dias
    if (prestamos[n_prestamos].fecha_devolucion[0] > 31) {
        prestamos[n_prestamos].fecha_devolucion[0] -= 31;
        prestamos[n_prestamos].fecha_devolucion[1]++;
    }
    
    prestamos[n_prestamos].devuelto = 0;
    lista_libros[libro_index].cantidad--;
    n_prestamos++;
    
    cout << "Prestamo registrado con exito!" << endl;
}

void mostrarPrestamosUsuario(prestamo prestamos[], int n_prestamos) {
    if (n_prestamos == 0) {
        cout << "No hay prestamos registrados." << endl;
        return;
    }
    
    int DNI;
    cout << "Ingrese DNI del usuario: ";
    cin >> DNI;
    
    int contador = 0;
    cout << "\nPRESTAMOS DEL USUARIO:" << endl;
    for (int i = 0; i < n_prestamos; i++) {
        if (prestamos[i].usuarioPrestamo.DNI == DNI) {
            cout << "---------------------" << endl;
            cout << "Libro: " << prestamos[i].libroPrestado.titulo << endl;
            cout << "Autor: " << prestamos[i].libroPrestado.autor << endl;
            cout << "Fecha prestamo: " << prestamos[i].fecha_prestamo[0] << "/" 
                 << prestamos[i].fecha_prestamo[1] << "/" << prestamos[i].fecha_prestamo[2] << endl;
            cout << "Fecha devolucion: " << prestamos[i].fecha_devolucion[0] << "/" 
                 << prestamos[i].fecha_devolucion[1] << "/" << prestamos[i].fecha_devolucion[2] << endl;
            cout << "Estado: " << (prestamos[i].devuelto ? "Devuelto" : "Pendiente") << endl;
            contador++;
        }
    }
    
    if (contador == 0) {
        cout << "No se encontraron prestamos para este usuario." << endl;
    } else {
        cout << "Total de prestamos: " << contador << endl;
    }
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
