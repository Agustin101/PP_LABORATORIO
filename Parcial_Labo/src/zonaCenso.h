/*
 * zonaCenso.h
 *
 *  Created on: 15 may. 2022
 *      Author: Agustin
 */

#ifndef ZONACENSO_H_
#define ZONACENSO_H_

#define PENDIENTE 1
#define FINALIZADO 2
#include "bibliotecaESDeDatos.h"
#define LANUS 1
#define AVELLANEDA 2
#define GERLI 3
#define ALSINA 4
#define BARRACAS 5


struct{
	char calles[4][51]; //ya
	int localidad; //ya
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int estadoZona; //ya
	int isEmpty; //no
	int idZona;  //ya
	int idCensistaAsignado; //no
}typedef zonaCenso;

void cargaForzadaZona(zonaCenso * zonas);
int printZonas(zonaCenso * zonas, int length);
int initZonas(zonaCenso *list, int len);
int zonaId(void);
int encontrarZonaPorId(zonaCenso *zonas, int len, int id);
int encontrarPosicionLibre(zonaCenso *zonas, int len);
int cargarZona(zonaCenso * zonas, int len, int localidad);
int printZonaCensar(zonaCenso * zonas, int length);
int hayZona(zonaCenso *zonas, int len);
int buscarZonaPendiente(zonaCenso *zonas, int lenZonas);
int verificarZona(zonaCenso *zonas, int len, int id);
#endif /* ZONACENSO_H_ */
