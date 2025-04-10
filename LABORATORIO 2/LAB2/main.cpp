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
    problema11();

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


    /*
    b                -> direccion: 0x0A12
    b + 2            -> direccion: 0xA1A
    *(b + 2)         -> = 28  Apunta a b[2][0]
    *(b + 2) + 1     -> = 39
    *(*(b + 2) + 1)  -> = 39
    b[3][1]          -> = 3
    *b++             -> = 77
    */


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


/*  Ejercicio 4

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

Ejercicio 5

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
String msgUser = "";

void setup()
{
  lcd.begin(16,2); //Inicia el sistema con 16 columnas y 2 filas
  Serial.begin(9600);
  lcd.print("Hola soy Arduino, escribe un msg");
}

void loop()
{


  if (Serial.available()) {
    msgUser = Serial.readStringUntil('\n');  // Leer hasta ENTER

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msgUser);
    lcd.setCursor(0, 1);

    lcd.print("");

    Serial.println("Mensaje exitoso en LCD.");
  }

  lcd.scrollDisplayLeft();
  delay(300);

}


 */

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
    void problema7() {
        char original[100];
        char sinRepetidos[100];
        int i = 0, j = 0, k;
        bool repetido;

        cout << "Ingrese una cadena: ";
        cin >> original;

        while (original[i] != '\0') {
            repetido = false;

            // Revisar si el carácter ya está en sinRepetidos
            for (k = 0; k < j; k++) {
                if (original[i] == sinRepetidos[k]) {
                    repetido = true;
                    break;
                }
            }

            if (!repetido) {
                sinRepetidos[j] = original[i];
                j++;
            }

            i++;
        }

        sinRepetidos[j] = '\0';  // Fin de cadena

        cout << "Original: " << original << ". Sin repetidos: " << sinRepetidos << "." << endl;
    }
    void problema8() {
        char original[100], texto[100], numero[100];
        int i = 0, j = 0, k = 0;

        cout << "Ingrese una cadena: ";
        cin >> original;

        while (original[i] != '\0') {
            if (original[i] >= '0' && original[i] <= '9') {
                numero[j] = original[i];
                j++;
            } else {
                texto[k] = original[i];
                k++;
            }
            i++;
        }

        numero[j] = '\0';
        texto[k] = '\0';

        cout << "Original: " << original << "." << endl;
        cout << "Texto: " << texto << ". Numero: " << numero << "." << endl;
    }

    void problema9() {
        int n, indice = 0, suma = 0, longitud = 0;
        char cadena[100], copia[100];

        cout << "Ingrese la cantidad de cifras por grupo: ";
        cin >> n;

        cout << "Ingrese la cadena numerica: ";
        cin >> cadena;

        // Calcular longitud
        while (cadena[longitud] != '\0') {
            longitud++;
        }

        int sobrante = longitud % n;

        // Agregar ceros si es necesario
        if (sobrante != 0) {
            int ceros = n - sobrante;
            for (int i = longitud - 1; i >= 0; i--) {
                cadena[i + ceros] = cadena[i];
            }
            for (int i = 0; i < ceros; i++) {
                cadena[i] = '0';
            }
            cadena[longitud + ceros] = '\0';
            longitud += ceros;
        }

        // Copiar la cadena modificada a copia
        for (int i = 0; i < longitud; i++) {
            copia[i] = cadena[i];
        }
        copia[longitud] = '\0';

        // Sumar bloques de n cifras
        while (indice < longitud) {
            int numero = 0;
            for (int j = 0; j < n; j++) {
                numero = numero * 10 + (cadena[indice + j] - '0');
            }
            suma += numero;
            indice += n;
        }

        cout << "Original: " << copia << ". Suma: " << suma << "." << endl;
    }
    void problema10() {
        char romano[100];
        int valores[100];
        int total = 0;
        int longitud = 0;

        cout << "Ingrese un numero romano en mayusculas: ";
        cin >> romano;

        // Convertir letras romanas a valores
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
                valores[longitud] = 0; // por si hay un caracter no válido
            }
            longitud++;
        }

        // Aplicar reglas de suma y resta
        for (int i = 0; i < longitud; i++) {
            if (i < longitud - 1 && valores[i] < valores[i + 1]) {
                total -= valores[i];
            } else {
                total += valores[i];
            }
        }

        cout << "El numero ingresado fue: " << romano << " Que corresponde a: " << total << "." << endl;
    }

    void problema11() {
        const int filas = 15;
        const int asientos = 20;
        char sala[filas][asientos];

        // Inicializar todos los asientos como disponibles '-'
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < asientos; j++) {
                sala[i][j] = '-';
            }
        }

        char opcion;
        do {
            cout << "\nOpciones:\n";
            cout << "1. Ver sala\n";
            cout << "2. Reservar asiento\n";
            cout << "3. Cancelar reserva\n";
            cout << "4. Salir\n";
            cout << "Seleccione una opcion (1-4): ";
            cin >> opcion;

            if (opcion == '1') {
                // Mostrar sala
                cout << "\n    ";
                for (int j = 0; j < asientos; j++) {
                    if (j + 1 < 10) cout << " " << j + 1;
                    else cout << j + 1;
                    cout << " ";
                }
                cout << "\n";
                for (int i = 0; i < filas; i++) {
                    cout << (char)('A' + i) << " | ";
                    for (int j = 0; j < asientos; j++) {
                        cout << " " << sala[i][j] << " ";
                    }
                    cout << "\n";
                }
            } else if (opcion == '2' || opcion == '3') {
                char letra;
                int numero;
                cout << "Ingrese fila (A-O): ";
                cin >> letra;
                letra = toupper(letra);
                cout << "Ingrese asiento (1-20): ";
                cin >> numero;

                int fila = letra - 'A';
                int asiento = numero - 1;

                if (fila >= 0 && fila < filas && asiento >= 0 && asiento < asientos) {
                    if (opcion == '2') {
                        if (sala[fila][asiento] == '-') {
                            sala[fila][asiento] = '+';
                            cout << "Reserva realizada.\n";
                        } else {
                            cout << "El asiento ya esta reservado.\n";
                        }
                    } else {
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
            } else if (opcion != '4') {
                cout << "Opcion no valida.\n";
            }

        } while (opcion != '4');
    }

    void problema15(){
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
