#ifndef MENU_H
#define MENU_H
#include <iostream>
// Clases generales
#include "Escritor.h"
#include "Lectura.h"
#include "CONSTANTES.h"
// Subclases
#include "Novela.h"
#include "Novela_historica.h"
#include "Cuento.h"
#include "Poema.h"
// Para la opcion de sortear una lectura
#include <stdlib.h>
#include <time.h>
// Para la cola de lecturas
#include "Lista.h"
#include "Lista_lecturas.h"
//Para pedir datos al usuario
#include "Impresor.h"
//Hash
#include "Hash.h"
//Opciones
#include "Opciones.h"
//Impresor
#include "Impresor.h"

using namespace std;

class Menu {

private:

    int opcion;
    Opciones* opciones;
    Impresor impresor;
    Hash <string, Escritor*>* tabla;
    Lista_lecturas* lista_lecturas;
    Cola<Lectura*>* cola_lecturas;
    Grafo_lecturas* grafo_lecturas;

    //PRE: -
    //POST: Inicializa la semilla para sortear la lectura.
    void inicializar_semilla();

public:

    //PRE: -
    //POST: Construye un Menu.
    Menu();

    //PRE: -
    //POST: Destruye un Menu.
    ~Menu();

    //PRE: La tabla y la lista deben estar bien definidas.
    //POST: Carga la tabla de Escritores y la lista de Lecturas con los métodos del Praser.
    void cargar(Hash<string, Escritor*>* tabla, Lista_lecturas* lista_lecturas);

    //PRE: Menu debe ser un objeto válido.
    //POST: Impriem las opcines del Menu.
    void mostrar_menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Pide al usuario la opcion que desea ejecutar del Menu.
    void elegir_opcion();

    //PRE: Menu debe ser un objeto válido.
    //POST: Dependiendo de la opcion ingresada por el usuario, se ejecuta la acción correspondiente.
    bool selector_menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Dependiendo de la opcion ingresada por el usuario, se ejecuta la acción correspondiente.
    bool selector_menu(Opciones* opciones);

};

#endif
