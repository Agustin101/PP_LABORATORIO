/*
 * Informes.c
 *
 *  Created on: 16 may. 2022
 *      Author: Agustin
 */

#include "informes.h"

/** @brief Imprime todas las zonas que estan siendo censadas
 * @param zonas zonaCenso* puntero al array de zonas.
 * @param lenZonas int largo del array.
 * @param censista Censista*  Ipuntero al array de censistas.
 * @param lenZlenCensistasonas int largo del array.
 */
void printCargaDeDatos(zonaCenso * zonas, int lenZonas, Censista * censista, int lenCensistas){
	char auxLocalidad[5][51] = {"LANUS","AVELLANEDA","GERLI","ALSINA","BARRACAS"};
	int localidad = 0;

		if (zonas != NULL && lenZonas > 0 && censista != NULL && lenCensistas > 0) {
			for (int i = 0; i < lenZonas; i++) {
				if (zonas[i].isEmpty == 0 && zonas[i].estadoZona == PENDIENTE) {
					for(int j = 0; j < lenCensistas; j++){
						if(zonas[i].idZona == censista[j].idZona && censista[j].estadoCensista == ACTIVO){
							localidad = zonas[i].localidad;
							localidad--;

							printf("\n__________________________________________________________________________________________");
							printf("\nZONA  LOCALIDAD      CALLES              NOMBRE CEN     APELLIDO CEN                      ");
							printf("\n__________________________________________________________________________________________");
							printf("\n%-5i %-15s%-20s%-15s %-15s\n",zonas[i].idZona,auxLocalidad[localidad],zonas[i].calles[0],censista[j].name,censista[j].lastName);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
						}
					}
				}
			}
		}
}

/** @brief Imprime todas las zonas en estado pendiente.
 * @param zonas zonaCenso* puntero al array de zonas.
 * @param lenZonas int largo del array.
 */
void printAsignacion(zonaCenso * zonas, int lenZonas){
	char auxLocalidad[5][51] = {"LANUS","AVELLANEDA","GERLI","ALSINA","BARRACAS"};
	int localidad = 0;

		if (zonas != NULL && lenZonas > 0) {
			for (int i = 0; i < lenZonas; i++) {
				if (zonas[i].isEmpty == 0 && zonas[i].estadoZona == PENDIENTE) {

							localidad = zonas[i].localidad;
							localidad--;

							printf("\n__________________________________________________________________________________________");
							printf("\nZONA  LOCALIDAD      CALLES                                                               ");
							printf("\n__________________________________________________________________________________________");
							printf("\n%-5i %-15s%-20s         \n",zonas[i].idZona,auxLocalidad[localidad],zonas[i].calles[0]);
							printf("                     %-20s\n",zonas[i].calles[1]);
							printf("                     %-20s\n",zonas[i].calles[2]);
							printf("                     %-20s\n",zonas[i].calles[3]);
				}
			}
		}
}

/** @brief Carga los datos recolectados en el censo en el array de zonacenso.
 * @param zonas zonaCenso* puntero al array de zonas.
 * @param lenZonas int largo del array.
 * @param censistas Censista *  puntero al array de censistas.
 * @param lenCensistas int largo del array.
 * @ return Retorna -1 si no pudo cargar los datos correctamente 0 si si pudo.
 *  */
