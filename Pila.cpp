#include <iostream>
#include <string>

const int TAM = 5; // Tamaño máximo de la pila

using namespace std;

class empleado {
private:
    int claveEm;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

public:
    empleado() : claveEm(0), nombre(""), domicilio(""), sueldo(0.0), reportaA("") {}

    empleado(int CE, string N, string D, float S, string R) {
        claveEm = CE;
        nombre = N;
        domicilio = D;
        sueldo = S;
        reportaA = R;
    }

    void imprime() const {
        cout << "Clave de empleado: " << claveEm << endl;
        cout << "Nombre empleado: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reportaA << endl;
        cout << "\n";
    }
};

class Pila {
private:
    empleado datos[TAM];
    int tope;

public:
    Pila() : tope(-1) {}

    bool vacia() const {
        return tope == -1;
    }

    bool llena() const {
        return tope == TAM - 1;
    }

    void Push(const empleado& elem) {
        if (llena()) {
            cout << "La pila está llena. No se puede apilar más elementos." << endl;
        } else {
            tope++;
            datos[tope] = elem;
            cout << "Elemento apilado correctamente." << endl;
        }
    }

    void Pop() {
        if (vacia()) {
            cout << "La pila está vacía. No se puede desapilar." << endl;
        } else {
            tope--;
            cout << "Elemento desapilado correctamente." << endl;
        }
    }

    void Top() const {
        if (vacia()) {
            cout << "La pila está vacía. No hay elementos en la cima." << endl;
        } else {
            cout << "Elemento en la cima de la pila:" << endl;
            datos[tope].imprime();
        }
    }
};

int main() {
    Pila miPila;
    int opcion;

    do {
        cout << "\nMenú:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int CE;
                string N, D, R;
                float S;

                cout << "Clave de empleado: ";
                cin >> CE;
                cin.ignore(); // Para eliminar el salto de línea pendiente
                cout << "Nombre empleado: ";
                getline(cin, N);
                cout << "Domicilio: ";
                getline(cin, D);
                cout << "Sueldo: ";
                cin >> S;
                cin.ignore(); // Para eliminar el salto de línea pendiente
                cout << "Reporta a: ";
                getline(cin, R);

                empleado nuevoEmpleado(CE, N, D, S, R);
                miPila.Push(nuevoEmpleado);
                break;
            }
            case 2:
                miPila.Pop();
                break;
            case 3:
                miPila.Top();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Introduce una opción válida del menú." << endl;
        }
    } while (opcion != 4);

    return 0;
}
