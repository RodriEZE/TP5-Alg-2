
#include "Grafo.h"

Grafo::Grafo(){

}

bool Grafo::esta_vacio(){
	return lista_vertices.empty() == 1;
}


bool Grafo::existe_vertice(string c){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	bool existe = false;
	while( iterador != lista_vertices.end() && existe != true){
		if(c == (*iterador)->obtener_codigo()){
			existe = true;
		} else {
			iterador ++;
		}
	}
	return existe;
}

void Grafo::insertar_vertice(Vertice* v){
	lista_vertices.push_back(v);
}

void Grafo::imprimir_vertices(){
	list<Vertice*> :: iterator iterador;
	for(iterador = lista_vertices.begin(); iterador != lista_vertices.end(); iterador++){
		cout << (*iterador)->obtener_codigo() << "->";
		(*iterador)->imprimir_ady();
		cout << endl;
	}
}

Vertice* Grafo::obtener_vertice(string codigo){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	bool existe = false;
	Vertice* aux;
	while( iterador != lista_vertices.end() && existe != true){
		if(codigo == (*iterador)->obtener_codigo()){
				existe = true;
				aux = (*iterador);
			} else {
				iterador ++;
			}
		} return aux;
}

void Grafo::insertar_arista(Vertice* o, Arista* d){
	 list<Vertice*> :: iterator iterador;
	 iterador = lista_vertices.begin();
	 bool existe = false;
	 while( iterador != lista_vertices.end() && existe != true){
		 if(o->obtener_codigo() == (*iterador)->obtener_codigo()){
			 (*iterador)->agregar_ady(d);
			 existe = true;
		 } else {
			 iterador ++;
		 }
	 }
}

void Grafo::eliminar_vertice(string o){
	Vertice* aux = obtener_vertice(o);
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	bool existe = false;
	while( iterador != lista_vertices.end() && existe != true){
		if(aux->obtener_codigo() == (*iterador)->obtener_codigo()){
			delete aux;
			lista_vertices.remove(aux);
			existe = true;
		} else {
			iterador++;
		}
	}
}

void Grafo::eliminar_todo(){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	while(esta_vacio() == false){
		Vertice* aux;
		aux = (*iterador);
		delete aux;
		lista_vertices.remove(aux);
		iterador ++;
	}
}

bool Grafo::existe_arista(string o, string d){
	Vertice* aux_partida = obtener_vertice(o);
	if(aux_partida->existe_arista(d))
		return true;
	else
		return false;
}

Grafo::~Grafo(){
	eliminar_todo();
}
