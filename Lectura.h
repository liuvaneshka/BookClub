#ifndef TP2_LECTURA_H
#define TP2_LECTURA_H
#include <iostream>
#include "CONSTANTES.h"
#include "Escritor.h"
using namespace std;

class Lectura {

protected:
    int minutos;
    int anio;
    Escritor* escritor;
    string titulo;
    bool leida;

public:

    //PRE: anio > 0, minutos > 0, escritor es un objeto válido.
    //POST: Construye un objeto Lectura.
    Lectura(string titulo, Escritor *escritor, int anio, int minutos);

    //PRE: -
    //POST: Constructor sin parámetros para el template de Lista<Lectura*>.
    Lectura();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Destruye la Lectura (destructor virtual).
    virtual ~Lectura() = 0;

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Método virtual que imprime los atributos de la Lectura (polimorfismo).
    virtual void mostrar_lectura();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve el titulo de la Lectura.
    string obtener_titulo();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve los minutos de la Lectura.
    int obtener_minutos();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve el año de publicación de la Lectura.
    int obtener_anio();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve true si la lectura fdue leida, false en caso contrario.
    bool lectura_leida();

    //PRE: El objeto lectura debe ser un objeto válido.
    //POST: Lee una lectura.
    void leer();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve el escritor de la Lectura.
    Escritor *obtener_escritor();

    //PRE: Lectura es un objeto válido.
    /*POST: Devuelve -1 si la Lectura que llama posee un año de publicación anterior a la del parámetro.
            Devuelve 0 si las Lecturas poseen el mismo año de publicación.
            Devuelve 1 si la Lectura que llama posee un año de publicación posterior a la del parámetro. */
    int comparar_lecturas(Lectura *lectura);

    int comparar_lecturas(Lectura *lectura, int sobrecargar);

    //PRE: escritor debe ser un escritor válido.
    //POST: Modifica el escritor de la lectura.
    void modificar_escritor(Escritor* escritor);

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Método virtual, definido en cada subclase.
    virtual int imprimir_novela_genero(generos genero) = 0;

    //PRE: -
    //POST: Método virtual, definido en cada subclase.
    virtual string obtener_tipo() = 0;

    //PRE: -
    //POST: Método virtual, definido en cada subclase.
    virtual bool es_cuento() = 0;
    virtual bool es_poema() = 0;
    virtual bool es_novela() = 0;
    virtual bool es_historica() = 0;
};

#endif //TP2_LECTURA_H
