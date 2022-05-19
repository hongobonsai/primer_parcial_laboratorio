#include "StructLib.h"
/** \brief Asigna el primer censista encontrado al id de zona
 *
 * \param list Censista*
 * * \param list Zona*
 * \param len int
 * \param id int
 * \return
 */
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
/** \brief Finaliza una zona, pone como finalizado su estado, carga censados.
 *
 * \param list Censista*
 * * \param list Zona*
 * \param len int
 * \param id int
 * \return
 */
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
/** \brief Encuentra el indice de un censista comparandolo con el id de una zona
 *
 * \param list Censista*
 * * \param list Zona*
 * \param len int
 * \param id int
 * \return
 */
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
int findCensistaByZonaDos(Censista *cencistas, int lenCen, int idZona) {
	int retorno = -1;
		for (int i = 0; i < lenCen; i++) {
			if (cencistas[i].idZona == idZona) {
				retorno = i;
				break;
			}
		}
		return retorno;
	}
/** \brief Imprime todas las zonas, sus datos, quien los censa.
 *
 * \param list Censista*
 * * \param list Zona*
 * \param len int
 * \param id int
 * \return
 */
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
		} else {
			printf("\n-NO SE CARGÓ NINGUNA ZONA/NO HAY ZONAS PENDIENTES-\n");
		}

	}
	return 0;
}

int activoZonaPendiente(Zona *zonas, Censista *censistas, int lenZona,
		int lenCen) {

	int auxIdZona;
	int auxIndiceZona;
	int contadorDeCensistas = 0;
	for (int i = 0; i < lenCen; i++) {

		if (censistas[i].estado == ACTIVO) {

			auxIdZona = censistas[i].idZona;
			auxIndiceZona = findZonaById(zonas, lenZona, auxIdZona);

			if (zonas[auxIndiceZona].estado == PENDIENTE) {
				contadorDeCensistas++;
			}

		}

	}
	printf("\nCantidad de censistas ACTIVOS cuya zona está PENDIENTE: %d\n",
			contadorDeCensistas);

	return 0;
}

int localidadMasCasasAusentes(Zona *zonas, int lenZona, char arrayLocalidades[][26]) {

//	 {"AVELLANEDA", "BARRACAS", "LA BOCA", "SAN TELMO", "SANTOS LUGARES",
//				"CASEROS", "PALOMAR", "SAN MARTIN", "HURLINGHAM", "BELLA VISTA"};

	int aux = 0;
	int mayorLoca;
	int estaOrdenado;
	int i = 0;

	do{

		if (zonas[i].isEmpty == 0 && zonas[i].estado == FINALIZADO) {

			aux = zonas[i].censados.cantidadAusentes;
			if (zonas[i].censados.cantidadAusentes > aux){
				estaOrdenado = 0;
				aux = zonas[i].censados.cantidadAusentes;
				mayorLoca = zonas[i].localidad;
				mayorLoca--;
			} else{
				aux = zonas[i].censados.cantidadAusentes;
				mayorLoca = zonas[i].localidad;
				mayorLoca--;
				break;
			}

		}

		}while (estaOrdenado != 1);
	printf("La localidad con mas ausentes es: %s", arrayLocalidades[mayorLoca]);
	return 0;
}


int promedioCensosPorZona(Zona *zonas, Censista *censistas, int lenZona){

	int total = 0;
	int promedio;
	int indiceCen;
	int idZona;

	for(int i = 0; i<lenZona; i++){

		if(zonas[i].isEmpty == 0 && censistas[i].isEmpty == 0 && zonas[i].estado == FINALIZADO){

		total += zonas[i].censados.cantidadInSitu;
		total += zonas[i].censados.cantidadVirtual;
		promedio = total / 2;

		zonas[i].censados.promedio = promedio;
		printf("\nID ZONA: %d\n"
				"PROMEDIO: %d\n", zonas[i].idZona, zonas[i].censados.promedio);

		idZona = zonas[i].idZona;
		indiceCen = findCensistaByZonaDos(censistas, 10, idZona); //retorna -1 no se por que
		printf("promedio %d",promedio);
		printf("indiceCen %d",indiceCen);
		printf("idZona %d",idZona);
		censistas[indiceCen].promedioCensados += promedio;
		}
	}

	for(int i = 0; i<lenZona; i++){

			if(censistas[i].isEmpty == 0){
				printf("\nID: %d\n"
						"NOMBRE: %s\n"
						"APELLIDO: %s\n"
						"PROMEDIO: %d\n", censistas[i].id, censistas[i].nombre, censistas[i].apellido, censistas[i].promedioCensados);

			}
		}


	return 0;
}


