/*
 * Informes.h
 *
 *  Created on: 16 may. 2022
 *      Author: Agustin
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Censista.h"
#include "zonaCenso.h"
int printCargaDeDatos(zonaCenso * zonas, int length, Censista * censista);
int asignarZonaACensar(Censista* censistas, int len,zonaCenso* zonas);
int cargaDeDatos(zonaCenso * zonas, int len, Censista * censistas);
int printZonasyCensistas(zonaCenso * zonas, int length, Censista * censistas);
#endif /* INFORMES_H_ */
