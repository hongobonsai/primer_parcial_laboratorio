

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayCensistas.h"
#include "Utn.h"
#include "ArrayZonas.h"
#include "tp_2_library.h"
//ok

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

	initCensistas(censistas, LEN_CENSISTAS);

	do{
		fflush(stdin);
		opcionMenu = menuPrincipal();


		switch(opcionMenu){

		case 1:
			altaCensista(censistas, LEN_CENSISTAS, LEN_NOM_APELL);
			break;
		case 2:
			modificarCensista(censistas, LEN_CENSISTAS, LEN_NOM_APELL);
			break;
		case 3:
			bajaCencista(censistas, LEN_CENSISTAS);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			for(int i = 0; i < LEN_CENSISTAS; i++){
				if(censistas[i].isEmpty == 0){
			printf("\nNOMBRE: %s"
					"\nAPELLIDO: %s"
					"\nID: %d"
					"\nEDAD: %d"
					"\nDIA: %d"
					"\nMES: %d"
					"\nAÑO: %d"
					"\nCALLE: %s"
					"\nALTURA: %d\n"
					"\nESTADO: %d", censistas[i].nombre, censistas[i].apellido, censistas[i].id, censistas[i].edad,
					censistas[i].fechaNacimiento.dia, censistas[i].fechaNacimiento.mes, censistas[i].fechaNacimiento.anio,
					censistas[i].direccion.calle, censistas[i].direccion.altura, censistas[i].estado);
				}
			}
			break;

//			char auxNombre[lenPalabra];
//				char auxApellido[lenPalabra];
//				int auxId;
//				int auxEdad;
//				int auxDia;
//				int auxMes;
//				int auxAnio;
//				char auxCalle[51];
//				int auxAltura;
		case 0:
			printf("--Ejecucion finalizada--");
			break;

		}


	}while(opcionMenu != 0);





	return EXIT_SUCCESS;
}
