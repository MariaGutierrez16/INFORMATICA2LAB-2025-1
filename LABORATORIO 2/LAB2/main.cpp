#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void problema1();
void problema2();

int main()
{
    problema2();

    return 0;
}


//ejercicio1
void fun_a(int *px,int*py){ int tmp = *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam){
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--) { fun_a(&b[f], &b[l]);
    }
}

//ejercicio2

//int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//fun_b(array, 10);

void fun_c(double *a, int n, double *promedio, double *suma) {
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++)
        *suma += *(a + i);
    *promedio = *suma / n;
}

//ejercicio 3

//int main() {
    unsigned short b[4][2] = {
        {77, 50},
        {5, 2},
        {28, 39},
        {99, 3}
    };

    //cout << "b         = " << b << endl;
    //cout << "b + 2     = " << b + 2 << endl;
    //cout << "*(b + 2)  = " << *(b + 2) << endl;
    //cout << "*(b+2)+1  = " << *(b + 2) + 1 << endl;
    //cout << "*(*(b+2)+1) = " << *(*(b + 2) + 1) << endl;
    //cout << "b[3][1]   = " << b[3][1] << endl;

    // Esto genera error: b++
    // b++;

    //return 0;
//}

    void problema1(){

        int billetes[6] = {0}; // Para almacenar los billetes de 1000, 2000, 5000, 10000, 20000, 50000
        int monedas[4] = {0};  // Para almacenar las monedas de 50, 100, 200, 500
        int faltante = 0;
        int cantdinero;

        cout << "Ingresa el valor de cantidad de dinero: ";
        cin >> cantdinero;

        // Denominaciones de billetes y monedas
        int valores_billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
        int valores_monedas[] = {500, 200, 100, 50};

        // Calcular billetes
        for (int i = 0; i < 6; i++) {
            billetes[i] = cantdinero / valores_billetes[i];
            cantdinero %= valores_billetes[i];
        }

        // Calcular monedas
        for (int i = 0; i < 4; i++) {
            monedas[i] = cantdinero / valores_monedas[i];
            cantdinero %= valores_monedas[i];
        }

        faltante = cantdinero; // Lo que queda es el faltante

        // Mostrar el resultado
        cout << "50000 : " << billetes[0] << endl;
        cout << "20000 : " << billetes[1] << endl;
        cout << "10000 : " << billetes[2] << endl;
        cout << "5000  : " << billetes[3] << endl;
        cout << "2000  : " << billetes[4] << endl;
        cout << "1000  : " << billetes[5] << endl;
        cout << "500   : " << monedas[0] << endl;
        cout << "200   : " << monedas[1] << endl;
        cout << "100   : " << monedas[2] << endl;
        cout << "50    : " << monedas[3] << endl;
        cout << "Faltante: " << faltante << endl;

    }
    void problema2() {
        srand(time(0));

        const int tamaño = 10;
        char letras[tamaño];
        int conteo[26] = {0};

        // Llenar el arreglo con letras mayúsculas aleatorias
        for (int i = 0; i < tamaño; i++) {
            letras[i] = 'A' + rand() % 26;
        }

        // Imprimir el arreglo
        for (int i = 0; i < tamaño; i++) {
            cout << letras[i];
        }
        cout << endl;

        // Contar las letras
        for (int i = 0; i < tamaño; i++) {
            if (letras[i] >= 'A' && letras[i] <= 'Z') {
                conteo[letras[i] - 'A']++;
            }
        }

        // Imprimir el conteo
        for (int i = 0; i < 26; i++) {
            if (conteo[i] > 0) {
                cout << char('A' + i) << ": " << conteo[i] << endl;
            }
        }
    }
