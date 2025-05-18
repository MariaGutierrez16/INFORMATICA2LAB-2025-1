#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <random>
#include <ctime>

const int INF = std::numeric_limits<int>::max();

/*----------------------------------------------------------------------*
 |  Clase Router                                                        |
 *----------------------------------------------------------------------*/
class Router
{
public:
    explicit Router(const std::string& nombre_) : nombre(nombre_) {}
    ~Router() = default;                       // nada que liberar internamente

    /* Vecinos directos y sus costos */
    std::map<std::string,int> vecinos;

    /* Tabla de enrutamiento: destino → (costo, siguiente salto)        */
    struct EntradaTabla { int costo; std::string siguiente; };
    std::map<std::string,EntradaTabla> tabla;

    const std::string& obtenerNombre() const { return nombre; }

    /* Actualiza/añade un vecino */
    void actualizarVecino(const std::string& destino, int costo)
    {
        vecinos[destino] = costo;
    }

    /* Elimina un vecino */
    void eliminarVecino(const std::string& destino)
    {
        vecinos.erase(destino);
    }

private:
    std::string nombre;
};

