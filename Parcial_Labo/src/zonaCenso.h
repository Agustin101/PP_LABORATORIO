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
	char calles[4][51];
	int localidad;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int estadoZona;
	int isEmpty;
	int idZona;
	int idCensistaAsignado;
}typedef zonaCenso;

void cargaForzadaZona(zonaCenso * zonas);
int initZonas(zonaCenso *list, int len);
int zonaId(void);
int encontrarZonaPorId(zonaCenso *zonas, int len, int id);
int encontrarPosicionLibre(zonaCenso *zonas, int len);
int cargarZona(zonaCenso * zonas, int len, int localidad);
int hayZona(zonaCenso *zonas, int len);
int buscarZonaPendiente(zonaCenso *zonas, int lenZonas);
int verificarZona(zonaCenso *zonas, int len, int id);
int hayZonaPendiente(zonaCenso *zonas, int len);
#endif /* ZONACENSO_H_ */
