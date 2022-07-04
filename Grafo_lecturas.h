#ifndef __GRAFO_LECTURAS_H__
#define __GRAFO_LECTURAS_H__
#include "Grafo.h"
#include "Lista_lecturas.h"
#include "CONSTANTES.h"

class Grafo_lecturas : public Grafo{

private:
    Grafo* grafo_lecturas;
    Lista_lecturas* lista_lecturas;
    string* vertices;

    //PRE: -
    //POST: Agrega todos los caminos del grafo.
    void actualizar_grafo();

    //PRE: Los vertices son vértices existentes.
    //POST: Agrega una arista entre dos vértices con el peso correspondiente.
    void agregar_arista(int i, int j);

    //PRE: -
    //POST: Inicializa un vector de vértices con cadenas vacías.
    void inicializar_vertices();

    //PRE: tipo_v1 y tipo_v2 deben ser tipos válidos.
    //POST: Devuelve el peso de la arista que une ambos vértices según el tipo de Lectura.
    int calcular_peso(string tipo_v1, string tipo_v2);

    //PRE: tipo_v debe ser un tipo válido.
    //POST: Devuelve el peso de la arista que une dos vértices del mismo tipo, según el tipo del vértice en cuestión.
    int peso_mismo_tipo(string tipo_v);

    //PRE: tipo_v1 y tipo_v2 deben ser tipos válidos.
    //POST: Devuelve el peso de la arista que une dos vértices de distinto tipo, según los itpos de vértices en cuestión.
    int peso_distinto_tipo(string tipo_v1, string tipo_v2);

    //PRE: lectura debe ser un objeto válido.
    //POST: Devuelve el tipo de Lectura del vértice.
    string obtener_tipo(Lectura* lectura);

public:

    //PRE: lista_lecturas debe ser un objeto válido.
    //POST: Construye un objeto de tipo grafo_lecturas.
    Grafo_lecturas(Lista_lecturas* lista_lecturas);

    //PRE: lista_lecturas debe ser un objeto válido.
    //POST: Completa el grafo basándose en la lista de Lecturas.
    void crear_grafo();

    //PRE: grafo_lecturas debe ser un objeto válido.
    //POST: Destruye un objeto del tipo grafo_lecturas.
    ~Grafo_lecturas();

};
#endif // __GRAFO_LECTURAS_H__