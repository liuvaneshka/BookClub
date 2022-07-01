#ifndef __PARSER_H__
#define __PARSER_H__

#include "Lectura.h"
#include "Escritor.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Cuento.h"
#include "Poema.h"
#include "Archivo.h"

#include "Hash.h"
//Para las listas
#include "Lista.h"
#include "Lista_lecturas.h"

#include "Hash.h"

#include <sstream>
using namespace std;

class Parser{

private:

    Archivo entrada(string ruta);


    //PRE: linea_genero es una linea leida del archivo de Lecturas.
    //POST: Devuelve el genero del enumerado asociado.
    generos obtener_genero(string linea_genero);

    //PRE: lectura debe ser un objeto válido.
    //POST: Almacena en la lista_lecturas la lectura en orden según el año de publicacion, de manera creciente.
    void almacenar_lectura(Lectura* lectura,Lista_lecturas*lista_lectura);

    //PRE: linea es una linea leida del archivo de Lecturas.
    //POST: Devuelve true si se conoce al escritor de la lectura, false en caso contrario.
    bool verificar_escritor(string linea_escritor);

    //PRE: linea es una linea leida del archivo de Lecturas.
    //POST: Devuelve el escritor, de no existir, devueleve nullptr.
    Escritor* obtener_escritor(string linea, Hash<string, Escritor*>* tabla);

public:

    //PRE: ruta debe ser una ruta válida.
    //POST: Lee el archivo de escritores, crea los objetos y los almacena en lista_escritores.
    Hash<string, Escritor*>* procesar_escritor(string ruta,Hash<string, Escritor*>* tabla);

    //PRE: ruta debe ser una ruta válida.
    //POST: Lee el archivo de lecturas, crea los objetos y los almacena en lista_lecturas.
    Lista_lecturas* procesar_lectura(string ruta,  Lista_lecturas *lista_lectura, Hash<string, Escritor*>* tabla);

};
#endif // __PARSER_H__
