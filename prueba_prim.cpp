#include "Grafo.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Poema.h"
#include "Cuento.h"
/*
int main(){

    // Creo objetos necesarios
    Escritor autor1("José Martinez", "Argentino", 1920, 2000);
    Escritor autor2("Julia Rossenwasser", "Alemana", 1995, -1);
    Escritor autor3("Donato Di Santis ", "Italiano", -1, 2000);
    Escritor autor4("Tamara Sosa ", "¿?", 1890, 1940);

    Lectura* p1 = new Poema("el gran amor", nullptr, 2000, 3, 10);
    Lectura* nh1 = new Novela_historica("El cruce", &autor1, 1950, 3000, "El cruce de los andes de San Martin");
    Lectura* c1 = new Cuento("el flautista", &autor1, 1989, 1000, "libro de cuentos");
    Lectura* n1 = new Novela("el fantasma", &autor1, 1960, 1000, TERROR);

    // Creo un grafo manualmente
    Grafo grafo;
    grafo.agregar_vertice(p1);
    grafo.agregar_vertice(nh1);
    grafo.agregar_vertice(c1);
    grafo.agregar_vertice(n1);

    // (vertice_uno, vetice_dos, peso_arista)
    grafo.agregar_camino(p1, nh1, 8);
    grafo.agregar_camino(c1, nh1, 7);
    grafo.agregar_camino(nh1, n1, 5);
    grafo.agregar_camino(c1, n1, 1);
    grafo.agregar_camino(c1, p1, 1);
    grafo.agregar_camino(p1, n1, 5);

    // Se muestra matriz de adyacencia
    grafo.mostrar_grafo();

    // Devuelve caminos y minutos de lectura
    grafo.arbol_expansion();

    return 0;
}
*/

