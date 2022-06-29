#ifndef TP3_PRIM_H
#define TP3_PRIM_H
#include <iostream>
#include "Lista.h"
#include "Lectura.h"

class Prim{

private:
    // Atributos para el algoritmo
    int** matriz_arbol;
    bool* vertices_visitados;

    // Atributos provenientes el grafo necesarios para crear el árbol
    Lista<Lectura*>* vertices;
    int cant_vertices;

    // Resultado del arbol de expansión mínima
    int tiempo_vertices;
    int tiempo_aristas;


    //PRE: -
    //POST: Rellena la primera posicion con True y el resto con False.
    void inicializar_visitados();

    //PRE: -
    //POST: Crea una matriz vacía.
    void crear_matriz_arbol();

    //PRE: -
    //POST: Recoprre la matriz y almacena INFINITO en todas las posiciones.
    void inicializar_matriz_arbol();

    //PRE: matriz_adyacencia debe ser una matriz válida (matriz del grafo).
    //POST: Ejecuta el algoritmo de Prim, resultando en la matriz del arbol de expansión mínima del grafo.
    void hallar_arbol(int** matriz_adyacencia);

    //PRE: tiempo >= 0.
    //POST: Va aumentando el tiempo entre lecturas total en base a las aristas del arbol de expansion mínimo.
    void actualizar_tiempo_aristas(int tiempo);

    //PRE: -
    //PRE: Determina el tiempo total de lectura de todas las lecturas del grafo.
    void calcular_tiempo_vertices();

    //PRE: -
    //POST: Libera la memoria de la matriz del arbol.
    void liberar_matriz_arbol();

public:

    //PRE:
    //POST: Construye un objeto de tipo Prim.
    Prim(int ** matriz_adyacencia, Lista<Lectura*> * vertices);

    //PRE: -
    //POST: Imprime por pantalla los caminos y el tiempo total mínimo de lectura (tiempo de cada lectura y el tiempo entre lecturas).
    void arbol_expansion();

    //PRE: -
    //POST: Destruye un objeto de tipo Prim.
    ~Prim();

};

#endif //TP3_PRIM_H
