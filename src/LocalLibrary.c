/*
 * tp_2_library.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */
#include "Utn.h"
#include "StructLib.h"

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
	printf("\n5. Asignar zona a censar.");
	printf("\n6. Carga de datos.");
	printf("\n7. Mostrar censistas.");
	printf("\n8. Mostrar zonas.\n");
	printf("\n9. Hardcode 5 Cencistas.");
	printf("\n10. Hardcode 5 Zonas.");
	printf("\n11. Informes.\n");
	printf("\n0. EXIT\n");

	utn_getNumero(&auxOpcionMenuPrincipal, "", "\nIngrese una opcion valida.",
			0, 11, 5);

	return auxOpcionMenuPrincipal;
}

/** \brief Generador de ID autoincremental. Utiliza un valor static. Comienza en 3000
 *
 * \return Retorna el valor del ID,
 */
int calcularId() {

	static int id = 2999;
	id++;
	return id;
}
/** \brief Generador de ID autoincremental pero para zonas. Utiliza un valor static. Comienza en 1000
 *
 * \return Retorna el valor del ID,
 */
int calcularIdZona() {

	static int id = 999;
	id++;
	return id;
}
