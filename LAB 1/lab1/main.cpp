#include <iostream>
#include <cmath>

using namespace std;


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
void problema15();
void problema17();


int main()
{

    problema13();
    return 0;
}

void ejercicio1()
{
    int a, b, residuo;
    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    // Validación: el segundo número no puede ser 0 para evitar la división por cero
    while (b == 0) {
        cout << "El segundo numero no puede ser 0, intenta de nuevo: ";
        cin >> b;
    }

    // Cálculo del residuo de la división entera
    residuo = a % b;
    cout << "El residuo de la division de " << a << " / " << b << " es " << residuo << endl;
}

void ejercicio3(){
    int a, b;
    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    // Validación: los números no pueden ser iguales, ya que buscamos el mayor
    while (a == b){
        cout << "Los numeros ingresados son iguales, intenta de nuevo: ";
        cin >> a >> b;
    }

    // Determinar y mostrar el número mayor
    if (a > b)
        cout << "El mayor es: " << a << endl;
    else
        cout << "El mayor es: " << b << endl;
}

void ejercicio5(){
    int a, b;
    double dividir;
    cout << "Ingresa dos numeros: ";
    cin >> a >> b;

    // Validación: el divisor no puede ser 0 para evitar errores matemáticos
    while (b == 0) {
        cout << "El segundo numero no puede ser 0, intenta de nuevo: ";
        cin >> b;
    }

    // Realizar la división y mostrar el resultado
    dividir = (double)a / b;
    cout << "El resultado de la division es: " << dividir << endl;
}

void ejercicio7(){
    int n, sum = 0;
    cout << "Introduce un numero: ";
    cin >> n;

    // Sumatoria desde 1 hasta n usando un bucle for
    for (int i = 1; i <= n; i++){
        sum += i; // Acumulamos la suma de los números
    }
    cout << "La sumatoria desde 0 hasta " << n << " es: " << sum << endl;
}

void ejercicio9(){
    int n;
    double perimetro, area;

    cout << "Ingrese un numero: ";
    cin >> n;

    // Validación: el radio del círculo debe ser mayor que 0
    while (n <= 0){
        cout << "Ingresa un numero diferente a 0: ";
        cin >> n;
    }

    // Cálculo del perímetro y área de un círculo usando la fórmula del círculo
    perimetro = 2 * 3.1416 * n;
    area = 3.1416 * n * n;

    cout << "El perimetro: " << perimetro << endl;
    cout << "El area es: " << area << endl;
}

void ejercicio11(){
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    // Validación: el número debe ser positivo para calcular su tabla de multiplicar
    while (n <= 0){
        cout << "El numero no puede ser negativo o 0, ingresa de nuevo el numero: ";
        cin >> n;
    }

    // Mostrar la tabla de multiplicar del número ingresado del 1 al 10
    for (int i = 1; i <= 10; i++){
        cout << n << " * " << i << " = " << n * i << endl;
    }
}

void ejercicio13(){
    int n;
    cout << "Ingresa un numero: ";
    cin >> n;

    // Validación: el número debe ser positivo para calcular sus divisores
    while (n <= 0){
        cout << "El numero no puede ser negativo o 0, intenta de nuevo: ";
        cin >> n;
    }

    // Mostrar todos los divisores del número ingresado
    cout << "Los divisores de " << n << " son:" << endl;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) // Si el residuo es 0, significa que i es un divisor de n
            cout << " " << i << endl;
    }
}

void ejercicio15(){
    int n , sum = 0;

    // Solicita números al usuario y los suma hasta que ingrese 0
    do {
        cout << "Ingresa un numero: ";
        cin >> n;
        sum += n;
    } while (n!= 0);

    cout << "El resultado de la sumatoria es: " << sum << endl;
}

void ejercicio17(){
    int n =1;
    int mayor = 0;

    // Encuentra el número mayor ingresado hasta que se ingrese 0
    while (n !=0){
        cout << "Ingresa un numero: ";
        cin >> n;

        if ( n > mayor){
            mayor = n;
        }
    }

    cout << "El numero mayor fue: " << mayor << endl;
}

