
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LocalLibrary.h"
#include "Utn.h"
#include "StructLib.h"

//#define LEN_CENCISTAS 40
//#define LEN_NOM_APELL 51
//#define ACTIVO 1
//#define INACTIVO 2
//#define LIBERADO 3

#define LEN_CALLES 20
#define CANT_LOCALIDADES 10

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	char arrayLocalidades[CANT_LOCALIDADES][26] = {"AVELLANEDA", "BARRACAS", "LA BOCA", "SAN TELMO", "SANTOS LUGARES",
			"CASEROS", "PALOMAR", "SAN MARTIN", "HUERLINGHAM", "BELLA VISTA"};

	Censista censistas[LEN_CENSISTAS];
	Zona zonas[LEN_ZONAS];

	initCensistas(censistas, LEN_CENSISTAS);
	initZona(zonas, LEN_ZONAS);

	do {
		fflush(stdin);
		opcionMenu = menuPrincipal();

		switch (opcionMenu) {

		case 1:
			altaCensista(censistas, LEN_CENSISTAS, LEN_NOM_APELL);
			break;
		case 2:
			modificarCensista(censistas, LEN_CENSISTAS, LEN_NOM_APELL);
			break;
		case 3:
			bajaCensista(censistas, LEN_CENSISTAS);
			break;
		case 4:
			altaZona(zonas, LEN_ZONAS, LEN_NOM_APELL);
			break;
		case 5:
			asignarCensistaResponsable(zonas, censistas, LEN_ZONAS, LEN_CENSISTAS);
			break;
		case 6:
			finalizarZona(zonas, censistas, LEN_ZONAS, LEN_CENSISTAS);
			break;
		case 7:
			printCensistas(censistas, LEN_CENSISTAS);
			break;
		case 8:
			printZonas(zonas, censistas, LEN_ZONAS, LEN_CENSISTAS, arrayLocalidades, CANT_LOCALIDADES);
			break;
		case 9://censista
			hardCodeCensista(censistas);
			break;
		case 10://zona
			hardCodeZona(zonas);
			break;
		case 11://informe
			break;
		case 0:
			printf("--Ejecucion finalizada--");
			break;

		}

	} while (opcionMenu != 0);

	return EXIT_SUCCESS;
}
