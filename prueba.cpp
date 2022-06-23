#include "Grafo.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Poema.h"
#include "Cuento.h"
#include "Grafo_lecturas.h"

int main(){

    // PRUEBA GENERAL
    Escritor autor1("José Martinez", "Argentino", 1920, 2000);
    Escritor autor2("Julia Rossenwasser", "Alemana", 1995, -1);
    Escritor autor3("Donato Di Santis ", "Italiano", -1, 2000);
    Escritor autor4("Tamara Sosa ", "¿?", 1890, 1940);

    Lista<Lectura*> lista_lec;
    Lectura* p1 = new Poema("el gran amor", nullptr, 2000, 3, 10);
    lista_lec.alta(p1);

    Lectura* nh1 = new Novela_historica("El cruce", &autor1, 1950, 3000, "El cruce de los andes de San Martin");
    lista_lec.alta(nh1);

    Lectura* c1 = new Cuento("el flautista", &autor2, 1989, 1000, "libro de cuentos");
    lista_lec.alta(c1);

    Lectura* n1 = new Novela("el fantasma", &autor4, 1960, 1000, TERROR);
    lista_lec.alta(n1);

    // Se crea el grafo de lecturas en base a la lista
    Grafo_lecturas grafo_lec(&lista_lec);

    // Muestro el grafo final
    grafo_lec.mostrar_grafo();

    // Creo el mst en base al grafo
    grafo_lec.arbol_expansion();


    // PRUEBA 2 -> agrego elemento
    Lectura* p2 = new Poema("jaja", &autor3, 1999, 1, 5);
    lista_lec.alta(p2);

    // Creo el nuevo grafo
    Grafo_lecturas grafo_lec_mas(&lista_lec);
    grafo_lec_mas.mostrar_grafo();
    grafo_lec_mas.arbol_expansion();


    // PRUEBA 3 -> Eliminos dos elementos
    lista_lec.baja(1);
    lista_lec.baja(1);
    lista_lec.baja(1);

    Grafo_lecturas grafo_lec_menos(&lista_lec);
    grafo_lec_menos.mostrar_grafo();
    grafo_lec_menos.arbol_expansion();


    // PRUEBA 4 -> lista de un elemento
    Lista<Lectura*> lista_lec_dos;
    Lectura* c2 = new Cuento("casa", &autor1, 1900, 990, "el ayer");
    lista_lec_dos.alta(c2);

    Grafo_lecturas grafo_lec_uno(&lista_lec_dos);
    grafo_lec_uno.mostrar_grafo();
    grafo_lec_uno.arbol_expansion();


    // PRUEBA 5 -> sin elementos
    lista_lec_dos.baja(1);

    Grafo_lecturas grafo_lec_cero(&lista_lec_dos);
    grafo_lec_cero.mostrar_grafo();
    grafo_lec_cero.arbol_expansion();

    return 0;
}