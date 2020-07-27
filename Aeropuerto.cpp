
#include "Aeropuerto.h"

Aeropuerto::Aeropuerto() {

	this->cant_terminales = 0;
	this->dest_internacionales = 0;
	this->dest_nacionales = 0;
	this->superficie = 0;
}

Aeropuerto::Aeropuerto(string n, string c, string p, float s, unsigned ter, unsigned nac, unsigned inter){

	this->cant_terminales = ter;
	this->dest_internacionales = inter;
	this->dest_nacionales = nac;
	this->superficie = s;
	this->ciudad = c;
	this->pais = p;
	this->nombre = n;
}

void Aeropuerto::asignar_ciudad(string c){
	this->ciudad = c;
}

void Aeropuerto::asignar_pais(string p){
	this->pais = p;
}

void Aeropuerto::asignar_nombre(string n){
	this->nombre = n;
}

void Aeropuerto::asignar_superficie(float s){
	this->superficie = s;
}

void Aeropuerto::asignar_terminales(unsigned ter){
	this->cant_terminales = ter;
}

void Aeropuerto::asignar_internacional(unsigned inter){
	this->dest_internacionales = inter;
}

void Aeropuerto::asignar_nacional(unsigned nac){
	this->dest_nacionales = nac;
}

string Aeropuerto::obtener_ciudad(){
	return this->ciudad;
}

string Aeropuerto::obtener_nombre(){
	return this->nombre;
}

string Aeropuerto::obtener_pais(){
	return this->pais;
}

float Aeropuerto::obtener_superficie(){
	return this->superficie;
}

unsigned Aeropuerto::obtener_internacional(){
	return this->dest_internacionales;
}

unsigned Aeropuerto::obtener_nacional(){
	return this->dest_nacionales;
}

unsigned Aeropuerto::obtener_terminales(){
	return this->cant_terminales;
}


