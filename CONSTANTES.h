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
                          "Eliminar escritor",
                          "Salir"
                          };

const int CANT_OPCIONES = 14;

//Mensajes
const string INGRESO_INVALIDO = "\nIngreso inválido, intente nuevamente.\n";
const string NO_QUEDAN_LECTURAS = "\nYa no quedan lecturas por ser leidas.\n";
const string LISTA_VACIA = "\n No se puede eliminar ninguna lectura, la lista de lecturas está vacía.\n";
const string LECTURA_INEXISTENTE = "\nLa lectura que desea eliminar no existe, intente nuevamente.\n";
const string ESCRITOR_INEXISTENTE = "\nNo existe el escritor, intente nuevamente.\n";
const string ESCRITOR_EXISTENTE = "Escritor existente";
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
const string AVISO_FALLECIMIENTO_VALIDO = "El fallecimiento debe ser después del anio de nacimiento: ";
const string ESCRITOR_ELIMINADO = "\n Escritor eliminado con éxito!\n";
const string ELIMINACION_ERRONEA = "\n No es posible eliminar un escritor anónimo, intente nuevamente.\n";
const string ESCRITOR_INVALIDO = "\n No es posible crear un escritor anónimo, intente nuevamente.\n";

// Opciones
const char SI = 's';
const char NO = 'n';
const string CASO_1 = "Caso 1: Agregar una nueva lectura";
const string CASO_2 = "Caso 2: Quitar lectura";
const string CASO_3 = "Caso 3: Agregar un escritor";
const string CASO_4 = "Caso 4: Actualizar fallecimiento autor";
const string CASO_5 = "Caso 5: Listar los escritores";
const string CASO_6 = "Caso 6: Sortear una lectura";
const string CASO_7 = "Caso 7: Listar lecturas";
const string CASO_8 = "Caso 8: Listar lecturas por anio";
const string CASO_9 = "Caso 9: Listar lecturas por escritor";
const string CASO_10 = "Caso 10: Listar Novelas por genero";
const string CASO_11 = "Caso 11: Listar proximas lecturas";
const string CASO_12 = "Caso 12: Tiempo mínimo de lectura";
const string CASO_13 = "Caso 13: Eliminar un escritor";
const string DESPEDIDA = "\n\t\t\tCordial despedida\n";
const string OPCION_INVALIDA = "\nError elige otra opcion valida\n";

//Colores
const string NEGRO = "\e[1;30m";
const string ROJO = "\e[1;31m";
const string AZUL = "\e[1;34m";
const string VERDE = "\e[1;32m";
const string AMARILLO = "\e[1;33m";
const string VIOLETA = "\e[1;35m";

// Tabala de Hash
const string ANONIMO = "0";
const int N = 25; // lambda = 0.8, lambda = clave/n un numero primo al menos 1.3 veces mas de las claves

//Constantes imprimir tabla
const int VALOR = 1;
const int LLAVE = 2;
const int NOMBRE = 3;

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

// Atributo de leida de lecturas
const bool NO_LEIDA = false;
const bool LEIDA = true;

#endif // __CONSTANTES_H__
