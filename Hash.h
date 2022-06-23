#ifndef HASH_H
#define HASH_H
#include "CONSTANTES.h"
#include "Lista.h"
#include "Escritor.h"

class Hash {

private:

    struct Item{
        string llave; // llave
        Escritor* escritor; // dato
        struct Item* siguiente; // dir sig item
    };

    Item* tabla_hash[N];// se crea la tabla, con su cantidad de buckets

public:

    //PRE:
    //POST: Construye la tabal hash.
    Hash();

    //PRE:
    //POST: destruye la tabla.
    //~Hash();

    //PRE: Recibe una cadena.
    //POST: Genera una clave.
    int valor_Hash(string llave);

    //PRE: Recibe una cadena para generar la clave, y el objeto a introducir.
    //POST: Agrega un item a la lista.
    void agregar_item(string isni, Escritor* escritor);

    //PRE: Indice debe ser un entero.
    //POST: Retorna la cantidad de items dentro de un bucket o indice.
    int cantidad_item_en_indice(int indice);

    //PRE:
    //POST: Imprime los primeros items de cada bucket, y cuantos items contiene c/u.
    void imprimir_tabla();

    //PRE: Recibe un indice entero.
    //POST: Imprime los valores dentro de cada indice.
    void imprimir_item(int indice);

    //PRE: Recibe una cadena representando la llave.
    //POST: Busca el objeto asociado a la llave.
    Escritor* encontrar_dato(string llave);

    //PRE: Recibe una entero representado el indice y una cadena.
    //POST: Busca el objeto asociado a la cadena y retorna su direccion.
    Escritor* buscar_item(int indice, string nombre);

    //PRE: Recibe una cadena.
    //POST: Busca el objeto asociado a la cadena devuelve puntero al objeto.
    Escritor* encontrar_por_nombre(string nombre);

    //PRE:
    //POST: Lista los escritores.
    void listar_escritor();

    //PRE:
    //POST: Imprime los nombres del objeto dado el bucket escritores.
    void imprimir_nombre(int indice);
};


#endif