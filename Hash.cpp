//
// Created by liuvaneshka on 17/06/22.
//

#include <iostream>
#include "Hash.h"

Hash::Hash(){
    for(int i = 0; i < N; i++){
        tabla_hash[i] = new Item;
        tabla_hash[i]->llave = "";
        tabla_hash[i]->escritor = nullptr;
        tabla_hash[i]->siguiente = nullptr;
    }
}
/*
Hash::~Hash(){
    std::cout << "DESTRUCTOR HASH ------ DESTRUCTOR HASH " << std::endl;

    Item* temp;
    Item* siguiente_temp;

    for(int i = 0; i < n; i++){
        temp = tabla_hash[i];
        while(nullptr != temp){
            siguiente_temp = temp->siguiente;
            delete temp;
            temp = siguiente_temp;
        }
        tabla_hash[i] = nullptr;
    }

}*/

int Hash::valor_Hash(string llave){
    int hash = 0 , i = 1;

    while(llave[i] != ')'){
        hash = hash + (int)llave[i];
        i++;
    }
    return(hash % N); // devuelve el indice
}

void Hash::agregar_item(string isni , Escritor* escritor) {

    int indice = valor_Hash(isni);

    if(tabla_hash[indice]->escritor == nullptr){
        tabla_hash[indice]->llave = isni;
        tabla_hash[indice]->escritor = escritor;
    }
    else{
        Item* puntero = tabla_hash[indice]; // apnta al primer
        Item* nuevo= new Item; // crea una nueva lista de elementos
        nuevo->llave = isni;
        nuevo->escritor = escritor;
        nuevo->siguiente = nullptr;

        while(puntero->siguiente != nullptr){
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo;
    }
}

int Hash::cantidad_item_en_indice(int indice) {
    int contador = 0;

    if(tabla_hash[indice]->llave == ""){
        return contador;
    }
    else{
        contador++;
        Item* puntero = tabla_hash[indice];
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

        cantidad_elementos = cantidad_item_en_indice(i);

        if(cantidad_elementos > 0){
             imprimir_item(i);
         }
    }
}

void Hash::imprimir_item(int indice) {
    Item* puntero = tabla_hash[indice];
    if(puntero->escritor != nullptr){

        while(puntero != nullptr){
            puntero->escritor->mostrar_escritor();
            puntero = puntero->siguiente;
        }
    }
}

Escritor* Hash::encontrar_dato(string llave) {
    int indice = valor_Hash(llave);
    bool encontrado = false;
    Escritor* escritor;

    Item* puntero = tabla_hash[indice];
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


Escritor* Hash::buscar_item(int indice, string nombre) {
    Item* puntero = tabla_hash[indice];
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
        cantidad_elementos = cantidad_item_en_indice(i);
        if(cantidad_elementos > 0){
            escritor = buscar_item(i, nombre);
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
        cantidad_buckets = cantidad_item_en_indice(i);

        if(cantidad_buckets > 0){
            Item* puntero = tabla_hash[i];
            if(puntero->escritor != nullptr){

                while(puntero != nullptr){
                    cout << puntero->escritor->obtener_nombre() << "  *****  ";
                    puntero = puntero->siguiente;
                }
            }
        }
    }
}

/*
void Hash::eliminar_lista(string llave) {

    int indice = Hash(llave);

    lista* puntero_eliminar;
    lista* puntero;
    lista* aux;



}
*/