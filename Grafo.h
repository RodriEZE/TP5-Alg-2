
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <list>

#include "Vertice.h"


using namespace std;


class Grafo{
private:
	 list<Vertice*> lista_vertices;
public:
	/*
	 * PRE: -
	 * POST: Genera un grafo vacio
	 */
	Grafo();

	/*
	 * PRE: Existe el grafo
	 * POST: Nodo es un valor valido
	 */
	bool existe_vertice(string);

	/*
	 * PRE: Existe el grafo, el nodo a eliminar existe en el grafo y no este no tiene aristas incidentes en el
	 * POST: El grafo queda modificado con la eliminacion del nodo
	 */
	void eliminar_vertice(string);

	/*
	 * PRE: Existe el grafo, la arista no esta previamente y existan en el grafo los nodos de origen y destino
	 * POST: El grafo queda modificado por el agregado de una nueva arista
	 */
	void insertar_arista(Vertice* origen, Arista* destino);

	/*
	 * PRE: Existe un grafo y el nodo no esta previamente
	 * POST: El grafo queda modificado con el nuevo nodo agregado
	 */
	void insertar_vertice(Vertice*);

	/*
	 * PRE: Existe un grafo
	 * POST: Libera recursos
	 */
	~Grafo();

	/*
	 * PRE: -
	 * POST: Imprime por pantalla los datos el Vertice
	 */
	void imprimir_vertices();

	/*
	 *  PRE: Existe el grafo
	 *  POST: Devuelve true si el grafo esta vacio, false en caso contrario
	 */
	bool esta_vacio();

	/*
	 * PRE: Recibe un string
	 * POST: Devuelve Vertice*
	 */
	Vertice* obtener_vertice(string);

	/*
	 * PRE: Existe el grafo
	 * POST: Elimina el atributo lista_vertice, libera recursos, etc.
	 */
	void eliminar_todo();

	/*
	 * PRE: Existe el grafo
	 * POST: Arista es un valor valido
	 */
	bool existe_arista(string o, string d);


};

#endif /* GRAFO_H_ */
