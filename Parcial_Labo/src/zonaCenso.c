/*
 * zonaCenso.c
 *
 *  Created on: 15 may. 2022
 *      Author: Agustin
 */

#include "zonaCenso.h"



int initZonas(zonaCenso *list, int len) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			list[i].localidad = i+1;
		}
		retorno = 0;
	}
	return retorno;
}

/// @brief Genera una id autoinrecemental.
///
/// @return Retorna el numero de id.
int zonaId(void) {
	static int id = 1999;
	id++;
	return id;
}

int encontrarZonaPorId(zonaCenso *zonas, int len, int id){
	int retorno = -1;

		if(zonas != NULL && len > 0){
			for(int i = 0; i<len;i++){
				if(zonas[i].isEmpty==0 && zonas[i].idZona == id){
					retorno = i;
				}
			}
		}
	return retorno;
}





int cargarZona(zonaCenso * zonas, int len, int localidad){
	int retorno = -1;
	char auxCalles[4][51];
	int indiceLibre;


		if(zonas != NULL && len > 0){
				switch(localidad){
				case 1 : //lanus
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = LANUS;
						}
					}
					break;
				case 2 : // avellaneda
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = AVELLANEDA;
						}
					}
					break;
				case 3 : // GERLI
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = GERLI;
						}
					}
					break;
				case 4 : // caballito
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = CABALLITO;
						}
					}
					break;
				case 5 : // barracas
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = BARRACAS;
						}
					}
					break;
				case 6 :
					printf("Volviendo al menu principal.");
					break;
				}
		}

	return retorno;
}

int encontrarPosicionLibre(zonaCenso *zonas, int len) {
	int retorno;
	retorno = -1;
	if (zonas != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (zonas[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printZonaCensar(zonaCenso * zonas, int length){
	int retorno = -1;
	char auxLocalidad[51];

		if (zonas != NULL && length > 0) {
			for (int i = 0; i < length; i++) {
				switch(zonas[i].localidad){
				case LANUS:
						strncpy(auxLocalidad, "LANUS",sizeof(auxLocalidad));
					break;
				case AVELLANEDA:
						strncpy(auxLocalidad, "AVELLANEDA",sizeof(auxLocalidad));
					break;
				case GERLI:
						strncpy(auxLocalidad,"GERLI",sizeof(auxLocalidad));
					break;
				case CABALLITO:
						strncpy(auxLocalidad,"CABALLITO",sizeof(auxLocalidad));
					break;
				case BARRACAS:
						strncpy(auxLocalidad,"BARRACAS",sizeof(auxLocalidad));
					break;
				}
				if (zonas[i].isEmpty == 0) {
					printf("\n______________________________");
					printf("\nZONA  LOCALIDAD       CALLES   ");
					printf("\n_____________________________  ");
					printf("\n%-4i  %-15s%-20s\n",zonas[i].idZona,auxLocalidad,zonas[i].calles[0]);
					printf("                     %-20s\n",zonas[i].calles[1]);
					printf("                     %-20s\n",zonas[i].calles[2]);
					printf("                     %-20s\n",zonas[i].calles[3]);
				}
			}
		}
	return retorno;
}

void cargaForzadaZona(zonaCenso * zonas)
{
		zonas[0].isEmpty = 0;
		zonas[0].estadoZona = PENDIENTE;
		zonas[0].idZona = zonaId();
		strcpy(zonas[0].calles[0], "Blas parera");
		strcpy(zonas[0].calles[1], "Donato alvarez");
		strcpy(zonas[0].calles[2], "Juncal");
		strcpy(zonas[0].calles[3], "San carlos");
		zonas[0].localidad = LANUS;
		zonas[0].censadosInSitu = 0;
		zonas[0].censadosVirtual = 0;
		zonas[0].ausentes = 0;

		zonas[1].isEmpty = 0;
		zonas[1].estadoZona = PENDIENTE;
		zonas[1].idZona = zonaId();
		strcpy(zonas[1].calles[0], "Martinto");
		strcpy(zonas[1].calles[1], "Pringles");
		strcpy(zonas[1].calles[2], "Yapeyu");
		strcpy(zonas[1].calles[3], "Guido");
		zonas[1].localidad = LANUS;
		zonas[1].censadosInSitu = 0;
		zonas[1].censadosVirtual = 0;
		zonas[1].ausentes = 0;

		zonas[2].isEmpty = 0;
		zonas[2].estadoZona = PENDIENTE;
		zonas[2].idZona = zonaId();
		strcpy(zonas[2].calles[0], "Carlos seminario");
		strcpy(zonas[2].calles[1], "Amaro giura");
		strcpy(zonas[2].calles[2], "Berisso");
		strcpy(zonas[2].calles[3], "Guemes");
		zonas[2].localidad = AVELLANEDA;
		zonas[2].censadosInSitu = 0;
		zonas[2].censadosVirtual = 0;
		zonas[2].ausentes = 0;

		zonas[3].isEmpty = 0;
		zonas[3].estadoZona = PENDIENTE;
		zonas[3].idZona = zonaId();;
		strcpy(zonas[3].calles[0], "Mitre");
		strcpy(zonas[3].calles[1], "Alsina");
		strcpy(zonas[3].calles[2], "Lavalle");
		strcpy(zonas[3].calles[3], "Belgrano");
		zonas[3].localidad = AVELLANEDA;
		zonas[3].censadosInSitu = 0;
		zonas[3].censadosVirtual = 0;
		zonas[3].ausentes = 0;

		zonas[4].isEmpty = 0;
		zonas[4].estadoZona = PENDIENTE;
		zonas[4].idZona = zonaId();;
		strcpy(zonas[4].calles[0], "Carabelas");
		strcpy(zonas[4].calles[1], "Donovan");
		strcpy(zonas[4].calles[2], "Cangallo");
		strcpy(zonas[4].calles[3], "Reconquista");
		zonas[4].localidad = GERLI;
		zonas[4].censadosInSitu = 0;
		zonas[4].censadosVirtual = 0;
		zonas[4].ausentes = 0;

		zonas[5].isEmpty = 0;
		zonas[5].estadoZona = PENDIENTE;
		zonas[5].idZona = zonaId();
		strcpy(zonas[5].calles[0], "Tapalque");
		strcpy(zonas[5].calles[1], "Tres Sargentos");
		strcpy(zonas[5].calles[2], "Nazar");
		strcpy(zonas[5].calles[3], "Helguera");
		zonas[5].localidad = GERLI;
		zonas[5].censadosInSitu = 0;
		zonas[5].censadosVirtual = 0;
		zonas[5].ausentes = 0;

}
