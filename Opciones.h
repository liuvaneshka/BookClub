#ifndef OPCIONES_H
#define OPCIONES_H
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
#include "Cola.h"
//Para pedir datos al usuario
#include "Impresor.h"
//Para las listas
#include "Lista.h"
#include "Lista_lecturas.h"
#include "Hash.h"
#include "Nodo.h"
//Para grafos
#include "Grafo_lecturas.h"
#include "Escritor.h"


class Opciones {

private:
    Hash<string, Escritor*>* tabla;
    Impresor impresor;
    Lista_lecturas* lista_lecturas;
    Cola<Lectura*>* cola_lecturas;
    Grafo_lecturas* grafo_lecturas;


    //PRE: La tabla de escritores debe estar ben definida.
    //POST: Pide al usuario los atributos necesarios y crea al Escritor.
    Escritor* crear_escritor();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea una cola de lecturas, ordenada por minutos de lectura.
    void cola_de_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Devuelve una lista con las lecturas, ordenada por minutos de lectura.
    Lista<Lectura*>* ordenar_por_minutos();

    //PRE: la lista_lecturas y lecturas_ordenadas deben estar bien definidas.
    /*POST: Devuelve el indice de la lista_lecturas donde se debe almacenar
            la lectura para mantener la lista ordenada por minutos de lectura. */
    int obtener_posicion_segun_minutos(Lista<Lectura*>*  lecturas_ordenadas, Lectura* lectura);

    //PRE: La cola_lecturas debe estar bien definida.
    //POST: Pregunta al usuario si desea leer la lectura al frente de la cola.
    void marcar_como_leida();


public:
    //pre: Recibe un objeto tipo hash y una lista de objetos -lecturas-.
    //post: Construye las opciones con el objeto y lista.
    Opciones(Hash<string, Escritor*>* tabla, Lista_lecturas* lista_lecturas, Cola<Lectura*>* cola_lecturas, Grafo_lecturas* grafo_lecturas);

    //PRE: -
    //POST: Destruye las opciones.
    ~Opciones();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea y almacena en lista_lecturas la lectura con los atributos ingresados por el usuario.
    void agregar_lectura();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Pide al usuario los atributos necesarios y crea el objeto correspondiente (Poema, Cuento, Novela, Novela_historica).
    Lectura* crear_lectura();

    //PRE: La tabla de escritores debe estar ben definida.
    //POST: Crea y almacena en lista_escritores el escritor con los atributos ingresados por el usuario.
    void agregar_escritor();

    //PRE: lista_lecturas.vacia() = false.
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista.
    void listar_lecturas();

    //PRE:
    //POST:
    void listar_escritores();

    //PRE: La lista_lecturas debe estar bien definida.
    /*POST: Quita de lista_lecturas la lectura ingresada por el usuario.
            De no existir, se lo comunica al usuario. */
    void quitar_lectura();

    //PRE: La lista_escritores debe estar bien definida.
    //POST: Modifica el atributos anio_dfallecimiento del Escritor ingresado por el usuario.
    void modificar_fallecimiento();

    //PRE: -
    /*POS: Sortea un numero (1 <= num_random <= obtener_tamanio()) e imprime los datos de la lectura cuyo indice es el
            numero sorteado. */
    void sortear();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas entre dos años ingresados por el usuario.
    void listar_lecturas_entre_anios();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas que pertenezcan al escritor ingresado por el usuario.
    void listar_por_escritor();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Imprime las novelas del género ingresado por el usuario.
    void listar_novelas_de_genero();

    //PRE: La lista_lecturas y la cola_lecturas deben estar bien definidas.
    //POST: Crea una cola de lecturas y permite leer la del frente de la cola.
    void proximas_lecturas();

    //PRE: -
    //POST: Devueve el arbol de expansion mínimo del grafo de lecturas y su tiempo mínimo de lectura.
    void tiempo_minimo();

    //PRE: La tabla de escritores debe estar bien definida.
    //POST: Elimina de la tabla el escritor ingresado por el usuario.
    void eliminar_escritor();

};

#endif
