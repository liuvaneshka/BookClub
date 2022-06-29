#include "Opciones.h"

Opciones::Opciones(Hash<string, Escritor*> *tabla, Lista_lecturas* lista_lecturas, Cola<Lectura*>* cola_lecturas, Grafo_lecturas* grafo_lecturas){

    this->tabla = tabla;
    this->lista_lecturas = lista_lecturas;
    this->cola_lecturas = cola_lecturas;
    this->grafo_lecturas = grafo_lecturas;
}

Opciones::~Opciones(){
    delete grafo_lecturas;
    grafo_lecturas = nullptr;
}

void Opciones::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    lista_lecturas->alta(nueva_lectura);

    cout << LECTURA_CREADA << endl;
    nueva_lectura->mostrar_lectura();
}

Lectura* Opciones::crear_lectura(){
    Lectura* nueva_lectura = nullptr;
    string titulo = impresor.pedir_titulo();
    int anio = impresor.pedir_anio();
    int minutos = impresor.pedir_minutos();
    Escritor* escritor_lectura = crear_escritor();
    int tipo = impresor.pedir_tipo();

    switch(tipo) {

        case 1:{
            int versos = impresor.pedir_versos();
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro = impresor.pedir_libro();
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            generos genero = impresor.pedir_genero();

            if(genero == HISTORICA){
                string tema = impresor.pedir_tema();
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero);
            break;
        }

        default:
            cout << ROJO << INGRESO_INVALIDO << endl;
    }
    return nueva_lectura;
}


void Opciones::agregar_escritor(){
    Escritor* nuevo_escritor = crear_escritor();
    cout << ESCRITOR_CREADO << endl;
    nuevo_escritor->mostrar_escritor();
}

Escritor* Opciones::crear_escritor() {
    Escritor *nuevo_escritor;
    Escritor *escritor_hallado;

    string nuevo_isni;
    nuevo_isni = impresor.pedir_isni();
    nuevo_isni = "(" + nuevo_isni +  ")";

    if(nuevo_isni != "(0)"){
        escritor_hallado = tabla->encontrar_dato(nuevo_isni);
        if (escritor_hallado != nullptr) {
            nuevo_escritor = escritor_hallado;
            cout << ESCRITOR_EXISTENTE << endl;
        }
        else{
            string nombre = impresor.pedir_nombre();
            string nacionalidad = impresor.pedir_nacionalidad();
            int nacimiento = impresor.pedir_nacimiento();
            int fallecimiento = impresor.pedir_fallecimiento();

            nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            tabla->agregar_lista(nuevo_isni, nuevo_escritor);
            //tabla->imprimir_tabla(LLAVE);
        }
    } else
        nuevo_escritor = nullptr;

    return nuevo_escritor;
}

void Opciones::listar_lecturas(){
    lista_lecturas->listar();
}

void Opciones::listar_escritores(){
    tabla->imprimir_tabla(VALOR);
}

void Opciones::quitar_lectura(){

    lista_lecturas->listar_titulos_lecturas();

    if (lista_lecturas->vacia())
        cout << ROJO << LISTA_VACIA << endl;

    else {
        string titulo_lectura = impresor.pedir_titulo();
        int indice_a_eliminar = lista_lecturas->rastrear(titulo_lectura);

        if (indice_a_eliminar == DESCONOCIDO)
            cout << ROJO << LECTURA_INEXISTENTE << endl;

        else{

            if (cola_lecturas && !cola_lecturas->vacia())
                actualizar_cola(lista_lecturas->consultar(indice_a_eliminar));
            cout << "Lista lecturas " << lista_lecturas->obtener_dato_cursor() << endl;
            Lectura * eliminar =  lista_lecturas->consultar(indice_a_eliminar);
            delete eliminar;

            lista_lecturas->baja(indice_a_eliminar);
            cout << AZUL << ELIMINACION_EXITOSA << endl;
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
    tabla->imprimir_tabla(LLAVE);
    string isni = impresor.pedir_isni();
    isni = "(" + isni + ")";

    Escritor* escritor_a_modificar = tabla->encontrar_dato(isni);
    cout << AVISO_FALLECIMIENTO_VALIDO << escritor_a_modificar->obtener_anio_nacimiento() << endl;
    int nuevo_fallecimiento = impresor.pedir_fallecimiento();

    if (escritor_a_modificar == nullptr)
        cout << ROJO << ESCRITOR_INEXISTENTE << endl;

    else if (nuevo_fallecimiento == -1 || nuevo_fallecimiento > escritor_a_modificar->obtener_anio_nacimiento()){

        escritor_a_modificar -> modificar_fallecimiento(nuevo_fallecimiento);
        cout << AZUL << ACTUALIZACION_EXITOSA << endl;
    }
    else
        cout << ROJO << INGRESO_INVALIDO << endl;
}

void Opciones::sortear(){
    lista_lecturas->sortear();
}

void Opciones::listar_lecturas_entre_anios(){
    char opcion = SI;

    while(opcion == SI){
        int desde = impresor.pedir_anio_desde();
        int hasta = impresor.pedir_anio_hasta();
        lista_lecturas->listar_entre_anios(desde, hasta);
        opcion = impresor.seguir_listando();
    }

    if (opcion != NO)
        cout << ROJO << INGRESO_INVALIDO << endl;
}

void Opciones::listar_por_escritor(){
    char opcion = SI;
    tabla->imprimir_tabla(NOMBRE);
    while(opcion == SI){
        string nombre_escritor = impresor.pedir_nombre_escritor();
        lista_lecturas->listar_por_escritor(nombre_escritor);
        opcion = impresor.seguir_listando();
    }

    if (opcion != NO)
        cout << ROJO << INGRESO_INVALIDO << endl;
}

void Opciones::listar_novelas_de_genero(){
    char opcion = SI;

    while(opcion == SI){
        generos genero = impresor.pedir_genero();
        lista_lecturas->listar_por_genero(genero);
        opcion = impresor.seguir_listando();
    }

    if (opcion != NO)
        cout << ROJO << INGRESO_INVALIDO << endl;
}


Cola<Lectura*>* Opciones::proximas_lecturas(){

    if (!cola_lecturas){
        cola_de_lecturas();
    }

    if (!cola_lecturas->vacia()){
        marcar_como_leida();
    }
    else
        cout << ROJO << NO_QUEDAN_LECTURAS << endl;
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

int Opciones::obtener_posicion_segun_minutos(Lista<Lectura*>*  lecturas_ordenadas, Lectura* lectura){

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

    cout << VERDE << PROXIMA << endl;
    Lectura* prox_lectura = cola_lecturas->consultar();
    prox_lectura -> mostrar_lectura();

    opcion = impresor.opcion_leer();

    if (tolower(opcion) == SI){
        if (cola_lecturas->vacia())
            cout << ROJO << NO_QUEDAN_LECTURAS << endl;
        else {
            cola_lecturas->desencolar();
            cout << AZUL << LECTURA_EXITOSA << endl;
        }
    }
    else if(tolower(opcion) == NO)
        cout << AZUL << ELEGIR_NUEVA_OPCION << endl;
    else
        cout << ROJO << INGRESO_INVALIDO << endl;
}

void Opciones::tiempo_minimo(){
    delete grafo_lecturas;
    grafo_lecturas = nullptr;
    grafo_lecturas = new Grafo_lecturas(lista_lecturas);
    grafo_lecturas->arbol_expansion();
}

