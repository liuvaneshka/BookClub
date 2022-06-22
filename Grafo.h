#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Prim.h"
#include "Vertice.h"

using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Prim * algoritmo_arbol_expansion;

/*MÉTODOS*/

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_adyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();

public:

    Grafo();

    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregar_vertice(int nuevo_vertice);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(int origen, int destino, int peso);

    //post: imprime por pantalla el grafo
    void mostrar_grafo();

    //post: crea el arbol de expansión mínimo e imprime el tiempo minimo de lectura.
    void arbol_expansion();

    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
