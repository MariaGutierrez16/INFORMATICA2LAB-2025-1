#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void problema1();
void problema2();
void problema3();
void problema4();
void problema5();
void problema6();

int main()
{
    problema6();

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

        const int tamaño = 200;
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
    void problema3() {
        char a[100], b[100];
        int i = 0;

        cout << "Ingrese la primera cadena: ";
        cin >> a;

        cout << "Ingrese la segunda cadena: ";
        cin >> b;

        while (a[i] != '\0' && b[i] != '\0') {
            if (a[i] != b[i]) {
                cout << "Las cadenas son diferentes." << endl;
                return;
            }
            i++;
        }

        if (a[i] == '\0' && b[i] == '\0') {
            cout << "Las cadenas son iguales." << endl;
        } else {
            cout << "Las cadenas son diferentes." << endl;
        }
    }

    void problema4() {
        char texto[100];
        int numero = 0, i = 0;

        cout << "Ingrese un numero en forma de cadena: ";
        cin >> texto;

        while (texto[i] != '\0') {
            numero = numero * 10 + (texto[i] - '0');
            i++;
        }

        cout << "El numero entero es: " << numero << endl;
    }
    void problema5() {
        int numero;
        char cadena[20];
        char temp[20];
        int i = 0, j = 0;

        cout << "Ingrese un numero entero: ";
        cin >> numero;

        if (numero == 0) {
            cadena[0] = '0';
            cadena[1] = '\0';
        } else {
            while (numero > 0) {
                temp[i] = (numero % 10) + '0';
                numero = numero / 10;
                i++;
            }

            while (i > 0) {
                i--;
                cadena[j] = temp[i];
                j++;
            }

            cadena[j] = '\0';
        }

        cout << "La cadena es: " << cadena << endl;
    }
    void problema6() {
        char texto[100];
        char mayuscula[100];
        int i = 0;

        cout << "Ingrese una cadena: ";
        cin >> texto;

        while (texto[i] != '\0') {
            if (texto[i] >= 'a' && texto[i] <= 'z') {
                mayuscula[i] = texto[i] - ('a' - 'A');  // Convertir a mayúscula
            } else {
                mayuscula[i] = texto[i];  // Dejar igual si no es minúscula
            }
            i++;
        }

        mayuscula[i] = '\0';  // Fin de cadena

        cout << "Original: " << texto << ". En mayuscula: " << mayuscula << "." << endl;
    }
