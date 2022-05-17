/*
 * Informes.c
 *
 *  Created on: 16 may. 2022
 *      Author: Agustin
 */

#include "informes.h"

int printCargaDeDatos(zonaCenso * zonas, int length, Censista * censista){
	int retorno = -1;

		if (zonas != NULL && length > 0 && censista != NULL) {

			for (int i = 0; i < length; i++) {
				if (zonas[i].isEmpty == 0 && zonas[i].estadoZona == PENDIENTE) {
					for(int j = 0; j < length; j++){
						if(zonas[i].idZona == censista[j].idZona && censista[j].estadoCensista == ACTIVO){
							printf("\n__________________________________________________________________________________________");
							printf("\nZONA  LOCALIDAD      CALLES              NOMBRE CEN     APELLIDO CEN                      ");
							printf("\n__________________________________________________________________________________________");
							printf("\n%-5i %-15i%-20s%-15s %-15s\n",zonas[i].idZona,zonas[i].localidad,zonas[i].calles[0],censista[j].name,censista[j].lastName);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
						}
					}
				}
			}
		}


	return retorno;
}

int cargaDeDatos(zonaCenso * zonas, int len, Censista * censistas){
	int retorno = 1;
	int idZonaAFinalizar;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int idALiberar;
	int retornoZona;

	    if(censistas != NULL && len > 0 && zonas != NULL){
	    	printCargaDeDatos(zonas,len,censistas);
	    	if(utn_getInt(&idZonaAFinalizar, "Ingrese el id de la zona a finalizar:\n", "Error valor invalido.\n",2000,3000,2)==0){
		        if((retornoZona = encontrarZonaPorId(zonas,len,idZonaAFinalizar))!=-1){
					if(zonas[retornoZona].estadoZona == PENDIENTE){
						if(utn_getInt(&censadosInSitu, "¿Cuantas personas censo de manera presencial?", "Ingrese un valor valido mayor o igual a 0.",0,10000,2)==0 && utn_getInt(&censadosVirtual, "¿Cuantas personas censo de manera virtual?", "Ingrese un valor valido mayor o igual a 0.",0,100000,2)==0 && utn_getInt(&ausentes, "¿Cuantas personas estuvieron ausentes?", "Ingrese un valor valido mayor o igual a 0.",0,10000,2)==0){
							zonas[retornoZona].estadoZona = FINALIZADO;
							zonas[retornoZona].censadosInSitu = censadosInSitu;
		            		zonas[retornoZona].censadosVirtual= censadosVirtual;
		            		zonas[retornoZona].ausentes = ausentes;
							idALiberar = encontrarCensistaPorIdZona(censistas, len,idZonaAFinalizar);
							censistas[idALiberar].estadoCensista = LIBERADO;
							retorno = 0;
						}
					}
				}
		        else{
		        	mensajeGenerico("El id ingresado no corresponde a ninguna zona activa.\n");
		        }
	    	}
	    }

	return retorno;
}

int asignarZonaACensar(Censista* censistas, int len,zonaCenso* zonas){
	int retorno = -1;
	int idZona;
	int indexLibre;
	int retornoZona;

	    if(censistas != NULL && len > 0 && zonas != NULL){
	    	printZonaCensar(zonas,len);
		    	if(utn_getInt(&idZona, "Ingrese el id de la zona a censar:\n", "Error valor invalido.\n",2000,99999,2)==0){
			        if((retornoZona = encontrarZonaPorId(zonas,len,idZona))!=-1){
						if(zonas[retornoZona].estadoZona == PENDIENTE ){
							if(verificarCensista(censistas,len, idZona) != 1){
								indexLibre = encontrarCensistaLiberado(censistas, len);
								censistas[indexLibre].idZona = idZona;
								censistas[indexLibre].estadoCensista = ACTIVO;
								printf("\nLa zona ha sido asignada a un censista responsable correctamente.\n");
								retorno = 0;
							}
							else{
								printf("La zona ya esta siendo censada");
							}
						}
					}
			        else{
			        	printf("El id ingresado no corresponde a ninguna zona activa.\n");
			        }
		    	}

	    }

	    return retorno;
}

int printZonasyCensistas(zonaCenso * zonas, int length, Censista * censistas){
	int retorno = -1;
	char auxLocalidad[51];


		if (zonas != NULL && length > 0 && censistas != NULL) {

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
					for(int j = 0; j < length; j++){
						if(zonas[i].idZona == censistas[j].idZona && censistas[j].estadoCensista == ACTIVO){

							printf("\n__________________________________________________________________________________________    ");
							printf("\nZONA  LOCALIDAD      CALLES               CENSISTA RESPONSABLE DE LA ZONA                     ");
							printf("\n__________________________________________________________________________________________    ");
							printf("\n%-5i %-15s%-20s %-15s %-15s\n",zonas[i].idZona,auxLocalidad,zonas[i].calles[0],censistas[j].name,censistas[j].lastName);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
							break;
						}
						else{
							printf("\n__________________________________________________________________________________________   ");
							printf("\nZONA  LOCALIDAD      CALLES              CENSISTA RESPONSABLE DE LA ZONA                     ");
							printf("\n__________________________________________________________________________________________   ");
							printf("\n%-5i %-15s%-20s                          LA ZONA AUN NO TIENE UN CENSISTA ASIGNADO         \n",zonas[i].idZona,auxLocalidad,zonas[i].calles[0]);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
							break;
						}
						}
					}

				}
			}

	return retorno;
}
