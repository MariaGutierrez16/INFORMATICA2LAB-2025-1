#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>
#include <QStringList>

// Funcion para encriptar una clave con SHA-256
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
        }
    }
}

// Verifica si la clave ingresada coincide con la guardada
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

// Permite registrar un nuevo usuario
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

// Menu de administrador con opcion para registrar usuarios
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

// Menu para usuarios (consultar saldo, retirar)
void menuUsuario(const QString &cedula) {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    while (true) {
        QFile archivo("usuarios.txt");
        if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            cout << "[ERROR] No se pudo abrir usuarios.txt\n";
            return;
        }

        QStringList lineas;
        QString lineaUsuario;
        while (!archivo.atEnd()) {
            QString linea = archivo.readLine().trimmed();
            if (linea.startsWith(cedula + "|")) {
                lineaUsuario = linea;
            }
            lineas.append(linea);
        }
        archivo.close();

        if (lineaUsuario.isEmpty()) {
            cout << "[ERROR] Usuario no encontrado.\n";
            return;
        }

        QStringList partes = lineaUsuario.split("|");
        QString claveHash = partes[1];
        double saldo = partes[2].toDouble();

        cout << "\n--- Menu Usuario ---\n";
        cout << "1. Consultar saldo (costo 1000 COP)\n";
        cout << "2. Retirar dinero (costo adicional 1000 COP)\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cout.flush();
        QString opcion = cin.readLine().trimmed();

        if (opcion == "1") {
            if (saldo >= 1000) {
                saldo -= 1000;
                cout << "Saldo actual: " << saldo << " COP\n";
            } else {
                cout << "[ERROR] Saldo insuficiente para consultar.\n";
            }
        } else if (opcion == "2") {
            cout << "Ingrese monto a retirar: ";
            cout.flush();
            double monto = cin.readLine().toDouble();

            double total = monto + 1000;
            if (saldo >= total) {
                saldo -= total;
                cout << "Retiro exitoso. Saldo restante: " << saldo << " COP\n";
            } else {
                cout << "[ERROR] Saldo insuficiente para retirar.\n";
            }
        } else if (opcion == "3") {
            break;
        } else {
            cout << "[ERROR] Opcion invalida.\n";
            continue;
        }

        // Actualizar archivo con nuevo saldo
        for (int i = 0; i < lineas.size(); ++i) {
            if (lineas[i].startsWith(cedula + "|")) {
                lineas[i] = cedula + "|" + claveHash + "|" + QString::number(saldo);
                break;
            }
        }

        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream out(&archivo);
            for (const QString &linea : lineas) {
                out << linea << "\n";
            }
            archivo.close();
        }
    }
}

// Validar usuario con cedula y clave
void accesoUsuario() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Ingrese su cedula: ";
    cout.flush();
    QString cedula = cin.readLine().trimmed();

    cout << "Ingrese su clave: ";
    cout.flush();
    QString clave = cin.readLine().trimmed();
    QString claveHash = encriptarClave(clave);

    QFile archivo("usuarios.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "[ERROR] No se pudo abrir usuarios.txt\n";
        return;
    }

    bool encontrado = false;
    while (!archivo.atEnd()) {
        QString linea = archivo.readLine().trimmed();
        QStringList partes = linea.split("|");
        if (partes.size() == 3 && partes[0] == cedula && partes[1] == claveHash) {
            encontrado = true;
            break;
        }
    }
    archivo.close();

    if (encontrado) {
        cout << "[OK] Acceso concedido.\n";
        menuUsuario(cedula);
    } else {
        cout << "[ERROR] Cedula o clave incorrecta.\n";
    }
}

// Menu principal
void menuPrincipal() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    QString opcion;

    while (true) {
        cout << "\n=== Bienvenido al sistema de cajero electronico ===\n";
        cout << "Seleccione una opcion:\n";
        cout << "1. Ingresar como administrador\n";
        cout << "2. Ingresar como usuario\n";
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
            accesoUsuario();
        } else if (opcion == "3") {
            cout << "Gracias por usar el sistema. Hasta pronto.\n";
            break;
        } else {
            cout << "[ERROR] Opcion invalida. Intente de nuevo.\n";
        }
    }
}

// Funcion principal
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    crearClaveAdminSiNoExiste();
    menuPrincipal();
    return 0;
}
