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
void problema7();
void problema8();
void problema9();
void problema10();
void problema11();
void problema12();
void problema13();
void problema14();
void problema15();
void problema16();
void problema17();
void problema18();


int main()
{
    problema7();

    return 0;
}


//ejercicio1

//int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//fun_b(array, 10);

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



void fun_c(double *a, int n, double *promedio, double *suma) {
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++)
        *suma += a[i];
    *promedio = *suma / n;

    cout << endl << endl;
    cout << "Suma: " << *suma << endl;
    cout << "Promedio: " << *promedio << endl;

    //main
    //double datos[] = {5, 4, 7, 2, 3, 9};
    //int cantidad = 6;
    //double suma, promedio;

    //fun_c(datos, cantidad, &promedio, &suma);

}

//ejercicio 3  Encontrar direcciones en memoria y valores de variables

//int main() {
    unsigned short b[4][2] = {
        {77, 50},
        {5, 2},
        {28, 39},
        {99, 3}
    };


    /*
    b                -> direccion: 0x0A12
    b + 2            -> direccion: 0xA1A    Por notacion hexadecimal
    *(b + 2)         -> = 28  Apunta a b[2][0]
    *(b + 2) + 1     -> = 39
    *(*(b + 2) + 1)  -> = 39
    b[3][1]          -> = 3
    *b++             -> = 77
    */


//}


