#include <iostream>

using namespace std;

void ejercicio1();

int main()
{
    ejercicio1();
    return 0;
}

void ejercicio1()
{
 int a, b;
 cout << "Ingresa dos numeros: ";
 cin >> a >> b;
 cout << "el residuo de la divion es: " << a << "/" << b << "es " << a % b << endl;
}
