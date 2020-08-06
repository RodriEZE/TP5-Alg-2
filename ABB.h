

#include<iostream>

#include "NodoABB.h"
#include <string.h>

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
    NodoABB<T>* insertar(NodoABB<T>* nodo, string clave, T valor);
    void imprimir_en_orden(NodoABB<T> * nodo);
    NodoABB<T>* buscar(NodoABB<T>* nodo, string clave);
    string buscar_min(NodoABB<T>* nodo);
    T buscar_max(NodoABB<T>* nodo);
    string sucesor(NodoABB<T>* nodo);
    T predecesor(NodoABB<T>* nodo);
    NodoABB<T>* eliminar(NodoABB<T>* nodo, string clave);
    void eliminar_todo(NodoABB<T>* nodo);
    NodoABB<T>* buscar_padre(NodoABB<T>* nodo, string clave);


public:

    // Post: Crea un arbol vacio
    ABB();

    // Post: Agrega un nodo con dato al arbol. Si el nodo esta vacio
    // 		 se asigna como la raiz del arbol
    void insertar(string clave, T valor);

    // Post: Imprime los datos almacenados en el ABB, de menor a mayor
    void imprimir_en_orden();

    // Post: Busca un dato concreto en el arbol, si encuentra devuelve el nodo.
    NodoABB<T>* buscar(string clave);

    // Post: Busca el padre de una clave determinada en el arbol,
    // 		 devolviendo el nodo.
    NodoABB<T>* buscar_padre(string clave);

    // Post: Busca el valor minimo en el ABB
    string buscar_min();

    // Post: Busca el valor maximo en el ABB
    T buscar_max();

    // Post: Busca el sucesor de un dato concreto en el ABB
    string sucesor(string clave);

    // Post: Busca el predecesor de un dato concreto en el ABB
    T predecesor(string clave);

    // Post: Elimina un dato concreto del ABB
    void eliminar(string clave);

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
NodoABB<T>* ABB<T>::insertar(NodoABB<T>* nodo, string clave, T valor) {

    if (nodo == NULL) {
        nodo = new NodoABB<T>(clave, valor);
    }

    else if (clave > nodo->obtener_clave()) {
        nodo->asignar_derecha(insertar(nodo->obtener_derecha(), clave, valor), nodo);
    }

    else {
        nodo->asignar_izquierda(insertar(nodo->obtener_izquierda(), clave, valor), nodo);
    }
    return nodo;
}

template <class T>
void ABB<T>::insertar(string clave, T valor)
{
    this->raiz = insertar(this->raiz, clave, valor);
}

