#include "ArrayCensistas.h"

/** \brief Para indicar que todas las posiciones en la matriz están vacías,
 * esta función pone la bandera (isEmpty) en VERDADERO en todas las posiciones de la estructura
 *
 * \param list Passenger* Puntero a la estructura
 * \param len Largo del array
 * \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int initCensistas(Censista list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int altaCensista(Censista list[], int lenStruct, int lenPalabra) {

	int reintento = 5;
	int retorno = -1;
	int validacion;
	char auxNombre[lenPalabra];
	char auxApellido[lenPalabra];
	int auxId;
	int auxEdad;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxCalle[51];
	int auxAltura;
	int restaEdad;
	int indiceVacio;
	if ((findEmptySpace(list, lenStruct)) != -1) {

		printf("\n-CARGA DE DATOS-\n");

		if (getEspaciosYLetras(auxNombre, lenPalabra,
				"\nIntroduzca el nombre del censista: ",
				"\n-Ingrese un nombre valido-\n", 5) == 0
				&& getEspaciosYLetras(auxApellido, lenPalabra,
						"\nIntroduzca el apellido del censista: ",
						"\n-Ingrese un apellido valido-\n", 5) == 0
				&& utn_getNumero(&auxEdad, "\nIngrese su edad",
						"\n-Ingrese un dato valido-\n", 18, 50, 5) == 0) {

			printf("\n-FECHA DE NACIMIENTO-\n");

			if (utn_getNumero(&auxDia, "\nIngrese su dia de nacimiento",
					"\nIngrese un dato valido", 1, 31, 5) == 0
					&& utn_getNumero(&auxMes, "\nIngrese su mes de nacimiento",
							"\n-Ingrese un dato valido-\n", 1, 12, 5) == 0) {

				do {
					utn_getNumero(&auxAnio, "\nIngrese su año de nacimiento",
							"\n-Ingrese un dato valido-\n", 1972, 2003, 5);
					restaEdad = 2022 - auxAnio;

					if ((restaEdad == auxEdad)) {
						validacion = 0;
					} else {
						printf(
								"\n-Su año de nacimiento no condice con su edad-");
						validacion = 1;
						reintento--;
					}
					if (reintento == 0) {
						printf(
								"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
					}
				} while (validacion == 1 || reintento == 0);

				printf("\n-DIRECCION-\n");

				if (validacion == 0) {
					if (getEspaciosYLetras(auxCalle, lenPalabra,
							"\nIntroduzca la calle de residencia: ",
							"\n-Ingrese una calle valida-\n", 5) == 0
							&& utn_getNumero(&auxAltura,
									"\nIngrese la altura de la calle",
									"\n-Ingrese una altura valida-\n", 0, 27300,
									5) == 0) {

						if (list != NULL && lenStruct > 0) {
							indiceVacio = findEmptySpace(list, lenStruct);
							if (indiceVacio != -1) {
								auxId = calcularId();
								list[indiceVacio].id = auxId;
								strncpy(list[indiceVacio].nombre, auxNombre,
										sizeof(list[indiceVacio].nombre));
								strncpy(list[indiceVacio].apellido, auxApellido,
										sizeof(list[indiceVacio].apellido));
								list[indiceVacio].edad = auxEdad;
								list[indiceVacio].fechaNacimiento.dia = auxDia;
								list[indiceVacio].fechaNacimiento.mes = auxMes;
								list[indiceVacio].fechaNacimiento.anio =
										auxAnio;
								strncpy(list[indiceVacio].direccion.calle,
										auxCalle,
										sizeof(list[indiceVacio].direccion.calle));
								list[indiceVacio].direccion.altura = auxAltura;
								list[indiceVacio].isEmpty = 0; //ESCRIBE EL EMPTY
								list[indiceVacio].estado = LIBERADO; //ESCRIBE ESTADO LIBERADO
								list[indiceVacio].idZona = 0;
								printf("\n-El cencista se cargo con estado: LIBERADO.-\n");
								printf(
										"\n+SE REALIZO LA CARGA CORRECTAMENTE+\n");
								retorno = 0;
							} else {
								printf(
										"\n-NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL CENSISTA-");
								retorno = -1;
							}
						}
					} else {
						printf(
								"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
						retorno = -1;
					}
				} else {
					printf(
							"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
					retorno = -1;
				}
			} else {
				printf(
						"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
				retorno = -1;
			}
		} else {
			printf("\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO LA CARGA-");
			retorno = -1;
		}
	} else {
		printf("\n-NO SE ENCONTRÓ ESPACIO LIBRE, NO SE AGREGÓ EL CENSISTA-");
		retorno = -1;
	}
	//printf("%d\n %s\n %s\n %d\n %d\n %d\n %d\n %s\n %d\n", auxId, auxNombre, auxApellido, auxEdad, auxDia, auxMes, auxAnio, auxCalle, auxAltura);
	return retorno;
}

int modificarCensista(Censista list[], int lenStruct, int lenPalabra) {

	int retorno = -1;

	int opcionDato;
	int opcionSubmenuNacimiento;
	int indiceEncontrado;
	int opcionSubmenuDireccion;

	char auxNombre[lenPalabra];
	char auxApellido[lenPalabra];
	int auxId;
	int auxEdad;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxCalle[51];
	int auxAltura;

	if (isThereAnyCensista(list, LEN_CENSISTAS) != -1) {
		printf("\n-MODIFICAR DATOS-\n");

		if (utn_getNumero(&auxId, "\nIngrese el ID del cencista a modificar: ",
				"\n-Ingrese un dato valido-", 3000, 9999, 5) == 0) {
			if ((indiceEncontrado = findCensistaById(list, LEN_CENSISTAS, auxId))
					!= -1) {

				do {

					printf("\nNOMBRE: %s"
							"\nAPELLIDO: %s"
							"\nID: %d"
							"\nEDAD: %d"
							"\nDIA: %d"
							"\nMES: %d"
							"\nAÑO: %d"
							"\nCALLE: %s"
							"\nALTURA: %d\n", list[indiceEncontrado].nombre,
							list[indiceEncontrado].apellido,
							list[indiceEncontrado].id,
							list[indiceEncontrado].edad,
							list[indiceEncontrado].fechaNacimiento.dia,
							list[indiceEncontrado].fechaNacimiento.mes,
							list[indiceEncontrado].fechaNacimiento.anio,
							list[indiceEncontrado].direccion.calle,
							list[indiceEncontrado].direccion.altura);

					if (utn_getNumero(&opcionDato,
							"\n-¿QUE DATO DESEA MODIFICAR?-\n"
									"\n1. NOMBRE"
									"\n2. APELLIDO"
									"\n3. FECHA DE NACIMIENTO"
									"\n4. DIRECCION"
									"\n0. EXIT",
							"\n-Ingrese una opcion valida-\n", 0, 4, 5) == 0) {

						switch (opcionDato) {

						case 1:
							if (getEspaciosYLetras(auxNombre, lenPalabra,
									"\nIngrese el nuevo nombre: ",
									"\n-Ingrese un dato valido-", 5) == 0) {
								strncpy(list[indiceEncontrado].nombre,
										auxNombre,
										sizeof(list[indiceEncontrado].nombre));
								retorno = 0;
							} else {
								printf("\n-NO SE REALIZO LA CARGA-\n");
							}
							break;
						case 2:
							if (getEspaciosYLetras(auxApellido, lenPalabra,
									"\nIngrese el nuevo apellido: ",
									"\n-Ingrese un dato valido-", 5) == 0) {
								strncpy(list[indiceEncontrado].apellido,
										auxApellido,
										sizeof(list[indiceEncontrado].apellido));
								retorno = 0;
							} else {
								printf("\n-NO SE REALIZO LA CARGA-\n");
							}
							break;
						case 3:
							do {
								printf("\nID: %d"
										"\nEDAD: %d"
										"\nDIA: %d"
										"\nMES: %d"
										"\nAÑO: %d", list[indiceEncontrado].id,
										list[indiceEncontrado].edad,
										list[indiceEncontrado].fechaNacimiento.dia,
										list[indiceEncontrado].fechaNacimiento.mes,
										list[indiceEncontrado].fechaNacimiento.anio);
								if (utn_getNumero(&opcionSubmenuNacimiento,
										"\n-¿QUE DATO DESEA MODIFICAR?-\n"
												"\n*La edad se calculará automaticamente con el año de nacimiento."
												"\n1. DIA"
												"\n2. MES"
												"\n3. AÑO"
												"\n0. EXIT",
										"\n-Ingrese una opcion valida-", 0, 3,
										5) == 0) {
									switch (opcionSubmenuNacimiento) {

									case 1:
										if (utn_getNumero(&auxDia,
												"\nIngrese el nuevo dia de nacimiento",
												"\nIngrese un dato valido", 1,
												31, 5) == 0) {
											list[indiceEncontrado].fechaNacimiento.dia =
													auxDia;
											retorno = 0;
										} else {
											printf(
													"\n-NO SE REALIZO LA CARGA-\n");
										}
										break;
									case 2:
										if (utn_getNumero(&auxMes,
												"\nIngrese el nuevo mes de nacimiento",
												"\n-Ingrese un dato valido-\n",
												1, 12, 5) == 0) {
											list[indiceEncontrado].fechaNacimiento.mes =
													auxMes;
											retorno = 0;
										} else {
											printf(
													"\n-NO SE REALIZO LA CARGA-\n");
										}
										break;
									case 3:
										if (utn_getNumero(&auxAnio,
												"\nIngrese su año de nacimiento",
												"\n-Ingrese un dato valido-\n",
												1972, 2003, 5) == 0) {
											list[indiceEncontrado].fechaNacimiento.anio =
													auxAnio;
											auxEdad = 2022 - auxAnio;
											list[indiceEncontrado].edad =
													auxEdad;
											retorno = 0;
										} else {
											printf(
													"\n-NO SE REALIZO LA CARGA-\n");
										}

										break;
									case 0:
										break;
									}
								}
							} while (opcionSubmenuNacimiento != 0);
							break;
						case 4:
							do {
								printf("\nCALLE: %s"
										"\nALTURA: %d\n",
										list[indiceEncontrado].direccion.calle,
										list[indiceEncontrado].direccion.altura);
								if (utn_getNumero(&opcionSubmenuDireccion,
										"\n-¿QUE DATO DESEA MODIFICAR?-\n"
												"\n1. CALLE"
												"\n2. ALTURA"
												"\n0. EXIT",
										"\n-Ingrese una opcion valida-", 0, 2,
										5) == 0) {

									switch (opcionSubmenuDireccion) {

									case 1:
										if (getEspaciosYLetras(auxCalle,
												lenPalabra,
												"\nIngrese la nueva calle: ",
												"\n-Ingrese un dato valido-", 5)
												== 0) {
											strncpy(
													list[indiceEncontrado].direccion.calle,
													auxCalle,
													sizeof(list[indiceEncontrado].direccion.calle));
											retorno = 0;
										} else {
											printf(
													"\n-NO SE REALIZO LA CARGA-\n");
										}
										break;
									case 2:
										if (utn_getNumero(&auxAltura,
												"\nIngrese la nueva altura",
												"\n-Ingrese un dato valido-\n",
												0, 27300, 5) == 0) {
											list[indiceEncontrado].direccion.altura =
													auxAltura;
											retorno = 0;
										} else {
											printf(
													"\n-NO SE REALIZO LA CARGA-\n");
										}
										break;
									case 0:
										break;
									}
								}
							} while (opcionSubmenuDireccion != 0);

							break;
						case 0:
							break;
						}
					} else {
						printf(
								"\n-SE ACABARON LOS REINTENTOS. NO SE REALIZO MODIFICACION-\n");
						opcionDato = 0;
					}
				} while (opcionDato != 0);

			} else {
				printf(
						"\n-EL ID INGRESADO NO CORRESPONDE A NINGUN CENSISTA-\n");
			}

		} else {
			printf(
					"\n-SE ACABARON LOS REINTENTOS. REGRESANDO AL MENÚ PRINCIPAL-\n");
		}
	} else {
		printf("\n-NO SE CARGÓ NINGUN CENSISTA-\n");
	}

	return retorno;
}

int bajaCensista(Censista list[], int len) {
	int retorno = -1;
	int auxId;
	int indiceEncontrado;
	if (isThereAnyCensista(list, LEN_CENSISTAS) != -1) {
		if (utn_getNumero(&auxId, "\nIngrese el ID del cencista a modificar: ",
				"\n-Ingrese un dato valido-", 3000, 9999, 5) == 0) {
			if ((indiceEncontrado = findCensistaById(list, LEN_CENSISTAS, auxId))
					!= -1) {
				if (list[indiceEncontrado].estado != ACTIVO) {
					list[indiceEncontrado].estado = INACTIVO;
				} else {
					printf(
							"\n-¡NO SE PUEDE DAR DE BAJA A UN CENCISTA ACTIVO!-\n");
				}
			} else {
				printf(
						"\n-EL ID INGRESADO NO CORRESPONDE A NINGUN CENSISTA-\n");
			}
		} else {
			printf(
					"\n-SE ACABARON LOS REINTENTOS. REGRESANDO AL MENÚ PRINCIPAL-\n");
		}
	} else {
		printf("\n-NO SE CARGÓ NINGUN CENSISTA-\n");
	}
	return retorno;
}

int findEmptySpace(Censista list[], int len) {
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

int isThereAnyCensista(Censista *list, int len) { //IS THERE ANYBODY... OUT - THERE
	int retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int findCensistaById(Censista *list, int len, int id) {
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int findCensistaLiberado(Censista list[], int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].estado == 3 && list[i].isEmpty == 0) {

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
