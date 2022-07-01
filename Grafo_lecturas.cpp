#include "Grafo_lecturas.h"
#include "Lista.h"


Grafo_lecturas::Grafo_lecturas(Lista_lecturas* lista_lecturas) : Grafo(){
    this->lista_lecturas = lista_lecturas;
    this->grafo_lecturas = new Grafo();
    this->vertices = new string[lista_lecturas->obtener_tamanio()];

    inicializar_vertices();
    crear_grafo();
}

Grafo_lecturas::~Grafo_lecturas(){
    delete [] vertices;
    delete grafo_lecturas;
    grafo_lecturas = nullptr;
}


void Grafo_lecturas::inicializar_vertices(){
    for (int i = 0; i < lista_lecturas->obtener_tamanio(); i++)
        vertices[i] = "";
}

void Grafo_lecturas::crear_grafo(){
    int i = 1;

    while(i <= lista_lecturas->obtener_tamanio()){
        Lectura* lectura_actual = lista_lecturas->consultar(i);
        agregar_vertice(lectura_actual);

        //string tipo_vertice = obtener_tipo(lectura_actual);
        string tipo_vertice = lectura_actual->obtener_tipo();

        vertices[i - 1] = tipo_vertice;
        i++;
    }

    actualizar_grafo();
}

void Grafo_lecturas::actualizar_grafo(){
    for(int i = 1; i <= lista_lecturas->obtener_tamanio(); i++){
        for (int j = 1; j < i; j++){
            agregar_arista(i, j);
        }
    }
}

void Grafo_lecturas::agregar_arista(int i, int j){  // Indices de cada vértice provenientes de los ciclos de actualizar_grafo
    string tipo1 = vertices[i - 1];
    string tipo2 = vertices[j - 1];

    int peso = calcular_peso(tipo1, tipo2);

    Lectura* origen = lista_lecturas->consultar(i);
    Lectura* destino = lista_lecturas->consultar(j);

    agregar_camino(origen, destino, peso);
}

int Grafo_lecturas::calcular_peso(string tipo_v1, string tipo_v2){
    int peso;

    if(tipo_v1 == tipo_v2)
        peso = peso_mismo_tipo(tipo_v1);
    else
        peso = peso_distinto_tipo(tipo_v1, tipo_v2);

    return peso;
}

int Grafo_lecturas::peso_mismo_tipo(string tipo_v){
    int peso;

    if (tipo_v == "C")
        peso = CUENTO_CUENTO;
    else if (tipo_v == "P")
        peso = POEMA_POEMA;
    else if (tipo_v == "N")
        peso = NOVELA_NOVELA;
    else if (tipo_v == "H")
        peso = HISTORICA_HISTORICA;

    return peso;
}

int Grafo_lecturas::peso_distinto_tipo(string tipo_v1, string tipo_v2){
    int peso;

    if ((tipo_v1 == "C" && tipo_v2 == "P") || (tipo_v2 == "C" && tipo_v1 == "P"))
        peso = CUENTO_POEMA;
    else if ((tipo_v1 == "C" && tipo_v2 == "N") || (tipo_v2 == "C" && tipo_v1 == "N"))
        peso = CUENTO_NOVELA;
    else if ((tipo_v1 == "C" && tipo_v2 == "H") || (tipo_v2 == "C" && tipo_v1 == "H"))
        peso = CUENTO_HISTORICA;
    else if ((tipo_v1 == "P" && tipo_v2 == "N") || (tipo_v2 == "P" && tipo_v1 == "N"))
        peso = POEMA_NOVELA;
    else if ((tipo_v1 == "P" && tipo_v2 == "H") || (tipo_v2 == "P" && tipo_v1 == "H"))
        peso = POEMA_HISTORICA;
    else if ((tipo_v1 == "H" && tipo_v2 == "N") || (tipo_v2 == "H" && tipo_v1 == "N"))
        peso = HISTORICA_NOVELA;

    return peso;
}

/*
string Grafo_lecturas::obtener_tipo(Lectura* lectura){
    string tipo_lectura;

    if(lectura->es_cuento())
        tipo_lectura = CUENTO;
    else if(lectura->es_poema())
        tipo_lectura = POEMA;
    else if(lectura->es_novela())
        tipo_lectura = NOVELA;
    else if(lectura->es_historica())
        tipo_lectura = _HISTORICA;

    return tipo_lectura;
}
*/
