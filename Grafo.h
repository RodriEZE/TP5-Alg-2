
#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <list>

#include "Vertice.h"
#include "Cola.h"

#define INF 999999
#define MAX_V 50

using namespace std;

class Grafo{

private:
	//atributos
	list<Vertice*> lista_vertices;
	Cola<Vertice*> cola_prioridad;
	float distancia[MAX_V];
	int previo[MAX_V];
	int tam;

	//metodos
	//Inicia las variables de dijkstra.
	void iniciar(float distancia[], bool visitado[], int previo[]);
	//compara un vertice con su adyacente para calculo de camino minimo.
	void comparacion(Vertice*, Vertice*, float &);


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

	Vertice* obtener_vertice(int);

	int obtener_previo();

	float obtener_distancia();

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

	/*
	 * PRE: Existe, vertice y estan cargadas los vuelos y sus conexiones
	 * POST: Arma los caminos y pesos minimos hacia todos los vertices
	 *		 desde el vertice pasado como parametro.
	 */
	void Dijkstra(Vertice* inicial, int op);

	void imprimir_dijkstra(int, float&, float&);

	string hallar_codigo(int);

	void recorrer(Vertice* actual, bool visitado[], int op);



};

#endif /* GRAFO_H_ */
