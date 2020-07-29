/*
 * Menu.h
 *
 *  Created on: 29 jul. 2020
 *      Author: Luz M. Diaz
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "Archivo.h"
#include "Aeropuerto.h"
#include "ABB.h"
#include "NodoABB.h"

using namespace std;

const int FINALIZAR_APLICACION = 6;

class Menu{
	private:

		Archivo archivo;
		ABB<Aeropuerto>* arbol;

	public:
		Menu();

		void iniciar();

		void seleccionar_opcion(int&);

		void realizar_accion(int num);

		void consultar_aeropuerto();

		void agregar_aeropuerto();

		void ingresar_aeropuerto(string);

		void eliminar_aeropuerto();

		void mostrar_aeropuerto(NodoABB<Aeropuerto>*);

		void mostrar_aeropuertos_en_ancho();

		~Menu();
};




#endif /* MENU_H_ */

