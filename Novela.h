#ifndef __NOVELA_H__
#define __NOVELA_H__
#include "Lectura.h"
using namespace std;

class Novela : public Lectura {

private:
    generos genero;

public:

    //PRE: anio > 0, minutos > 0, genero debe ser un género válido.
    //POST: Construye un objeto Novela.
    Novela(string titulo, Escritor *escritor, int anio, int minutos, generos genero);

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Destruye un objeto Novela.
    ~Novela();

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Devuelve el numero del enumerado del género de la novela.
    generos obtener_genero();

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Imprime los atributos de la Novela.
    void mostrar_lectura();

    //PRE: El genero debe ser un genero válido.
    //POST: Devuelve el string correspondiente al genero del enumerado
    string string_genero(generos genero);

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Imprime por pantalla la NOvela, si su género se corresponde con genero.
    int imprimir_novela_genero(generos genero);

    //PRE: -
    //POST: Devuelve True, dado que esta es la clase Novela.
    bool es_novela();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Novela.
    bool es_cuento();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Novela.
    bool es_poema();

    //PRE: -
    //POST: Devuelve False, dado que esta es la clase Novela.
    bool es_historica();

    //PRE:
    //POST: Devuelve "N", dado que se trata de una Novela.
    string obtener_tipo();

};
#endif // __NOVELA_H__
