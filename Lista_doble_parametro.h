//
// Created by liuvaneshka on 28/06/22.
//

#ifndef _LISTA_DOBLE_PARAMETRO_H
#define _LISTA_DOBLE_PARAMETRO_H

template <class T1, class T2>
class Lista_doble_parametro{

public:
    T1 llave;
    T2 valor;
    Lista_doble_parametro * siguiente;

    //PRE: La lista debe contener dos parametros validos
    //POST: Construye el objeto lista doble parametro.
    Lista_doble_parametro(T1 llave, T2 valor);

    //PRE: -
    //POST: Devuelve la llave.
    T1 obtener_llave();

    //PRE: -
    //POST: Devuelve el valor.
    T2 obtener_valor();

    //PRE: -
    //POST: Devuelve el siguiente.
    Lista_doble_parametro* obtener_siguiente(){
        return siguiente;
    }
};

template <class T1, class T2>
Lista_doble_parametro <T1, T2> :: Lista_doble_parametro(T1 llave, T2 valor){
    this->llave = llave;
    this->valor = valor;
    this->siguiente = nullptr;
}

template <class T1, class T2>
T1 Lista_doble_parametro<T1, T2>:: obtener_llave(){
    return llave;
}
template <class T1, class T2>
T2 Lista_doble_parametro<T1, T2>::obtener_valor(){
    return valor;
}

#endif //_LISTA_DOBLE_PARAMETRO_H
