//
// Created by liuvaneshka on 17/06/22.
//

#ifndef HASH_H
#define HASH_H
#include "CONSTANTES.h"
#include "Lista.h"
#include "Escritor.h"

class Hash {

private:

    struct Lista{
        string llave; // llave
        Escritor* escritor; // dato
        struct Lista* siguiente; // dir sig Lista
    };

    Lista* tabla_hash[N];// se crea la tabla, con su cantidad de buckets

public:

    //post: construye la tabal hash
    Hash();

    //post: destruye la tabla
    ~Hash();

    //pre: recibe una cadena
    //post: genera una clave
    int valor_hash(string llave);

    //pre: recibe una cadena para generar la clave, y el objeto a introducir
    //post: agrega un Lista a la lista
    void agregar_lista(string isni, Escritor* escritor);

    //pre: indice debe ser un entero
    //post: retorna la cantidad de Listas dentro de un bucket o indice
    int cantidad_lista_en_indice(int indice);

    //post: imprime los primeros Listas de cada bucket, y cuandos Listas contiene c/u
    void imprimir_tabla();

    //pre: recibe un indice entero
    //post: imprime los valores dentro de cada indice
    void imprimir_lista(int indice);

    //pre: recibe una cadena representando la llave
    //post: busca el objeto asociado a la llave
    Escritor* encontrar_dato(string llave);

    //pre: recibe una entero representado el indice y una cadena
    //post: busca el objeto asociado a la cadena y retorna su direccion
    Escritor* buscar_lista(int indice, string nombre);

    //pre: recibe una cadena
    //post: busca el objeto asociado a la cadena devuelve puntero al objeto
    Escritor* encontrar_por_nombre(string nombre);

    //pre:
    //post: lista los escritores
    void listar_escritor();

    //pre:
    //post: imprime los nombres del objeto dado el bucket escritores
    void imprimir_nombre(int indice);

    //pre:
    //post: imprime los nombres del objeto dado el bucket escritores
    bool buscar_llave(string llave);

    void eliminar_lista(string llave);

    void borrar_tabla();

    };


#endif