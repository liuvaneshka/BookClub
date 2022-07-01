#include "Menu.h"
#include "Parser.h"

Menu::Menu(){

    lista_lecturas = new Lista_lecturas;
    tabla = new Hash<string, Escritor*>;
    cola_lecturas = nullptr;
    grafo_lecturas = nullptr;

    cargar(tabla, lista_lecturas);
    opciones = new Opciones(tabla, lista_lecturas, cola_lecturas, grafo_lecturas);
    inicializar_semilla();
}

Menu::~Menu(){

    tabla->vaciar_tabla();
    delete tabla;

    delete opciones;
    delete lista_lecturas;
}

void Menu::cargar(Hash<string, Escritor*> *tabla, Lista_lecturas *lista_lecturas){

    Parser parser;
    tabla = parser.procesar_escritor(ARCHIVO_ESCRITORES, tabla);
    lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, tabla);
}

void Menu::mostrar_menu(){
    for(int i = 0; i < CANT_OPCIONES; i++)
        cout << AMARILLO << i+1 << ". " << OPCIONES[i]  << endl;
}

void Menu::elegir_opcion(){
    string opcion;
    this->opcion = impresor.pedir_opcion();
}

bool Menu::selector_menu(){
    bool estado;

    switch (this->opcion){

        case 1:
            cout << VERDE << CASO_1 << endl;
            opciones->agregar_lectura();
            estado = true;
            break;

        case 2:
            cout << VERDE << CASO_2 << endl;
            opciones->quitar_lectura();
            estado = true;
            break;

        case 3:
            cout << VERDE << CASO_3 << endl;
            opciones->agregar_escritor();
            estado = true;
            break;

        case 4:
            cout << VERDE << CASO_4 << endl;
            opciones->modificar_fallecimiento();
            estado = true;
            break;

        case 5:
            cout << VERDE << CASO_5 << endl;
            opciones->listar_escritores();
            estado = true;
            break;

        case 6:
            cout << VERDE << CASO_6 << endl;
            opciones->sortear();
            estado = true;
            break;

        case 7:
            cout << VERDE << CASO_7 << endl;
            opciones->listar_lecturas();
            estado = true;
            break;

        case 8:
            cout << VERDE << CASO_8 << endl;
            opciones->listar_lecturas_entre_anios();
            estado = true;
            break;

        case 9:
            cout << VERDE << CASO_9 << endl;
            opciones->listar_por_escritor();
            estado = true;
            break;

        case 10:
            cout << VERDE << CASO_10 << endl;
            opciones->listar_novelas_de_genero();
            estado = true;
            break;

        case 11:
            cout << VERDE << CASO_11 << endl;
            opciones->proximas_lecturas();
            estado = true;
            break;

        case 12:
            cout << VERDE << CASO_12 << endl;
            opciones->tiempo_minimo();

            estado = true;
            break;

        case 13:
            cout << VERDE << CASO_13 << endl;
            opciones->eliminar_escritor();
            estado = true;
            break;

        case 14:
            cout << DESPEDIDA << endl;
            estado = false;
            break;

        default:
            cout << OPCION_INVALIDA << endl;
            estado = true;

    }

    return estado;
}

void Menu::inicializar_semilla(){
    srand( (unsigned int) time(0));
}