int cargaDeDatos(zonaCenso * zonas, int lenCensistas, Censista * censistas, int lenZonas){
	int retorno = -1;
	int idZonaAFinalizar;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int indiceZonaVerificada;
	int indiceCensistaACambiar;

	    if(censistas != NULL && lenCensistas > 0 && zonas != NULL && lenZonas > 0){
	    	if(hayCensistaActivo(censistas, lenCensistas) == 1 && hayZonaPendiente(zonas,lenZonas) == 1 ){
	    		printCargaDeDatos(zonas,lenZonas, censistas,lenCensistas);
	    		if(utn_getInt(&idZonaAFinalizar, "Ingrese el id de la zona a finalizar:\n", "Error valor invalido.\n",2000,5000,2)==0){
	    			if(encontrarZonaPorId(zonas,lenZonas,idZonaAFinalizar)!=-1){
	    				if((indiceZonaVerificada = verificarZona(zonas,lenZonas,idZonaAFinalizar))!=-1){
	    					if((indiceCensistaACambiar = verificarCensista(censistas,lenCensistas,idZonaAFinalizar)) != -1){
	    						if(utn_getInt(&censadosInSitu, "¿Cuantas personas censo de manera presencial?", "Ingrese un valor valido mayor o igual a 0.",0,100000,2)==0 && utn_getInt(&censadosVirtual, "¿Cuantas personas censo de manera virtual?", "Ingrese un valor valido mayor o igual a 0.",0,100000,2)==0 && utn_getInt(&ausentes, "¿Cuantas personas estuvieron ausentes?", "Ingrese un valor valido mayor o igual a 0.",0,100000,2)==0){
	    							zonas[indiceZonaVerificada].estadoZona = FINALIZADO;
	    							zonas[indiceZonaVerificada].censadosInSitu = censadosInSitu;
	    							zonas[indiceZonaVerificada].censadosVirtual= censadosVirtual;
	    							zonas[indiceZonaVerificada].ausentes = ausentes;
	    							zonas[indiceZonaVerificada].idCensistaAsignado = censistas[indiceCensistaACambiar].idCensista;
	    							censistas[indiceCensistaACambiar].estadoCensista = LIBERADO;
	    							retorno = 0;
	    							printf("\n*El censo en la zona finalizo correctamente.*\n");
	    						}
	    						else{
		        				printf("La carga de datos de la zona fallo.\n");
	    						}
	    					}
	    					else{
		        			printf("\nLa zona aun no fue censada.\n");
	    					}
	    				}
	    				else{
	    					printf("El id ingresado no corresponde con ninguna zona en estado pendiente.");
		        		}
					}
		        	else{
		        		mensajeGenerico("El id ingresado no corresponde a ninguna zona cargada.\n");
		        	}
	    		}
	    	}
	    	else{
	    		printf("Debe al menos un censista activo y una zona pendiente para acceder a esta opcion.\n");
	    	}
	    }

	return retorno;
}

/** @brief Asigna el primer censista en estado LIBERADO a la zona que indica el usuario.
 * @param zonas zonaCenso* puntero al array de zonas.
 * @param lenZonas int largo del array.
 * @param censistas Censista *  puntero al array de censistas.
 * @param lenCensistas int largo del array.
 * @ return Retorna -1 si no pudo realizar la asignacion y 0 si pudo hacerlo.
 *  */
