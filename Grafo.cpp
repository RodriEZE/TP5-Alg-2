
#include "Grafo.h"

Grafo::Grafo(){
	tam = 0;
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
	v->asignar_id(tam);
	tam++;

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
	tam--;
}

void Grafo::eliminar_todo(){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	while(esta_vacio() == false){
		Vertice* aux;
		aux = (*iterador);
		iterador ++;
		delete aux;
		lista_vertices.remove(aux);
	}
}

bool Grafo::existe_arista(string o, string d){
	Vertice* aux_partida = obtener_vertice(o);
	if(aux_partida->existe_arista(d))
		return true;
	else
		return false;
}

void Grafo::iniciar(float distancia[], bool visitado[], int previo[]){

	for( int i = 0 ; i <= tam ; ++i ){

		distancia[ i ] = INF;
	    previo[ i ] = -1;
	    visitado[i]=false;
	}
}

int Grafo::obtener_previo(){

	return *previo;
}

void Grafo::Dijkstra(Vertice* inicial){

		bool visitado[tam];

		this->iniciar(distancia, visitado, previo);
		cola_prioridad.insertar(inicial, 0);
		distancia[inicial->obtener_id()]= 0;

		Vertice* actual;

		while (!cola_prioridad.esVacia()){
			actual = cola_prioridad.desacolar();

			if (visitado[actual->obtener_id()]) continue;
			visitado[actual->obtener_id()] = true;
			recorrer(actual, visitado);
		}

}

void Grafo::recorrer(Vertice* actual, bool visitado[]){
	Vertice* adyacente;
	list<Arista*> :: iterator iterador;
	list<Arista*> aux = actual->obtener_lista();
	float peso;

	for(iterador = aux.begin(); iterador != aux.end(); iterador++){

		adyacente = obtener_vertice((*iterador)->obtener_destino());
		peso = (*iterador)->obtener_peso_horas();

		if(!visitado[adyacente->obtener_id()]){
		comparacion(actual, adyacente, peso);
	}
  }
}

void Grafo::comparacion(Vertice* actual, Vertice* adyacente, float &pes){

	if(distancia[actual->obtener_id()] + pes <  distancia[adyacente->obtener_id()]){

		distancia[adyacente->obtener_id()] = distancia[actual->obtener_id()] + pes;
		previo[adyacente->obtener_id()] = actual->obtener_id();

		cola_prioridad.insertar(adyacente, distancia[adyacente->obtener_id()]);
	}

}


void Grafo::imprimir_dijkstra(int dest){

	if(distancia[dest] == 0){
		cout << "No hay conexiones entre los dos aeropuertos" << endl;
	} else {
		this->imprimir_dijkstra(previo[dest]);
			Vertice* aux_destino = obtener_vertice(dest);
			Vertice* aux_origen = obtener_vertice(previo[dest]);
			Arista* aux_a = aux_origen->obtener_arista(aux_destino->obtener_codigo());
			aux_a->imprimir_datos();
		}
}

Vertice* Grafo::obtener_vertice(int dest){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	bool existe = false;
	Vertice* aux;
	while( iterador != lista_vertices.end() && existe != true){
		if(dest == (*iterador)->obtener_id()){
				existe = true;
				aux = (*iterador);
			} else {
				iterador ++;
			}
		} return aux;
}

Grafo::~Grafo(){
	eliminar_todo();
}
