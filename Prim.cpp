#include "Prim.h"

Prim::Prim(int ** matriz_adyacencia, Lista<Vertice> * vertices){
    this->vertices = vertices;
    cant_vertices = vertices->obtener_tamanio();

    //Inicializar vertices visitados
    vertices_visitados = new bool[cant_vertices];
    inicializar_visitados();

    //Inicializar_aristas();
    aristas = 0;

    //Inicializar tiempos
    actualizar_tiempo_vertices();
    tiempo_aristas = 0;

    //Inicializar matriz del arbol (copia de la de adyacencia)
    matriz_arbol = matriz_adyacencia;
    calcular_matriz_arbol(matriz_adyacencia);
    hallar_arbol();
}

void Prim::inicializar_visitados(){
    for (int i = 1; i < cant_vertices; i++)
        vertices_visitados[i] = false;

    vertices_visitados[0] = true;
}

// NO HARIA FALTA

void Prim::calcular_matriz_arbol(int** matriz_adyacencia){
    for(int i = 0; i < cant_vertices; i++){
        for(int j = 0; j < cant_vertices; j++){
            matriz_arbol[i][j] = matriz_adyacencia[i][j];
        }
    }
}


void Prim::hallar_arbol(){
    int minimo = INFINITO, x = 0, y = 0;

    while(aristas < cant_vertices - 1){
        for (int i = 0; i < cant_vertices; i++)
            if (vertices_visitados[i])
                for (int j = 0; j < cant_vertices; j++)
                    if (!vertices_visitados[j] && matriz_arbol[i][j] != INFINITO)
                        if(minimo > matriz_arbol[i][j]){
                            minimo = matriz_arbol[i][j];
                            x = i;
                            y = j;
                        }
        // Para debuggear y ver los caminos entre aristas que pertenecen al arbol de expansion miniima juntop con su peso asociado
        std::cout << x <<  " ---> " << y << " // Peso: " << matriz_arbol[x][y] << std::endl;

        actualizar_tiempo_aristas(matriz_arbol[x][y]);
        vertices_visitados[y] = true;
        aristas++;
        minimo = INFINITO;
    }
}

void Prim::actualizar_tiempo_vertices(){
    tiempo_vertices = 0;
    for (int i = 1; i <= cant_vertices; i++){
        tiempo_vertices += vertices->consultar(i);
    }
}

void Prim::actualizar_tiempo_aristas(int tiempo_arista){
    tiempo_aristas += tiempo_arista;
}

void Prim::arbol_expansion(){
    std::cout << "El tiempo de lectura es de: " << tiempo_vertices << std::endl;
    std::cout << "El tiempo entre lecturas es de: " << tiempo_aristas << std::endl;
    std::cout << "El tiempo total es de: " << tiempo_vertices + tiempo_aristas << std::endl;
}

void Prim::liberar_matriz_arbol(){
    for(int i = 0; i < cant_vertices; i++)
        delete[] matriz_arbol[i];

    delete[] matriz_arbol;
    matriz_arbol = nullptr;
}

Prim::~Prim(){
    delete [] vertices_visitados;
    liberar_matriz_arbol();
}
