#ifndef __LISTA_ESCRITORES_H__
#define __LISTA_ESCRITORES_H__
#include "Lista.h"
#include "Escritor.h"
#include "CONSTANTES.h"

class Lista_escritores : public Lista<Escritor*> {

private:
    Lista<Escritor*>* lista_escritores;

public:
    //PRE: -
    //POS: Construye una Lista de Escritores vacia.
    Lista_escritores();

    //PRE: El objeto Lista de Escritores debe ser un objeto válido.
    //POS: Destruye la lista de escritores.
    ~Lista_escritores();

    //PRE: vacia() = false
    //POS: Muestra la informacion de los escritores que pertenecen a la lista.
    void listar();

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista.
    void listar_nombres_escritores();

    //PRE: El escritor hallado debe ser un objeto valido.
    //POS: Devuelve el escritor cuyo nombre se busca en la lista.
    Escritor* rastrear(string nombre_escritor);
};

#endif // __LISTA_ESCRITORES_H__
