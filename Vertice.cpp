#include "Vertice.h"


Vertice::Vertice(){
	codigo = "";
	id = 0;
}


Vertice::Vertice(string c){
	codigo = c;
	id = 0;
}

void Vertice::asignar_codigo(string c){
	codigo = c;
}

void Vertice::asignar_id(int i){
	id = i;
}

string Vertice::obtener_codigo(){
	return codigo;
}

int Vertice::obtener_id(){
	return this->id;
}

list<Arista*> Vertice::obtener_lista(){
	return lista_ady;
}

void Vertice::agregar_ady(Arista* d){
	lista_ady.push_back(d);
}

void Vertice::imprimir_ady(){
	list<Arista*> :: iterator iterador;
	for(iterador = lista_ady.begin(); iterador != lista_ady.end(); iterador++){
		cout << (*iterador)->obtener_destino() << "->";
	}
}

void Vertice::eliminar_arista(Vertice* o, Vertice* d){
	list<Arista*> :: iterator iterador;
	iterador = lista_ady.begin();
	bool existe = false;
	while(iterador != lista_ady.end() && existe != true){
		if(o->obtener_codigo() == (*iterador)->obtener_origen() && d->obtener_codigo() == (*iterador)->obtener_destino()){
			Arista* aux;
			aux = (*iterador);
			lista_ady.remove(aux);
			existe = true;
		} else {
			iterador ++;
		}
	}
}

void Vertice::eliminar_todo(){
	list<Arista*> :: iterator iterador;
	iterador = lista_ady.begin();
	while(esta_vacia() == false){
		Arista* aux;
		aux = (*iterador);
		iterador ++;
		delete aux;
		lista_ady.remove(aux);
	}
}

bool Vertice::esta_vacia(){
	return lista_ady.empty() == 1;
}


Arista* Vertice::obtener_arista(string codigo){
	list<Arista*> :: iterator iterador;
	iterador = lista_ady.begin();
	bool existe = false;
	Arista* aux;
	while( iterador != lista_ady.end() && existe != true){
		if(codigo == (*iterador)->obtener_destino()){
				existe = true;
				aux = (*iterador);
			} else {
				iterador ++;
			}
		} return aux;
}

bool Vertice::existe_arista(string destino){
	list<Arista*> :: iterator iterador;
	iterador = lista_ady.begin();
	bool existe = false;
	while( iterador != lista_ady.end() && existe != true){
		if(destino == (*iterador)->obtener_destino()){
				existe = true;
			} else {
				iterador ++;
			}
		}
		return existe;
}

Vertice::~Vertice(){
	eliminar_todo();
}
