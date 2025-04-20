#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>

// Funcion para encriptar la clave con SHA-256
QString encriptarClave(const QString &clave) {
    QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

// Crea la clave por defecto del administrador si no existe
void crearClaveAdminSiNoExiste() {
    QFile archivo("sudo.txt");
    if (!archivo.exists()) {
        QString claveAdmin = "$admin123*";
        QString hash = encriptarClave(claveAdmin);

        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&archivo);
            out << hash;
            archivo.close();
            qDebug() << "Archivo sudo.txt creado con la clave encriptada.";
        }
    }
}

// Verifica si la clave ingresada coincide con la clave guardada
bool validarClaveAdmin(const QString &claveIngresada) {
    QFile archivo("sudo.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir sudo.txt";
        return false;
    }

    QString claveGuardada = QString::fromUtf8(archivo.readAll()).trimmed();
    QString claveIngresadaHash = encriptarClave(claveIngresada);

    return claveGuardada == claveIngresadaHash;
}

// Registra un nuevo usuario con cedula, clave y saldo
void registrarUsuario() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Ingrese la cedula del usuario: ";
    cout.flush();
    QString cedula = cin.readLine().trimmed();

    cout << "Ingrese la clave del usuario: ";
    cout.flush();
    QString clave = cin.readLine().trimmed();

    cout << "Ingrese el saldo inicial (COP): ";
    cout.flush();
    QString saldo = cin.readLine().trimmed();

    QString claveEncriptada = encriptarClave(clave);

    QFile archivo("usuarios.txt");
    if (archivo.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&archivo);
        out << cedula << "|" << claveEncriptada << "|" << saldo << "\n";
        archivo.close();
        cout << "[OK] Usuario registrado correctamente.\n";
    } else {
        cout << "[ERROR] No se pudo abrir usuarios.txt para escribir.\n";
    }
}

// Menu que aparece al ingresar como administrador
void menuAdministrador() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    QString opcion;
    while (true) {
        cout << "\n--- Menu Administrador ---\n";
        cout << "1. Registrar usuario\n";
        cout << "2. Volver al menu principal\n";
        cout << "Opcion: ";
        cout.flush();

        opcion = cin.readLine().trimmed();

        if (opcion == "1") {
            registrarUsuario();
        } else if (opcion == "2") {
            break;
        } else {
            cout << "[ERROR] Opcion invalida. Intente de nuevo.\n";
        }
    }
}

// Menu principal del sistema
void menuPrincipal() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    QString opcion;

    while (true) {
        cout << "\n=== Bienvenido al sistema de cajero electronico ===\n";
        cout << "Seleccione una opcion:\n";
        cout << "1. Ingresar como administrador\n";
        cout << "2. Ingresar como usuario (sin implementar)\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cout.flush();

        opcion = cin.readLine().trimmed();

        if (opcion == "1") {
            cout << "Ingrese la clave del administrador: ";
            cout.flush();
            QString clave = cin.readLine();

            if (validarClaveAdmin(clave)) {
                cout << "[OK] Acceso concedido como administrador.\n";
                menuAdministrador();
            } else {
                cout << "[ERROR] Clave incorrecta. Acceso denegado.\n";
            }

        } else if (opcion == "2") {
            cout << "[INFO] La funcionalidad de usuario aun no esta implementada.\n";
        } else if (opcion == "3") {
            cout << "Gracias por usar el sistema. Hasta pronto.\n";
            break;
        } else {
            cout << "[ERROR] Opcion invalida. Intente de nuevo.\n";
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    crearClaveAdminSiNoExiste(); // Crea la clave si no existe
    menuPrincipal();             // Muestra el menu principal
    return 0;
}
