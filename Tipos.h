#ifndef Tipos
#define Tipos

#include <iostream>

using namespace std;

//Definición de tipos de datos:
struct CoordenadasGPS
{
    int latitud[3];
    int longitud[3];
};

struct Paquete
{
    string idPaquete;
    CoordenadasGPS coordenadas;
    string NIF;
    int numCP;
};


//Lista
class NodoLista
{
private:
    Paquete paquete;
    NodoLista *siguiente;
    friend class Lista;
public:
    NodoLista(Paquete p, NodoLista *sig = NULL)
    {
        paquete= p;
        siguiente = sig;
    }
};
typedef NodoLista *pnodolista;

class Lista
{
private:
    pnodolista cabeza, actual, final;
public:
    Lista()
    {
        cabeza = actual = final = NULL;
    }
    ~Lista();
    void insertarNodo(Paquete p);
    void insertarNodoIntermedio(Paquete p, int posicion);
    void borrarNodo(Paquete p);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    int paqueteActual();
    void recorrerLista();
};
struct CP
{
    int numCP;
    string localidad;
    Lista listaPaq;
};

class NodoArbol {
    private:
        // Miembros:
        CP centralP;
        NodoArbol *izquierdo;
        NodoArbol *derecho;
        friend class Arbol;

    public:
        // Constructor:
        NodoArbol(CP cp, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
        centralP(cp), izquierdo(izq), derecho(der) {}
};
typedef NodoArbol *pNodoArbol;

class Arbol {
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        pNodoArbol raiz;
        pNodoArbol actual;
        int contador;
        int altura;

    public:
        // Constructor y destructor básicos:
        Arbol() : raiz(NULL), actual(NULL) {}
        ~Arbol() { Podar(raiz); }
        // Insertar en árbol ordenado:
        void Insertar(CP cp);
        // Borrar un elemento del árbol:
        void Borrar(CP cp);
        // Función de búsqueda:
        bool Buscar(CP cp);
        // Comprobar si el árbol está vacío:
        bool Vacio(pNodoArbol r) { return r==NULL; }
        // Comprobar si es un nodo hoja:
        bool EsHoja(Arbol r) { return !r->derecho && !r->izquierdo; }
        // Contar número de nodos:
        const int NumeroNodos();
        const int AlturaArbol();
        // Calcular altura de un int:
        int Altura(const int dat);
        // Devolver referencia al int del nodo actual:
        CP CpActual() { return actual->centralP; } //&ValorActual()
        // Moverse al nodo raiz:
        void Raiz() { actual = raiz; }
        // Aplicar una función a cada elemento del árbol:
        void InOrden(void (*func)(int&) , pNodoArbol nodo=NULL, bool r=true);
        void PreOrden(void (*func)(int&) , pNodoArbol nodo=NULL, bool r=true);
        void PostOrden(void (*func)(int&) , pNodoArbol nodo=NULL, bool r=true);
        private:
        // Funciones auxiliares
        void Podar(pNodoArbol &nodo);
        void auxContador(pNodoArbol nodo);
        void auxAltura(pNodoArbol nodo, int alt);
};

void Mostrar(int&);
void generarArbol(Arbol&);

#endif
