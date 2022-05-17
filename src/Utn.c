/*
 * Utn.c
 *
 *  Created on: 12 may. 2022
 *      Author: Hongo
 */

#include "Utn.h"

int esNumerica(char *cadena, int limite);
int getInt(int *pResultado);
int getString(char *cadena, int longitud);

/** \brief Valida si el string recibido es una palabra A-Z, a-z
 *
 * \param string
 * \return Devuelve 0 si es una palabra, 1 Si no lo es.
 */
int validateWordChar(char string[]) {
	int retorno = -1;
	int i = 0;
	if (string != NULL) {
		if (string[strnlen(string, 50) - 1] == '\n') {
			string[strnlen(string, 50) - 1] = '\0';
		}
		while (string[i] != '\0') {
			if (!(isalpha(string[i]))) {
				retorno = -1;
				break;
			} else {
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}
/** \brief Obtiene un string, y valida si el string recibido es una palabra A-Z, a-z
 *
 * \param *cadena puntero a string
 * * \param *mensaje Recibe el mensaje a mostrar cuando se obtiene el dato
 * * \param *mensajeError Recibe el mensaje de error para cuando no es un dato valido
 * * \param len
 * \return Devuelve 0 si esta ok, -1 Si no pudo obtener el string
 */
int getValidWord(char *cadena, char *mensaje, char *mensajeError, int len) {
	char auxCadena[len];
	int validacion;
	if (mensaje != NULL && mensajeError != NULL && len > 0) {
		do {
			printf("%s", mensaje);
			fgets(auxCadena, len, stdin);
			if (auxCadena[strnlen(auxCadena, len) - 1] == '\n') {
				auxCadena[strnlen(auxCadena, len) - 1] = '\0';
			}
			if (validateWordChar(auxCadena) == -1) {
				printf("%s", mensajeError);
				fflush(stdin);
				validacion = -1;
			} else {
				validacion = 0;
			}
		} while (validacion == -1);
	}
	strncpy(cadena, auxCadena, len);
	return 0;
}
/** \brief Obtiene un string, y valida si el string recibido contiene solo caracteres numericos
 * y un ".", luego lo transforma en un flotante .float
 *
 * \param *numero puntero a float
 * * \param *mensaje Recibe el mensaje a mostrar cuando se obtiene el dato
 * * \param *mensajeError Recibe el mensaje de error para cuando no es un dato valido
 * * \param len
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int getValidFloat(float *numero, char *mensaje, char *mensajeError, int len) {
	char charNumero[len];
	float numeroFinal;
	int validacion;
	if (mensaje != NULL && mensajeError != NULL && len > 0) {
		do {
			printf("%s", mensaje);
			fgets(charNumero, len, stdin);
			if (charNumero[strnlen(charNumero, 50) - 1] == '\n') {
				charNumero[strnlen(charNumero, 50) - 1] = '\0';
			}
			if (validateFloatChar(charNumero) == -1) {
				printf("%s", mensajeError);
				fflush(stdin);
				validacion = -1;
			} else {
				validacion = 0;
			}
		} while (validacion == -1);
		numeroFinal = atof(charNumero);
	}
	*numero = numeroFinal;
	return 0;
}
/** \brief Valida si el string recibido contiene solo numeros y hasta un "." que
 * divida en dos mitades (formato tipo flotante)
 *
 * \param string
 * \return Devuelve 0 si respeta el formato, -1 si no lo es
 */
int validateFloatChar(char string[]) {
	int retorno = -1;
	int i = 0;
	int contadorPuntos = 0;
	if (string != NULL) {
		if (string[strnlen(string, 50) - 1] == '\n') {
			string[strnlen(string, 50) - 1] = '\0';
		}
		while (string[i] != '\0') {
			if (string[i] == '.') {
				contadorPuntos++;
				if (contadorPuntos > 1) {
					retorno = -1;
					break;
				}
			}
			if (!(string[i] >= 48 && string[i] <= 57) && (string[i] != '.')) {
				retorno = -1;
				break;
			} else {
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	do {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		reintentos--;
	} while (reintentos >= 0);

	return retorno;
}
/**
 *brief Utiliza las funciones getString y esNumerica, para obtener y validar
 *brief una cadena como numero respectivamente, si salio ok,
 *brief transforma la cadena en un entero.
 *
 * * \param *cadena
 * * \param *limite
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];
	if (pResultado != NULL && getString(bufferString, sizeof(bufferString)) == 0
			&& esNumerica(bufferString, sizeof(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);

	}
	return retorno;
}

/**
 *brief Verifica si la cadena recibida es numerica, si contiene solo
 *brief los caracteres "1 al 9", "+" y "-"
 *
 * * \param *cadena
 * * \param *limite
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int esNumerica(char *cadena, int limite) {
	int retorno = -1; // ERROR
	int i;
	if (cadena != NULL && limite > 0) {
		retorno = 1; // VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/**
 *brief Obtiene un string, reemplaza los caracteres correspondientes
 *brief al enter si los encuentra, y los reemplaza con el caracter terminante
 *brief de la cadena
 *
 * * \param *cadena
 * * \param *longitud
 * \return Devuelve 0 si esta ok, -1 Si fallo
 */
int getString(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096];
	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int getEspaciosYLetras(char *string, int len, char *mensaje, char *mensajeError,
		int reintentos) {
	int retorno = -1;
	char bufferString[len];

	if (string != NULL && len > 0) {
		printf("%s", mensaje);
		do {
			if (getString(bufferString, sizeof(bufferString)) == 0
					&& isName(bufferString) == 1) {
				strncpy(string, bufferString, sizeof(bufferString));
				retorno = 0;
				break;

			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s", mensajeError);
				} else {
					printf("\n-Se quedo sin reintentos-\n");
				}
			}
		} while (reintentos > 0);
	}
	return retorno;
}

int isName(char *string) {
	int retorno = 1;
	int i = 0;
	int isAlpha;

	if (string != NULL) {
		while (string[i] != '\0') {
			isAlpha = isalpha(string[i]);
			if (isAlpha != 0 || string[i] == ' ') {
				i++;
			} else {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
