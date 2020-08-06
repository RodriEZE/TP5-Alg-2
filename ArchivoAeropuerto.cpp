
#include "ArchivoAeropuerto.h"

ArchivoAeropuerto::ArchivoAeropuerto(){
	archivo_aeropuertos.open(ARCHIVO_AERO);
}

void ArchivoAeropuerto::cargar_arbol(ABB<Aeropuerto*>* arbol){

	Aeropuerto* aero;

	while(!archivo_aeropuertos.eof()){
		archivo_aeropuertos >> codigo;
		archivo_aeropuertos >> nombre;
		archivo_aeropuertos >> ciudad;
		archivo_aeropuertos >> pais;
		archivo_aeropuertos >> superficie;
		archivo_aeropuertos >> cant_terminales;
		archivo_aeropuertos >> dest_nacionales;
		archivo_aeropuertos >> dest_internacionales;

		aero = new Aeropuerto(nombre, ciudad, pais, superficie, cant_terminales, dest_nacionales, dest_internacionales);

		arbol->insertar(codigo, aero);
	}
}


