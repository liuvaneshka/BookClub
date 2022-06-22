#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H
#include <string>

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    int nombre;

/*MÉTODOS*/
public:
    Vertice(int nombre);

    //post: obtiene el nombre del vertice
    int obtener_nombre();

    ~Vertice();
};

#endif //GRAFOS_VERTICE_H
