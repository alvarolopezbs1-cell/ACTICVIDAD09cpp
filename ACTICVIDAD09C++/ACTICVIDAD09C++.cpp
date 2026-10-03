#include <iostream>

#define MaxTamC 10
typedef int TipoDato;

using namespace std;

int main() {
    int frente = 0;
    int final = 0;
    TipoDato A[MaxTamC];
    int contador = 0;
    char respuesta;

    cout << "¿Desea agregar elementos a la cola? (s/n): ";
    cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
        if ((final + 1) % MaxTamC == frente) {
            cout << "Desbordamiento de la cola\n";
            cout << "Presiona Enter para salir...";
            cin.ignore(10000, '\n');
            cin.get();
            return 1;
        }

        cout << "Ingrese un elemento para la cola: ";
        TipoDato elemento;
        cin >> elemento;

        final = (final + 1) % MaxTamC;
        A[final] = elemento;
        contador++;

        cout << "Elemento " << contador << " agregado a la cola: " << elemento << "\n";

        if (contador < 10) {
            cout << "¿Desea agregar mas elementos a la cola? (s/n): ";
            cin >> respuesta;
        }
    }

    if (frente == final) {
        cout << "La cola esta vacia.\n";
        cout << "Presiona Enter para salir...";
        cin.ignore(10000, '\n');
        cin.get();
        return 1;
    }

    TipoDato primerElemento = A[(frente + 1) % MaxTamC];
    cout << "\nEl primer elemento de la cola es: " << primerElemento << "\n";

    frente = (frente + 1) % MaxTamC;
    cout << "Un elemento ha sido eliminado de la cola (FIFO).\n";

    cout << "Elementos de la cola en el orden de ingreso:\n";

    if (frente != final) {
        int i = (frente + 1) % MaxTamC;
        while (true) {
            cout << A[i] << " ";
            if (i == final) break;
            i = (i + 1) % MaxTamC;
        }
        cout << "\n";
    }
    else {
        cout << "La cola se ha vaciado.\n";
    }

    cout << "\nPresiona Enter para salir...";
    cin.ignore(10000, '\n');
    cin.get();

    return 0;
}