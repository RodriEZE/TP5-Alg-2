#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"
template<class T>

class Cola
{
private:
	// Primer elemento de la cola
	Nodo<T>* primero; ;
	// Ultimo elemento de la cola
	Nodo<T>* ultimo ;
	int tam;

public:

	// Constructor
	// PRE : ninguna
	// POST : construye una cola vacía
	// - primero y ultimo apuntan a nulo
	Cola ();

	// Destructor
	// PRE : cola creada
	// POST : Libera todos los recursos de la cola
	~ Cola ();

	// ¿La cola es vacía ?
	// PRE : cola creada
	// POST : devuelve verdadero si la cola es vacía
	// falso de lo contrario
	bool esVacia ();

	// Agregar un elemento a la cola
	// PRE : cola creada
	// POST : agrega un dato ( dentro de un nodo ) al final
	void insertar(T d);

	// Obtener el dato que está al principio
	// PRE : - cola creada y no vacía
	// POST : devuelve el dato que está al principio
	T obtenerDato ();
	// Borrado del nodo que está al principio
	// PRE : - cola creada y no vacía
	// POST : libera el nodo que está al principio
	void sacarDato ();
};

template<class T>
Cola<T>:: Cola () {
	primero = ultimo = 0;
	tam = 0;
}

template<class T>
Cola<T>::~ Cola () {
	while (!( esVacia ()))
		sacarDato ();
}

template<class T>
bool Cola<T>:: esVacia () {
	return ( primero == 0);
}


template<class T>
void Cola<T>:: insertar(T d) {
	Nodo<T>* pnodo = new Nodo<T>(d);
	if (this -> esVacia ()) {
		primero = pnodo ;
	}
	else
		ultimo -> establecer_siguiente ( pnodo );
	ultimo = pnodo ;
	tam ++;
}

template<class T>
T Cola<T>:: obtenerDato () {
	return primero -> obtener_dato ();
}

template<class T>
void Cola<T>:: sacarDato () {
	if (primero == ultimo)
		ultimo = 0;
	Nodo<T>* paux = primero ;
	primero = paux -> obtener_siguiente ();
	delete paux ;
	tam --;
}

#endif /* COLA_H_ */
