

#include<iostream>

#include "NodoABB.h"

#ifndef ABB_ABB_H
#define ABB_ABB_H

using namespace std;

template <class T>
class ABB
{
private:

    // atributos
    NodoABB<T>* raiz;

    // metodos
    NodoABB<T>* insertar(NodoABB<T>* nodo, string dato, T* valor);
    void imprimir_en_orden(NodoABB<T> * nodo);
    NodoABB<T>* buscar(NodoABB<T>* nodo, string dato);
    T buscar_min(NodoABB<T>* nodo);
    T buscar_max(NodoABB<T>* nodo);
    T sucesor(NodoABB<T>* nodo);
    T predecesor(NodoABB<T>* nodo);
    NodoABB<T>* eliminar(NodoABB<T>* nodo, string dato);
    void eliminar_todo(NodoABB<T>* nodo);

public:

    // Post: Crea un arbol vacio
    ABB();

    // Post: Agrega un nodo con dato al arbol. Si el nodo esta vacio
    // 		 se asigna como la raiz del arbol
    void insertar(string dato, T* valor);

    // Post: Imprime los datos almacenados en el ABB, de menor a mayor
    void imprimir_en_orden();

    // Post: Busca un dato concreto en el arbol, si encuentra devuelve true.
    NodoABB<T>* buscar(string dato);

    // Post: Busca el valor minimo en el ABB
    T buscar_min();

    // Post: Busca el valor maximo en el ABB
    T buscar_max();

    // Post: Busca el sucesor de un dato concreto en el ABB
    T sucesor(string dato);

    // Post: Busca el predecesor de un dato concreto en el ABB
    T predecesor(string dato);

    // Post: Elimina un dato concreto del ABB
    void eliminar(string dato);

    // Post: devuelve la raiz del arbol
    NodoABB<T>* obtener_raiz();

    // Post: Si el ABB esta vacio devuelve true, sino false
    bool vacio();

    // Post: Elimina todos los nodos en el ABB
    void eliminar_todo();

    // Post: Libera los recursos tomados por el ABB
    ~ABB<T>();


};

template <class T>
ABB<T>::ABB() {
    this->raiz = NULL;
}

template <class T>
NodoABB<T>* ABB<T>::insertar(NodoABB<T>* nodo, string dato, T* valor) {

    if (nodo == NULL) {
        nodo = new NodoABB<T>(dato, valor);
    }

    else if (dato > nodo->obtener_dato()) {
        nodo->asignar_derecha(insertar(nodo->obtener_derecha(), dato, valor), nodo);
    }

    else {
        nodo->asignar_izquierda(insertar(nodo->obtener_izquierda(), dato, valor), nodo);
    }
    return nodo;
}

template <class T>
void ABB<T>::insertar(string dato, T* valor)
{
    this->raiz = insertar(this->raiz, dato, valor);
}

template <class T>
void ABB<T>::imprimir_en_orden(NodoABB<T>* nodo)
{
    if (nodo != NULL)
    {
        imprimir_en_orden(nodo->obtener_izquierda());
        cout << nodo -> obtener_dato()<<' ';
        T* aux = nodo->obtener_valor();
        aux->imprimir_datos();
        imprimir_en_orden(nodo->obtener_derecha());
    }
}

template <class T>
void ABB<T>::imprimir_en_orden()
{
    this->imprimir_en_orden(this->raiz);
}

template <class T>
NodoABB<T>* ABB<T>::buscar(NodoABB<T>* nodo, string dato)
{
    if (nodo == NULL || nodo->obtener_dato() == dato)
        return nodo;

    if (dato > nodo->obtener_dato())
        return buscar(nodo->obtener_derecha(), dato);

    return buscar(nodo->obtener_izquierda(), dato);
}

template <class T>
NodoABB<T>* ABB<T>::buscar(string dato)
{
    NodoABB<T>* buscado = buscar(this->raiz, dato);

    return buscado;
}

template <class T>
T ABB<T>::buscar_min(NodoABB<T>* nodo)
{
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_izquierda() == NULL)
        return nodo->obtener_dato();
    else
        return buscar_min(nodo->obtener_izquierda());
}

template <class T>
T ABB<T>::buscar_min()
{
    return buscar_min(this->raiz);
}

