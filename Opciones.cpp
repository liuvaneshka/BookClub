//
// Created by liuvaneshka on 20/06/22.
//

#include "Opciones.h"

Opciones::Opciones(Hash tabla, Lista<Lectura*>* lista_lecturas, Cola<Lectura*>* cola_lecturas){
    this->tabla = tabla;
    this->lista_lecturas = lista_lecturas;
    this->cola_lecturas = cola_lecturas;

}

Opciones::~Opciones(){}

void Opciones::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    lista_lecturas->alta(nueva_lectura);

    cout << "\nLectura creada: " << endl;
    nueva_lectura->mostrar_lectura();
}

Lectura* Opciones::crear_lectura(){
    Lectura* nueva_lectura = nullptr;

    string titulo = printer.pedir_titulo();
    int anio = printer.pedir_anio();
    int minutos = printer.pedir_minutos();
    Escritor* escritor_lectura = crear_escritor();
    int tipo = printer.pedir_tipo();

    switch(tipo) {

        case 1:{
            int versos = printer.pedir_versos();
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro = printer.pedir_libro();
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            generos genero = printer.pedir_genero();

            if(genero == HISTORICA){
                string tema = printer.pedir_tema();
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero);
            break;
        }

        default:
            cout << ROJO << "\nDatos inválidos, intente nuevamente.\n" << endl;
    }
    return nueva_lectura;
}


void Opciones::agregar_escritor(){
    Escritor* nuevo_escritor = crear_escritor();
    cout << "\nEscritor creado:" << endl;
    nuevo_escritor->mostrar_escritor();
}

Escritor* Opciones::crear_escritor() {
    Escritor *nuevo_escritor;
    Escritor *escritor_hallado;
    string nuevo_isni;

    string nombre = printer.pedir_nombre();

    if(nombre != "ANONIMO"){
        escritor_hallado = tabla.encontrar_por_nombre(nombre);
        if (escritor_hallado != nullptr) {
            nuevo_escritor = escritor_hallado;
            cout << "Escritor existente\n" << endl;
        }
        else{
            string nacionalidad = printer.pedir_nacionalidad();
            int nacimiento = printer.pedir_nacimiento();
            int fallecimiento = printer.pedir_fallecimiento();

            nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            nuevo_isni = generar_isni();
            tabla.agregar_item(nuevo_isni, nuevo_escritor);
        }
    } else
        nuevo_escritor = nullptr;

    return nuevo_escritor;
}

string Opciones::generar_isni(){
    string isni = "" ;
    isni = printer.pedir_isni();
    isni = "(" + isni +  ")";
    std::cout << isni << std::endl;
    while(tabla.encontrar_dato(isni) != nullptr){
        isni = printer.pedir_isni();
        isni = "(" + isni +  ")";
    }
    std::cout << isni << std::endl;
    return isni;
}

void Opciones::listar_lecturas(){
    int contador = 1;
    lista_lecturas->inicializar();

    while(lista_lecturas->hay_actual()){
        cout << "Lectura numero: "<< contador << endl;
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        lectura_actual->mostrar_lectura();

        lista_lecturas->siguiente();
        contador++;
    }
}

void Opciones::listar_titulos_lecturas(){
    int contador = 1;
    lista_lecturas->inicializar();

    cout << NEGRO << "Lecturas Exitentes: " << endl;

    while(lista_lecturas->hay_actual()){
        string titulo;
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        cout << VIOLETA << lectura_actual->obtener_titulo() << "  **  ";

        lista_lecturas->siguiente();
        contador++;
    }
    cout << endl;
}

int Opciones::rastrear(string titulo){
    int indice = 1, indice_correspondiente = -1;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual() && lista_lecturas->consultar(indice)->obtener_titulo() != titulo){
        indice++;
        lista_lecturas->siguiente();
    }

    if(lista_lecturas->hay_actual())
        indice_correspondiente = indice;

    return indice_correspondiente;
}


void Opciones::quitar_lectura(){

    listar_titulos_lecturas();

    if (lista_lecturas->vacia())
        cout << ROJO << "\n No se puede eliminar ninguna lectura, la lista de lecturas está vacía.\n" << endl;

    else {
        string titulo_lectura = printer.pedir_titulo();
        int indice_a_eliminar = rastrear(titulo_lectura);

        if (indice_a_eliminar == DESCONOCIDO)
            cout << ROJO << "\nLa lectura que desea eliminar no existe, intente nuevamente.\n" << endl;

        else{

            if (cola_lecturas && !cola_lecturas->vacia())
                actualizar_cola(lista_lecturas->consultar(indice_a_eliminar));

            lista_lecturas->baja(indice_a_eliminar);
            cout << AZUL << "\nLectura eliminada con éxito!\n" << endl;
        }

    }
}

void Opciones::actualizar_cola(Lectura* lectura_eliminada){
    Cola<Lectura*>* cola_actualizada = new Cola<Lectura*>;

    while(!cola_lecturas->vacia()){
        Lectura* lectura_actual = cola_lecturas->desencolar();
        if (lectura_actual != lectura_eliminada)
            cola_actualizada -> encolar(lectura_actual);
    }
    delete cola_lecturas;
    this->cola_lecturas = cola_actualizada;
}


