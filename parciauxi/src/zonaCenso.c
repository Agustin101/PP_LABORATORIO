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



int encontrarZonaPorId(zonaCenso *zonas, int len, int id){
	int retorno = -1;

		if(zonas != NULL && len > 0){
			for(int i = 0; i<len;i++){
				if(zonas[i].isEmpty==0 && zonas[i].idZona == id){
					retorno = i;
					break;
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
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la cuarta calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
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
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la cuarta calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
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
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la cuarta calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
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
				case 4 : // ALSINA
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la cuarta calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
							strncpy(zonas[indiceLibre].calles[0],auxCalles[0],sizeof(zonas[indiceLibre].calles[0]));
							strncpy(zonas[indiceLibre].calles[1],auxCalles[1],sizeof(zonas[indiceLibre].calles[1]));
							strncpy(zonas[indiceLibre].calles[2],auxCalles[2],sizeof(zonas[indiceLibre].calles[2]));
							strncpy(zonas[indiceLibre].calles[3],auxCalles[3],sizeof(zonas[indiceLibre].calles[3]));
							zonas[indiceLibre].estadoZona = PENDIENTE;
							zonas[indiceLibre].idZona = zonaId();
							zonas[indiceLibre].isEmpty = 0;
							zonas[indiceLibre].localidad = ALSINA;
						}
					}
					break;
				case 5 : // barracas
					if((indiceLibre = encontrarPosicionLibre(zonas,len)) != -1){
						if(getString(auxCalles[0],"Ingrese la primera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[1],"Ingrese la segunda calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[2],"Ingrese la tercera calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && getString(auxCalles[3],"Ingrese la cuarta calle :\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0){
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
				case ALSINA:
						strncpy(auxLocalidad,"ALSINA",sizeof(auxLocalidad));
					break;
				case BARRACAS:
						strncpy(auxLocalidad,"BARRACAS",sizeof(auxLocalidad));
					break;
				}
				if (zonas[i].isEmpty == 0) {
					printf("\n______________________________");
					printf("\nZONA  LOCALIDAD       CALLES  ");
					printf("\n______________________________");
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
		strncpy(zonas[0].calles[0], "Blas parera",sizeof(zonas[0].calles[0]));
		strncpy(zonas[0].calles[1], "Donato alvarez",sizeof(zonas[0].calles[1]));
		strncpy(zonas[0].calles[2], "Juncal",sizeof(zonas[0].calles[2]));
		strncpy(zonas[0].calles[3], "San carlos",sizeof(zonas[0].calles[3]));
		zonas[0].localidad = LANUS;
		zonas[0].censadosInSitu = 0;
		zonas[0].censadosVirtual = 0;
		zonas[0].ausentes = 0;
		zonas[0].idCensistaAsignado = 0;


		zonas[1].isEmpty = 0;
		zonas[1].estadoZona = PENDIENTE;
		zonas[1].idZona = zonaId();
		strncpy(zonas[1].calles[0], "Martinto",sizeof(zonas[1].calles[0]));
		strncpy(zonas[1].calles[1], "Pringles",sizeof(zonas[1].calles[1]));
		strncpy(zonas[1].calles[2], "Yapeyu",sizeof(zonas[1].calles[2]));
		strncpy(zonas[1].calles[3], "Guido",sizeof(zonas[1].calles[3]));
		zonas[1].localidad = LANUS;
		zonas[1].censadosInSitu = 0;
		zonas[1].censadosVirtual = 0;
		zonas[1].ausentes = 0;
		zonas[1].idCensistaAsignado = 0;

		zonas[2].isEmpty = 0;
		zonas[2].estadoZona = PENDIENTE;
		zonas[2].idZona = zonaId();
		strncpy(zonas[2].calles[0], "Carlos seminario",sizeof(zonas[2].calles[0]));
		strncpy(zonas[2].calles[1], "Amaro giura",sizeof(zonas[2].calles[1]));
		strncpy(zonas[2].calles[2], "Berisso",sizeof(zonas[2].calles[2]));
		strncpy(zonas[2].calles[3], "Guemes",sizeof(zonas[2].calles[3]));
		zonas[2].localidad = AVELLANEDA;
		zonas[2].censadosInSitu = 0;
		zonas[2].censadosVirtual = 0;
		zonas[2].ausentes = 0;
		zonas[2].idCensistaAsignado = 0;

		zonas[3].isEmpty = 0;
		zonas[3].estadoZona = PENDIENTE;
		zonas[3].idZona = zonaId();;
		strncpy(zonas[3].calles[0], "Mitre",sizeof(zonas[3].calles[0]));
		strncpy(zonas[3].calles[1], "Alsina",sizeof(zonas[3].calles[1]));
		strncpy(zonas[3].calles[2], "Lavalle",sizeof(zonas[3].calles[2]));
		strncpy(zonas[3].calles[3], "Belgrano",sizeof(zonas[3].calles[3]));
		zonas[3].localidad = AVELLANEDA;
		zonas[3].censadosInSitu = 0;
		zonas[3].censadosVirtual = 0;
		zonas[3].ausentes = 0;
		zonas[3].idCensistaAsignado = 0;

		zonas[4].isEmpty = 0;
		zonas[4].estadoZona = PENDIENTE;
		zonas[4].idZona = zonaId();;
		strncpy(zonas[4].calles[0], "Carabelas",sizeof(zonas[4].calles[0]));
		strncpy(zonas[4].calles[1], "Donovan",sizeof(zonas[4].calles[1]));
		strncpy(zonas[4].calles[2], "Cangallo",sizeof(zonas[4].calles[2]));
		strncpy(zonas[4].calles[3], "Reconquista",sizeof(zonas[4].calles[3]));
		zonas[4].localidad = GERLI;
		zonas[4].censadosInSitu = 0;
		zonas[4].censadosVirtual = 0;
		zonas[4].ausentes = 0;
		zonas[4].idCensistaAsignado = 0;


		zonas[5].isEmpty = 0;
		zonas[5].estadoZona = PENDIENTE;
		zonas[5].idZona = zonaId();
		strncpy(zonas[5].calles[0], "Tapalque",sizeof(zonas[5].calles[0]));
		strncpy(zonas[5].calles[1], "Tres Sargentos",sizeof(zonas[5].calles[1]));
		strncpy(zonas[5].calles[2], "Nazar",sizeof(zonas[5].calles[2]));
		strncpy(zonas[5].calles[3], "Helguera",sizeof(zonas[5].calles[3]));
		zonas[5].localidad = GERLI;
		zonas[5].censadosInSitu = 0;
		zonas[5].censadosVirtual = 0;
		zonas[5].ausentes = 0;
		zonas[5].idCensistaAsignado = 0;

		zonas[6].isEmpty = 0;
		zonas[6].estadoZona = PENDIENTE;
		zonas[6].idZona = zonaId();
		strncpy(zonas[6].calles[0], "Paraguay",sizeof(zonas[6].calles[0]));
		strncpy(zonas[6].calles[1], "Florida",sizeof(zonas[6].calles[1]));
		strncpy(zonas[6].calles[2], "Rucci",sizeof(zonas[6].calles[2]));
		strncpy(zonas[6].calles[3], "R Argentina",sizeof(zonas[6].calles[3]));
		zonas[6].localidad = ALSINA;
		zonas[6].censadosInSitu = 0;
		zonas[6].censadosVirtual = 0;
		zonas[6].ausentes = 0;
		zonas[6].idCensistaAsignado = 0;

		zonas[7].isEmpty = 0;
		zonas[7].estadoZona = PENDIENTE;
		zonas[7].idZona = zonaId();
		strncpy(zonas[7].calles[0], "Chile",sizeof(zonas[7].calles[0]));
		strncpy(zonas[7].calles[1], "Paso de patria",sizeof(zonas[7].calles[1]));
		strncpy(zonas[7].calles[2], "Ricardo balvin",sizeof(zonas[7].calles[2]));
		strncpy(zonas[7].calles[3], "Guatemala",sizeof(zonas[7].calles[3]));
		zonas[7].localidad = ALSINA;
		zonas[7].censadosInSitu = 0;
		zonas[7].censadosVirtual = 0;
		zonas[7].ausentes = 0;
		zonas[7].idCensistaAsignado = 0;

}

/// @brief Genera una id autoinrecemental.
///
/// @return Retorna el numero de id.
int zonaId(void) {
	static int id = 1999;
	id++;
	return id;
}

int hayZona(zonaCenso *zonas, int len) {
	int retorno;
	retorno = 0;

	if (zonas != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (zonas[i].isEmpty == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int buscarZonaPendiente(zonaCenso *zonas, int lenZonas){
	int retorno = -1;

		if(zonas != NULL && lenZonas > 0){
			for(int i =0; i< lenZonas;i++){
				if(zonas[i].isEmpty == 0 && zonas[i].estadoZona == PENDIENTE){
					retorno = i;
					break;
				}
			}

		}


	return retorno;
}


int verificarZona(zonaCenso *zonas, int len, int id){
	int retorno = -1;

		if(zonas !=NULL && len > 0){
			for(int i =0; i<len; i++){
				if(zonas[i].isEmpty == 0 && zonas[i].idZona == id && zonas[i].estadoZona == PENDIENTE){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}
