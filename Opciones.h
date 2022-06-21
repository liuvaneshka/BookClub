//
// Created by liuvaneshka on 20/06/22.
//

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
#include "Printer.h"
//Para las listas
#include "Lista.h"
#include "Hash.h"
#include "Nodo.h"


class Opciones {

private:
    Hash tabla;
    Printer printer;
    Lista<Lectura*>* lista_lecturas;
    Cola<Lectura*>* cola_lecturas;

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Pide al usuario los atributos necesarios y crea el objeto correspondiente (Poema, Cuento, Novela, Novela_historica)
    Lectura* crear_lectura();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Pide al usuario los atributos necesarios y crea al Escritor.
    Escritor* crear_escritor();

    //PRE: -
    //POST: Pide al usuario isni.
    string generar_isni();

    //PRE: lista_lecturas.vacia() = false.
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista.
    void listar_titulos_lecturas();

    //PRE: -
    //POS: Devuelve el indice (numero entero) de la lista de la lectura que se quiere rastrear.
    int rastrear(string titulo);

    //PRE: lista_lecturas.vacia() = false, tienen que ser anios validos.
    //POS: Muestra la informacion de las lecturas publicados entre dos anios particulares (siempre que pertenezcan a la lista).
    void listar_entre_anios(int desde, int hasta);

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea una cola de lecturas, ordenada por minutos de lectura.
    void cola_de_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Devuelve una lista con las lecturas, ordenada por minutos de lectura.
    Lista<Lectura*>* ordenar_por_minutos();

    //PRE: la lista_lecturas y lecturas_ordenadas deben estar bien definidas.
    /*POST: Devuelve el indice de la lista_lecturas donde se debe almacenar
            la lectura para mantener la lista ordenada por minutos de lectura. */
    int obtener_posicion_segun_minutos(Lista<Lectura*>* lecturas_ordenadas, Lectura* lectura);

    //PRE: -
    //POST: Elimina de la cola de lecturas la lectura que fue eliminada con quitar_lectura().
    void actualizar_cola(Lectura* lectura_eliminada);

    //PRE: La cola_lecturas debe estar bien definida.
    //POST: Poregunta al usuario si desea leet la lectura al frente de la cola.
    void marcar_como_leida();


public:
    //pre: recibe un objeto tipo hash y una lista de objetos -lecturas-
    //post: construye las opciones con el objeto y lista
    Opciones(Hash tabla, Lista<Lectura*>* lista_lecturas, Cola<Lectura*>* cola_lecturas);

    //PRE: -
    //POST: Destruye las opciones.
    ~Opciones();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea y almacena en lista_lecturas la lectura con los atributos ingresados por el usuario.
    void agregar_lectura();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Crea y almacena en lista_escritores el escritor con los atributos ingresados por el usuario.
    void agregar_escritor();

    //PRE: lista_lecturas.vacia() = false.
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista.
    void listar_lecturas();

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
    //POST: Crea una cola de lecturas y perite leer la del frente de la cola.
    Cola<Lectura*>* proximas_lecturas();

    };


#endif
