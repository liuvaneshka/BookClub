#include "Novela.h"

Novela::Novela(string titulo, Escritor *escritor, int anio, int minutos, generos genero)
                : Lectura(titulo, escritor, anio, minutos){
    this -> genero = genero;
}

Novela::~Novela(){}

generos Novela::obtener_genero(){
    return genero;
}

void Novela::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Género: " << string_genero(obtener_genero()) << "\n" << endl;
}

string Novela::string_genero(generos genero){
    string cadena_genero;
    switch(genero){
        case 1:
            cadena_genero = "DRAMA"; break;
        case 2:
            cadena_genero = "COMEDIA";break;
        case 3:
            cadena_genero = "FICCION"; break;
        case 4:
            cadena_genero = "SUSPENSO"; break;
        case 5:
            cadena_genero = "TERROR"; break;
        case 6:
            cadena_genero = "ROMANTICA"; break;
        case 7:
            cadena_genero = "HISTORICA"; break;
    }
    return cadena_genero;
}

string Novela::obtener_tipo(){
    return NOVELA;
}

int Novela::imprimir_novela_genero(generos genero){
    int contador = 0;
    if (genero == obtener_genero()){
        contador += 1;
        mostrar_lectura();
    }
    return contador;
}

bool Novela::es_novela(){return true;}
bool Novela::es_poema(){return false;}
bool Novela::es_historica(){return false;}
bool Novela::es_cuento(){return false;}
