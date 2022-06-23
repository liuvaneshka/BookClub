#include "Lista_escritores.h"

Lista_escritores::Lista_escritores() : Lista<Escritor*>(){
    lista_escritores = new Lista<Escritor*>;
}

Lista_escritores::~Lista_escritores(){
    while(!vacia()){
        Escritor* eliminar = consultar(1);
        delete eliminar;
        baja(1);
    }
    //delete lista_escritores //????
}

void Lista_escritores::listar(){
    int contador = 1;
    inicializar();

    while(hay_actual()){
        cout << VERDE << "Escritor numero: " << contador << endl;
        Escritor* escritor_actual = obtener_dato_cursor();
        escritor_actual -> mostrar_escritor();

        siguiente();
        contador++;
    }
}

void Lista_escritores::listar_nombres_escritores(){
    int contador = 1;
    inicializar();

    while(hay_actual()){
        Escritor* escritor_actual = obtener_dato_cursor();
        cout << VIOLETA << escritor_actual->obtener_nombre() << " ** ";

        siguiente();
        contador++;
    }
    cout << endl;
}

Escritor* Lista_escritores::rastrear(string nombre_escritor){
    int indice = 1;
    Escritor* escritor_buscado = nullptr;

    inicializar();
    while(hay_actual() && consultar(indice) -> obtener_nombre() != nombre_escritor){
        indice++;
        siguiente();
    }
    if (hay_actual())
        escritor_buscado = consultar(indice);

    return escritor_buscado;
}
