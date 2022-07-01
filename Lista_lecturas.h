#ifndef __LISTA_LECTURAS_H__
#define __LISTA_LECTURAS_H__
#include "Lista.h"
#include "Lectura.h"
#include "CONSTANTES.h"

class Lista_lecturas : public Lista<Lectura*> {

private:
    Lista<Lectura*>* lista_lecturas;

public:

    //PRE: -
    //POS: Construye una Lista de Lecturas vacia.
    Lista_lecturas();

    //PRE: El objeto Lista_lecturas debe ser un objeto válido.
    //POS: Destruye la Lista de Lecturas.
    ~Lista_lecturas();

    //PRE: -
    //POS: Devuelve el indice (numero entero) de la lista de la lectura que se quiere rastrear
    int rastrear(string titulo);

    //PRE: -
    //POS: Sortea un numero (1 <= num_random <= obtener_tamanio()) e imprime los datos de la lectura cuyo indice es el
    //      numero sorteado
    void sortear();

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra el titulo de las lecturas
    void listar();

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista
    void listar_titulos_lecturas();

    //PRE: lista_lecturas.vacia() = false, tienen que ser anios validos.
    //POS: Muestra la informacion de las lecturas publicados entre dos anios particulares (siempre que pertenezcan a la lista)
    void listar_entre_anios(int desde, int hasta);

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las lecturas escritos por un escritor en particular (siempre que pertenezcan a la lista)
    void listar_por_escritor(string nombre_escritor);

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las Novelas de un genero en paricular (siempre que pertenezcan a la lista)
    void listar_por_genero(generos genero);

    //PRE: el objeto lectura debe ser un objeto valido
    //POS: Determina la posicion de una lectura en la lista segun su anio de publicacion
    int posicion_segun_anio(Lectura* lectura);


    void eliminar_escritor_en_lectura(string nombre_escritor);
};
#endif // __LISTA_LECTURAS_H__
