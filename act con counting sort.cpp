#include <iostream>
#include <array>
#include <vector>
using namespace std;

// Función para aplicar Counting Sort
void countingSort(array<int, 20>& a, size_t n) {
    // Encuentra el valor máximo en el array para determinar el tamaño de conteo
    int max_val = 100; // En este caso sabemos que el máximo valor es 100

    // Crea el array de conteo e inicialízalo con ceros
    vector<int> count(max_val + 1, 0);

    // Cuenta la ocurrencia de cada valor
    for (size_t i = 0; i < n; ++i) {
        count[a[i]]++;
    }

    // Reconstruye el array ordenado
    size_t index = 0;
    for (int i = 10; i <= max_val; ++i) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    const size_t TAMANO{20}; // tamaño del array
    array<int, TAMANO> a{};
    size_t subindice{0};
    bool duplicado{false};

    cout << "Ingrese 20 enteros entre 10 y 100:\n";

    // Obtener 20 enteros no duplicados en el rango entre 10 y 100
    unsigned int i{0};

    while (i < a.size()) {
        duplicado = false;
        int valor{0}; // número ingresado por el usuario
        cin >> valor;

        // Validar entrada y comprobar si hay duplicados
        if (valor >= 10 && valor <= 100) {
            for (size_t j{0}; j < subindice; ++j) {
                if (valor == a[j]) {
                    duplicado = true;
                    break;
                }
            }

            // Si el número no es un duplicado, ingresarlo en el array
            if (!duplicado) {
                a[subindice++] = valor;
            }
            else {
                cout << "Número duplicado.\n";
            }

            ++i;
        }
        else {
            cout << "Número inválido.\n";
        }
    }

    // Ordenar el array de valores no duplicados usando Counting Sort
    countingSort(a, subindice);

    cout << "\nLos valores no duplicados y ordenados son:\n";

    // Mostrar array ordenado sin duplicados
    for (size_t indice{0}; indice < subindice; ++indice) {
        cout << a[indice] << ' ';
    }

    cout << endl;
}