template <class T>
T ABB<T>::buscar_max(NodoABB<T>* nodo)
{
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_derecha() == NULL)
        return nodo->obtener_dato();
    else
        return buscar_max(nodo->obtener_derecha());
}

template <class T>
T ABB<T>::buscar_max()
{
    return buscar_max(this->raiz);
}

template <class T>
T ABB<T>::sucesor(NodoABB<T>* nodo)
{
    if (nodo->obtener_derecha() != NULL)
    {
        return buscar_min(nodo->obtener_derecha());
    }
    NodoABB<T>* sucesor = NULL;
    NodoABB<T>* ancesor = this->raiz;
    while(ancesor != nodo) {
        if(nodo->obtener_dato() < ancesor->obtener_dato()) {
            sucesor = ancesor;
            ancesor = ancesor->obtener_izquierda();
        }
        else
            ancesor = ancesor->obtener_derecha();
    }
    return sucesor->obtener_dato();
}

template <class T>
T ABB<T>::sucesor(string dato)
{
    NodoABB<T>* dato_nodo = this->buscar(this->raiz, dato);
    if(dato_nodo == NULL)
        return -1;
    else return sucesor(dato_nodo);
}

template <class T>
T ABB<T>::predecesor(NodoABB<T> * nodo)
{
    if (nodo->obtener_izquierda() != NULL)
    {
        return buscar_max(nodo->obtener_izquierda());
    }

    NodoABB<T>* sucesor = NULL;
    NodoABB<T>* ancesor = this->raiz;
    while(ancesor != nodo) {
        if(nodo->obtener_dato() > ancesor->obtener_dato()) {
            sucesor = ancesor;
            ancesor = ancesor->obtener_derecha();
        }
        else
            ancesor = ancesor->obtener_izquierda();
    }
    return sucesor->obtener_dato();
}

template <class T>
T ABB<T>::predecesor(string dato)
{
    NodoABB<T> * dato_nodo = this->buscar(this->raiz, dato);

    if(dato_nodo == NULL)
        return -1;
    else return predecesor(dato_nodo);
}

template <class T>
NodoABB<T> * ABB<T>::eliminar(NodoABB<T>* nodo, string dato)
{
    if (nodo == NULL)
        return NULL;

    if (nodo->obtener_dato() == dato)
    {
        if (nodo->isLeaf())
            delete nodo;
        else if (nodo->solo_hijo_derecha())
        {
            nodo->obtener_derecha()->asignar_parent(nodo->obtener_padre());
            NodoABB<T>* aux = nodo;
            nodo = nodo->obtener_derecha();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierda())
        {
            nodo->obtener_izquierda()->asignar_parent(nodo->obtener_padre());
            NodoABB<T>* aux = nodo;
            nodo = nodo->obtener_izquierda();
            delete aux;
        }

        else
        {
            T sucesor_dato = this->sucesor(dato);

            nodo->asignar_dato(sucesor_dato);

            nodo->asignar_derecha(eliminar(nodo->obtener_derecha(), sucesor_dato));
        }
    }

    else if (nodo->obtener_dato() < dato)
        nodo->asignar_derecha(eliminar(nodo->obtener_derecha(), dato));

    else
        nodo->asignar_izquierda(eliminar(nodo->obtener_izquierda(), dato));

    return nodo;
}

template <class T>
void ABB<T>::eliminar(string dato)
{
    this->raiz = eliminar(this->raiz, dato);
}

template <class T>
NodoABB<T>* ABB<T>::obtener_raiz(){
    return this->raiz;
}

template <class T>
bool ABB<T>::vacio()
{
    return this->raiz == NULL;
}


template <class T>
void ABB<T>::eliminar_todo(NodoABB<T>* nodo)
{
    if(nodo == NULL)
        return;
    this->eliminar_todo(nodo->obtener_izquierda());
    this->eliminar_todo(nodo->obtener_derecha());
    delete nodo;
}

template <class T>
void ABB<T>::eliminar_todo()
{
    this->eliminar_todo(this->raiz);
}

template <class T>
ABB<T>::~ABB()
{
    this->eliminar_todo();
}


#endif //ABB_ABB_H
