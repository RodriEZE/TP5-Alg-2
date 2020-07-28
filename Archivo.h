/*
 * Archivo.h
 *
 *  Created on: 25 jul. 2020
 *      Author: carolina
 */

#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <fstream>
#include "ABB.h"
#include "Aeropuerto.h"

using namespace std;

const string ARCHIVO_AERO = "aeropuertos.txt";

class Archivo{
private:
	string nombre, ciudad, pais, codigo;
	float superficie;
	unsigned cant_terminales, dest_nacionales, dest_internacionales;
	ifstream archivo_aeropuertos;
	ABB<Aeropuerto>* arbol;

public:
	/*
	 * PRE: -
	 * POST: Crea un objeto de tipo Archivo
	 */
	Archivo();

	/*
	 * PRE: -
	 * POST: Lee los datos del atributo archivo_aeropuertos y los inserta en el arbol
	 */
	void cargar_arbol();

	/*
	 * PRE: Existe el objeto archivo
	 * POST: Elimina el objeto
	 */
	~Archivo();

};



#endif /* ARCHIVO_H_ */
