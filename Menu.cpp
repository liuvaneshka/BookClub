#include "Menu.h"
#include "Parser.h"

Menu::Menu(){

    Lista_lecturas *lista_lecturas = new Lista_lecturas;
    Hash<string, Escritor*> *tabla = new Hash<string, Escritor*>;
    cola_lecturas = nullptr;
    grafo_lecturas = nullptr;

    Opciones* opciones = cargar(tabla, lista_lecturas, cola_lecturas, grafo_lecturas);
    inicializar_semilla();
    mantener_abierto_menu(opciones);
    delete opciones;
}

Menu::~Menu(){

    tabla->vaciar_tabla();
    delete tabla;
    delete lista_lecturas;
    if (cola_lecturas)
        delete cola_lecturas;
    delete grafo_lecturas;
    grafo_lecturas = nullptr;

}


Opciones* Menu::cargar(Hash<string, Escritor*> *tabla, Lista_lecturas* lista_lecturas, Cola<Lectura*>* cola_lecturas, Grafo_lecturas* grafo_lecturas) {


    Parser parser;
    cola_lecturas = nullptr;
    tabla = parser.procesar_escritor(ARCHIVO_ESCRITORES, tabla);
    lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, tabla);
    grafo_lecturas = nullptr;

    Opciones* opciones = new Opciones(tabla, lista_lecturas, cola_lecturas, grafo_lecturas);

    return opciones;
}

void Menu::mostrar_menu(){
    for(int i = 0; i < CANT_OPCIONES; i++)
        cout << AMARILLO << i+1 << ". " << OPCIONES[i]  << endl;
}

void Menu::elegir_opcion(){
    string opcion;
    this->opcion = impresor.pedir_opcion();
}



bool Menu::selector_menu(Opciones* opciones){
    bool estado;

    switch (this->opcion){

        case 1:
            cout << VERDE << "Caso 1: Agregar una nueva lectura"<< endl;
            opciones->agregar_lectura();
            estado = true;
            break;

        case 2:
            cout << VERDE << "Caso 2: Quitar lectura" << endl;
            opciones->quitar_lectura();
            estado = true;
            break;

        case 3:
            cout << VERDE << "Caso 3: Agregar un escritor" << endl;
            opciones->agregar_escritor();
            estado = true;
            break;

        case 4:
            cout << VERDE << "Caso 4: Actualizar fallecimiento autor" << endl;
            opciones->modificar_fallecimiento();
            estado = true;
            break;

        case 5:
            cout << VERDE << "Caso 5: Listar los escritores" << endl;
            opciones->listar_escritores();
            estado = true;
            break;

        case 6:
            cout << VERDE << "Caso 6: Sortear una lectura" << endl;
            opciones->sortear();
            estado = true;
            break;

        case 7:
            cout << VERDE << "Caso 7: Listar lecturas" << endl;
            opciones->listar_lecturas();
            estado = true;
            break;

        case 8:
            cout << VERDE << "Caso 8: Listar lecturas por anio" << endl;
            opciones->listar_lecturas_entre_anios();
            estado = true;
            break;

        case 9:
            cout << VERDE << "Caso 9: Listar lecturas por escritor" << endl;
            opciones->listar_por_escritor();
            estado = true;
            break;

        case 10:
            cout << VERDE << "Caso 10: Listar Novelas por genero" << endl;
            opciones->listar_novelas_de_genero();
            estado = true;
            break;

        case 11:
            cout << VERDE << "Caso 11: Listar proximas lecturas" << endl;
            cola_lecturas = opciones->proximas_lecturas();
            estado = true;
            break;

        case 12:
            cout << VERDE << "Caso 12: Tiempo mínimo de lectura" << endl;
            opciones->tiempo_minimo();

            estado = true;
            break;

        case 13:
            cout << "\n\t\t\tCordial despedida\n" << endl;
            estado = false;
            break;

        default:
            cout << "\nError elige otra opcion valida\n" << endl;
            estado = true;

    }

    return estado;
}


void Menu::mantener_abierto_menu(Opciones *opciones){
    mostrar_menu();
    elegir_opcion();

    while (selector_menu(opciones)) {
        mostrar_menu();
        elegir_opcion();
    }
}

void Menu::inicializar_semilla(){
    srand( (unsigned int) time(0));
}
