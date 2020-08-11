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

void Arista::asignar_peso_horas(float p){
	peso_horas = p;
}

void Arista::asignar_peso_costo(float c){
	peso_costo = c;
}

string Arista::obtener_origen(){
	return origen;
}

string Arista::obtener_destino(){
	return this->destino;
}

float Arista::obtener_peso_horas(){
	return peso_horas;
}

float Arista::obtener_peso_costo(){
	return peso_costo;
}

void Arista::imprimir_datos(){
	cout << "Vuelo origen:" << " " << origen << " " << "Vuelo destino:" << " " << destino << " " << "Horas:" << " " << peso_horas << " " << "Costo:" << " " << peso_costo << endl;
}

Arista::~Arista(){

}

