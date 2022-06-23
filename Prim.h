#ifndef TP3_PRIM_H
#define TP3_PRIM_H
#include <iostream>
#include "Lista.h"
#include "Lectura.h"

class Prim{

private:
    // Atributos para el algoritmo propiamente dicho
    int** matriz_arbol;
    bool* vertices_visitados;

    // Atributos provenientes el grafo
    Lista<Lectura*>* vertices;
    int cant_vertices;

    // Resultado del arbol de expansión mínima
    int tiempo_vertices;
    int tiempo_aristas;


    //PRE:
    //POST: Rellena la primera posicion con True y el resto con False.
    void inicializar_visitados();

    //PRE:
    //POST:
    void crear_matriz_arbol();

    //PRE: La matriz_adyacencia debe ser una matriz válida.
    //POST: Copia la matriz dada y pasa a ser el atributo matriz_arbol
    void inicializar_matriz_arbol();

    //PRE:
    //POST: Modifica la matriz, resultando en la matriz del arbol de expansión mínimo del grafo.
    void hallar_arbol(int** matriz_adyacencia);

    //PRE: tiempo >= 0.
    //POST: Va aumentando el tiempo entre lecturas total en base a las aristas del arbol de expansion mínimo.
    void actualizar_tiempo_aristas(int tiempo);

    //PRE:
    //PRE: Determina el tiempo total de lectura de todas las lecturas del grafo.
    void actualizar_tiempo_vertices();

    //PRE:
    //POST: Libera la memoria de la matriz del arbol.
    void liberar_matriz_arbol();

public:

    //PRE:
    //POST:
    Prim(int ** matriz_adyacencia, Lista<Lectura*> * vertices);

    //PRE:
    //POST: Imprime por pantalla el tiempo total mínimo de lectura (tiempo de cada lectur ay el tiempo entre lecturas)
    void arbol_expansion();

    //PRE:
    //POST:
    ~Prim();

};


#endif //TP3_PRIM_H