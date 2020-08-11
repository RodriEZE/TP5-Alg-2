
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
		float peso;

		this->iniciar(distancia, visitado, previo);

		cola_prioridad.insertar(inicial, 0);
		distancia[inicial->obtener_id()]= 0;

		Vertice* actual, *adyacente;
		list<Arista*> :: iterator iterador;

		while (!cola_prioridad.esVacia()){
			actual = cola_prioridad.desacolar();

			if (visitado[actual->obtener_id()]) continue;
			visitado[actual->obtener_id()] = true;

			iterador = actual->obtener_lista().begin();

			for(float i = 0; i < actual->obtener_lista().size(); i++){

				adyacente = obtener_vertice((*iterador)->obtener_destino());
				peso = (*iterador)->obtener_peso();
				iterador++;

				if(!visitado[adyacente->obtener_id()]){
					comparacion(actual, adyacente, peso);
				}
			}
		}

}

void Grafo::comparacion(Vertice* act, Vertice* ady, float &pes){

	if(distancia[act->obtener_id()] + pes <  distancia[ady->obtener_id()]){

		distancia[ady->obtener_id()] = distancia[act->obtener_id()] + pes;
		previo[ady->obtener_id()] = act->obtener_id();

		cola_prioridad.insertar(ady, distancia[ady->obtener_id()]);
	}

}

//void Grafo::imprimir_dijkstra(int dest){
//
//	if(previo[dest] != -1){
//		this->imprimir_dijkstra(previo[dest]);
//
//		cout <<
//
//
//	}
//}


Grafo::~Grafo(){
	eliminar_todo();
}
