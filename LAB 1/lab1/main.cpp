#include <iostream>

using namespace std;

void ejercicio1();
int ejercicio3();
int ejercicio5();
int ejercicio7();
int ejercicio9();

int main()
{
    ejercicio9();
    return 0;
}

void ejercicio1()
{
 int a, b;
 cout << "Ingresa dos numeros: ";
 cout << "Ingresa el primer numero: ";
 cin >> a;
 cout << "ingresa el segundo numero: ";
 cin >> b;
 cout << "el residuo de la divion es: " << a << "/" << b << "es " << a % b << endl;


}

int ejercicio3(){
    int a, b;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;
    if (a > b)
        cout << "El mayor es: " << a << endl;
    else
        cout << "El mayor es: " << b << endl;

    return 0;
}

int ejercicio5(){
    int a, b;
    float dividir;
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "ingresa el segundo numero: ";
    cin >> b;
    dividir = a / b;
    cout << "El resultado de la divison es: " << dividir;
    return 0;
}

int ejercicio7(){
    int n, sum, i;

    sum = 0;

    cout << "Introduce un numero: ";
    cin >> n;

    for (i = 1; i <= n; i++){
        sum = sum + i;
    }
    cout <<  "la suma es: " << sum << endl;
    return 0;
}

int ejercicio9(){
    int n;
    double perimetro,area;

    cout << "Ingrese un numero: ";
    cin >> n;

    perimetro = 2 * 3.1416 * n;
    area = 3.1416 * n * n;

    cout << "El perimetro: " << perimetro << endl;
    cout << "el area es : " << area << endl;
    return 0;
}
