#ifndef TP2_POEMA_H
#define TP2_POEMA_H
#include "Lectura.h"

class Poema : public Lectura {

private:
    int versos;

public:

    //PRE: anio > 0, minutos > 0, versos >0, escritor es un objeto válido.
    //POST: Construye un objeto Poema.
    Poema(std::string titulo, Escritor *escritor, int anio, int minutos, int versos);

    //PRE: El objeto Poema debe ser un objeto válido.
    //POST: Destruye un objeto Poema.
    ~Poema();

    //PRE: El objeto Poema debe ser un objeto válido.
    //POST: Devuelve la cantidad de versos del Poema.
    int obtener_versos();

    //PRE: El objeto Poema debe ser un objeto válido.
    //POST: Imprime los atributos del Poema.
    void mostrar_lectura();

    //PRE: El objeto Poema debe ser un objeto válido.
    //POST: Por ser un Poema, no hace nada ya que no tiene género (polimorfimo)
    int imprimir_novela_genero(generos genero);

    //PRE: -
    //POST: Devuelve True, dado que esta es la clase Poema;
    bool es_poema();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Poema;
    bool es_cuento();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Poema;
    bool es_novela();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Poema;
    bool es_historica();

    //PRE:
    //POST: Devuelve "P", dado que se trata de una Poema.
    string obtener_tipo();

};

#endif //TP2_POEMA_H
