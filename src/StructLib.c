#include "StructLib.h"

int asignarCensistaResponsable(Zona *zonas, Censista *cencistas, int lenZona,
		int lenCen) {

	int retorno = -1;
	int auxIdZona;
	int indiceZona;
	int indiceLiberado;

	if ((indiceLiberado = findCensistaLiberado(cencistas, lenCen)) != -1) {
		if (findZonaPendiente(zonas, lenZona) != -1) {
			if (utn_getNumero(&auxIdZona,
					"\nIngrese el ID de la zona a censar: ",
					"\n-Ingrese un dato valido-", 1000, 5999, 5) == 0) {
				if ((indiceZona = findZonaById(zonas, lenZona, auxIdZona))
						!= -1) {
					if (findCensistaByZona(cencistas, lenCen, auxIdZona)
							== -1) {
						cencistas[indiceLiberado].idZona = auxIdZona;
						zonas[indiceZona].idCensistaAsignado =
								cencistas[indiceLiberado].id;
						;
						cencistas[indiceLiberado].estado = ACTIVO;
						printf("\n-La zona sera censada por: %s %s-\n",
								cencistas[indiceLiberado].nombre,
								cencistas[indiceLiberado].apellido);
						printf("\n+LA ZONA FUE ASIGNADA CORRRECTAMENTE+\n");
						retorno = 0;

					} else {
						printf("\n-YA HAY UN CENSISTA ASIGNADO A ESTA ZONA-\n");
					}

				} else {
					printf(
							"\n-EL ID INGRESADO NO CORRESPONDE A NINGUNA ZONA-\n");
				}
			} else {
				printf(
						"\n-SE ACABARON LOS REINTENTOS. NO SE ASIGNÓ NINGUN CENSISTA-\n");
			}
		} else {
			printf("\n-NO SE CARGÓ NINGUNA ZONA-\n");
		}
	} else {
		printf("\n-NO SE CARGARON CENSISTAS/NO HAY CENSISTAS LIBERADOS-\n");
	}
	return retorno;
}

int finalizarZona(Zona *zonas, Censista *cencistas, int lenZona, int lenCen) {
	int retorno = -1;
	int auxIdZona;
	int indiceZona;
	int indiceCensista;

	if (isThereAnyCensista(cencistas, lenCen) != -1) {
		if (findZonaPendiente(zonas, lenZona) != -1) {
			if (utn_getNumero(&auxIdZona,
					"\nIngrese el ID de la zona a finalizar: ",
					"\n-Ingrese un dato valido-", 1000, 5999, 5) == 0) {
				if ((indiceZona = isZonaPendiente(zonas, lenZona, auxIdZona)) != -1) {
					if ((indiceCensista = findCensistaByZona(cencistas, lenCen, auxIdZona)) != -1) {

						zonas[indiceZona].estado = FINALIZADO;
						cencistas[indiceCensista].estado = LIBERADO;
						printf("\n-La zona fue finalizada por: %s %s-\n",
								cencistas[indiceCensista].nombre,
								cencistas[indiceCensista].apellido);
						printf("\n+LA ZONA FUE FINALIZADA CORRECTAMENTE+\n");
						retorno = 0;
					} else {
						printf("\n-ESTA ZONA NO FUE CENSADA POR NINGUN CENSISTA-\n");
					}
				} else {
					printf("\n-EL ID INGRESADO NO CORRESPONDE A NINGUNA ZONA PENDIENTE-\n");
				}
			} else {
				printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZARA LA FINALIZACION-\n");
			}
		} else {
			printf("\n-NO SE CARGÓ NINGUNA ZONA/NO HAY ZONAS PENDIENTES-\n");
		}
	} else {
		printf("\n-NO SE CARGARON CENSISTAS-\n");
	}
	return retorno;
}

int findCensistaByZona(Censista *cencistas, int lenCen, int idZona) {
	int retorno = -1;
	for (int i = 0; i < lenCen; i++) {
		if (cencistas[i].idZona == idZona && cencistas[i].estado == ACTIVO) {
			retorno = i;
			break;
		}
	}
	printf("\nretorno - %d", retorno);
	return retorno;
}