/*  Ejercicio 4 LED con potenciometro

int potPin = A0;       // Pin analógico donde está el potenciómetro
int ledAzul = 3;        // Pin PWM donde está conectado el LED
int valorPot = 0;      // Valor leído del potenciómetro (0-1023)
int brillo = 0;        // Valor convertido para PWM (0-255)

void setup() {
  pinMode(ledAzul, OUTPUT);  // El pin del LED es salida
}

void loop() {
  valorPot = analogRead(potPin);            // Leer valor del potenciómetro (0-1023)
  brillo = map(valorPot, 0, 1023, 0, 255);  // Convertir a rango PWM (0-255)
  analogWrite(ledAzul, brillo);             // Escribir el brillo al LED
  delay(10);                               // Pequeña pausa para estabilidad
}

Ejercicio 5  Mostrar mensaje en pantalla LCD

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);   //Inicia los puertos del arduino desde el 2 hasta el 7
String msgUser = "";  //Inicializa la variable msgUser

void setup()
{
  lcd.begin(16,2); //Inicia el sistema con 16 columnas y 2 filas
  Serial.begin(9600); //Inicializa el serial
  lcd.print("Hola soy Arduino, escribe un msg");
}

void loop()
{


  if (Serial.available()) {
    msgUser = Serial.readStringUntil('\n');  // Leer hasta que se oprima enter

    lcd.clear();  //limpia la pantalla
    lcd.setCursor(0, 0); //pone el cursor de la pantalla en el inicio para mostrar mensaje nuevo
    lcd.print(msgUser); //Muestra el mensaje que envio el usuario
    lcd.setCursor(0, 1);

    lcd.print("");

    Serial.println("Mensaje exitoso en LCD."); //muestra mensaje exitoso en consola

  lcd.scrollDisplayLeft();  //hace que los mensajes se desplacen hacia la izq.
  delay(300);

}


 */

    void problema1(){ //Maquina de cambio de dinero

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
    void problema2() { //Generar 200 letras mayusculas aleatorias
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


    void problema3() { //Comparar 2 cadenas y devolver True/ False si son iguales

        char a[100], b[100];  // Arreglos para almacenar las dos cadenas (máximo 99 caracteres cada una)
        int i = 0;            // Índice para recorrer las cadenas

        cout << "Ingrese la primera cadena: ";
        cin >> a;             // Se lee la primera cadena (sin espacios)

        cout << "Ingrese la segunda cadena: ";
        cin >> b;             // Se lee la segunda cadena (sin espacios)

        // Se recorre ambas cadenas carácter por carácter mientras no se llegue al final de alguna
        while (a[i] != '\0' && b[i] != '\0') {
            // Si se encuentra un carácter diferente, se concluye que las cadenas son distintas
            if (a[i] != b[i]) {
                cout << "Las cadenas son diferentes." << endl;
                return;  // Sale de la función al encontrar la diferencia
            }
            i++;  // Pasa al siguiente carácter
        }

        // Si ambas cadenas terminaron al mismo tiempo, son iguales
        if (a[i] == '\0' && b[i] == '\0') {
            cout << "Las cadenas son iguales." << endl;
        } else {
            // Si una cadena es más larga que la otra, son diferentes
            cout << "Las cadenas son diferentes." << endl;
        }
    }


    void problema4() {//Convertir de str a int
        char texto[100];          // Arreglo para almacenar la cadena ingresada (máximo 99 caracteres + terminador nulo)
        int numero = 0, i = 0;    // Variables: 'numero' para acumular el resultado y 'i' como índice para recorrer el texto

        cout << "Ingrese un numero en forma de cadena: ";
        cin >> texto;             // Se lee la cadena ingresada por el usuario

        // Bucle que recorre cada carácter de la cadena hasta encontrar el terminador nulo '\0'
        while (texto[i] != '\0') {
            // Convierte el carácter actual a número y lo acumula en 'numero'
            numero = numero * 10 + (texto[i] - '0');
            i++; // Avanza al siguiente carácter
        }

        // Muestra el número entero resultante
        cout << "El numero entero es: " << numero << endl;
    }


    void problema5() { //Convertir de int a str
        int numero;
        char cadena[20];  // Arreglo donde se almacenará la cadena resultante
        char temp[20];    // Arreglo temporal para almacenar los dígitos en orden inverso
        int i = 0, j = 0;  // Variables auxiliares para los índices

        cout << "Ingrese un numero entero: ";
        cin >> numero;  // Se lee el número entero ingresado por el usuario

        // Caso especial: si el número es 0, se asigna manualmente
        if (numero == 0) {
            cadena[0] = '0';
            cadena[1] = '\0';  // Se agrega el terminador nulo
        } else {
            // Se extraen los dígitos del número desde el final
            while (numero > 0) {
                temp[i] = (numero % 10) + '0';  // Convierte el dígito a carácter y lo guarda en 'temp'
                numero = numero / 10;           // Elimina el último dígito del número
                i++;
            }

            // Se invierte el orden de los caracteres para obtener la cadena correcta
            while (i > 0) {
                i--;
                cadena[j] = temp[i];  // Copia de 'temp' a 'cadena' en orden correcto
                j++;
            }

            cadena[j] = '\0';  // Se agrega el terminador nulo al final de la cadena
        }

        // Se muestra la cadena resultante
        cout << "La cadena es: " << cadena << endl;
    }


    void problema6() { //Cambiar letras de minusculas a mayusculas
        char texto[100];       // Arreglo para almacenar la cadena original ingresada por el usuario
        char mayuscula[100];   // Arreglo para almacenar la versión en mayúsculas
        int i = 0;             // Índice para recorrer los arreglos

        cout << "Ingrese una cadena: ";
        cin >> texto;          // Se lee la cadena (sin espacios) desde el teclado

        // Recorre cada carácter de la cadena hasta llegar al final ('\0')
        while (texto[i] != '\0') {
            // Si el carácter es una letra minúscula (entre 'a' y 'z')
            if (texto[i] >= 'a' && texto[i] <= 'z') {
                // Se convierte a mayúscula restando la diferencia entre 'a' y 'A'
                mayuscula[i] = texto[i] - ('a' - 'A');
            } else {
                // Si no es una minúscula, se copia tal cual
                mayuscula[i] = texto[i];
            }
            i++;  // Avanza al siguiente carácter
        }

        mayuscula[i] = '\0';  // Se agrega el terminador nulo para finalizar la nueva cadena

        // Se muestra la cadena original y la convertida en mayúsculas
        cout << "Original: " << texto << ". En mayuscula: " << mayuscula << "." << endl;
    }


    void problema7() { //Quitar caracteres repetidos
        char original[100];        // Arreglo para la cadena original ingresada
        char sinRepetidos[100];    // Arreglo para almacenar la cadena sin caracteres repetidos
        int i = 0, j = 0, k;       // 'i' recorre original, 'j' controla el índice de sinRepetidos, 'k' para buscar repeticiones
        bool repetido;             // Bandera para saber si un carácter ya fue agregado

        cout << "Ingrese una cadena: ";
        cin >> original;           // Se lee la cadena (sin espacios)

        // Recorre cada carácter de la cadena original
        while (original[i] != '\0') {
            repetido = false;  // Se asume que el carácter no está repetido

            // Compara con los caracteres ya guardados en sinRepetidos
            for (k = 0; k < j; k++) {
                if (original[i] == sinRepetidos[k]) {
                    repetido = true;  // Si ya está, se marca como repetido
                    break;            // Se sale del ciclo interno
                }
            }

            // Si no está repetido, se agrega a sinRepetidos
            if (!repetido) {
                sinRepetidos[j] = original[i];
                j++;
            }

            i++;  // Avanza al siguiente carácter
        }

        sinRepetidos[j] = '\0';  // Se finaliza la nueva cadena con el terminador nulo

        // Muestra el resultado
        cout << "Original: " << original << ". Sin repetidos: " << sinRepetidos << "." << endl;
    }


    void problema8() { //Separa los numeros de los caracteres
        char original[100], texto[100], numero[100];  // original: entrada, texto: letras y otros, numero: solo dígitos
        int i = 0, j = 0, k = 0;  // i: recorre original, j: índice para número, k: índice para texto

        cout << "Ingrese una cadena: ";
        cin >> original;  // Se lee la cadena (sin espacios)

        // Se recorre la cadena original
        while (original[i] != '\0') {
            // Si el carácter es un dígito (entre '0' y '9')
            if (original[i] >= '0' && original[i] <= '9') {
                numero[j] = original[i];  // Se guarda en el arreglo de números
                j++;
            } else {
                texto[k] = original[i];   // Si no es número, se guarda en el arreglo de texto
                k++;
            }
            i++;  // Avanza al siguiente carácter
        }

        // Se agregan los terminadores nulos a ambas cadenas resultantes
        numero[j] = '\0';
        texto[k] = '\0';

        // Se imprime el resultado
        cout << "Original: " << original << "." << endl;
        cout << "Texto: " << texto << ". Numero: " << numero << "." << endl;
    }


    void problema9() { //Separar por grupos de 3 a numeros que estan en una cadena y sumarlos
        int n, indice = 0, suma = 0, longitud = 0;
        char cadena[100], copia[100];  // cadena: entrada original, copia: respaldo de la cadena modificada

        cout << "Ingrese la cantidad de cifras por grupo: ";
        cin >> n;

        cout << "Ingrese la cadena numerica: ";
        cin >> cadena;  // Se lee la cadena numérica como texto (sin espacios)

        // Calcular la longitud de la cadena
        while (cadena[longitud] != '\0') {
            longitud++;
        }

        int sobrante = longitud % n;  // Verifica si hay cifras que no completan un grupo

        // Si hay sobrante, se agregan ceros al principio para completar el último grupo
        if (sobrante != 0) {
            int ceros = n - sobrante;  // Cuántos ceros se necesitan

            // Mover todos los caracteres hacia la derecha para hacer espacio
            for (int i = longitud - 1; i >= 0; i--) {
                cadena[i + ceros] = cadena[i];
            }

            // Insertar ceros al inicio
            for (int i = 0; i < ceros; i++) {
                cadena[i] = '0';
            }

            // Finalizar la cadena con el terminador nulo
            cadena[longitud + ceros] = '\0';
            longitud += ceros;  // Actualizar la nueva longitud
        }

        // Copiar la cadena ajustada a una variable auxiliar para mostrarla sin modificarla luego
        for (int i = 0; i < longitud; i++) {
            copia[i] = cadena[i];
        }
        copia[longitud] = '\0';

        // Recorrer la cadena por bloques de n cifras y convertir cada uno a número
        while (indice < longitud) {
            int numero = 0;
            for (int j = 0; j < n; j++) {
                numero = numero * 10 + (cadena[indice + j] - '0');  // Convertir dígito a entero
            }
            suma += numero;     // Acumular la suma
            indice += n;        // Avanzar al siguiente grupo
        }

        // Mostrar el resultado
        cout << "Original: " << copia << ". Suma: " << suma << "." << endl;
    }



    void problema10() {//Convertir numeros a romano
        char romano[100];       // Arreglo para almacenar el número romano ingresado
        int valores[100];       // Arreglo que guardará los valores equivalentes de cada letra romana
        int total = 0;          // Acumulador para el número entero resultante
        int longitud = 0;       // Longitud de la cadena romana

        cout << "Ingrese un numero romano en mayusculas: ";
        cin >> romano;          // Se lee el número romano (sin espacios)

        // Paso 1: Convertir cada letra romana a su valor numérico correspondiente
        while (romano[longitud] != '\0') {
            if (romano[longitud] == 'M') {
                valores[longitud] = 1000;
            } else if (romano[longitud] == 'D') {
                valores[longitud] = 500;
            } else if (romano[longitud] == 'C') {
                valores[longitud] = 100;
            } else if (romano[longitud] == 'L') {
                valores[longitud] = 50;
            } else if (romano[longitud] == 'X') {
                valores[longitud] = 10;
            } else if (romano[longitud] == 'V') {
                valores[longitud] = 5;
            } else if (romano[longitud] == 'I') {
                valores[longitud] = 1;
            } else {
                valores[longitud] = 0;  // En caso de que haya un carácter no válido
            }
            longitud++;  // Avanza al siguiente carácter
        }

        // Paso 2: Aplicar las reglas de los números romanos
        // Si un valor menor está antes de uno mayor, se resta. Si no, se suma.
        for (int i = 0; i < longitud; i++) {
            if (i < longitud - 1 && valores[i] < valores[i + 1]) {
                total -= valores[i];  // Se resta si el siguiente valor es mayor
            } else {
                total += valores[i];  // Si no, se suma
            }
        }

        // Mostrar resultado
        cout << "El numero ingresado fue: " << romano << " Que corresponde a: " << total << "." << endl;
    }


    // Función que simula un sistema de reservas para una sala de cine
    void problema11() {
        const int filas = 15;         // Cantidad de filas en la sala (de la A a la O)
        const int asientos = 20;      // Cantidad de asientos por fila
        char sala[filas][asientos];   // Matriz que representa la sala

        // Inicializa todos los asientos como disponibles, usando el símbolo '-'
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < asientos; j++) {
                sala[i][j] = '-';
            }
        }

        char opcion;  // Variable para almacenar la opción del usuario

        // Menú principal
        do {
            cout << "\nOpciones:\n";
            cout << "1. Ver sala\n";
            cout << "2. Reservar asiento\n";
            cout << "3. Cancelar reserva\n";
            cout << "4. Salir\n";
            cout << "Seleccione una opcion (1-4): ";
            cin >> opcion;

            // Opción 1: Mostrar el estado actual de la sala
            if (opcion == '1') {
                cout << "\n    ";
                for (int j = 0; j < asientos; j++) {
                    if (j + 1 < 10) cout << " " << j + 1;
                    else cout << j + 1;
                    cout << " ";
                }
                cout << "\n";
                for (int i = 0; i < filas; i++) {
                    cout << (char)('A' + i) << " | ";  // Nombre de la fila
                    for (int j = 0; j < asientos; j++) {
                        cout << " " << sala[i][j] << " ";
                    }
                    cout << "\n";
                }

                // Opción 2 y 3: Reservar o cancelar asiento
            } else if (opcion == '2' || opcion == '3') {
                char letra;
                int numero;
                cout << "Ingrese fila (A-O): ";
                cin >> letra;
                letra = toupper(letra);  // Convertir a mayúscula si fue en minúscula
                cout << "Ingrese asiento (1-20): ";
                cin >> numero;

                int fila = letra - 'A';      // Convertir letra a índice
                int asiento = numero - 1;    // Convertir a índice de 0 a 19

                // Validar que la fila y el asiento estén dentro del rango permitido
                if (fila >= 0 && fila < filas && asiento >= 0 && asiento < asientos) {
                    if (opcion == '2') {
                        // Reservar asiento si está disponible
                        if (sala[fila][asiento] == '-') {
                            sala[fila][asiento] = '+';
                            cout << "Reserva realizada.\n";
                        } else {
                            cout << "El asiento ya esta reservado.\n";
                        }
                    } else {
                        // Cancelar reserva si el asiento está ocupado
                        if (sala[fila][asiento] == '+') {
                            sala[fila][asiento] = '-';
                            cout << "Reserva cancelada.\n";
                        } else {
                            cout << "El asiento ya estaba disponible.\n";
                        }
                    }
                } else {
                    cout << "Fila o asiento fuera de rango.\n";
                }

                // Validar opción incorrecta
            } else if (opcion != '4') {
                cout << "Opcion no valida.\n";
            }

        } while (opcion != '4');  // Repetir hasta que el usuario elija salir
    }


    // Esta función verifica si una matriz 3x3 ingresada por el usuario
    // forma un cuadrado mágico, es decir, que la suma de todas sus filas,
    // columnas y diagonales sea la misma.
