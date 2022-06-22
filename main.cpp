#include "Grafo.h"

//!NOTAS:
// El dato de los vertices es un entero para poder probar como devuelve la suma total del tiempo de lectura.

// Uso la Lista que dieron en clase, no la nuestra que utilizamos en el tp2Ç
    // Habria que verificar 1. Si es posible adaptarla y usar una sola
    //                      2. Como adpatarla para que funcione tanto con objetos de tipo Lectura* y objeto de tipo Vertice

// Verificar que es lo que se debe mostrar por pantalla al obtener el mst
    // Por el momento, lo que yo hice fue imprimir el tiempo total (tiempo de cada lectura (vertice) + tiempo entre lecturas(arista))

// Agregar a archivo CONSTANTES.h -> INFINITO, POSICION_NO_ENCONTRADA, NOMBRE_NO_ENCONTRADO

// Adaptar la clase Vértice, Grafo y Pfrim, teniendo en cuenta que los datos seran del tipo Lectura*

int main(){
    Grafo grafo;

    grafo.agregar_vertice(1);
    grafo.agregar_vertice(3);
    grafo.agregar_vertice(6);
    grafo.agregar_vertice(9);
    grafo.agregar_vertice(5);

    //(vertice_uno, vetice_dos, peso_arista)
    grafo.agregar_camino(1, 6, 8);
    grafo.agregar_camino(6, 3, 7);
    grafo.agregar_camino(6, 9, 5);
    grafo.agregar_camino(9, 3, 1);
    grafo.agregar_camino(5, 1, 1);
    grafo.agregar_camino(5, 9, 5);

    grafo.mostrar_grafo();

    grafo.arbol_expansion();

    return 0;
}
