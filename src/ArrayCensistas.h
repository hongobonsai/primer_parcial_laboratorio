/*
 * ArrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Hongo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "tp_2_library.h"

#define LEN_CENSISTAS 5
#define LEN_NOM_APELL 51
#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#ifndef ARRAYCENCISTAS_H_
#define ARRAYCENCISTAS_H_

struct{
	int dia;
	int mes;
	int anio;
}typedef Nacimiento;

struct{
	char calle[21];
	int altura;
}typedef Direccion;

struct{

	int isEmpty;
	int id;
	int idZona;
	char nombre[LEN_NOM_APELL];
	char apellido[LEN_NOM_APELL];
	int estado;
	int edad;
	Nacimiento fechaNacimiento;
	Direccion direccion;

}typedef Censista;

int initCensistas(Censista list[], int len);
int findEmptySpace(Censista list[], int len);
int altaCensista(Censista list[], int lenStruct, int lenPalabra);
int isThereAnyCensista(Censista *list, int len);
int findCensistaById(Censista *list, int len, int id);
int modificarCensista(Censista list[], int lenStruct, int lenPalabra);
int bajaCensista(Censista list[], int len);
int findCensistaLiberado(Censista list[], int len);

#endif /* ARRAYCENCISTAS_H_ */





