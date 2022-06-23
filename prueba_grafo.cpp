#include "Grafo.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Poema.h"
#include "Cuento.h"
#include "Grafo_lecturas.h"

int main(){

    Escritor autor1("José Martinez", "Argentino", 1920, 2000);
    Escritor autor2("Julia Rossenwasser", "Alemana", 1995, -1);
    Escritor autor3("Donato Di Santis ", "Italiano", -1, 2000);
    Escritor autor4("Tamara Sosa ", "¿?", 1890, 1940);

    Lista<Lectura*> lista_lec;
    Lectura* p1 = new Poema("el gran amor", nullptr, 2000, 3, 10);
    lista_lec.alta(p1);

    Lectura* nh1 = new Novela_historica("El cruce", &autor1, 1950, 3000, "El cruce de los andes de San Martin");
    lista_lec.alta(nh1);

    Lectura* c1 = new Cuento("el flautista", &autor1, 1989, 1000, "libro de cuentos");
    lista_lec.alta(c1);

    Lectura* n1 = new Novela("el fantasma", &autor1, 1960, 1000, TERROR);
    lista_lec.alta(n1);

    // Se crea el grafo de lecturas en base a la lista
    Grafo_lecturas grafo_lec(&lista_lec);
    grafo_lec.mostrar_grafo();

    return 0;
}


