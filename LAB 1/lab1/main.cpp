#include <iostream>
#include <cmath>

using namespace std;

/*
void ejercicio1();
void ejercicio3();
void ejercicio5();
void ejercicio7();
void ejercicio9();
void ejercicio11();
void ejercicio13();
void ejercicio15();
void ejercicio17();
void ejercicio19();
void ejercicio21();
void ejercicio23();
void ejercicio25();
void ejercicio27();
void ejercicio29();
void problema1();
void problema3();
void problema5();
void problema7();
void problema9();
void problema11();
void problema13();
*/

void problema15();
void problema17();


int main()
{
    /*
    ejercicio19();
    */
    problema17();
    return 0;
}

void ejercicio1()
{
    int a, b,residuo;
    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    while (b == 0) {
        cout << "El segundo numero no puede ser 0, intenta de nuevo: ";
        cin >> b;
    }

    residuo = a % b;

    cout << "El residuo de la division de " << a << " / " << b << " es " << residuo << endl;
}

void ejercicio3(){
    int a, b;

    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    while (a == b){
        cout << "Los numeros ingresados son iguales, intenta de nuevo: ";
        cin >> a >> b;
    }
    if (a > b)
        cout << "El mayor es: " << a << endl;
    else
        cout << "El mayor es: " << b << endl;


}

void ejercicio5(){
    int a, b;
    double dividir;
    cout << "Ingresa dos numeros: ";
    cin >> a >> b ;
    while (b == 0) {
        cout << "El segundo numero no puede ser 0, intenta de nuevo: ";
        cin >> b;
    }
    dividir = a / b;
    cout << "El resultado de la divison es: " << dividir << endl;

}

void ejercicio7(){
    int n, sum, i;

    sum = 0;

    cout << "Introduce un numero: ";
    cin >> n;

    for (i = 1; i <= n; i++){
        sum = sum + i;
    }
    cout <<  "la sumatoria desde 0 hasta " << n << " es: " << sum << endl;

}

void ejercicio9(){
    int n;
    double perimetro,area;

    cout << "Ingrese un numero: ";
    cin >> n;

    while ( n <= 0){
        cout << "Ingresa un numero diferente a 0: ";
        cin >> n;
    }

    perimetro = 2 * 3.1416 * n;
    area = 3.1416 * n * n;

    cout << "El perimetro: " << perimetro << endl;
    cout << "el area es : " << area << endl;

}

void ejercicio11(){
    int n ;
    int mult = 0;
    cout << "Ingrese un numero: ";
    cin >> n;

    while (n <=0){
        cout << "El numero no puede ser negativo o 0, ingresa de nuevo el numero: ";
        cin >> n;
    }
    for (int i=1;i<=10;i++){

        mult= n * i;
        cout << n << "*" << i << " = " << mult << endl;
    }


}

void ejercicio13(){

    int n;
    cout << "Ingresa un numer: ";
    cin >> n;

    while (n<=0){
        cout << " El numero no puede ser negativo o 0, intenta de nuevo: ";
        cin >> n;
    }

    cout << "Los divisores de " << n << " son:" << endl;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << " " << i << endl;
    }


}

void ejercicio15(){

    int n , sum = 0;

    do {
        cout << "Ingresa un numero: ";
        cin >> n;
        sum += n;
    } while (n!= 0);

    cout << "El resultado de la  sumatoria es: " << sum << endl;



}

void ejercicio17(){

    int n =1;

    int mayor = 0;

        while (n !=0){
        cout << "Ingresa un numero: ";
        cin >> n;

        if ( n > mayor){

            mayor = n;
        }
    }

    cout << " el numero mayor fue: " << mayor << endl;


}

void ejercicio19() {
    int n;
    int prim = 0;

    cout << "Ingresa un numero: ";
    cin >> n;


    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            prim++;
        }
    }

    if (prim == 2) {
        cout << n << " es un numero primo" << endl;
    } else {
        cout << n << " no es un numero primo" << endl;
    }


}

