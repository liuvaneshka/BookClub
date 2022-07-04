#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Lectura*>;
    algoritmo_arbol_expansion = nullptr;
}

void Grafo::agregar_vertice(Lectura* nuevo_vertice) {
    agrandar_matriz_adyacencia();
    vertices->alta(nuevo_vertice);
}

void Grafo::mostrar_grafo() {
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

void Grafo::agregar_camino(Lectura* origen, Lectura* destino, int peso) {
    int posicion_origen = vertices->obtener_posicion(origen);
    int posicion_destino = vertices->obtener_posicion(destino);

    matriz_adyacencia[posicion_origen][posicion_destino] = peso;
    matriz_adyacencia[posicion_destino][posicion_origen] = peso;
}

void Grafo::agrandar_matriz_adyacencia() {
    int** matriz_aux;
    int nueva_cant_vertices = vertices->obtener_tamanio() + 1;
    matriz_aux = new int*[nueva_cant_vertices];

    for(int i = 0; i < nueva_cant_vertices; i++){
        matriz_aux[i] = new int[nueva_cant_vertices];
    }

    copiar_matriz_adyacente(matriz_aux);
    inicializar_vertice(matriz_aux);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_aux;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_tamanio(); i++){
        for(int j = 0; j < vertices -> obtener_tamanio(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_tamanio(); i++){
        nueva_adyacente[vertices -> obtener_tamanio()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_tamanio()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_tamanio()][vertices -> obtener_tamanio()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_tamanio() ; i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}


void Grafo::arbol_expansion(){
    algoritmo_arbol_expansion = new Prim(matriz_adyacencia, vertices);
    algoritmo_arbol_expansion -> arbol_expansion();
    delete algoritmo_arbol_expansion;
    algoritmo_arbol_expansion = nullptr;
}

Grafo::~Grafo(){
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_arbol_expansion;

}

void Grafo::mostrar_vertices() {
    cout << "Lista de vértices: [";
    for(int i = 1; i <= vertices -> obtener_tamanio(); i++){
        cout << vertices -> consultar(i);
        if(i != vertices -> obtener_tamanio()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtener_tamanio(); i++){
        for(int j = 0; j < vertices -> obtener_tamanio() * 2; j++) {
            if(j == vertices -> obtener_tamanio() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_adyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}
