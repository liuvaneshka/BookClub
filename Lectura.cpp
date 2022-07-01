#include "Lectura.h"

Lectura::Lectura(string titulo, Escritor * escritor, int anio, int minutos){
    this->titulo = titulo;
    this->anio = anio;
    this->minutos = minutos;
    this->escritor = escritor;
    this->leida = NO_LEIDA;
}
Lectura::~Lectura(){}

int Lectura::obtener_anio() {
    return anio;
}

int Lectura::obtener_minutos() {
    return minutos;
}

string Lectura::obtener_titulo() {
    return titulo;
}

Escritor *Lectura::obtener_escritor() {
    return escritor;
}

void Lectura::modificar_escritor(Escritor* escritor){
    this->escritor = escritor;
}

bool Lectura::lectura_leida(){
    return leida;
}

void Lectura::leer(){
    leida = LEIDA;
}

int Lectura::comparar_lecturas(Lectura *lectura) {
    int valor;

    if(obtener_anio() < lectura->obtener_anio())
        valor = -1;
    else if(obtener_anio() > lectura->obtener_anio())
        valor = 1;
    else
        valor = 0;
    return valor;
}

int Lectura::comparar_lecturas(Lectura* lectura, int sobrecargar){
    int valor;

    if(obtener_minutos() < lectura->obtener_minutos())
        valor = -1;
    else if(obtener_minutos() > lectura->obtener_minutos())
        valor = 1;
    else
        valor = 0;
    return valor;
}

void Lectura::mostrar_lectura() {
    cout << "Titulo: " << obtener_titulo() << endl;
    if (escritor)
        cout << "Escritor: " << obtener_escritor() -> obtener_nombre() << endl;
    else
        cout << "Escritor: Desconocido" << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Anio: " << obtener_anio() << endl;
}