void Opciones::modificar_fallecimiento(){
    tabla.imprimir_tabla();
    string nombre_escritor = printer.pedir_nombre();
    Escritor* escritor_a_modificar = tabla.encontrar_por_nombre( nombre_escritor);
    int nuevo_fallecimiento = printer.pedir_fallecimiento();

    if (escritor_a_modificar == nullptr)
        cout << ROJO << "\nNo se encuentra el escritor que desea modificar, intente nuevamente.\n" << endl;

    else if (nuevo_fallecimiento == -1 || nuevo_fallecimiento > escritor_a_modificar->obtener_anio_nacimiento()){
        escritor_a_modificar -> modificar_fallecimiento(nuevo_fallecimiento);
        cout << AZUL << "\nFallecimiento actualizado con éxito!\n" << endl;
    }
    else
        cout << ROJO <<  "\nEl año de fallecimiento ingresado es inválido, intente nuevamente.\n" << endl;
}


void Opciones::sortear(){

    int num_random = rand() % lista_lecturas->obtener_tamanio() + 1;
    Lectura* lectura_random = lista_lecturas->consultar(num_random);

    cout << "Lectura sorteada: " << endl;
    lectura_random->mostrar_lectura();
}

void Opciones::listar_entre_anios(int desde, int hasta){
    int contador_lecturas = 0;

    if (desde > hasta)
        cout << "\nAños inválidos, intente nuevamente\n" << endl;

    else{
        lista_lecturas->inicializar();
        while(lista_lecturas->hay_actual()){
            Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
            int anio_lectura_actual = lectura_actual->obtener_anio();

            if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta){
                lectura_actual->mostrar_lectura();
                contador_lecturas++;
            }
            lista_lecturas->siguiente();
        }
        if(contador_lecturas == 0)
            cout << "\nNo hay lecturas entre los anios ingresados\n" << endl;
    }
}

void Opciones::listar_lecturas_entre_anios(){
    int desde = printer.pedir_anio_desde();
    int hasta = printer.pedir_anio_hasta();
    listar_entre_anios(desde, hasta);
}

void Opciones::listar_por_escritor(){

    string nombre_escritor = printer.pedir_nombre();
    bool hay_lecturas = false;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor){
            hay_lecturas = true;
            cout << '\n';
            lectura_actual->mostrar_lectura();
        }
        lista_lecturas->siguiente();
    }

    if (!hay_lecturas)
        cout << "\nNo existen lecturas escritas por el Escritor ingresado, intente nuevamente\n" << endl;
}

void Opciones::listar_novelas_de_genero(){
    generos genero = printer.pedir_genero();
    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        lectura_actual->imprimir_novela_genero(genero);
        lista_lecturas->siguiente();
    }
}


Cola<Lectura*>* Opciones::proximas_lecturas(){

    if (!cola_lecturas){
        cout << "no hay cola de lecturas " << endl;
        cola_de_lecturas();
    }

    if (!cola_lecturas->vacia()){
        cout << "no esta vacia  " << endl;
        marcar_como_leida();
    }
    else
        cout << ROJO << "\n\t\t Ya no quedan lecturas por ser leidas: " << endl;
    return  cola_lecturas;
}

void Opciones::cola_de_lecturas(){
    Lista<Lectura*>* lecturas_ordenadas = ordenar_por_minutos();
    cola_lecturas = new Cola<Lectura*>;

    lecturas_ordenadas->inicializar();
    while(lecturas_ordenadas->hay_actual()){
        Lectura* lectura_actual = lecturas_ordenadas->obtener_dato_cursor();

        cola_lecturas->encolar(lectura_actual);
        lecturas_ordenadas->siguiente();
    }
    delete lecturas_ordenadas;
}

Lista<Lectura*>* Opciones::ordenar_por_minutos(){
    Lista<Lectura*>* lecturas_ordenadas = new Lista<Lectura*>;
    int posicion_correcta;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        posicion_correcta = obtener_posicion_segun_minutos(lecturas_ordenadas, lectura_actual);

        lecturas_ordenadas->alta(lectura_actual, posicion_correcta);
        lista_lecturas->siguiente();
    }
    return lecturas_ordenadas;
}

int Opciones::obtener_posicion_segun_minutos(Lista<Lectura*>* lecturas_ordenadas, Lectura* lectura){

    int indice = 1;
    int sobrecargar = 0; //numero = 0, creado para sobrecargar el método de comparar

    if (!lecturas_ordenadas->vacia()){
        lecturas_ordenadas->inicializar();

        while(lecturas_ordenadas->hay_actual() && lectura->comparar_lecturas(lecturas_ordenadas->consultar(indice), sobrecargar) != -1){
            indice++;
            lecturas_ordenadas->siguiente();
        }
    }
    return indice;
}


void Opciones::marcar_como_leida(){
    char opcion;

    cout << VERDE << "Proxima lectura: " << endl;
    Lectura* prox_lectura = cola_lecturas->consultar();
    prox_lectura -> mostrar_lectura();

    cout << AZUL << "\nDesea marcar la lectura de la cola como leida?" << endl;
    cout << VERDE << " (S.Si / N.No): ";
    cin >> opcion;

    if (tolower(opcion) == 's'){
        if (cola_lecturas->vacia())
            cout << ROJO << "\nYa no quedan lecturas por ser leidas.\n" << endl;
        else {
            cola_lecturas->desencolar();
            cout << AZUL << "\nLectura leida con éxito.\n" << endl;
        }
    }
    else if(tolower(opcion) == 'n')
        cout << AZUL << "\nElija otra opcion del menu.\n" << endl;
    else
        cout << ROJO << "\nIngreso inválido, intente nuevamente.\n" << endl;
}


