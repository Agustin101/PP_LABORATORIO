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
#include "bibliotecaESDeDatos.h"

void printCargaDeDatos(zonaCenso * zonas, int lenZonas, Censista * censista, int lenCensistas);
int asignarZonaACensar(Censista* censistas, int lenCensista,zonaCenso* zonas, int lenZonas);
int cargaDeDatos(zonaCenso * zonas, int lenCensistas, Censista * censistas, int lenZonas);
int printZonasyCensistas(zonaCenso * zonas, int length, Censista * censistas);
void mostrarZonas(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas);
void mostrarZona(zonaCenso  zonas,  Censista  censistas);
int listarZonas(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas);
#endif /* INFORMES_H_ */
