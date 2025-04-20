#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>

QString encriptarClave(const QString &clave) {
    QByteArray hash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

void crearClaveAdminSiNoExiste() {
    QFile archivo("sudo.txt");
    if (!archivo.exists()) {
        QString claveAdmin = "$admin123*";  // 🔐 NUEVA CLAVE AQUÍ
        QString hash = encriptarClave(claveAdmin);

        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&archivo);
            out << hash;
            archivo.close();
            qDebug() << "Archivo sudo.txt creado con la nueva clave admin encriptada.";
        }
    }
}

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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    crearClaveAdminSiNoExiste(); // Asegura que sudo.txt exista con la nueva clave

    cout << "¿Deseas ingresar como administrador o usuario? (admin/usuario): ";
    cout.flush();
    QString tipo = cin.readLine().trimmed().toLower();

    if (tipo == "admin") {
        cout << "Ingrese la clave del administrador: ";
        cout.flush();
        QString clave = cin.readLine();

        if (validarClaveAdmin(clave)) {
            cout << "✅ Acceso concedido como administrador." << Qt::endl;
            // Próximo paso: registrar usuarios
        } else {
            cout << "❌ Clave incorrecta. Acceso denegado." << Qt::endl;
        }
    } else if (tipo == "usuario") {
        cout << "🔐 Módulo de acceso para usuarios aún no implementado." << Qt::endl;
    } else {
        cout << "⚠️ Opción no válida." << Qt::endl;
    }

    return 0;
}
