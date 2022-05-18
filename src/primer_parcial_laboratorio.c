
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "tp_2_library.h"
#include "StructLib.h"

//#define LEN_CENCISTAS 40
//#define LEN_NOM_APELL 51
//#define ACTIVO 1
//#define INACTIVO 2
//#define LIBERADO 3

#define LEN_CALLES 20

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	//char prueba[LEN_NOM_APELL] = {"mensajito"};
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
			asignarCensistaResponsable(zonas, censistas, LEN_ZONAS,
					LEN_CENSISTAS);
			break;
		case 6:
			break;
		case 7: //censistas
			for (int i = 0; i < LEN_CENSISTAS; i++) {
				if (censistas[i].isEmpty == 0) {
					printf("\nNOMBRE: %s"
							"\nAPELLIDO: %s"
							"\nID: %d"
							"\nEDAD: %d"
							"\nDIA: %d"
							"\nMES: %d"
							"\nAÑO: %d"
							"\nCALLE: %s"
							"\nALTURA: %d"
							"\nZONA ACTIVA: %d"
							"\nESTADO: %d\n", censistas[i].nombre,
							censistas[i].apellido, censistas[i].id,
							censistas[i].edad, censistas[i].fechaNacimiento.dia,
							censistas[i].fechaNacimiento.mes,
							censistas[i].fechaNacimiento.anio,
							censistas[i].direccion.calle,
							censistas[i].direccion.altura, censistas[i].idZona, censistas[i].estado);
				}
			}
			break;
			break;
		case 8: //zonas
			for (int i = 0; i < LEN_ZONAS; i++) {
				if (zonas[i].isEmpty == 0) {
					printf("\nID ZONA: %d"
							"\nID CENCISTA: %d"
							"\nLOCALIDAD: %d"
							"\nESTADO: %d"
							"\nCALLE 1: %s"
							"\nCALLE 2: %s"
							"\nCALLE 3: %s"
							"\nCALLE 4: %s\n", zonas[i].idZona, zonas[i].idCensistaAsignado,
							zonas[i].localidad, zonas[i].estado,
							zonas[i].calles[0], zonas[i].calles[1],
							zonas[i].calles[2], zonas[i].calles[3]);
				}
			}
			break;

		case 0:
			printf("--Ejecucion finalizada--");
			break;

		}

	} while (opcionMenu != 0);

	return EXIT_SUCCESS;
}