void ejercicio21(){

    char letra;

    cout << "ingrese una letra: ";
    cin >> letra;

    if (letra >=   'a' && letra <= 'z'){

       letra -= 32;

     } else if (letra >=  'A' && letra  <= 'Z' ){
      letra += 32;
         }

     cout << letra << endl;


}

void ejercicio23(){
    int n1, n2, a, b, c, mcm;
    cout << "Ingrese dos numeros: ";
    cin >> n1 >> n2;

    a = n1;
    b = n2;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    mcm = (n1 / a) * n2;
    cout << "El MCM de " << n1 << " y " << n2 << " es " << mcm << "." << endl;
}

void ejercicio25(){
    int n,a;

    int c = 1;



    cout << "Ingresa un numero: ";
    cin >> n;

    a=n;

    while (n >= 10){
        n = n /10;
        c ++;

    }

    cout << " el numero " << a << " tiene " << c << " digitos " << endl;



}

void ejercicio27() {
    double n1, n2;
    double sum, rest, mult, div;
    char simb;

    cout << "Ingrese dos numeros: ";
    cin >> n1 >> n2;

    cout << "Ingrese el simbolo de la operacion que desea realizar: ";
    cin >> simb;


    while (simb != '+' && simb != '-' && simb != '*' && simb != '/') {
        cout << "Error: Operacion no reconocida. Use +, -, * o /." << endl;
        cin >> simb;
    }

    if (simb == '+') {
        sum = n1 + n2;
        cout << "El resultado de la suma es: " << sum << endl;
    } else if (simb == '-') {
        rest = n1 - n2;
        cout << "El resultado de la resta es: " << rest << endl;
    } else if (simb == '*') {
        mult = n1 * n2;
        cout << "El resultado de la multiplicacion es: " << mult << endl;
    } else if (simb == '/') {

        while (n2 == 0) {
            cout << "Error: Division por cero no permitida. Ingresa de nuevo el divisor: ";
            cin >> n2;
        }
        div = n1 / n2;
        cout << "El resultado de la division es: " << div << endl;
    }
}

void ejercicio29(){
    int min = 0, max = 100, mid;
    char res;

    cout << "Piensa en un numero entre 0 y 100 y yo lo adivinare." << endl;

    while (min <= max) {
        mid = (min + max) / 2;
        cout << "Es " << mid << " tu numero? (Ingrese '>' si es mayor, '<' si es menor, '=' si es correcto): ";
        cin >> res;

        if (res == '=') {
            cout << "He adivinado tu numero!" << endl;
            break;
        } else if (res == '<') {
            max = mid - 1;
        } else if (res == '>') {
            min = mid + 1;
        } else {
            cout << "Entrada no valida. Usa solo '>', '<' o '='." << endl;
        }
    }
}

void problema1(){
    char caracter;
        cout << "Ingrese un caracter" << endl;
    cin >> caracter;

    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
        // Convertimos a mayúscula si es minúscula
        if (caracter >= 'a') {
            caracter -= 32;
        }

        // Verificamos si es vocal
        if (caracter == 'A' || caracter == 'E' || caracter == 'I' ||
            caracter == 'O' || caracter == 'U') {
            cout << caracter << " es una vocal" << endl;
        } else {
            cout << caracter << " es una consonante" << endl;
        }
    } else {
        cout << caracter << " No es una letra" << endl;
    }
}

