#ifndef __HASH_H__
#define __HASH_H__
#include <iostream>
#include <vector>
#include "Lista_doble_parametro.h"
#include "Escritor.h"
#include "CONSTANTES.h"

using namespace std;


template <class T1, class T2>
class Hash{

private:

    vector<Lista_doble_parametro<T1, T2>*> indices;

    //PRE: Recibe una llave
    //POST: retorna un entero representando el indice de la tabla.
    int funcion_hash(T1 llave);

    //PRE: Recibe un enetero representando el indice, recibe tipo llave y tipo valor.
    //POST: Inserta el valor en el indice indicado, sino existe crea el nodo.
    void insertar_en_indice(int indice, T1 llave, T2 valor);

    //PRE: Recibe un enterp representando el tipo de impresion, y un puntero a lista representando el valor.
    //POST: Imprime, la llave o el valor. o ambos.
    void imprimir_por_tipo(int tipo, Lista_doble_parametro<T1, T2>*puntero);

public:

    //PRE: La lista debe contener dos parametros validos (llave y valor)
    //POST: Construye el objeto lista doble parametro.
    void agregar_lista(T1 llave, T2 valor);

    //PRE: Entero representando el tipo de impresion deseado.
    //POST: recorre la tabla y llama al metodo imprimir por tipo.
    void imprimir_tabla(int tipo);

    //PRE: La lista debe contener un oarametro valido representando la llave.
    //POST: devuelve el valor en caso de existir la llave.
    T2 encontrar_dato(T1 llave);

    //PRE: -
    //POST: Destruye los escritores y los nodos creados, vacia la lista.
    void vaciar_tabla();

    //PRE: Recibe la llave del escritor a eliminar
    //POST: Elimina el escritor y los nodos creados, vacia la lista.
    void eliminar(T1 llave);

};

template <class T1, class T2>
int Hash<T1, T2> :: funcion_hash(T1 llave){
    int hash = 0 , i = 1;

    while(llave[i] != ')'){
        hash = hash + (int)llave[i];
        i++;
    }
    return ((hash % N) + 1 ); // Devuelve el indice, sumo uno para que la tabla no comience de 0
}

template <class T1, class T2>
void Hash<T1, T2> :: insertar_en_indice(int indice, T1 llave, T2 valor){
    if(indices.at(indice) == nullptr){
        Lista_doble_parametro<T1, T2> *nodo =  new Lista_doble_parametro<T1, T2>(llave, valor);
        indices[indice] = nodo;

    }
    else{
        Lista_doble_parametro<T1, T2> *puntero = indices[indice];// Apunta al primero

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        Lista_doble_parametro<T1, T2> *nodo = new Lista_doble_parametro<T1, T2>(llave, valor);
        puntero->siguiente = nodo;
    }
}

template <class T1, class T2>
void Hash<T1, T2> :: imprimir_por_tipo(int tipo, Lista_doble_parametro<T1, T2>*puntero){

    Escritor * escritor;
    escritor = puntero->obtener_valor();

    if(tipo == VALOR){
        cout << "ISNI: " << puntero->obtener_llave()<<endl;
        escritor->mostrar_escritor();
    }
    else if(tipo == LLAVE){
        cout << " **** " << puntero->obtener_llave() << " " << escritor->obtener_nombre() << " **** " ;
    }
    else if(tipo == NOMBRE){
        cout << " **** " << escritor->obtener_nombre() << " **** " ;
    }
}

template <class T1, class T2>
void Hash<T1, T2> :: agregar_lista(T1 llave, T2 valor){
    int indice = funcion_hash(llave);

    if(((int)indices.size()) < (indice + 1)){
        indices.resize((indice + 1), nullptr);
    }
    insertar_en_indice(indice, llave, valor);
}


template <class T1, class T2>
void Hash<T1, T2> :: imprimir_tabla(int tipo){

    for(int i = 0; i < (int)indices.size(); i++){
        if (indices[i] != nullptr){
            if(tipo == VALOR)
                cout << "   INDICE       " << i << "  -->  " << endl;
            Lista_doble_parametro<T1, T2> *puntero = indices[i];
            while(puntero != nullptr){
                imprimir_por_tipo(tipo, puntero);
                puntero = puntero->obtener_siguiente();
            }
        }
    }
    cout << endl;
}


template <class T1, class T2>
T2 Hash<T1, T2> :: encontrar_dato(T1 llave) {
    T2 valor = nullptr;
    for (int i = 0; i < (int) indices.size(); i++) {
        if (indices[i] != nullptr) {
            Lista_doble_parametro<T1, T2> *puntero = indices[i];

            while (puntero != nullptr) {
                if (puntero->obtener_llave() == llave){
                    valor = puntero->obtener_valor();
                }
                puntero = puntero->obtener_siguiente();
            }
        }
    }
    return valor;
}

template <class T1, class T2>
void Hash<T1, T2> :: eliminar(T1 llave){
    if(indices.empty()){
        cout << "Tabla vacia" << endl;
    }
    int indice = funcion_hash(llave);
    Lista_doble_parametro<T1, T2> *puntero = indices[indice];

    if(puntero->obtener_llave() == llave){
        indices[indice] = puntero->obtener_siguiente();
        Escritor* escritor_actual = puntero->obtener_valor();
        delete escritor_actual;
        delete puntero;
        return;
    }

    while(puntero != nullptr){

        if(puntero->obtener_siguiente()->obtener_llave() == llave){
            Lista_doble_parametro<T1, T2> *aux = puntero->obtener_siguiente();
            puntero->siguiente = puntero->siguiente->obtener_siguiente();
            Escritor* escritor_actual = aux->valor;
            delete escritor_actual;
            delete(aux);
            return;
        }
        puntero = puntero->siguiente;
    }
}

template <class T1, class T2>
void Hash<T1, T2> :: vaciar_tabla(){

    for(int i = 0; i < (int)indices.size(); i++){

        if (indices[i] != nullptr){
            Lista_doble_parametro<T1, T2> *puntero = indices[i];

            while(puntero != nullptr){
                Lista_doble_parametro<T1, T2> *anterior = puntero;
                puntero = puntero->siguiente;
                Escritor* eliminar = anterior->valor;
                delete eliminar;
                delete anterior;
            }
        }
    }
}

#endif