void problema12() {
        const int tam = 3;                 // Tamaño de la matriz (3x3)
        int matriz[tam][tam];              // Declaración de la matriz 3x3

        // Solicitar al usuario los 9 números para llenar la matriz
        cout << "Ingrese los 9 numeros de la matriz 3x3:\n";
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                cin >> matriz[i][j];       // Leer cada elemento de la matriz
            }
        }

        // Mostrar la matriz ingresada
        cout << "\nMatriz ingresada:\n";
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

        // Calcular la suma de la primera fila como suma de referencia
        int sumaMagica = matriz[0][0] + matriz[0][1] + matriz[0][2];

        // Verificar que todas las filas tengan la misma suma
        for (int i = 0; i < tam; i++) {
            int sumaFila = 0;
            for (int j = 0; j < tam; j++) {
                sumaFila += matriz[i][j];
            }
            if (sumaFila != sumaMagica) {          // Si una fila no coincide, no es mágico
                cout << "No es un cuadrado magico.\n";
                return;
            }
        }

        // Verificar que todas las columnas tengan la misma suma
        for (int j = 0; j < tam; j++) {
            int sumaCol = 0;
            for (int i = 0; i < tam; i++) {
                sumaCol += matriz[i][j];
            }
            if (sumaCol != sumaMagica) {           // Si una columna no coincide, no es mágico
                cout << "No es un cuadrado magico.\n";
                return;
            }
        }

        // Verificar suma de la diagonal principal
        int diag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
        // Verificar suma de la diagonal secundaria
        int diag2 = matriz[0][2] + matriz[1][1] + matriz[2][0];

        // Si alguna de las diagonales no coincide con la suma mágica
        if (diag1 != sumaMagica || diag2 != sumaMagica) {
            cout << "No es un cuadrado magico.\n";
            return;
        }

        // Si todas las sumas coinciden, es un cuadrado mágico
        cout << "¡Es un cuadrado magico!\n";
    }

