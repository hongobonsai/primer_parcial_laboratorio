



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utn.h"
#include "tp_2_library.h"

#include "ArrayCensistas.h"
#include "ArrayZonas.h"


#ifndef STRUCTLIB_H_
#define STRUCTLIB_H_

int asignarCensistaResponsable(Zona *zonas, Censista *cencistas, int lenZona, int lenCen);
int findCensistaByZona(Censista *cencistas, int lenCen, int idZona);
int finalizarZona(Zona *zonas, Censista *cencistas, int lenZona, int lenCen);

#endif /* STRUCTLIB_H_ */
