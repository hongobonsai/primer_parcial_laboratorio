/*
 * tp_2_library.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */
#include "Utn.h"

/** \brief Imprime el menu principal del programa
*
*/
int menuPrincipal() {
	int auxOpcionMenuPrincipal;
	printf("\n*MENU*");
	printf("\n1. Cargar censista.");
	printf("\n2. Modificar censista.");
	printf("\n3. Dar de baja censista.");
	printf("\n4. Cargar zona.");
	printf("\n5. Asignar zona a censar: se asigna un censista responsable a la zona.");
	printf("\n6. Carga de datos.");
	printf("\n7. Mostrar censistas.");
	printf("\n8. Mostrar zonas.\n");
	printf("\n0. EXIT\n");


	utn_getNumero(&auxOpcionMenuPrincipal, "", "\nIngrese una opcion valida.", 0, 8, 5);

	return auxOpcionMenuPrincipal;
}

/** \brief Generador de ID autoincremental. Utiliza un valor static. Comienza en 1000
*
* \return Retorna el valor del ID,
*/
int calcularId() {

	static int id = 2999;
	id++;
	return id;
}