void problema14() {//Recibe una matriz 5x5 y muestra los resultados al rotarla 90,180 y 270 grados
    const int tamaño = 5;
    int matriz[tamaño][tamaño];
    int numeros[25];

    // Llenar el arreglo con números del 1 al 25
    for (int i = 0; i < 25; i++) {
        numeros[i] = i + 1;
    }

    // Mezclar los números aleatoriamente
    srand(time(0));
    for (int i = 0; i < 25; i++) {
        int j = rand() % 25;
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    // Llenar la matriz con los números aleatorios sin repetir
    int pos = 0;
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            matriz[i][j] = numeros[pos++];
        }
    }

    // Imprimir matriz original
    cout << "Matriz original:\n";
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    // Rotar 90 grados
    cout << "\nMatriz rotada 90 grados:\n";
    for (int j = 0; j < tamaño; j++) {
        for (int i = tamaño - 1; i >= 0; i--) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    // Rotar 180 grados
    cout << "\nMatriz rotada 180 grados:\n";
    for (int i = tamaño - 1; i >= 0; i--) {
        for (int j = tamaño - 1; j >= 0; j--) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    // Rotar 270 grados
    cout << "\nMatriz rotada 270 grados:\n";
    for (int j = tamaño - 1; j >= 0; j--) {
        for (int i = 0; i < tamaño; i++) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
}

void problema15(){ //Encontrar la interseccion entre 2 rectangulos
    // Rectángulo A: {x, y, ancho, alto}
    int A[4] = {0, 8, 4, 4};

    // Rectángulo B: {x, y, ancho, alto}
    int B[4] = {5, 6, 2, 7};

    // Rectángulo C donde se guardará la intersección
    int C[4];

    // --- Cálculo de coordenadas de extremos de A ---
    int ax1 = A[0];              // x1 de A (esquina superior izquierda)
    int ay1 = A[1];              // y1 de A
    int ax2 = ax1 + A[2];        // x2 de A (esquina inferior derecha en x)
    int ay2 = ay1 - A[3];        // y2 de A (esquina inferior en y)

    // --- Cálculo de coordenadas de extremos de B ---
    int bx1 = B[0];              // x1 de B
    int by1 = B[1];              // y1 de B
    int bx2 = bx1 + B[2];        // x2 de B
    int by2 = by1 - B[3];        // y2 de B

    // --- Cálculo del área de intersección ---
    int cx1 = max(ax1, bx1);     // x superior izquierda de la intersección
    int cy1 = min(ay1, by1);     // y superior izquierda de la intersección
    int cx2 = min(ax2, bx2);     // x inferior derecha de la intersección
    int cy2 = max(ay2, by2);     // y inferior derecha de la intersección

    // Si hay intersección válida (ancho y alto positivos)
    if (cx1 < cx2 && cy2 < cy1) {
        C[0] = cx1;              // x de la intersección
        C[1] = cy1;              // y de la intersección
        C[2] = cx2 - cx1;        // ancho de la intersección
        C[3] = cy1 - cy2;        // alto de la intersección
    } else {
        // No hay intersección: rectángulo vacío
        C[0] = C[1] = C[2] = C[3] = 0;
    }

    // --- Mostrar el resultado ---
    cout << "Rectángulo intersección: [";
    for (int i = 0; i < 4; i++) {
        cout << C[i];           // Imprimir cada valor del arreglo C
        if (i < 3) cout << ", ";
    }
    cout << "]" << endl;


}

void problema16(){//Encontrar camino para llegar desde la esquian sup izq. a esquina inf. der
    //Formula (2n)! / (n!)(n!)
    int n;

    cout << "Ingrese el tamaño de la malla (n): ";
    cin >> n;

    // Variables para almacenar factoriales
    long long factorial_2n = 1;  // (2n)!
    long long factorial_n = 1;   // n!

    // Calcular (2n)!
    for(int i = 2*n; i >= 1; i--){
        factorial_2n *=i;
    }

    // Calcular n!
    for (int i = n; i >= 1; i--) {
        factorial_n *= i;
    }

    long long caminos = factorial_2n / (factorial_n * factorial_n);

    cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
}

void problema17(){//Encontrar numeros amigables
    int numUser;
    int sumaDivA = 0; //Almacena la suma de los divisores de numUser
    int b = 0;
    int sumaDivB = 0; //Almacena la suma de los divisores de b

    cout << "Ingrese un numero: ";
    cin >> numUser;

    for(int i = 1; i < numUser; i++){ //Encontrar divisores de numUser
        if(numUser%i == 0){
            sumaDivA += i;
        }

    }

    b = sumaDivA;

    for(int j = 1; j < b; j++) //Encontrar divisores de la sumaDivA
        if(b % j == 0){
            sumaDivB += j;
        }

    if(sumaDivB == numUser){ //Si son iguales entonces son compatibles
        cout << numUser << " y " << b << " son compatibles." << endl << "La suma de ellos da: " << (sumaDivA + numUser);
    }else{
        cout << "No son compatibles.";
    }

}

void problema18(){//Encontrar permutaciones lexicograficas
    long long numero; // El número de la permutación deseada
    cout << "Introduce el número de permutación: ";
    cin >> numero;

    int digitos[10];      // Arreglo para los dígitos 0-9
    bool usado[10];       // Arreglo para marcar si un dígito ya fue usado

    // Inicializar los dígitos y marcar todos como disponibles
    for (int i = 0; i < 10; i++) {
        digitos[i] = i;
        usado[i] = false;
    }

    numero--; // Ajustamos porque empezamos contando desde 0

    // Calculamos 9! que es el número de permutaciones por dígito
    long long factorial = 1;
    for (int i = 9; i >= 1; i--) {
        factorial *= i;
    }

    cout << "La permutación número " << (numero + 1) << " es: ";

    // Elegimos cada dígito de la permutación uno por uno
    for (int posiciones_restantes = 9; posiciones_restantes >= 0; posiciones_restantes--) {
        int indice = numero / factorial; // Calculamos en qué bloque estamos
        numero = numero % factorial;     // Actualizamos el número para la siguiente posición

        // Actualizamos el factorial para el siguiente paso
        if (posiciones_restantes != 0) {
            factorial = factorial / posiciones_restantes;
        }

        // Ahora buscamos el índice-ésimo número disponible
        int contador = -1;
        for (int j = 0; j < 10; j++) {
            if (!usado[j]) { // Si el dígito j no ha sido usado
                contador++;
            }
            if (contador == indice) { // Cuando llegamos al dígito correcto
                cout << j;             // Lo imprimimos
                usado[j] = true;       // Lo marcamos como usado
                break;                 // Salimos del ciclo
            }
        }
    }

    cout << endl;
}
