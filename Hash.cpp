//
// Created by liuvaneshka on 17/06/22.
//

#include <iostream>
#include "Hash.h"

Hash::Hash(){
    for(int i = 0; i < N; i++){
        tabla_hash[i] = new Lista;
        tabla_hash[i]->llave = "";
        tabla_hash[i]->escritor = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}

Hash::~Hash(){

    /*
    for(int i = 0; i < N; i++){
        delete Lista;
    }
    */
    /*
    Lista* temp;
    Lista* siguiente_temp;

    for(int i = 0; i < N; ++i){
        temp = tabla_hash[i];
        while(nullptr != temp){
            siguiente_temp = temp->siguiente;
            delete temp;
            temp = siguiente_temp;
        }
        tabla_hash[i] = nullptr;
    }
    */
    /*
    for (int i = 0; i < N; ++i){
        Lista* entrada = tabla_hash[i];
        while(entrada != nullptr){
            Lista* anterior = entrada;
            entrada = entrada->siguiente;
            delete anterior;
        }
        delete[] *tabla_hash;
    }
    */
}

int Hash::valor_hash(string llave){
    int hash = 0 , i = 1;

    while(llave[i] != ')'){
        hash = hash + (int)llave[i];
        i++;
    }
    return(hash % N); // devuelve el indice
}

void Hash::agregar_lista(string isni , Escritor* escritor) {

    int indice = valor_hash(isni);

    if(tabla_hash[indice]->escritor == nullptr){
        tabla_hash[indice]->llave = isni;
        tabla_hash[indice]->escritor = escritor;
    }
    else{
        Lista* puntero = tabla_hash[indice]; // apnta al primer
        Lista* nuevo= new Lista; // crea una nueva lista de elementos
        nuevo->llave = isni;
        nuevo->escritor = escritor;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

int Hash::cantidad_lista_en_indice(int indice) {
    int contador = 0;

    if(tabla_hash[indice]->llave == ""){
        return contador;
    }
    else{
        contador++;
        Lista* puntero = tabla_hash[indice];
        while(puntero->siguiente != nullptr){
            contador++;
            puntero = puntero->siguiente;
        }
    }
    return contador;
}

void Hash::imprimir_tabla() {
    int cantidad_elementos;
    for(int i = 0; i < N; i++){

        cantidad_elementos = cantidad_lista_en_indice(i);

        if(cantidad_elementos > 0){
             imprimir_lista(i);
         }
    }
}

void Hash::imprimir_lista(int indice) {
    Lista* puntero = tabla_hash[indice];
    if(puntero->escritor != nullptr){

        while(puntero != nullptr){
            puntero->escritor->mostrar_escritor();
            puntero = puntero->siguiente;
        }
    }
}

Escritor* Hash::encontrar_dato(string llave) {
    int indice = valor_hash(llave);
    bool encontrado = false;
    Escritor* escritor;

    Lista* puntero = tabla_hash[indice];
    while(puntero != nullptr){
        if(puntero->llave == llave){
            encontrado = true;
            escritor = puntero->escritor;
        }
        puntero = puntero->siguiente;
    }
    if(!encontrado)
        escritor = nullptr;
    return escritor;
}

Escritor* Hash::buscar_lista(int indice, string nombre) {
    Lista* puntero = tabla_hash[indice];
    Escritor* escritor = nullptr;

    if(puntero->escritor != nullptr){

        while((puntero != nullptr)){
            if(puntero->escritor->obtener_nombre() == nombre){
                escritor = puntero->escritor;
                return escritor;
            }
            puntero = puntero->siguiente;
        }
    }
    return escritor;
}

Escritor* Hash::encontrar_por_nombre(string nombre) {
    Escritor* escritor;
    Escritor* encontrado = nullptr;
    int cantidad_elementos;
    for(int i = 0; i < N; i++){
        cantidad_elementos = cantidad_lista_en_indice(i);
        if(cantidad_elementos > 0){
            escritor = buscar_lista(i, nombre);
            if(escritor != nullptr){
                encontrado = escritor;
            }
        }
    }
    return encontrado;
}


void Hash::listar_escritor() {
    int cantidad_buckets;

    for(int i = 0; i < N; i++){
        cantidad_buckets = cantidad_lista_en_indice(i);

        if(cantidad_buckets > 0){
            Lista* puntero = tabla_hash[i];
            if(puntero->escritor != nullptr){

                while(puntero != nullptr){
                    cout << puntero->escritor->obtener_nombre() << "  *****  ";
                    puntero = puntero->siguiente;
                }
            }
        }
    }
}

bool Hash::buscar_llave(string llave){
    bool bandera = false;
    int valor = valor_hash(llave);
    Lista* entrada = tabla_hash[valor];
    while (entrada != NULL){
        if (entrada->llave == llave){
            cout<<entrada->escritor<<endl;
            bandera = true;
        }
        entrada = entrada->siguiente;
    }

    return bandera;
}

void Hash::eliminar_lista(string llave){
    int indice = valor_hash(llave);

    Lista* puntero_eliminar;
    Lista* aux;
    Lista* aux_2;

    /*
    if((tabla_hash[indice]->escritor == nullptr) && (tabla_hash[indice]->llave == "")){
        cout << "caso 1" << endl;
    }
     */

    if ((tabla_hash[indice]->llave == llave) && (tabla_hash[indice]->siguiente == nullptr)){
        tabla_hash[indice]->llave = "";
        tabla_hash[indice]->escritor = nullptr;
    }

    else if(tabla_hash[indice]->llave == llave){
        puntero_eliminar = tabla_hash[indice];
        tabla_hash[indice] = tabla_hash[indice]->siguiente;
        delete puntero_eliminar;
    }

    else{
        aux = tabla_hash[indice]->siguiente;
        aux_2 = tabla_hash[indice];

        while(aux != nullptr && aux->llave != llave){
            aux_2 = aux;
            aux = aux->siguiente;
        }
        /*
        if(aux == nullptr){
            cout << "caso 4" << endl;
        }
        */
        if(aux != nullptr) {
            puntero_eliminar = aux;
            aux = aux->siguiente;
            aux_2->siguiente = aux;

            delete puntero_eliminar;
            //cout << "llave eliminada" << endl;
        }
    }

}

void Hash::borrar_tabla(){
    std::cout << "eliminar" << std::endl;
    for(int i = 0; i < N; i++){
        if(tabla_hash[i]->llave != "" && cantidad_lista_en_indice(i) > 0){
            cout<<tabla_hash[i]->llave<<endl;
            eliminar_lista(tabla_hash[i]->llave);
        }
    }
}