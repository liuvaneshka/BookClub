#include "Impresor.h"

int Impresor::pedir_opcion(){
    string opcion;
    cout << VIOLETA << "\n\t\tIngresar opcion: ";
    cin >> opcion;
    return atoi(opcion.c_str());
}

string Impresor::pedir_titulo(){
    string titulo;
    cout << NEGRO << "Ingrese el título de la lectura: ";
    cin.ignore();
    getline(cin, titulo);
    return titulo;
}


int Impresor::pedir_anio(){
    int anio;
    cout << NEGRO << "Ingrese el anio de publicacion de la lectura: ";
    cin >> anio;
    return anio;
}

int Impresor::pedir_minutos(){
    int minutos;
    cout << "Ingrese minutos promedio de lectura: ";
    cin >> minutos;
    return minutos;
}

int Impresor::pedir_tipo(){
    int tipo;
    cout << NEGRO << "Ingrese el numero de la lectura que deseas crear ";
    cout << AMARILLO << "(1. POEMA / 2. CUENTO / 3. NOVELA): ";
    cin >> tipo;
    return tipo;
}

int Impresor::pedir_versos(){
    int versos;
    cout << VERDE << "Ingrese la cantidad de versos del poema: ";
    cin >> versos;
    return versos;
}

string Impresor::pedir_libro(){
    string libro;
    cout << "Ingrese el titulo del libro: ";
    cin.ignore();
    getline(cin, libro);
    return libro;
}

generos Impresor::pedir_genero(){
    int genero;
    cout << "Ingrese el género de la novela (numero entero) " << endl;
    cout << AMARILLO << "(1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): "<< endl;
    cin >> genero;
    while(genero > 7 || genero < 1){
        cout << ROJO << "Dato incorrecto! Ingrese un genero valido" << endl;
        cout << AMARILLO << "(1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): "<< endl;
        cin >> genero;
    }
    return (generos) genero;
}


string Impresor::pedir_tema(){
    string tema;
    cout << NEGRO << "Ingrese el tema de la novela histórica: ";
    cin.ignore();
    getline(cin, tema);
    return tema;
}

string Impresor::pedir_isni(){
    string isni;
    cout << AZUL << "Ingrese isni del escritor: ";
    cin.ignore();
    getline(cin, isni);
    return isni;
}

string Impresor::pedir_isni(int sobrecargar){
    string isni;
    cout << AZUL << "Ingrese isni del escritor (Ingrese 0 si es ANONIMO): ";
    cin.ignore();
    getline(cin, isni);
    return isni;
}

string Impresor::pedir_nombre(){
    string nombre;
    cout << AZUL << "Ingrese el nombre del escritor: ";
    getline(cin, nombre);
    return nombre;
}

string Impresor::pedir_nombre_escritor(){
    string nombre;
    cout << AZUL << "Ingrese el nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre);
    return nombre;
}

string Impresor::pedir_nacionalidad(){
    string nacionalidad;
    cout << AZUL << "Ingrese la nacionalidad: " << endl;
    cout << VERDE << " (si es desconocida, ingrese ¿?): ";
    cin >> nacionalidad;
    return nacionalidad;
}

int Impresor::pedir_nacimiento(){
    int nacimiento;
    cout << AZUL << "Ingrese el año de nacimiento: " << endl;
    cout << VERDE << " (si es desconocida, ingrese -1): ";
    cin >> nacimiento;
    return nacimiento;
}

int Impresor::pedir_fallecimiento(){
    int fallecimiento;
    cout << AZUL << "Ingrese el año de fallecimiento: " << endl;
    cout << VERDE << "(si es desconocida o continua vivo, ingrese -1): ";
    cin >> fallecimiento;
    return fallecimiento;
}

int Impresor::pedir_anio_desde(){
    int desde;
    cout << VERDE << "Ingrese el año DESDE el cual desea listar las lecturas: ";
    cin >> desde;
    return desde;
}

int Impresor::pedir_anio_hasta(){
    int hasta;
    cout << VERDE << "Ingrese el año HASTA el cual desea listar las lecturas: ";
    cin >> hasta;
    cout << '\n';
    return hasta;
}


char Impresor::opcion_leer(){
    char opcion;
    cout << AZUL << "\nDesea marcar la lectura de la cola como leida?" << endl;
    cout << VERDE << " (S.Si / N.No): ";
    cin >> opcion;
    return opcion;
}

char Impresor::seguir_listando(){
    char opcion;
    cout << AZUL << "\n Desea seguir listando Lecturas?" << endl;
    cout << VERDE << " (S.Si / N.No): ";
    cin >> opcion;
    return opcion;
}