int asignarZonaACensar(Censista* censistas, int lenCensista,zonaCenso* zonas, int lenZonas){
	int retorno = -1;
	int idZonaAux;
	int indexLibre;
	int retornoZona;

	if(censistas != NULL && lenCensista > 0 &&  zonas != NULL && lenZonas > 0){
		if (buscarZonaPendiente(zonas, lenZonas) != -1) {
			if((indexLibre = encontrarCensistaLiberado(censistas, lenCensista)) != -1) {
				printAsignacion(zonas, lenZonas);
				if (utn_getInt(&idZonaAux,"\nIngrese el ID de la zona a censar: ","Ingrese un id valido.", 2000, 5999, 5) == 0) {
					if((retornoZona= verificarZona(zonas,lenZonas,idZonaAux))!=-1){
						if(verificarCensista(censistas,lenCensista,idZonaAux)==-1){
							censistas[indexLibre].idZona = idZonaAux;
							zonas[retornoZona].idCensistaAsignado = censistas[indexLibre].idCensista;
							censistas[indexLibre].estadoCensista = ACTIVO;
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
				printf("No hay censistas disponibles para asignar.");
			}
		}
		else{
			printf("No hay zonas pendientes para censar.\n");
		}
	}
	return retorno;
}




/** @brief Muestra los datos de una zona con valor empty en 0 incluyendo su censista.
 * @param zonas zonaCenso puntero al array de zonas.
 * @param censistas Censista puntero al array de censistas.
 *  */
void mostrarZona(zonaCenso  zonas,  Censista  censistas){
	char auxLocalidad[5][51] = {"LANUS","AVELLANEDA","GERLI","ALSINA","BARRACAS"};
	int localidad = 0;
	char auxEstado[2][15] = {"PENDIENTE", "FINALIZADO"};
	int estado = 0;

		if(zonas.isEmpty == 0 && censistas.isEmpty == 0){

			localidad = zonas.localidad;
			localidad--;

			estado = zonas.estadoZona;
			estado--;

			printf("\n_____________________________________________________________________________________________________");
		    printf("\nZONA  LOCALIDAD   CALLES                  ESTADO      CENSISTA RESPONSABLE DE LA ZONA CENSADOS       ");
			printf("\n_____________________________________________________________________________________________________");
			printf("\n%-5i %-10s  %-20s    %-11s %-15s %-15s In situ:  %-5i\n",zonas.idZona,auxLocalidad[localidad],zonas.calles[0],auxEstado[estado],censistas.name,censistas.lastName,zonas.censadosInSitu);
			printf("                  %-20s                                                Virtual:  %-5i \n",zonas.calles[1],zonas.censadosVirtual);
			printf("                  %-20s                                                Ausentes: %-5i \n",zonas.calles[2],zonas.ausentes);
			printf("                  %-20s                                     \n",zonas.calles[3]);
		}
}

/** @brief Lista todas las zonas con valor empty en 0 incluyendo su censista.
 * @param zonas zonaCenso* puntero al array de zonas.
 * @param lenZonas int largo del array.
 * @param censistas Censista *  puntero al array de censistas.
 * @param lenCensistas int largo del array.
 *  */
void listarZonas(zonaCenso * zonas, int lenZonas, Censista * censistas, int lenCensistas){
	int flagSinCensista;
	char auxLocalidad[5][51] = {"LANUS","AVELLANEDA","GERLI","ALSINA","BARRACAS"};
	char auxEstado[2][15] = {"PENDIENTE", "FINALIZADO"};
	int localidad = 0;
	int estado = 0;

	if(zonas != NULL && lenZonas > 0 && censistas != NULL && lenCensistas > 0){
		if(hayZona(zonas,lenZonas)==1){
			for(int i = 0; i < lenZonas; i++){

			flagSinCensista = 0;
				if(zonas[i].isEmpty == 0){

					for(int j = 0; j < lenCensistas; j++){
						if(zonas[i].idCensistaAsignado == censistas[j].idCensista){
							flagSinCensista = 1;
							mostrarZona(zonas[i],  censistas[j]);
							break;
						}
					}
					if(flagSinCensista == 0){

						localidad = zonas[i].localidad;
						localidad--;
						estado = zonas[i].estadoZona;
						estado--;

						printf("\n_____________________________________________________________________________________________________");
						printf("\nZONA  LOCALIDAD   CALLES                  ESTADO      CENSISTA RESPONSABLE DE LA ZONA CENSADOS       ");
						printf("\n_____________________________________________________________________________________________________");
						printf("\n%-5i %-10s  %-20s    %-11s ZONA SIN CENSISTA ASIGNADO      In situ:  %-5i               \n",zonas[i].idZona,auxLocalidad[localidad],zonas[i].calles[0],auxEstado[estado],zonas[i].censadosInSitu);
						printf("                  %-20s                                                Virtual:  %-5i \n",zonas[i].calles[1],zonas[i].censadosVirtual);
						printf("                  %-20s                                                Ausentes: %-5i             \n",zonas[i].calles[2],zonas[i].ausentes);
						printf("                  %-20s\n",zonas[i].calles[3]);
					}
				}

			}
		}
		else{
			printf("\nDebe cargar una zona para acceder a esta opcion.");
		}
	}
}














