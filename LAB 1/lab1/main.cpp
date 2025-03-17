#include <iostream>

using namespace std;

void ejercicio1();
int ejercicio3();

int main()
{
    ejercicio3();
    return 0;
}

void ejercicio1()
{
 int a, b;
 cout << "Ingresa dos numeros: ";
 cin >> a >> b;
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
