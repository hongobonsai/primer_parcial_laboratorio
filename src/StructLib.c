#include "StructLib.h"

int asignarCensistaResponsable(Zona *zonas, Censista *censistas, int lenZona,
		int lenCen) {

	int retorno = -1;
	int auxIdZona;
	int indiceZona;
	int indiceLiberado;

	if ((indiceLiberado = findCensistaLiberado(censistas, lenCen)) != -1) {
		if (findZonaPendiente(zonas, lenZona) != -1) {
			if (utn_getNumero(&auxIdZona,
					"\nIngrese el ID de la zona a censar: ",
					"\n-Ingrese un dato valido-", 1000, 5999, 5) == 0) {
				if ((indiceZona = findZonaById(zonas, lenZona, auxIdZona))
						!= -1) {
					if (findCensistaByZona(censistas, lenCen, auxIdZona)
							== -1) {
						censistas[indiceLiberado].idZona = auxIdZona;
						zonas[indiceZona].idCensistaAsignado =
								censistas[indiceLiberado].id;
						;
						censistas[indiceLiberado].estado = ACTIVO;
						printf("\n-La zona sera censada por: %s %s-\n",
								censistas[indiceLiberado].nombre,
								censistas[indiceLiberado].apellido);
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
	int cantVirtual;
	int cantInSitu;
	int cantAusentes;

	if (isThereAnyCensista(cencistas, lenCen) != -1) {
		if (findZonaPendiente(zonas, lenZona) != -1) {
			if (utn_getNumero(&auxIdZona,
					"\nIngrese el ID de la zona a finalizar: ",
					"\n-Ingrese un dato valido-", 1000, 5999, 5) == 0) {
				if ((indiceZona = isZonaPendiente(zonas, lenZona, auxIdZona))
						!= -1) {
					if ((indiceCensista = findCensistaByZona(cencistas, lenCen,
							auxIdZona)) != -1) {
						if (utn_getNumero(&cantVirtual,
								"\n¿Cuantas personas censadas en esta zona completaron el censo virtual?: ",
								"\n-Ingrese un dato valido-", 0, 250, 5) == 0) {
							if (utn_getNumero(&cantInSitu,
									"\n¿Cuantas personas fueron censadas in situ por el censista?: ",
									"\n-Ingrese un dato valido-", 0, 250, 5)
									== 0) {
								if (utn_getNumero(&cantAusentes,
										"\n¿Cuantas personas no se encontraban en su domicilio a la hora de realizar el censo?: ",
										"\n-Ingrese un dato valido-", 0, 250, 5)
										== 0) {

									zonas[indiceZona].censados.cantidadVirtual =
											cantVirtual;
									zonas[indiceZona].censados.cantidadInSitu =
											cantInSitu;
									zonas[indiceZona].censados.cantidadAusentes =
											cantAusentes;

									zonas[indiceZona].estado = FINALIZADO;
									cencistas[indiceCensista].estado = LIBERADO;
									printf(
											"\n-La zona fue finalizada por: %s %s-\n",
											cencistas[indiceCensista].nombre,
											cencistas[indiceCensista].apellido);
									printf(
											"\n+LA ZONA FUE FINALIZADA CORRECTAMENTE+\n");
									retorno = 0;

								} else {
									printf(
											"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZARA LA FINALIZACION-\n");
								}
							} else {
								printf(
										"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZARA LA FINALIZACION-\n");
							}
						} else {
							printf(
									"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZARA LA FINALIZACION-\n");
						}

					} else {
						printf(
								"\n-ESTA ZONA NO FUE CENSADA POR NINGUN CENSISTA-\n");
					}
				} else {
					printf(
							"\n-EL ID INGRESADO NO CORRESPONDE A NINGUNA ZONA PENDIENTE-\n");
				}
			} else {
				printf(
						"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZARA LA FINALIZACION-\n");
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
	return retorno;
}

int printZonas(Zona zonas[], Censista *cencistas, int lenZonas,
		int lenCencistas, char arrayLocalidades[][26], int lenLocalidades) {

	int localidadIteracion;
	int estadoIteracion;
	int indiceCencista;
	char arrayEstados[2][26] = { "PENDIENTE", "FINALIZADO" };

	if (zonas != NULL && cencistas != NULL && lenZonas > 0
			&& lenCencistas > 0) {
		if (isThereAnyZona(zonas, lenZonas) != -1) {

			printf(
					"\n+--------------------------------------------------------------------------------------------------------------------------+"
							"\n| ID ZONA |          CENCISTA ASIGNADO          |      LOCALIDAD      |         CALLES        |   ESTADO   |   CENSADOS    |"
							"\n+---------+-------------------------------------+---------------------+-----------------------+------------+---------------+");

			for (int i = 0; i < lenZonas; i++) {
				if (zonas[i].isEmpty == 0) {
					localidadIteracion = zonas[i].localidad;
					localidadIteracion--;
					estadoIteracion = zonas[i].estado;
					estadoIteracion--;

					if (findCensistaById(cencistas, lenCencistas,
							zonas[i].idCensistaAsignado) != -1) {
						indiceCencista = findCensistaById(cencistas,
								lenCencistas, zonas[i].idCensistaAsignado);

						printf(
								"\n| %-4d    | %17s %-17s | %-19s | %-21s | %-10s | VIRTUAL: %-3d  |"
										"\n|         |                                     |                     | %-21s |            | IN SITU: %-3d  |\n"
										"|         |                                     |                     | %-21s |            | AUSENTES: %-3d |\n"
										"|         |                                     |                     | %-21s |            |               |\n"
										"+---------+-------------------------------------+---------------------+-----------------------+------------+---------------+\n",
								zonas[i].idZona,
								cencistas[indiceCencista].nombre,
								cencistas[indiceCencista].apellido,
								arrayLocalidades[localidadIteracion],
								zonas[i].calles[0],
								arrayEstados[estadoIteracion],
								zonas[i].censados.cantidadVirtual,
								zonas[i].calles[1],
								zonas[i].censados.cantidadInSitu,
								zonas[i].calles[2],
								zonas[i].censados.cantidadAusentes,
								zonas[i].calles[3]);
					} else {
						printf(
								"\n| %-4d    |  NO SE ASIGNO UN CENSISTA A LA ZONA | %-19s | %-21s | %-10s | VIRTUAL: %-3d  |"
										"\n|         |                                     |                     | %-21s |            | IN SITU: %-3d  |\n"
										"|         |                                     |                     | %-21s |            | AUSENTES: %-3d |\n"
										"|         |                                     |                     | %-21s |            |               |\n"
										"+---------+-------------------------------------+---------------------+-----------------------+------------+---------------+\n",
								zonas[i].idZona,
								arrayLocalidades[localidadIteracion],
								zonas[i].calles[0],
								arrayEstados[estadoIteracion],
								zonas[i].censados.cantidadVirtual,
								zonas[i].calles[1],
								zonas[i].censados.cantidadInSitu,
								zonas[i].calles[2],
								zonas[i].censados.cantidadAusentes,
								zonas[i].calles[3]);

					}

				}
			}
		}else {
			printf("\n-NO SE CARGÓ NINGUNA ZONA/NO HAY ZONAS PENDIENTES-\n");
		}

	}
	return 0;
}

