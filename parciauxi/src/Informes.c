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

int cargaDeDatos(zonaCenso * zonas, int lenCensistas, Censista * censistas, int lenZonas){
	int retorno = 1;
	int idZonaAFinalizar;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int retornoZona;
	int indiceZonaVerificada;
	int indiceCensistaACambiar;

	    if(censistas != NULL && lenCensistas > 0 && zonas != NULL && lenZonas > 0){

	    	if(utn_getInt(&idZonaAFinalizar, "Ingrese el id de la zona a finalizar:\n", "Error valor invalido.\n",2000,5000,2)==0){
		        if((retornoZona = encontrarZonaPorId(zonas,lenZonas,idZonaAFinalizar))!=-1){

		        	if((indiceZonaVerificada = verificarZona(zonas,lenZonas,idZonaAFinalizar))!=-1){
		        		if((indiceCensistaACambiar = verificarCensista(censistas,lenCensistas,idZonaAFinalizar)) != -1){
		        			if(utn_getInt(&censadosInSitu, "¿Cuantas personas censo de manera presencial?", "Ingrese un valor valido mayor o igual a 0.",0,10000,2)==0 && utn_getInt(&censadosVirtual, "¿Cuantas personas censo de manera virtual?", "Ingrese un valor valido mayor o igual a 0.",0,100000,2)==0 && utn_getInt(&ausentes, "¿Cuantas personas estuvieron ausentes?", "Ingrese un valor valido mayor o igual a 0.",0,10000,2)==0){
		        				zonas[indiceZonaVerificada].estadoZona = FINALIZADO;
		        				zonas[indiceZonaVerificada].censadosInSitu = censadosInSitu;
		        				zonas[indiceZonaVerificada].censadosVirtual= censadosVirtual;
		        				zonas[indiceZonaVerificada].ausentes = ausentes;
		        				censistas[indiceCensistaACambiar].estadoCensista = LIBERADO;
		        				retorno = 0;
		        			}
		        			else{
		        				printf("La carga de datos de la zona fallo.\n");
		        			}
		        		}
		        		else{
		        			printf("\nLa zona ya esta siendo censada.\n");
		        		}
					}
		        	else{
		        		printf("El id ingresado no corresponde con ninguna zona en estado pendiente.");
		        	}
				}
		        else{
		        	mensajeGenerico("El id ingresado no corresponde a ninguna zona activa.\n");
		        }
	    	}
	    }

	return retorno;
}
/*
int asignarZonaACensar(Censista* censistas, int lenCensista,zonaCenso* zonas, int lenZonas){

	int retorno = -1;
	int idZona;
	int indexLibre;
	int retornoZona;

	    if(censistas != NULL && lenCensista > 0 && zonas != NULL && lenZonas ){

	    	printZonaCensar(zonas,lenZonas);
	    	fflush(stdin);
		    	if(utn_getInt(&idZona, "Ingrese el id de la zona a censar:\n", "Error valor invalido.\n",2000,99999,2)==0){
		    		printf("entre 81");
			        if(encontrarZonaPorId(zonas,lenZonas,idZona)!=-1){
			        	retornoZona = encontrarZonaPorId(zonas,lenZonas,idZona);
			        	printf("entre 83 % d",retornoZona);
						if(zonas[retornoZona].estadoZona == PENDIENTE ){
							printf("entre 85");
							printf("%d",idZona);
							if(verificarCensista(censistas,lenCensista, idZona) == 0){

								printf("entre 87");
								printf("La zona ya esta siendo censada");
							}
							else{
								printf("entre 91");
								indexLibre = encontrarCensistaLiberado(censistas, lenCensista);
								censistas[indexLibre].idZona = idZona;
								censistas[indexLibre].estadoCensista = ACTIVO;
								printf("\nLa zona ha sido asignada a un censista responsable correctamente.\n");
								retorno = 0;
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
*/

/*
int asignarZonaACensar(Censista* censistas, int lenCensista,zonaCenso* zonas, int lenZonas){
	int retorno = -1;
	int idZonaAux;
	int indexLibre;
	int retornoZona;

	if(censistas != NULL && lenCensista > 0 &&  zonas != NULL && lenZonas > 0){
		if ((indexLibre = encontrarCensistaLiberado(censistas, lenCensista)) != -1) {
			if(buscarZonaPendiente(zonas, lenZonas) != -1) {
				if (utn_getInt(&idZonaAux,"\nIngrese el ID de la zona a censar: ","Ingrese un id valido.", 2000, 5999, 5) == 0) {
					if((retornoZona= encontrarZonaPorId(zonas,lenZonas,idZonaAux))!=-1){
						printf("\n indice de la zona a censar %d", retornoZona);
						if(verificarCensista(censistas,lenCensista,idZonaAux)==-1){
							printf("\n indice del censista %d", indexLibre);
							censistas[indexLibre].idZona = idZonaAux;
							zonas[retornoZona].idCensistaAsignado = censistas[indexLibre].idCensista;
							censistas[indexLibre].estadoCensista = ACTIVO;
							printf("\n-La zona sera censada por: %s %s-\n",
									censistas[indexLibre].name,
									censistas[indexLibre].lastName);
							printf("\nLa zona fue asignada a un censista responsable correctamente.\n");
							retorno = 0;
						}
						else{
							printf("\n La zona ya esta siendo censada en este momento.\n");
						}
					}
					else{
						printf("El id no corresponde a ninguna zona pendiente. \n");
					}
				}
			}
			else{
				printf("No hay zonas pendientes para censar.\n");
			}
		}
		else{
			printf("No hay censistas disponibles para asignar.");
		}
	}
	return retorno;
}
*/

