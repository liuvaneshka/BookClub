#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <iostream>
using namespace std;

//Programa
enum generos {DRAMA = 1, COMEDIA, FICCION, SUSPENSO,
              TERROR, ROMANTICA, HISTORICA};

const std::string POEMA = "P";
const std::string NOVELA = "N";
const std::string CUENTO = "C";
const std::string N_HISTORICA = "H";

const int DESCONOCIDO = -1;

//Nombres archivos
const string ARCHIVO_LECTURAS = "Lecturas.txt";
const string ARCHIVO_ESCRITORES = "Autores.txt";

//Opciones
const string OPCIONES [] = {"Agregar una nueva lectura",
                          "Quitar lectura",
                          "Agregar un escritor",
                          "Actualizar fallecimiento autor",
                          "Listar los escritores",
                          "Sortear una lectura",
                          "Listar lecturas",
                          "Listar lecturas por anio",
                          "Listar lecturas por escritor",
                          "Listar Novelas por genero",
                          "Listar proximas lecturas",
                          "Tiempo mínimo de lectura",
                          "Salir"};

const int CANT_OPCIONES = 13;

//Colores
const string NEGRO = "\e[1;30m";
const string ROJO = "\e[1;31m";
const string AZUL = "\e[1;34m";
const string VERDE = "\e[1;32m";
const string AMARILLO = "\e[1;33m";
const string VIOLETA = "\e[1;35m";



//-------------- TP3 ------------------

// Hash
const int N = 25; // lambda = 0.8, lambda = clave/n un numero primo al menos 1.3 veces mas de las claves

// Tiempo entre lecturas
const int CUENTO_CUENTO = 8;
const int POEMA_POEMA = 1;
const int NOVELA_NOVELA = 30;
const int HISTORICA_HISTORICA = 80;
const int CUENTO_POEMA = 0;
const int CUENTO_NOVELA = 10;
const int CUENTO_HISTORICA = 15;
const int POEMA_NOVELA = 5;
const int POEMA_HISTÓRICA = 20;
const int HISTORICA_NOVELA = 60;

// Constantes para el grafo
const int INFINITO = 9999999;
//const int POSICION_NO_ENCONTRADA = -1;      // Verificacion innecesaria ya que el grafo se crea automaticamente ...

#endif // __CONSTANTES_H__
