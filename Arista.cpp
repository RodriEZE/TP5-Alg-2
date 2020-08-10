#include "Arista.h"

Arista::Arista(string o, string d, float p, float c){
	this->origen = o;
	this->destino = d;
	this->peso_horas = p;
	this->peso_costo = c;
}

void Arista::asignar_origen(string o){
	origen = o;
}

void Arista::asignar_destino(string d){
	destino = d;
}

void Arista::asignar_peso(float p){
	peso_horas = p;
}

string Arista::obtener_origen(){
	return origen;
}

string Arista::obtener_destino(){
	return this->destino;
}

float Arista::obtener_peso(){
	return peso_horas;
}

void Arista::imprimir_datos(){
	cout << "Vuelo origen:" << " " << origen << " " << "Vuelo destino:" << " " << destino << " " << "Peso:" << " " << peso_horas << endl;
}

Arista::~Arista(){

}

