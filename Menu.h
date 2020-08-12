/*
 * Menu.h
 *
 *  Created on: 29 jul. 2020
 *      Author: Luz M. Diaz
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include "Aeropuerto.h"
#include "ABB.h"
#include "ArchivoAeropuerto.h"
#include "NodoABB.h"
#include "Nodo.h"
#include "Cola.h"
#include "ArchivoVuelos.h"
#include "Grafo.h"


using namespace std;

const int FINALIZAR_APLICACION = 6;

class Menu{
	private:

		ArchivoAeropuerto archivo_aeropuerto;
		ArchivoVuelos archivo_vuelos;
		ABB<Aeropuerto*>* arbol;
		Grafo grafo;

	public:
		Menu();

		void iniciar();

		void seleccionar_opcion(int& op);

		void realizar_accion(int num);

		void consultar_aeropuerto();

		void agregar_aeropuerto();

		void ingresar_aeropuerto(string );

		void eliminar_aeropuerto();

		void agregar_claves(Cola<NodoABB<Aeropuerto*>*> &, NodoABB<Aeropuerto*>*);

		void mostrar_aeropuerto(NodoABB<Aeropuerto*>*);

		void mostrar_aeropuertos_por_nivel();

		void ingresar_entrada(string &, string &);

		void ingresar_entrada(string &);

		~Menu();
};




#endif /* MENU_H_ */

