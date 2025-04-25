#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

// ------------------------- FUNCIONES COMUNES -------------------------

// Cuenta 0s y 1s en un bloque
void contarBits(const char* bloque, int n, int& ceros, int& unos) {
    ceros = unos = 0;
    for (int i = 0; i < n; ++i) {
        if (bloque[i] == '0') ++ceros;
        else if (bloque[i] == '1') ++unos;
    }
}

// Invierte todos los bits de un bloque
void invertirTodos(char* bloque, int n) {
    for (int i = 0; i < n; ++i)
        bloque[i] = (bloque[i] == '0') ? '1' : '0';
}

// Invierte cada x bits dentro del bloque
void invertirCadaXBits(char* bloque, int n, int x) {
    for (int i = 0; i < n; i += x) {
        for (int j = 0; j < x && (i + j) < n; ++j) {
            bloque[i + j] = (bloque[i + j] == '0') ? '1' : '0';
        }
    }
}

// ------------------------- FUNCIONES DE CODIFICACIÓN -------------------------

// Convierte texto a cadena de bits '0' y '1'
void convertirABinario(const char* texto, int longitud, char*& binario, int& longitudBinario) {
    longitudBinario = longitud * 8;
    binario = new char[longitudBinario + 1];
    int k = 0;

    for (int i = 0; i < longitud; ++i) {
        unsigned char c = texto[i];
        for (int j = 7; j >= 0; --j) {
            binario[k++] = ((c >> j) & 1) ? '1' : '0';
        }
    }

    binario[longitudBinario] = '\0';
}

// Codifica el binario según el método 1
char* codificarMetodo1(const char* binario, int longitudBinario, int n) {
    int bloques = (longitudBinario + n - 1) / n;
    char* codificado = new char[longitudBinario + 1];
    char* anterior = new char[n];

    for (int j = 0; j < n; ++j)
        anterior[j] = '0';

    for (int i = 0; i < bloques; ++i) {
        int inicio = i * n;
        int tamBloque = (inicio + n <= longitudBinario) ? n : longitudBinario - inicio;

        char* bloque = new char[tamBloque + 1];
        for (int j = 0; j < tamBloque; ++j)
            bloque[j] = binario[inicio + j];
        bloque[tamBloque] = '\0';

        if (i == 0) {
            invertirTodos(bloque, tamBloque);
        } else {
            int ceros, unos;
            contarBits(anterior, tamBloque, ceros, unos);
            if (ceros == unos)
                invertirTodos(bloque, tamBloque);
            else if (ceros > unos)
                invertirCadaXBits(bloque, tamBloque, 2);
            else
                invertirCadaXBits(bloque, tamBloque, 3);
        }

        for (int j = 0; j < tamBloque; ++j)
            codificado[inicio + j] = bloque[j];

        for (int j = 0; j < tamBloque; ++j)
            anterior[j] = binario[inicio + j];

        delete[] bloque;
    }

    codificado[longitudBinario] = '\0';
    delete[] anterior;
    return codificado;
}

// Guarda los bits codificados en un archivo binario real
void guardarComoArchivoBinario(const char* bits, int longitudBits, const string& nombreSalida) {
    ofstream salida(nombreSalida, ios::binary);
    if (!salida) {
        cerr << "No se pudo crear el archivo de salida.\n";
        return;
    }

    int bitsFaltantes = (8 - (longitudBits % 8)) % 8;
    char* bitsCompletos = new char[longitudBits + bitsFaltantes + 1];
    strcpy(bitsCompletos, bits);
    for (int i = 0; i < bitsFaltantes; ++i) {
        bitsCompletos[longitudBits + i] = '0';
    }
    bitsCompletos[longitudBits + bitsFaltantes] = '\0';

    for (int i = 0; i < longitudBits + bitsFaltantes; i += 8) {
        unsigned char byte = 0;
        for (int j = 0; j < 8; ++j) {
            if (bitsCompletos[i + j] == '1') {
                byte |= (1 << (7 - j));
            }
        }
        salida.write(reinterpret_cast<char*>(&byte), 1);
    }

    salida.close();
    cout << "Archivo binario '" << nombreSalida << "' guardado correctamente.\n";
    delete[] bitsCompletos;
}

// ------------------------- FUNCIONES DE DECODIFICACIÓN -------------------------

// Convierte una cadena de bits '0' y '1' a texto
void convertirATexto(const char* binario, int longitudBinario, char*& texto, int& longitudTexto) {
    longitudTexto = longitudBinario / 8;
    texto = new char[longitudTexto + 1];
    int k = 0;

    for (int i = 0; i < longitudBinario; i += 8) {
        unsigned char c = 0;
        for (int j = 0; j < 8 && (i + j) < longitudBinario; ++j) {
            if (binario[i + j] == '1') {
                c |= (1 << (7 - j));
            }
        }
        texto[k++] = c;
    }

    texto[longitudTexto] = '\0';
}

