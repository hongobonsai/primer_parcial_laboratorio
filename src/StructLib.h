



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "ArrayCensistas.h"
#include "ArrayZonas.h"
#include "LocalLibrary.h"


#ifndef STRUCTLIB_H_
#define STRUCTLIB_H_

int asignarCensistaResponsable(Zona *zonas, Censista *cencistas, int lenZona, int lenCen);
int findCensistaByZona(Censista *cencistas, int lenCen, int idZona);
int finalizarZona(Zona *zonas, Censista *cencistas, int lenZona, int lenCen);
int printZonas(Zona zonas[], Censista *cencistas, int lenZonas, int lenCencistas, char arrayLocalidades[][26], int lenLocalidades);
void hardCodeCencista(Censista list[]);

#endif /* STRUCTLIB_H_ */
