#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Prim.h"
#include "Lectura.h"

using namespace std;

class Grafo {

private:
    int ** matriz_adyacencia;
    Lista<Lectura*>* vertices;
    Prim * algoritmo_arbol_expansion;


    //PRE: -
    //POST: Agranda dinamicamente la matriz de adyacencia.
    void agrandar_matriz_adyacencia();

    //PRE: La matriz que se le pasa ya debe tener memoria reservada.
    //POST: Copia la matriz de adyacencia en la nueva matriz.
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //PRE: -
    //POST: Inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito.
    void inicializar_vertice(int** nueva_adyacente);

    //PRE: -
    //POST: Libera la memoria de la matriz de adyacencia.
    void liberar_matriz_adyacencia();

    //PRE: -
    //POST: Imprime por pantalla los vertices del grafo.
    void mostrar_vertices();

    //PRE: -
    //POST: Imprime por pantalla la matriz de adyacencia.
    void mostrar_matriz_adyacencia();

public:

    //PRE: -
    //POST: Construye un objeto de tipo Grafo.
    Grafo();

    //PRE: -
    //POST: Agrega un nuevo vertice al grafo.
    void agregar_vertice(Lectura* nuevo_vertice);

    //PRE: El peso es un valor positivo.
    //POST: Ajusta la matriz de adyacencia con el peso ingresado.
    void agregar_camino(Lectura* origen, Lectura* destino, int peso);

    //PRE: -
    //POST: Imprime por pantalla el grafo.
    void mostrar_grafo();

    //PRE: -
    //POST: Crea el arbol de expansión mínimo, imprime los caminos y el tiempo minimo de lectura.
    void arbol_expansion();

    //PRE: Grafo debe ser un objeto válido.
    //POST: Destruye un objeto de tipo Grafo.
    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
