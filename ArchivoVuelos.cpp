
#include "ArchivoVuelos.h"

ArchivoVuelos::ArchivoVuelos(){
	archivo_vuelos.open(ARCHIVO_VUELOS);
	costo_vuelo = 0;
	horas_vuelo = 0;
}


void ArchivoVuelos::leer_archivo(){

	while(!archivo_vuelos.eof()){

		archivo_vuelos >> codigo_partida;
		archivo_vuelos >> codigo_llegada;
		archivo_vuelos >> costo_vuelo;
		archivo_vuelos >> horas_vuelo;

		verificar_vertice(codigo_partida);
		hallar_aristas(codigo_partida, codigo_llegada, horas_vuelo);

	}

}


void ArchivoVuelos::verificar_vertice(string codigo_partida){
	if(grafo.existe_vertice(codigo_partida) == false){
		Vertice* vertice = new Vertice(codigo_partida);
		grafo.insertar_vertice(vertice);
	}
}

void ArchivoVuelos::hallar_aristas(string codigo_partida, string codigo_llegada, float horas_vuelo){
	Vertice* aux_partida = grafo.obtener_vertice(codigo_partida);
	Arista* nuevo_vertice = new Arista(codigo_partida, codigo_llegada, horas_vuelo);

	grafo.insertar_arista(aux_partida, nuevo_vertice);
}

void ArchivoVuelos::eliminar_arista(string o, string d){
	Vertice* aux_partida = grafo.obtener_vertice(o);
	Vertice* aux_llegada = grafo.obtener_vertice(d);
	aux_partida->eliminar_arista(aux_partida, aux_llegada);
	grafo.imprimir_vertices();
}

void ArchivoVuelos::eliminar_vertice(string o){
	grafo.eliminar_vertice(o);
	grafo.imprimir_vertices();
}

void ArchivoVuelos::buscar_vuelo(string o, string d){
	Vertice* aux_partida = grafo.obtener_vertice(o);
	Arista* aux_arista = aux_partida->obtener_arista(d);
	aux_arista->imprimir_datos();

}

void ArchivoVuelos::imprimir_grafo(){
	grafo.imprimir_vertices();
}

ArchivoVuelos::~ArchivoVuelos(){

}
