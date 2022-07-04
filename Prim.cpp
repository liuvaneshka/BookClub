#include "Prim.h"

Prim::Prim(int ** matriz_adyacencia, Lista<Lectura*>* vertices){
    this->vertices = vertices;
    cant_vertices = vertices->obtener_tamanio();

    //Inicializar vertices visitados
    vertices_visitados = new bool[cant_vertices];
    inicializar_visitados();

    //Inicializar tiempos
    calcular_tiempo_vertices();
    tiempo_aristas = 0;

    //Inicializar matriz del arbol (matriz vacía) en donde voy a almacenar las aristas del árbol
    crear_matriz_arbol();

    hallar_arbol(matriz_adyacencia);
}

Prim::~Prim(){
    delete [] vertices_visitados;
    liberar_matriz_arbol();
}

void Prim::inicializar_visitados(){
    for (int i = 1; i < cant_vertices; i++)
        vertices_visitados[i] = false;

    vertices_visitados[0] = true;
}

void Prim::crear_matriz_arbol(){
    matriz_arbol = new int*[cant_vertices];
    for(int i = 0; i < cant_vertices; i++)
        matriz_arbol[i] = new int[cant_vertices];

    inicializar_matriz_arbol();
}

void Prim::inicializar_matriz_arbol(){
    for (int i = 0; i < cant_vertices; i++){
        for (int j = 0; j < cant_vertices; j++){
            matriz_arbol[i][j] = INFINITO;
        }
    }
}

void Prim::hallar_arbol(int** matriz_adyacencia){
    int minimo = INFINITO, x = 0, y = 0, aristas = 0;

    // Algoritmo de Prim
    while(aristas < cant_vertices - 1){
        for (int i = 0; i < cant_vertices; i++)
            if (vertices_visitados[i])
                for (int j = 0; j < cant_vertices; j++)
                    if (!vertices_visitados[j] && matriz_adyacencia[i][j] != INFINITO)
                        if(minimo > matriz_adyacencia[i][j]){
                            minimo = matriz_adyacencia[i][j];
                            x = i;
                            y = j;
                        }

        // Agrego a la matriz del arbol la arista agregada
        matriz_arbol[x][y] = matriz_adyacencia[x][y];
        actualizar_tiempo_aristas(matriz_adyacencia[x][y]);

        // Modifico los valores para la proxima iteración
        vertices_visitados[y] = true;
        aristas++;
        minimo = INFINITO;
    }
}

void Prim::calcular_tiempo_vertices(){
    tiempo_vertices = 0;
    for (int i = 1; i <= cant_vertices; i++){
        tiempo_vertices += vertices->consultar(i)->obtener_minutos();
    }
}

void Prim::actualizar_tiempo_aristas(int tiempo_arista){
    tiempo_aristas += tiempo_arista;
}

void Prim::arbol_expansion(){
    for (int i = 0; i < cant_vertices; i++){
        for(int j = 0; j < cant_vertices; j++){
            if (matriz_arbol[i][j] != INFINITO){
                Lectura* origen = vertices->consultar(i + 1);
                Lectura* destino = vertices->consultar(j + 1);

                std::cout << ROJO << origen->obtener_titulo() << " (" << origen->obtener_minutos() << " minutos)"
                          << AMARILLO << "  <------" << matriz_arbol[i][j] << "min------>  "
                          << ROJO << destino->obtener_titulo() << " (" << destino->obtener_minutos() << " minutos)\n" << std::endl;

            }
        }
    }

    std::cout << AZUL << "El tiempo de lectura es de: " << tiempo_vertices << " minutos" << std::endl;
    std::cout << AZUL << "El tiempo entre lecturas es de: " << tiempo_aristas << " minutos" << std::endl;
    std::cout << VERDE << "El tiempo total es de: " << tiempo_vertices + tiempo_aristas << " minutos\n" << std::endl;
}

void Prim::liberar_matriz_arbol(){
    for(int i = 0; i < cant_vertices; i++)
        delete[] matriz_arbol[i];

    delete[] matriz_arbol;
    matriz_arbol = nullptr;
}