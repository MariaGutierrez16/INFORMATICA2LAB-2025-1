#include <iostream>

using namespace std;

void ejercicio1();
int ejercicio3();
int ejercicio5();

int main()
{
    ejercicio5();
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
