/*
 * Censista.h
 *
 *  Created on: 15 may. 2022
 *      Author: Agustin
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaESDeDatos.h"
#include "nacimientoCensista.h"
#include "direccionCensista.h"

#define LIBERADO 1
#define ACTIVO 2
#define INACTIVO 3

struct
{
	char  name[51];
	char  lastName[51];
	Nacimiento datosNacimiento;
	Direccion direccionCensista;
	int estadoCensista;
	int edadCensista;
	int idCensista;
	int idZona;
	int isEmpty;
}typedef Censista;

int agregarCensista(Censista *list, int len);
int sortPassengersByFlyCode(Censista* list, int len, int order); // por ahora no
int printCensistas(Censista* list, int length);
int sortPassengersByName(Censista* list, int len, int order); // por ahora no
int removeCensista(Censista *censista, int len, int id);
int findCensistaById(Censista* list, int len,int id);
int initCensistas(Censista* list, int len);
int findFreeIndex(Censista* list,int len);
int hayCensista(Censista *list, int len);
int modificarCensista(Censista *list, int len, int id);
int promedioPassengers(Censista * list, int len );
int censistaId(void);
void cargaForzadaCensistas(Censista * list);
int encontrarCensistaLiberado(Censista *list, int len);
int encontrarCensistaPorIdZona(Censista *cencistas, int len, int id);
int verificarCensista(Censista *censistas, int len, int idZona);
#endif /* CENSISTA_H_ */
