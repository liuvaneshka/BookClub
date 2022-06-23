#ifndef __GRAFO_LECTURAS_H__
#define __GRAFO_LECTURAS_H__
#include "Grafo.h"
#include "CONSTANTES.h"

class Grafo_lecturas : public Grafo{

private:
    Grafo* grafo_lecturas;
    Lista<Lectura*>* lista_lecturas;
    string* vertices;

    //PRE:
    //POST:
    void actualizar_grafo();

    //PRE:
    //POST:
    void agregar_arista(int v1, int v2);

    //PRE:
    //POST:
    void inicializar_vertices();

    //PRE:
    //POST:
    int calcular_peso(string tipo_v1, string tipo_v2);

    //PRE:
    //POST:
    int peso_mismo_tipo(string tipo_v);

    //PRE:
    //POST:
    int peso_distinto_tipo(string tipo_v1, string tipo_v2);

    //PRE:
    //POST:
    string obtener_tipo(Lectura* lectura_actual);

public:

    //PRE:
    //POST:
    Grafo_lecturas(Lista<Lectura*>* lista_lecturas);

    //PRE:
    //POST:
    void crear_grafo();

    //PRE:
    //POST:
    ~Grafo_lecturas();

};
#endif // __GRAFO_LECTURAS_H__