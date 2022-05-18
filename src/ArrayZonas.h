#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "tp_2_library.h"

#define LEN_ZONAS 10
#define LEN_NOM_APELL 51
#define PENDIENTE 1
#define FINALIZADO 2

struct {

	int isEmpty;
	int idZona;
	int idCensistaAsignado;
	int localidad;
	int estado;
	char calles[4][51];
	int cantidadInSitu;
	int cantidadVirtual;
	int ausentes;

}typedef Zona;

#ifndef ARRAYZONAS_H_
#define ARRAYZONAS_H_

int initZona(Zona list[], int len);
int altaZona(Zona list[], int lenStruct, int lenPalabra);
int findEmptyZona(Zona list[], int len);
int isThereAnyZona(Zona *list, int len);
int findZonaById(Zona *list, int len, int idZona);
int findZonaPendiente(Zona list[], int len);
int isZonaPendiente(Zona *list, int len, int idZona);

#endif /* ARRAYZONAS_H_ */
