#ifndef NODO_H_
#define NODO_H_

#include <iostream>

using namespace std;

template<class T>

class Nodo {

	private:
		T dato;
		int prioridad;
		Nodo<T>* psig;

	public:

		//Pre: Recibe un dato T
		//Crea un nodo con el dato que recibe e inicializa siguiente en NULL
		Nodo(T dato_nuevo);

		//Post: Crea un nodo con dato_nuevo y prioridad p
		Nodo(T dato_nuevo, int p);

		//Pre: Existe el nodo
		//Post: Devuelve un dato T
		T obtener_dato();

		//Pre: Existe el nodo
		//Post: Devuelve el puntero al siguiente nodo, si es el ultimo devuelve NULL
		Nodo<T>* obtener_siguiente();

		//Post: devuelve la prioridad del nodo.
		int obtener_prioridad();

		//Pre: -
		//Post: El puntero al siguiente nodo apuntara a psig
		void establecer_siguiente(Nodo<T>* psig);

		//Pre: -
		//Post: Le otorga un valor al atributo dato
		void establecer_dato(T dato_nuevo);
		~Nodo();

};

template<class T>
T Nodo<T>::obtener_dato(){
	return dato;
}

template<class T>
void Nodo<T>::establecer_siguiente(Nodo<T>* psig){
	this->psig = psig;
}

template<class T>
Nodo<T>* Nodo<T>::obtener_siguiente(){
	return this->psig;
}

template<class T>
int Nodo<T>::obtener_prioridad(){
	return this->prioridad;
}

template<class T>
Nodo<T>::Nodo(T dato_nuevo){
	dato = dato_nuevo;
	this->psig = NULL;
	prioridad = 1;
}

template<class T>
Nodo<T>::Nodo(T dato_nuevo, int d){

	dato = dato_nuevo;
	this->psig = NULL;
	prioridad = d;
}

template<class T>
Nodo<T>::~Nodo(){
}

template<class T>
void Nodo<T>::establecer_dato(T dato_nuevo){
	dato = dato_nuevo;
}

#endif /* NODO_H_ */