template <class T>
void ABB<T>::imprimir_en_orden(NodoABB<T>* nodo)
{
    if (nodo != NULL)
    {
        imprimir_en_orden(nodo->obtener_izquierda());
        cout << nodo -> obtener_clave()<<' ';
        T aux = nodo->obtener_valor();
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
NodoABB<T>* ABB<T>::buscar(NodoABB<T>* nodo, string clave)
{
    if (nodo == NULL || nodo->obtener_clave() == clave)
        return nodo;

    if (clave > nodo->obtener_clave())
        return buscar(nodo->obtener_derecha(), clave);

    return buscar(nodo->obtener_izquierda(), clave);
}

template <class T>
NodoABB<T>* ABB<T>::buscar(string clave)
{
    NodoABB<T>* buscado = buscar(this->raiz, clave);

    return buscado;
}


template <class T>
string ABB<T>::buscar_min(NodoABB<T>* nodo)
{
	string error = "error";
    if(nodo == NULL)
        return error;
    if(nodo->obtener_izquierda() == NULL)
        return nodo->obtener_clave();
    else
        return buscar_min(nodo->obtener_izquierda());
}

template <class T>
string ABB<T>::buscar_min()
{
    return buscar_min(this->raiz);
}

template <class T>
T ABB<T>::buscar_max(NodoABB<T>* nodo)
{
    if(nodo == NULL)
        return -1;
    if(nodo->obtener_derecha() == NULL)
        return nodo->obtener_clave();
    else
        return buscar_max(nodo->obtener_derecha());
}

template <class T>
T ABB<T>::buscar_max()
{
    return buscar_max(this->raiz);
}

template <class T>
string ABB<T>::sucesor(NodoABB<T>* nodo)
{
    if (nodo->obtener_derecha() != NULL)
    {
        return buscar_min(nodo->obtener_derecha());
    }
    NodoABB<T>* sucesor = NULL;
    NodoABB<T>* ancesor = this->raiz;
    while(ancesor != nodo) {
        if(nodo->obtener_clave() < ancesor->obtener_clave()) {
            sucesor = ancesor;
            ancesor = ancesor->obtener_izquierda();
        }
        else
            ancesor = ancesor->obtener_derecha();
    }
    return sucesor->obtener_clave();
}

template <class T>
string ABB<T>::sucesor(string clave)
{
	string error = "error";
    NodoABB<T>* dato_nodo = this->buscar(this->raiz, clave);
    if(dato_nodo == NULL)
        return error;
     return sucesor(dato_nodo);
}

template <class T>
NodoABB<T>* ABB<T>::buscar_padre(string clave){

	return this->buscar_padre(this->raiz, clave);
}

template <class T>
NodoABB<T>* ABB<T>::buscar_padre(NodoABB<T>* nodo, string clave){

	if (nodo == NULL || nodo->obtener_derecha()->obtener_clave() == clave || nodo->obtener_izquierda()->obtener_clave() == clave)
	  return nodo;

	if (clave > nodo->obtener_clave())
	  return buscar_padre(nodo->obtener_derecha(), clave);

	return buscar_padre(nodo->obtener_izquierda(), clave);
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
        if(nodo->obtener_clave() > ancesor->obtener_clave()) {
            sucesor = ancesor;
            ancesor = ancesor->obtener_derecha();
        }
        else
            ancesor = ancesor->obtener_izquierda();
    }
    return sucesor->obtener_clave();
}

template <class T>
T ABB<T>::predecesor(string clave)
{
    NodoABB<T>* dato_nodo = this->buscar(this->raiz, clave);

    if(dato_nodo == NULL)
        return -1;
    else return predecesor(dato_nodo);
}

template <class T>
NodoABB<T>* ABB<T>::eliminar(NodoABB<T>* nodo, string clave)
{
    if (nodo == NULL)
        return NULL;

    if (nodo->obtener_clave() == clave)
    {
        if (nodo->es_hoja())
        	if(nodo->es_copiado()){
        		nodo->asignar_valor(NULL);
        		delete nodo;
        		nodo = NULL;
        	}else{
        		delete nodo;
        		nodo = NULL;
        	}

        else if (nodo->solo_hijo_derecha())
        {
            nodo->obtener_derecha()->asignar_padre(nodo->obtener_padre());
            NodoABB<T>* aux = nodo;
            nodo = nodo->obtener_derecha();
            delete aux;
            aux = NULL;
        }
        else if (nodo->solo_hijo_izquierda())
        {
            nodo->obtener_izquierda()->asignar_padre(nodo->obtener_padre());
            NodoABB<T>* aux = nodo;
            nodo = nodo->obtener_izquierda();
            delete aux;
            aux = NULL;
        }

        else
        {
            string sucesor_clave = this->sucesor(clave);
            NodoABB<T>* nodo_sucesor = this->buscar(sucesor_clave);

            nodo->asignar_valor(nodo_sucesor->obtener_valor());
            nodo->asignar_clave(sucesor_clave);
            nodo_sucesor->fue_copiado();

            nodo->asignar_derecha(eliminar(nodo->obtener_derecha(), sucesor_clave));
        }
    }

    else if (nodo->obtener_clave() < clave)
        nodo->asignar_derecha(eliminar(nodo->obtener_derecha(), clave));

    else
        nodo->asignar_izquierda(eliminar(nodo->obtener_izquierda(), clave));

    return nodo;
}

template <class T>
void ABB<T>::eliminar(string clave)
{
    this->raiz = eliminar(this->raiz, clave);
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
    nodo = NULL;
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
