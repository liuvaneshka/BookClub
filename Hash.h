#ifndef __HASH_H__
#define __HASH_H__
#include <iostream>
#include <vector>
#include "Escritor.h"

using namespace std;

template <class T1, class T2> class List{
public:
    T1 llave;
    T2 valor;
    List *siguiente;

    List(T1 llave, T2 valor){
        this->llave = llave;
        this->valor = valor;
        this->siguiente = nullptr;
    }
};


template <class T1, class T2> class Hash{
private:
    vector<List<T1, T2>*> indices;

    int valor_hash(T1 llave){
        int hash = 0 , i = 1;

        while(llave[i] != ')'){

            hash = hash + (int)llave[i];
            i++;
        }
        return(hash % N); // devuelve el indice
    }

    void insertar_en_indice(int indice, T1 llave, T2 valor){
        if(indices.at(indice) == nullptr){
            //cout << "NUEVO NODO" << llave << endl;
            List<T1, T2> *nodo =  new List<T1, T2>(llave, valor);
            indices[indice] = nodo;
            //cout << indice << endl;

        }
        else{
            List<T1, T2> *puntero = indices[indice];// apnta al primer
            if(puntero->llave == llave){
                puntero->valor = valor;
                return;
            }

            while(puntero->siguiente != nullptr){
                puntero = puntero->siguiente;

                if(puntero->llave == llave){
                    puntero->valor = valor;
                    return;
                }
            }

            List<T1, T2> *nodo = new List<T1, T2>(llave, valor);
            puntero->siguiente = nodo;

        }

    }

public:

    void agregar_lista(T1 llave, T2 valor){
        int indice = valor_hash(llave);

        if(((int)indices.size()) < (indice + 1)){
            indices.resize((indice + 1), nullptr);
            //cout << "resize  " << llave << " Indice "  << indice  <<endl;
        }

        insertar_en_indice(indice, llave, valor);
    }

    void imprimir_tabla(){
        if(indices.empty()){
            //cout << "Tabla vacia: " << endl;
        }
        else{
            for(int i = 0; i < (int)indices.size(); i++){

                if (indices[i] != nullptr){
                    //cout << "   INDICE       " << i << "  -->  " << endl;

                    List<T1, T2> *puntero = indices[i];
                    Escritor * escritor;

                    while(puntero != nullptr){
                        //cout << "ISNI: " << puntero->llave << endl;
                        escritor = puntero->valor;
                        escritor->mostrar_escritor();
                        puntero = puntero->siguiente;
                    }
                }
            }
        }
    }

    T2 encontrar_dato(T1 llave) {
        T2 valor = nullptr;
        for (int i = 0; i < (int) indices.size(); i++) {

            if (indices[i] != nullptr) {

                List<T1, T2> *puntero = indices[i];

                while (puntero != nullptr) {
                    if (puntero->llave == llave){
                        valor = puntero->valor;
                    }
                    puntero = puntero->siguiente;
                }
            }
        }
        return valor;
    }


    void vaciar_tabla(){

        for(int i = 0; i < (int)indices.size(); i++){

            if (indices[i] != nullptr){
                List<T1, T2> *puntero = indices[i];

                while(puntero != nullptr){
                    List<T1, T2> *anterior = puntero;
                    puntero = puntero->siguiente;
                    Escritor* eliminar = anterior->valor;
                    delete eliminar;
                    delete anterior;
                }
            }
        }
    }

};

#endif