// Decodifica el binario según el método 1 inverso
char* decodificarMetodo1(const char* codificado, int longitudCodificado, int n) {
    int bloques = (longitudCodificado + n - 1) / n;
    char* decodificado = new char[longitudCodificado + 1];
    char* anterior = new char[n];

    for (int j = 0; j < n; ++j)
        anterior[j] = '0';

    for (int i = 0; i < bloques; ++i) {
        int inicio = i * n;
        int tamBloque = (inicio + n <= longitudCodificado) ? n : longitudCodificado - inicio;

        char* bloque = new char[tamBloque + 1];
        for (int j = 0; j < tamBloque; ++j)
            bloque[j] = codificado[inicio + j];
        bloque[tamBloque] = '\0';

        char* bloqueOriginal = new char[tamBloque + 1];
        strcpy(bloqueOriginal, bloque);

        if (i == 0) {
            invertirTodos(bloque, tamBloque);
        } else {
            int ceros, unos;
            contarBits(anterior, tamBloque, ceros, unos);
            if (ceros == unos)
                invertirTodos(bloque, tamBloque);
            else if (ceros > unos)
                invertirCadaXBits(bloque, tamBloque, 2);
            else
                invertirCadaXBits(bloque, tamBloque, 3);
        }

        for (int j = 0; j < tamBloque; ++j)
            decodificado[inicio + j] = bloque[j];

        for (int j = 0; j < tamBloque; ++j)
            anterior[j] = bloqueOriginal[j];

        delete[] bloque;
        delete[] bloqueOriginal;
    }

    decodificado[longitudCodificado] = '\0';
    delete[] anterior;
    return decodificado;
}

// Lee un archivo binario y lo convierte a cadena de bits
void leerArchivoBinario(const string& nombreArchivo, char*& bits, int& longitudBits) {
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo binario.\n";
        return;
    }

    streamsize tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    vector<unsigned char> buffer(tamano);
    archivo.read(reinterpret_cast<char*>(buffer.data()), tamano);
    archivo.close();

    longitudBits = tamano * 8;
    bits = new char[longitudBits + 1];
    int k = 0;

    for (unsigned char byte : buffer) {
        for (int j = 7; j >= 0; --j) {
            bits[k++] = ((byte >> j) & 1) ? '1' : '0';
        }
    }
    bits[longitudBits] = '\0';
}

// Guarda el texto decodificado en un archivo
void guardarTextoDecodificado(const char* texto, const string& nombreSalida) {
    ofstream salida(nombreSalida);
    if (!salida) {
        cerr << "No se pudo crear el archivo de salida.\n";
        return;
    }

    salida << texto;
    salida.close();
    cout << "Archivo de texto guardado correctamente como: " << nombreSalida << endl;
}

// ------------------------- FUNCIONES PRINCIPALES -------------------------

void codificarArchivo() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto a codificar: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo, ios::in | ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo.\n";
        return;
    }

    archivo.seekg(0, ios::end);
    int longitud = archivo.tellg();
    archivo.seekg(0, ios::beg);

    char* contenido = new char[longitud + 1];
    archivo.read(contenido, longitud);
    contenido[longitud] = '\0';
    archivo.close();

    char* binario;
    int longitudBinario;
    convertirABinario(contenido, longitud, binario, longitudBinario);

    int n;
    cout << "Ingrese la semilla n para bloques: ";
    cin >> n;

    char* codificado = codificarMetodo1(binario, longitudBinario, n);

    string nombreSalida = nombreArchivo.substr(0, nombreArchivo.find_last_of('.')) + ".bin";
    guardarComoArchivoBinario(codificado, longitudBinario, nombreSalida);

    delete[] contenido;
    delete[] binario;
    delete[] codificado;
}

void decodificarArchivo() {
    string nombreArchivoBinario;
    cout << "Ingrese el nombre del archivo binario a decodificar: ";
    cin >> nombreArchivoBinario;

    ifstream test(nombreArchivoBinario, ios::binary);
    if (!test) {
        cerr << "No se pudo encontrar el archivo binario.\n";
        return;
    }
    test.close();

    int n;
    cout << "Ingrese la semilla n usada para codificar: ";
    cin >> n;

    char* bitsCodificados;
    int longitudBits;
    leerArchivoBinario(nombreArchivoBinario, bitsCodificados, longitudBits);

    char* bitsDecodificados = decodificarMetodo1(bitsCodificados, longitudBits, n);

    char* textoDecodificado;
    int longitudTexto;
    convertirATexto(bitsDecodificados, longitudBits, textoDecodificado, longitudTexto);

    string nombreSalida = nombreArchivoBinario.substr(0, nombreArchivoBinario.find_last_of('.')) + "_decodificado.txt";
    guardarTextoDecodificado(textoDecodificado, nombreSalida);

    delete[] bitsCodificados;
    delete[] bitsDecodificados;
    delete[] textoDecodificado;
}

int main() {
    int opcion;
    do {
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Codificar archivo de texto a binario\n";
        cout << "2. Decodificar archivo binario a texto\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            codificarArchivo();
            break;
        case 2:
            decodificarArchivo();
            break;
        case 3:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while(opcion != 3);

    return 0;
}
