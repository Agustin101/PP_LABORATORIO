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
void printAsignacion(zonaCenso * zonas, int lenZonas);
void mostrarZona(zonaCenso  zonas,  Censista  censistas);
void listarZonas(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas);
int sortCensistasByName(Censista *list, int lenCensistas,zonaCenso * zonas,int lenZonas );
int censistasEnEstadoActivo(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas);
int localidadMasAusentes(zonaCenso * zonas,int lenZonas );
int zonaMasCensada(Censista *list, int lenCensistas,zonaCenso * zonas,int lenZonas);
int promedioDeCensistas(Censista *list, int lenCensistas, zonaCenso *zonas,		int lenZonas);
#endif /* INFORMES_H_ */
