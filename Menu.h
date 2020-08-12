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

const int FINALIZAR_APLICACION = 8;

class Menu{
	private:

		ArchivoAeropuerto archivo_aeropuerto;
		ArchivoVuelos archivo_vuelos;
		ABB<Aeropuerto*>* arbol;
		Grafo grafo;

	public:

		/*
		 * PRE: -
		 * POST: Constructor carga la informacion de los archivos en el arbol y el grafo.
		 */
		Menu();

		/*
		 * PRE: -
		 * POST: Da inicio a las instrucciones de menu.
		 */
		void iniciar();

		/*
		 * PRE:-
		 * POST: Guarda la opcion que el usuario desea realizar.
		 */
		void seleccionar_opcion(int& op);


		/*
		 * PRE:
		 * POST: Ejecuta la acción segun el num ingresado.
		 */
		void realizar_accion(int num);


		/*
		 * PRE: El arbol tiene que estar cargado.
		 * POST: Si el aeropuerto existe devuelve la informacion.
		 */
		void consultar_aeropuerto();

		/*
		 * PRE: -
		 * POST: Si el codigo del aeropuerto ingresado no existe, se cargará en el arbol.
		 */
		void agregar_aeropuerto();


		/*
		 * PRE: -
		 * POST: Ingresa los datos del aeropuerto.
		 */
		void ingresar_aeropuerto(string );

		/*
		 * PRE: -
		 * POST: Si el codigo del aeropuerto ingresado existe en el arbol, este se eliminará
		 */
		void eliminar_aeropuerto();

		/*
		 * PRE: -
		 * POST: Si el nodo es distinto de null, se agrega en la cola.
		 */
		void agregar_claves(Cola<NodoABB<Aeropuerto*>*> &, NodoABB<Aeropuerto*>*);


		/*
		 * PRE: El arbol debe encontrarse cargado.
		 * POST: Muestra la informacion del aeropuerto.
		 */
		void mostrar_aeropuerto(NodoABB<Aeropuerto*>*);

		/*
		 * PRE: El arbol debe encontrarse cargado
		 * POST: Muestra el arbol haciendo un recorrido en ancho.
		 */
		void mostrar_aeropuertos_por_nivel();

		/*
		 * PRE:-
		 * POST: Ingresa origen y destino de los aeropuertos.
		 */
		void ingresar_entrada(string & origen, string & destino);

		//Destructor
		~Menu();
};




#endif /* MENU_H_ */