int asignarZonaACensar(Censista* censistas, int lenCensista,zonaCenso* zonas, int lenZonas){
	int retorno = -1;
	int idZonaAux;
	int indexLibre;
	int retornoZona;

	if(censistas != NULL && lenCensista > 0 &&  zonas != NULL && lenZonas > 0){
		if ((indexLibre = encontrarCensistaLiberado(censistas, lenCensista)) != -1) {
			if(buscarZonaPendiente(zonas, lenZonas) != -1) {
				if (utn_getInt(&idZonaAux,"\nIngrese el ID de la zona a censar: ","Ingrese un id valido.", 2000, 5999, 5) == 0) {
					if((retornoZona= verificarZona(zonas,lenZonas,idZonaAux))!=-1){
						printf("\n indice de la zona a censar %d", retornoZona);
						if(verificarCensista(censistas,lenCensista,idZonaAux)==-1){
							printf("\n indice del censista %d", indexLibre);
							censistas[indexLibre].idZona = idZonaAux;
							zonas[retornoZona].idCensistaAsignado = censistas[indexLibre].idCensista;
							censistas[indexLibre].estadoCensista = ACTIVO;
							printf("\n-La zona sera censada por: %s %s-\n",
									censistas[indexLibre].name,
									censistas[indexLibre].lastName);
							printf("\nLa zona fue asignada a un censista responsable correctamente.\n");
							retorno = 0;
						}
						else{
							printf("\n La zona ya esta siendo censada en este momento.\n");
						}
					}
					else{
						printf("El id no corresponde a ninguna zona pendiente. \n");
					}
				}
			}
			else{
				printf("No hay zonas pendientes para censar.\n");
			}
		}
		else{
			printf("No hay censistas disponibles para asignar.");
		}
	}
	return retorno;
}









int printZonasyCensistas(zonaCenso * zonas, int length, Censista * censistas){
	int retorno = -1;
	char auxLocalidad[51];
	char auxEstado[11];

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
				case ALSINA:
						strncpy(auxLocalidad,"ALSINA",sizeof(auxLocalidad));
					break;
				case BARRACAS:
						strncpy(auxLocalidad,"BARRACAS",sizeof(auxLocalidad));
					break;
				}
				switch(zonas[i].estadoZona){
				case PENDIENTE:
					strncpy(auxEstado,"PENDIENTE",sizeof(auxEstado));
					break;
				case FINALIZADO:
					strncpy(auxEstado,"FINALIZADA",sizeof(auxEstado));
					break;
				}
				if (zonas[i].isEmpty == 0) {
					for(int j = 0; j < length; j++){
						if(zonas[i].idZona == censistas[j].idZona && censistas[j].estadoCensista == ACTIVO){
							printf("\n_______________________________________________________________________________________________");
							printf("\nZONA  LOCALIDAD      CALLES               CENSISTA RESPONSABLE DE LA ZONA ESTADO               ");
							printf("\n_______________________________________________________________________________________________");
							printf("\n%-5i %-15s%-20s %-15s %-15s  %-10s\n",zonas[i].idZona,auxLocalidad,zonas[i].calles[0],censistas[j].name,censistas[j].lastName,auxEstado);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
							break;
						}
						else{
							printf("\n__________________________________________________________________________________________    ");
							printf("\nZONA  LOCALIDAD       CALLES               CENSISTA RESPONSABLE DE LA ZONA                    ");
							printf("\n__________________________________________________________________________________________    ");
							printf("\n%-5i %-15s%-20s ZONA SIN CENSISTA ASIGNADO           %-10s\n",zonas[i].idZona,auxLocalidad,zonas[i].calles[0],auxEstado);
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


void mostrarZonas(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas){

	if(zonas != NULL && lenZonas > 0 && censistas != NULL && lenCensistas > 0){

		for(int i = 0; i< lenZonas; i++){
			if(zonas[i].isEmpty == 0){
				printf("\n_______________________________________________________________________________________________");
				printf("\nZONA  LOCALIDAD      CALLES               CENSISTA RESPONSABLE DE LA ZONA ESTADO               ");
				printf("\n_______________________________________________________________________________________________");

				for(int j = 0; j< lenCensistas; j++){
					if(zonas[i].idZona == censistas[j].idZona){
						printf("\n%-5i %-1i%-20s         %-1i\n",zonas[i].idZona,zonas[i].localidad,zonas[i].calles[0],censistas[i].estadoCensista);
					}
				}
			}
		}
	}
}


