void ejercicio19() {
    int n;
    int prim = 0;

    cout << "Ingresa un numero: ";
    cin >> n;

    // Verifica cuántos divisores tiene el número ingresado
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            prim++;
        }
    }

    // Un número es primo si solo tiene dos divisores (1 y él mismo)
    if (prim == 2) {
        cout << n << " es un numero primo" << endl;
    } else {
        cout << n << " no es un numero primo" << endl;
    }
}

void ejercicio21(){
    char letra;

    cout << "Ingrese una letra: ";
    cin >> letra;

    // Convierte minúsculas a mayúsculas y viceversa
    if (letra >= 'a' && letra <= 'z'){
        letra -= 32;
    } else if (letra >= 'A' && letra  <= 'Z') {
        letra += 32;
    }

    cout << letra << endl;
}

void ejercicio23(){
    int n1, n2, a, b, c, mcm;
    cout << "Ingrese dos numeros: ";
    cin >> n1 >> n2;

    // Calcula el MCD utilizando el algoritmo de Euclides
    a = n1;
    b = n2;
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }

    // Calcula el MCM usando el MCD
    mcm = (n1 / a) * n2;
    cout << "El MCM de " << n1 << " y " << n2 << " es " << mcm << "." << endl;
}

void ejercicio25(){
    int n, a;
    int c = 1;

    cout << "Ingresa un numero: ";
    cin >> n;
    a = n;

    // Cuenta la cantidad de dígitos del número
    while (n >= 10){
        n = n / 10;
        c++;
    }

    cout << "El numero " << a << " tiene " << c << " digitos " << endl;
}

void ejercicio27() {
    double n1, n2;
    double sum, rest, mult, div;
    char simb;

    cout << "Ingrese dos numeros: ";
    cin >> n1 >> n2;
    cout << "Ingrese el simbolo de la operacion que desea realizar: ";
    cin >> simb;

    // Verifica que el operador ingresado sea válido
    while (simb != '+' && simb != '-' && simb != '*' && simb != '/') {
        cout << "Error: Operacion no reconocida. Use +, -, * o /." << endl;
        cin >> simb;
    }

    // Realiza la operación correspondiente
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
        // Evita la división por cero
        while (n2 == 0) {
            cout << "Error: Division por cero no permitida. Ingresa de nuevo el divisor: ";
            cin >> n2;
        }
        div = n1 / n2;
        cout << "El resultado de la division es: " << div << endl;
    }
}

void ejercicio29() {
    int min = 0, max = 100, mid; // Definimos los límites del rango y la variable para el valor medio
    char res; // Variable para almacenar la respuesta del usuario

    cout << "Piensa en un numero entre 0 y 100 y yo lo adivinare." << endl;

    // Utiliza búsqueda binaria para adivinar el número del usuario
    while (min <= max) {
        mid = (min + max) / 2; // Calcula el punto medio del rango actual
        cout << "Es " << mid << " tu numero? (Ingrese '>' si es mayor, '<' si es menor, '=' si es correcto): ";
        cin >> res;

        if (res == '=') { // Si el usuario indica que el número es correcto
            cout << "He adivinado tu numero!" << endl;
            break; // Termina el bucle
        } else if (res == '<') { // Si el número pensado es menor que mid
            max = mid - 1; // Ajusta el límite superior
        } else if (res == '>') { // Si el número pensado es mayor que mid
            min = mid + 1; // Ajusta el límite inferior
        } else { // Manejo de entrada no válida
            cout << "Entrada no valida. Usa solo '>', '<' o '='." << endl;
        }
    }
}


void problema1(){
    char caracter;
        cout << "Ingrese un caracter" << endl;
    cin >> caracter;


    while ((caracter != 'A' && caracter != 'Z') || (caracter != 'a' && caracter != 'z')){
        cout << caracter << " No es una letra, ingrese un caracter valido: " << endl;
        cin >> caracter;
        break;
    }

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
    }


}

