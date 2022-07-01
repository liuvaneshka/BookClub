#include "Lista_lecturas.h"

Lista_lecturas::Lista_lecturas() : Lista<Lectura*>() {
    lista_lecturas = new Lista<Lectura*>;
}

Lista_lecturas::~Lista_lecturas(){
    while(!vacia()){
        Lectura* eliminar = consultar(1);
        delete eliminar;
        baja(1);
    }
    delete lista_lecturas;
}

int Lista_lecturas::posicion_segun_anio(Lectura* lectura){
    int indice = 1;

    if (!vacia()){
        inicializar();

        while(hay_actual() && lectura->comparar_lecturas(consultar(indice)) != -1){
            indice++;
            siguiente();
        }
    }
    return indice;
}

int Lista_lecturas::rastrear(string titulo){
    int indice = 1, indice_correspondiente = -1;

    inicializar();
    while(hay_actual() &&consultar(indice)->obtener_titulo() != titulo){
        indice++;
        siguiente();
    }

    if(hay_actual())
        indice_correspondiente = indice;

    return indice_correspondiente;
}

void Lista_lecturas::sortear(){
    int num_random = rand() % obtener_tamanio() + 1;

    Lectura* lectura_random = consultar(num_random);

    cout << "Lectura sorteada: " << endl;
    lectura_random->mostrar_lectura();
}

void Lista_lecturas::listar(){
    int contador = 1;
    inicializar();

    while(hay_actual()){
        cout << "Lectura numero: "<< contador << endl;
        Lectura* lectura_actual = obtener_dato_cursor();
        lectura_actual->mostrar_lectura();

        siguiente();
        contador++;
    }
}

void Lista_lecturas::listar_titulos_lecturas(){
    int contador = 1;
    inicializar();

    while(hay_actual()){
        string titulo;
        Lectura* lectura_actual = obtener_dato_cursor();
        cout << VIOLETA << lectura_actual->obtener_titulo() << "  **  ";

        siguiente();
        contador++;
    }
    cout << endl;
}

void Lista_lecturas::listar_entre_anios(int desde, int hasta){
    int contador_lecturas = 0;

    if (desde > hasta)
        cout << ANIOS_INVALIDOS << endl;

    else{
        inicializar();
        while(hay_actual()){
            Lectura* lectura_actual = obtener_dato_cursor();
            int anio_lectura_actual = lectura_actual->obtener_anio();

            if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta){
                lectura_actual->mostrar_lectura();
                contador_lecturas++;
             }
            siguiente();
        }
        if(!contador_lecturas)
            cout << ROJO << ERROR_POR_ANIOS << endl;
    }
}

void Lista_lecturas::listar_por_escritor(string nombre_escritor){
    bool hay_lecturas = false;

    inicializar();
    while(hay_actual()){
        Lectura* lectura_actual = obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor){
            hay_lecturas = true;
            cout << '\n';
            lectura_actual->mostrar_lectura();
        }
        siguiente();
    }

    if (!hay_lecturas)
        cout << ROJO << ERROR_POR_ESCRITOR << endl;
}

void Lista_lecturas::listar_por_genero(generos genero){

    int contador_lecturas = 0;

    inicializar();
    while(hay_actual()){
        Lectura* lectura_actual = obtener_dato_cursor();
        contador_lecturas += lectura_actual->imprimir_novela_genero(genero);
        siguiente();
    }

    if (!contador_lecturas)
        cout << ROJO << ERROR_POR_GENERO << endl;
}


void Lista_lecturas::eliminar_escritor_en_lectura(string nombre_escritor){
    cout << nombre_escritor << endl;

    inicializar();
    while(hay_actual()){
        Lectura* lectura_actual = obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();
        Escritor* escritor_nulo = nullptr;

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor){
            lectura_actual->modificar_escritor(escritor_nulo);
        }

        siguiente();
    }

}

