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
const std::string _HISTORICA = "H";

const int DESCONOCIDO = -1;

//Nombres archivos
const string ARCHIVO_LECTURAS = "Lecturas.txt";
const string ARCHIVO_ESCRITORES = "Autores.txt";

//Opciones del menú
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
                          "Salir"
                          };

const int CANT_OPCIONES = 13;

//Mensajes / Opciones
const char SI = 's';
const char NO = 'n';
const string INGRESO_INVALIDO = "\nIngreso inválido, intente nuevamente.\n";
const string NO_QUEDAN_LECTURAS = "\nYa no quedan lecturas por ser leidas.\n";
const string LISTA_VACIA = "\n No se puede eliminar ninguna lectura, la lista de lecturas está vacía.\n";
const string LECTURA_INEXISTENTE = "\nLa lectura que desea eliminar no existe, intente nuevamente.\n";
const string ESCRITOR_INEXISTENTE = "\nNo se encuentra el escritor que desea modificar, intente nuevamente.\n";
const string ESCRITOR_EXISTENTE = "Escritor existente\n";
const string ACTUALIZACION_EXITOSA = "\nFallecimiento actualizado con éxito!\n";
const string ELIMINACION_EXITOSA = "\nLectura eliminada con éxito!\n";
const string LECTURA_EXITOSA = "\nLectura leida con éxito.\n";
const string ELEGIR_NUEVA_OPCION = "\nElija otra opcion del menu.\n";
const string PROXIMA = "Proxima lectura: ";
const string LECTURA_CREADA = "\nLectura creada: ";
const string ESCRITOR_CREADO = "\nEscritor creado:";
const string ERROR_POR_ANIOS = "\nNo hay lecturas entre los anios ingresados\n";
const string ERROR_POR_ESCRITOR = "\nNo existen lecturas escritas por el Escritor ingresado, intente nuevamente\n";
const string ERROR_POR_GENERO = "\nNo existen lecturas del género especificado, intente nuevamente.\n";
const string ANIOS_INVALIDOS = "\nAños inválidos, intente nuevamente\n";

//Colores
const string NEGRO = "\e[1;30m";
const string ROJO = "\e[1;31m";
const string AZUL = "\e[1;34m";
const string VERDE = "\e[1;32m";
const string AMARILLO = "\e[1;33m";
const string VIOLETA = "\e[1;35m";

// TP3 //

const string ANONIMO = "0";
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
const int POEMA_HISTORICA = 20;
const int HISTORICA_NOVELA = 60;

// Constantes para el grafo
const int INFINITO = 9999999;

#endif // __CONSTANTES_H__
