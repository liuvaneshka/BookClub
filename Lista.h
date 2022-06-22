#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const int NOMBRE_NO_ENCONTRADO = -2;        // Puse un -2 solo porque el nombre de los vertices es un int, entonces para mantener ese tipo de dato

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtener_tamanio();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtener_posicion(int nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    int consultar(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(int nuevoElemento);

    //post: devuelve true si la lista está vacia, flase en caso contrario.
    bool esta_vacia();

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtener_tamanio(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista<Tipo>::obtener_posicion(int nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtener_nombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(int nuevoElemento) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
int Lista<Tipo>::consultar(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

template<typename Tipo>
bool Lista<Tipo>::esta_vacia(){
    return not cantidadDeElementos;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    while(primero != nullptr){
        Nodo <Tipo>* siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

#endif //GRAFOS_LISTA_H
