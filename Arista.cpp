#include "Arista.h"

Arista::Arista(string o, string d, float p){
	this->origen = o;
	this->destino = d;
	this->peso = p;

}

void Arista::asignar_origen(string o){
	origen = o;
}

void Arista::asignar_destino(string d){
	destino = d;
}

void Arista::asignar_peso(float p){
	peso = p;
}

string Arista::obtener_origen(){
	return origen;
}

string Arista::obtener_destino(){
	return destino;
}

float Arista::obtener_peso(){
	return peso;
}

void Arista::imprimir_datos(){
	cout << "Vuelo origen:" << " " << origen << " " << "Vuelo destino:" << " " << destino << " " << "Peso:" << " " << peso << endl;
}

Arista::~Arista(){

}