void problema3(){
    int dia,mes;

    cout << "Ingrese dia:" << endl;
    cin>>dia;
    cout << "ingrese mes:" << endl;
    cin>>mes;

    if (mes < 1 || mes >12){
        cout << "El mes" << mes << " Es invalido"<< endl;
    }
    else{
        int dias[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (dia < 1||dias[mes-1]){
            if (mes ==2 && dia==29){
                cout << dia << "/" << mes<< "posible bisiesto" << endl;
            }else{

                cout << dia << "/" << mes << " es una fecha valida." <<endl;

            }
        } else {
            cout << dia << "/" << mes << " es una fecha invalida." << endl;

        }

    }
}

void problema5(){
    int n;
    cout << "Ingrese un numero entero impar: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Ingrese un numero impar." << endl;

    }

    // Imprimir el patron ascendente con espacio a la izquierda
    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= (n - i) / 2; j++) {
            cout << " "; // Espacios a la izquierda
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Imprimir el patron descendente con espacio a la izquierda
    for (int i = n - 2; i > 0; i -= 2) {
        for (int j = 1; j <= (n - i) / 2; j++) {
            cout << " "; // Espacios a la izquierda
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void problema7(){
    int n,c;
    cout << "Ingrese un numero n: " << endl;
    cin >> n;

    int a = 1, b = 1, sum = 0;

    while (b < n) {
        if (b % 2 == 0) {
            sum += b;
        }
        c = a + b;
        a = b;
        b = c;
    }

    cout << "El resultado de la suma es: " << sum << endl;


}

void problema9(){
    int n, sum = 0;
    cout << "Ingrese un numero entero N: " << endl;
    cin >> n;

    int b = n;
    while (b > 0) {
        int digit = b % 10;
        sum += pow(digit, digit);
        b /= 10;
    }

    cout << "El resultado de la suma es: " << sum << endl;
}

void problema11(){
    int num, mcm, a, b, c, i;
    cout << "Ingrese un numero: ";
    cin >> num;

    while(num < 1){
        cout << "El numero debe ser mayor o igual a 1." << endl;
        cout << "Ingrese nuevamente el numero: ";
        cin >> num;
    }

    mcm = 1;
    for (i = 1; i <= num; i++) {
        a = mcm;
        b = i;
        while (b != 0) {
            c = b;
            b = a % b;
            a = c;
        }
        mcm = (mcm * i) / a;
    }

    cout << " El minimo comun multiplo es: " << mcm << endl;

}

void problema13(){

    int n;
    int prim = 0;  //Contador de #´s primos

    cout << "Ingresa un numero: ";
    cin >> n;

    for (int i = 2; i <=n ; i++) {
        if (n % i == 0) {
            prim += i;

        }
    }

    cout << " la suma es " << prim << endl;

}

void problema15(){
    int num_user;
    cout << "Ingrese un numero impar y mayor que 0: ";
    cin >> num_user;


    while(num_user % 2 == 0 ||  num_user < 1) {
        cout << "El numero debe ser impar y mayor a 0." << endl;
        cout << "Ingresa de nuevo el numero: ";
        cin >> num_user;
    }

    /*suma_num es = 1 ya que en 1 comienza la espiral, y almacena la suma de la espiral
      num es en el numero en donde va la espiral
    */
    int suma_num = 1,num = 1, incremento = 2;

    for (int i = 1; i <= num_user / 2; ++i) {   //i <= num_user dicta el numero de capas de la espiral
        for (int j = 0; j < 4; ++j) { // Comienza a realizar la suma de los numeros hasta recorrer las 4 esquinas del espiral
            num += incremento;
            suma_num += num;
        }
        incremento += 2; // Aumenta  +2 para la siguiente capa
    }

    cout << "En una espiral de " << num_user << "x" << num_user << ", la suma es: " << suma_num << "." << endl;

}

void problema17(){

    int num_inicial = 1; //Dicta desde donde comienza el programa a evaluar para encontrar los divisores
    int num_user;

    cout<<"Ingrese un numero: ";
    cin >> num_user;

    while(true){
        int num_triangular = num_inicial *(num_inicial + 1)/2;
        int contador_divisores = 0;
        int raiz_num = sqrt(num_triangular); //La raiz cuadrada del numero triangular dicta cual es el # maximo por el cual dividirlo

        for(int i = 1; i <= raiz_num; i++){

            if(num_triangular % i == 0 && i*i != num_triangular){
                contador_divisores += 2; //El contador avanza +2 ya que si la division exacta entonces tanto el cociente como el divisor son divisores
            }
        }

        if(contador_divisores > num_user){
            cout<<"El primer numero triangular con mas de " << num_user << " divisores es: " << num_triangular << endl;
            break;
        }
        num_inicial +=1;
    }















}