void problema3(){
    int dia, mes;

    // Solicitar al usuario ingresar el día y el mes
    cout << "Ingrese dia:" << endl;
    cin >> dia;
    cout << "Ingrese mes:" << endl;
    cin >> mes;

    // Verificar si el mes ingresado es válido (entre 1 y 12)
    if (mes < 1 || mes > 12) {
        cout << "El mes " << mes << " es invalido." << endl;
    } else {
        // Definir la cantidad de días en cada mes (sin considerar años bisiestos)
        int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Verificar si el día ingresado es válido para el mes correspondiente
        if (dia < 1 || dia > dias[mes - 1]) {
            // Caso especial: verificar si el día es 29 de febrero (posible año bisiesto)
            if (mes == 2 && dia == 29) {
                cout << dia << "/" << mes << " posible bisiesto" << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
        } else {
            // Si el día y el mes son válidos, se considera una fecha válida
            cout << dia << "/" << mes << " es una fecha valida." << endl;
        }
    }
}

void problema5(){
    int n;
    cout << "Ingrese un numero entero impar: ";
    cin >> n;

    // Verificar si el número ingresado es par
    while (n % 2 == 0) {
        cout <<"Valor incorrecto, intenta de nuevo: " << endl;
        cin >> n;
    }

    // Imprimir el patrón ascendente con espacios a la izquierda
    for (int i = 1; i <= n; i += 2) {
        // Imprimir espacios a la izquierda para centrar el patrón
        for (int j = 1; j <= (n - i) / 2; j++) {
            cout << " ";
        }
        // Imprimir los asteriscos
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Imprimir el patrón descendente con espacios a la izquierda
    for (int i = n - 2; i > 0; i -= 2) {
        // Imprimir espacios a la izquierda para centrar el patrón
        for (int j = 1; j <= (n - i) / 2; j++) {
            cout << " ";
        }
        // Imprimir los asteriscos
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void problema7(){
    int n, c;

    // Solicitar al usuario un número límite
    cout << "Ingrese un numero n: " << endl;
    cin >> n;

    // Inicializar variables para la secuencia de Fibonacci
    int a = 1, b = 1, sum = 0;

    // Calcular la suma de los términos pares de la secuencia de Fibonacci menores a n
    while (b < n) {
        // Si el término actual es par, se suma al resultado
        if (b % 2 == 0) {
            sum += b;
        }
        // Calcular el siguiente término de la secuencia de Fibonacci
        c = a + b;
        a = b;
        b = c;
    }

    // Mostrar el resultado de la suma
    cout << "El resultado de la suma es: " << sum << endl;
}
void problema9(){
    int n, sum = 0;

    // Solicitar al usuario un número entero
    cout << "Ingrese un numero entero N: " << endl;
    cin >> n;

    int b = n; // Variable auxiliar para recorrer los dígitos de n

    // Iterar sobre cada dígito del número
    while (b > 0) {
        int digit = b % 10; // Obtener el último dígito
        sum += pow(digit, digit); // Elevar el dígito a sí mismo y sumarlo
        b /= 10; // Eliminar el último dígito
    }

    // Mostrar el resultado de la suma
    cout << "El resultado de la suma es: " << sum << endl;
}

void problema11(){
    int num, mcm, a, b, c, i;

    // Solicitar al usuario un número entero positivo
    cout << "Ingrese un numero: ";
    cin >> num;

    // Validar que el número sea mayor o igual a 1
    while(num < 1){
        cout << "El numero debe ser mayor o igual a 1." << endl;
        cout << "Ingrese nuevamente el numero: ";
        cin >> num;
    }

    mcm = 1; // Inicializar el mínimo común múltiplo

    // Calcular el MCM de los números del 1 hasta num
    for (i = 1; i <= num; i++) {
        a = mcm;
        b = i;

        // Calcular el máximo común divisor (MCD) usando el algoritmo de Euclides
        while (b != 0) {
            c = b;
            b = a % b;
            a = c;
        }

        // Calcular el MCM usando la fórmula: MCM(a, b) = (a * b) / MCD(a, b)
        mcm = (mcm * i) / a;
    }

    // Mostrar el resultado del MCM
    cout << " El minimo comun multiplo es: " << mcm << endl;
}
void problema13(){

    int n;
    int prim = 0;  // Contador para la suma de divisores de n

    // Solicitar al usuario un número entero
    cout << "Ingresa un numero: ";
    cin >> n;

    // Recorrer desde 2 hasta n para encontrar sus divisores
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) { // Verificar si i es divisor de n
            prim += i; // Sumar el divisor a la variable prim
        }
    }

    // Mostrar el resultado de la suma de los divisores de n
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

