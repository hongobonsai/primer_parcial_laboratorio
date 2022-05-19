#include "ArrayZonas.h"

int initZona(Zona list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int altaZona(Zona list[], int lenStruct, int lenPalabra) {

	int retorno;
	int indiceVacio;
	int auxIdZona;
	int auxLocalidad;
	char auxCalles[4][lenPalabra];

	if ((findEmptyZona(list, lenStruct)) != -1) {
		printf("\n-CARGA DE ZONAS-\n");

		if (getEspaciosYLetras(auxCalles[0], lenPalabra,
				"\nIntroduzca el nombre de la calle 1: ",
				"\n-Ingrese un nombre valido-\n", 5) == 0) {
			if (getEspaciosYLetras(auxCalles[1], lenPalabra,
					"\nIntroduzca el nombre de la calle 2: ",
					"\n-Ingrese un nombre valido-\n", 5) == 0) {
				if (getEspaciosYLetras(auxCalles[2], lenPalabra,
						"\nIntroduzca el nombre de la calle 3: ",
						"\n-Ingrese un nombre valido-\n", 5) == 0) {
					if (getEspaciosYLetras(auxCalles[3], lenPalabra,
							"\nIntroduzca el nombre de la calle 4: ",
							"\n-Ingrese un nombre valido-\n", 5) == 0) {

						if (utn_getNumero(&auxLocalidad, "\nIngrese a que localidad corresponde la zona",
											"\nIngrese un dato valido", 1, 26, 5) == 0) {

							if (list != NULL && lenStruct > 0) {
								indiceVacio = findEmptyZona(list, lenStruct);
									if (indiceVacio != -1) {
										auxIdZona = calcularIdZona();
										list[indiceVacio].idZona = auxIdZona;
										strncpy(list[indiceVacio].calles[0], auxCalles[0], sizeof(list[indiceVacio].calles[0]));
										strncpy(list[indiceVacio].calles[1], auxCalles[1], sizeof(list[indiceVacio].calles[1]));
										strncpy(list[indiceVacio].calles[2], auxCalles[2], sizeof(list[indiceVacio].calles[2]));
										strncpy(list[indiceVacio].calles[3], auxCalles[3], sizeof(list[indiceVacio].calles[3]));
										list[indiceVacio].localidad = auxLocalidad;
										list[indiceVacio].censados.cantidadVirtual = 0;
										list[indiceVacio].censados.cantidadInSitu = 0;
										list[indiceVacio].censados.cantidadAusentes = 0;
										list[indiceVacio].isEmpty = 0;
										list[indiceVacio].estado = PENDIENTE;
										list[indiceVacio].idCensistaAsignado = 0;
										printf("\n-La zona se cargo con estado: PENDIENTE.-\n");
										printf("\n+SE REALIZO LA CARGA CORRECTAMENTE+\n");
										retorno = 0;
									}else {
										printf("\n-NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ LA ZONA-");
										retorno = -1;
									}

							}
						}else {
							printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
							retorno = -1;
						}
					}else {
						printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
						retorno = -1;
					}

				}else {
					printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
					retorno = -1;
				}

			}else {
				printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
				retorno = -1;
			}
		}else {
			printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
			retorno = -1;
		}

	}
return retorno;
}

int findEmptyZona(Zona list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int isThereAnyZona(Zona *list, int len) { //IS THERE ANYBODY... OUT - THERE
	int retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int findZonaById(Zona *list, int len, int idZona) {
	int retorno = -1;
	if (list != NULL && len > 0 && idZona > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].idZona == idZona && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int findZonaPendiente(Zona list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].estado == 1 && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int isZonaPendiente(Zona *list, int len, int idZona) {
	int retorno = -1;
	if (list != NULL && len > 0 && idZona > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].idZona
					== idZona&& list[i].isEmpty == 0 && list[i].estado == PENDIENTE) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void hardCodeZona(Zona list[]) {

	printf("\nSe pisaran los datos\n");

	//

	list[0].isEmpty = 0;
	list[0].estado = PENDIENTE;
	list[0].idZona = calcularIdZona();
	strncpy(list[0].calles[0], "Brandsen", sizeof(list[0].calles[0]));
	strncpy(list[0].calles[1], "Suarez", sizeof(list[0].calles[1]));
	strncpy(list[0].calles[2], "Martin Garcia", sizeof(list[0].calles[2]));
	strncpy(list[0].calles[3], "Montes de Oca", sizeof(list[0].calles[3]));
	list[0].localidad = 2;
	list[0].censados.cantidadInSitu = 0;
	list[0].censados.cantidadVirtual = 0;
	list[0].censados.cantidadAusentes = 0;

	//

	list[1].isEmpty = 0;
	list[1].estado = PENDIENTE;
	list[1].idZona = calcularIdZona();
	strncpy(list[1].calles[0], "California", sizeof(list[1].calles[0]));
	strncpy(list[1].calles[1], "Iriarte", sizeof(list[1].calles[1]));
	strncpy(list[1].calles[2], "Mexico", sizeof(list[1].calles[2]));
	strncpy(list[1].calles[3], "Australia", sizeof(list[1].calles[3]));
	list[1].localidad = 5;
	list[1].censados.cantidadInSitu = 0;
	list[1].censados.cantidadVirtual = 0;
	list[1].censados.cantidadAusentes = 0;

	//

	list[2].isEmpty = 0;
	list[2].estado = PENDIENTE;
	list[2].idZona = calcularIdZona();
	strncpy(list[2].calles[0], "Gral Victoria", sizeof(list[2].calles[0]));
	strncpy(list[2].calles[1], "Pte Kennedy", sizeof(list[2].calles[1]));
	strncpy(list[2].calles[2], "Bergamini", sizeof(list[2].calles[2]));
	strncpy(list[2].calles[3], "Mengues", sizeof(list[2].calles[3]));
	list[2].localidad = 7;
	list[2].censados.cantidadInSitu = 0;
	list[2].censados.cantidadVirtual = 0;
	list[2].censados.cantidadAusentes = 0;

	//

	list[3].isEmpty = 0;
	list[3].estado = PENDIENTE;
	list[3].idZona = calcularIdZona();
	strncpy(list[3].calles[0], "Irusta", sizeof(list[3].calles[0]));
	strncpy(list[3].calles[1], "Flaubert", sizeof(list[3].calles[1]));
	strncpy(list[3].calles[2], "Pedro Diaz", sizeof(list[3].calles[2]));
	strncpy(list[3].calles[3], "Gorriti", sizeof(list[3].calles[3]));
	list[3].localidad = 10;
	list[3].censados.cantidadInSitu = 0;
	list[3].censados.cantidadVirtual = 0;
	list[3].censados.cantidadAusentes = 0;

	//

	list[4].isEmpty = 0;
	list[4].estado = PENDIENTE;
	list[4].idZona = calcularIdZona();
	strncpy(list[4].calles[0], "Brandsen", sizeof(list[4].calles[0]));
	strncpy(list[4].calles[1], "Suarez", sizeof(list[4].calles[1]));
	strncpy(list[4].calles[2], "CalleGarcia", sizeof(list[4].calles[2]));
	strncpy(list[4].calles[3], "Montes de Oca", sizeof(list[4].calles[3]));
	list[4].localidad = 2;
	list[4].censados.cantidadInSitu = 0;
	list[4].censados.cantidadVirtual = 0;
	list[4].censados.cantidadAusentes = 0;

}


