/*
 * Censista.c
 *
 *  Created on: 15 Mayo. 2022
 *      Author: Agustin
 */
#include "Censista.h"

/** \brief To indicate that all position in the array are empty,* this function put the flag (isEmpty)
 * in TRUE in all* position of the array
 * \param list Censista* Pointer to array of passenger
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
 */
int initCensistas(Censista *list, int len) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief carga en una lista de censistas existentes los valores tomados en la primer posicion libre.
 * \param censistas Censista *
 * \param len int
 * \retorno int Retorna -1 si no pudo cargar o fallo una validacion 0 si esta bien.
 */
int agregarCensista(Censista *censistas, int len) {
	int retorno = -1;
	int indiceVacio;
	char auxName[51];
	char auxLastName[51];
	int anioNacimiento;
	int auxEdad;
	int auxDia;
	int auxMes;

	char auxCalle[51];
	int auxAltura;



	if (censistas != NULL && len > 0 ) {
		if((indiceVacio = findFreeIndex(censistas, len))!=-1){
			if(getString(auxName,"Ingrese el nombre del censista:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2)==0 && getString(auxLastName,"Ingrese el apellido del censista:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2)==0 && utn_getInt(&anioNacimiento, "Indique el año de nacimiento del censista", "Error", 1960,2002,2)== 0 &&
					utn_getInt(&auxDia, "Indique el dia de nacimiento del censista (1 al 31)", "Error", 1,31,2)== 0 && utn_getInt(&auxMes, "Indique el mes de nacimiento del censista (1 al 12)", "Error", 1,12,2)== 0 && getString(auxCalle,"Ingrese la calle donde vive el censador:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && utn_getInt(&auxAltura, "Indique la altura.", "Error", 1,20000,2)== 0 &&
					utn_getInt(&auxEdad, "Indique la edad del censista: \n", "Error", 18,65,2)==0){
				censistas[indiceVacio].datosNacimiento.anioNacimiento = anioNacimiento;
				censistas[indiceVacio].datosNacimiento.diaNacimiento = auxDia;
				censistas[indiceVacio].datosNacimiento.mesNacimiento = auxMes;
				censistas[indiceVacio].direccionCensista.altura= auxAltura;
				strncpy(censistas[indiceVacio].direccionCensista.calle,auxCalle,sizeof(censistas[indiceVacio].direccionCensista.calle));
				censistas[indiceVacio].edadCensista = auxEdad;
				strncpy(censistas[indiceVacio].name,auxName,sizeof(censistas[indiceVacio].name));
				strncpy(censistas[indiceVacio].lastName,auxLastName,sizeof(censistas[indiceVacio].lastName));
				censistas[indiceVacio].estadoCensista = LIBERADO;
				censistas[indiceVacio].idCensista = censistaId();
				censistas[indiceVacio].isEmpty = 0;
				censistas[indiceVacio].idZona = 0;
				retorno = 0;
				printf("Carga exitosa.\n");
				mensajeGenerico("Presione una tecla para continuar...\n");
				fflush(stdin);
				getchar();
			}
			else{
				printf("La carga fallo, intentelo nuevamente.\n");
				mensajeGenerico("Presione una tecla para continuar...\n");
				fflush(stdin);
				getchar();
			}

		}
		else{
			printf("No hay espacio para cargar un nuevo censista.\n");
		}
	}
	return retorno;
}

/** \brief find a Censista by Id en returns the index position in array.*
 * \param list Censista*
 * \param len int
 * \param id int
 * \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 *
 */
int findCensistaById(Censista *list, int len, int id) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {


			if (list[i].idCensista == id && list[i].isEmpty == 0) {

				retorno = i;


				break;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Censista by Id (put isEmpty Flag in 1)
 *
 * \param list Censista*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 *
 */

int removeCensista(Censista *censista, int len, int id) {
	int retorno;
	int indiceAEliminar;
	retorno = -1;

	if (censista != NULL && len > 0 && id > 0) {
		indiceAEliminar = findCensistaById(censista, len, id);
		if (indiceAEliminar != -1 && censista[indiceAEliminar].estadoCensista != ACTIVO) {
			censista[indiceAEliminar].estadoCensista = INACTIVO;
			retorno = 0;
			printf("Censista dado de baja con exito.\n");
		}
		else {
			printf("No puede dar de baja un censista en estado ACTIVO.\n");
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order

 *
 * \param list Censista*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
 */
/*
int sortPassengersByName(Censista *list, int len, int order) {
	int retorno;
	int i;
	int estaOrdenado;
	retorno = -1;

	Censista aux;

	if (list != NULL && len > 0) {
		if (order == 0) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].lastName, list[i + 1].lastName) < 0) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					} else if (stricmp(list[i].lastName, list[i + 1].lastName)
							== 0
							&& list[i].edadCensista
									< list[i + 1].edadCensista) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);

		} else if (order == 1) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (stricmp(list[i].lastName, list[i + 1].lastName) > 0) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					} else if (stricmp(list[i].lastName, list[i + 1].lastName)
							== 0
							&& list[i].edadCensista
									> list[i + 1].edadCensista) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);
		}
		retorno = 0;
	}

	return retorno;
}
*/

/** \brief print the content of passengers array
 *
 * \param list Censista*
 * \param length int
 * \return int
 *
 */
int printCensistas(Censista *censistas, int length) {
char estadoAux[9];

	if (censistas != NULL && length > 0) {
		printf("\n___________________________________________________________________________________________");
		printf("\nNOMBRE         APELLIDO        FECHA NAC  DIRECCION                 ESTADO      EDAD  ID   ");
		printf("\n___________________________________________________________________________________________");
		for (int i = 0; i < length; i++) {
			switch(censistas[i].estadoCensista){
			case LIBERADO:
					strncpy(estadoAux, "LIBERADO",sizeof(estadoAux));
				break;
			case ACTIVO:
					strncpy(estadoAux, "ACTIVO",sizeof(estadoAux));
				break;
			case INACTIVO:
					strncpy(estadoAux,"INACTIVO",sizeof(estadoAux));
				break;
			}
			if (censistas[i].isEmpty == 0) {
				printf(
						"\n%-15s%-15s %-2.i/%-2.i/%-4.i %-20s %i %-9s   %-2i    %-5i\n\n",
						censistas[i].name, censistas[i].lastName, censistas[i].datosNacimiento.diaNacimiento,censistas[i].datosNacimiento.mesNacimiento,censistas[i].datosNacimiento.anioNacimiento,
						censistas[i].direccionCensista.calle,censistas[i].direccionCensista.altura,estadoAux,censistas[i].edadCensista,censistas[i].idCensista);
			}
		}
	}
	return 0;
}



/// @brief Finds a free index in the array of censistas
///
/// @param list Censista*
/// @param len int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a censista] - free index if Ok
int findFreeIndex(Censista *list, int len) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @brief Verifica si hay al menos un censista cargado en el array de censistas.
///
/// @param list Censista*
/// @param len int
/// @return int Retorna (-1) si tiene error o no puede encontrar un censista - 1 si al menos hay uno.
int hayCensista(Censista *list, int len) {
	int retorno;
	retorno = 0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


/// @brief Modifica un campo del pasajero indicando por el usuario.En caso de modificar el estado del vuelo
/// retorna por puntero una flag en 1 la cual es usada para modificar el estado de vuelo y el codigo de vuelo
/// en la estructura de vuelos.
///
/// @param list Censista
/// @param len int
/// @param id int
/// @param flyCode Codigo de vuelo retornado para la modificacion de la estructura de vuelos.
/// @param statusFlight Estado de vuelo retornado para la modificacion de la estructura de vuelos.
/// @param modificoVuelo Flag retornado para la modificacion de la estructura de vuelos.
/// @return int Retorna (-1) si tiene error  - 1 si pudo realizar los cambios correctamente.

int modificarCensista(Censista *list, int len){
	int retorno = -1;
	int idAux;

	int opcion;
	int opcionSubMenu;
	int opcionSubMenu2;
	char nombreAux[51];
	char apellidoAux[51];
	int anioNacimientoAux;
	int mesNacimientoAux;
	int diaNacimientoAux;
	int edadCensistaAux;
	int alturaDeLaCalleAux;
	char nombreDeLaCalleAux[51];
	int indiceAModificar;

	if (list != NULL && len > 0 ) {
		if(hayCensista(list, len) == 1){
			if(utn_getInt(&idAux,"Ingrese el id del censista a modificar:\n","Error ingrese un valor valido\n",1000,5000,2)==0){
				if(findCensistaById(list, len, idAux) != -1 ) {
					indiceAModificar = findCensistaById(list, len, idAux);

					do {
						if (utn_getInt(&opcion,
							"¿Que desea modificar?\n\n1)Nombre\n\n2)Apellido\n\n3)Datos de nacimiento\n\n4)Edad de censista\n\n5)Datos sobre la direccion del censista.\n\n6)Volver al menu principal",
							"Por favor, ingrese una opcion valida.", 1, 6, 2) == 0) {
						switch (opcion) {
						case 1:
							if (getString(nombreAux,"Introduzca el nuevo nombre del censista:\n","El nombre no pudo ser validado, ingreselo nuevamente:\n",2) == 0) {
								strncpy(list[indiceAModificar].name, nombreAux,sizeof(list[indiceAModificar].name));
								retorno = 0;
								mensajeGenerico("Nombre actualizado.\n");
							}
							else {
							mensajeGenerico("La modificacion fallo.\n");
							}
						break;
					case 2:
						if (getString(apellidoAux,"Introduzca el nuevo apellido del censista:\n","El apellido no pudo ser validado, ingreselo nuevamente:\n",2) == 0) {
							strncpy(list[indiceAModificar].lastName,apellidoAux,sizeof(list[indiceAModificar].lastName));
							mensajeGenerico("Apellido actualizado.\n");
							retorno = 0;
						} else {
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 3:
					do{
						if(utn_getInt(&opcionSubMenu,"¿Que quiere cambiar?\n1)Año de nacimiento\n2)Mes de nacimiento\n3)Dia de nacimiento\n4)Volver al menu de modificaciones","Error",1, 4, 2) == 0) {
							switch(opcionSubMenu){
							case 1:
								if(utn_getInt(&anioNacimientoAux,"Ingrese el nuevo año de nacimiento: \n", "error",1960, 2002, 2) == 0){
									list[indiceAModificar].datosNacimiento.anioNacimiento = anioNacimientoAux;
									mensajeGenerico("Año de nacimiento actualizado.\n");
									retorno = 0;
								}
								else {
									mensajeGenerico("La modificacion fallo.\n");
									}
								break;
							case 2:
								if(utn_getInt(&mesNacimientoAux,"Ingrese el nuevo mes de nacimiento: \n", "error",1, 31, 2) == 0){
									list[indiceAModificar].datosNacimiento.mesNacimiento = mesNacimientoAux;
									mensajeGenerico("Mes de nacimiento actualizado.\n");
									retorno = 0;
								}
								else {
									mensajeGenerico("La modificacion fallo.\n");
									}
								break;
							case 3:
								if(utn_getInt(&diaNacimientoAux,"Ingrese el nuevo mes de nacimiento: \n","error",1, 31, 2) == 0){
									list[indiceAModificar].datosNacimiento.diaNacimiento = diaNacimientoAux ;
									mensajeGenerico("Dia de nacimiento actualizado.\n");
									retorno = 0;
								}
								else {
									mensajeGenerico("La modificacion fallo.\n");
									}
								break;
							case 4:
								break;
							}
						}
					}while(opcionSubMenu != 4);
						break;
					case 4:
						if(utn_getInt(&edadCensistaAux, "Indique la nueva edad del censista: \n", "Error", 18,65,2)==0){
							list[indiceAModificar].edadCensista = edadCensistaAux ;
							mensajeGenerico("Edad actualizado.\n");
							retorno = 0;
						}
						else {
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 5:
						do{
							if(utn_getInt(&opcionSubMenu2,"¿Que quiere cambiar?\n1)Nombre de la calle\n2)Altura de la calle\n3)Volver al menu de modificaciones","Error",1, 3, 2) == 0) {
								switch(opcionSubMenu2){
								case 1:
									if (getString(nombreDeLaCalleAux,"Introduzca el nuevo nombre de la calle:\n","El nombre no pudo ser validado, ingreselo nuevamente:\n",2) == 0) {
										strncpy(list[indiceAModificar].direccionCensista.calle, nombreDeLaCalleAux,sizeof(list[indiceAModificar].direccionCensista.calle));
										retorno = 0;
										mensajeGenerico("Nombre actualizado.\n");
									}
									else {
										mensajeGenerico("La modificacion fallo.\n");
									}
									break;
								case 2:
									if(utn_getInt(&alturaDeLaCalleAux,"Ingrese la nueva altura de la calle: \n","error",1, 20000, 2) == 0){
										list[indiceAModificar].direccionCensista.altura = alturaDeLaCalleAux;
										mensajeGenerico("Altura actualizada.\n");
										retorno = 0;
									}
									else {
										mensajeGenerico("La modificacion fallo.\n");
										}
									break;
								case 3:
									break;
								}
							}
						}while(opcionSubMenu2 != 3);
						break;
					case 6:
						mensajeGenerico("Volviendo al menu principal...\n\n");
						break;
					}
				}} while (opcion != 6);
			}
				else{
					printf("El id no coincide con ningun censista activo. \n");
				}
		}
	}
		else{
			printf("Es necesario cargar un censista para acceder a esta opcion.\n");
		}


	}
	return retorno;
}


/// @brief Genera una id autoinrecemental.
///
/// @return Retorna el numero de id.
int censistaId(void) {
	static int id = 999;
	id++;
	return id;
}


void cargaForzadaCensistas(Censista * list)
{
		strncpy(list[0].name, "Juan",sizeof(list[0].name));
		strncpy(list[0].lastName, "Perez",sizeof(list[0].name));
		list[0].idCensista = censistaId();
		list[0].edadCensista = 22;
		list[0].estadoCensista = LIBERADO;
		list[0].isEmpty = 0;
		list[0].datosNacimiento.diaNacimiento = 10;
		list[0].datosNacimiento.mesNacimiento = 9;
		list[0].datosNacimiento.anioNacimiento = 2000;
		strncpy(list[0].direccionCensista.calle, "Avenida mitre",sizeof(list[0].name));
		list[0].direccionCensista.altura = 2057;
		list[0].idZona = -1;

		strncpy(list[1].name, "Marcos",sizeof(list[1].name));
		strncpy(list[1].lastName, "Amarillo",sizeof(list[1].name));
		list[1].idCensista = censistaId();
		list[1].edadCensista = 22;
		list[1].estadoCensista = LIBERADO;
		list[1].isEmpty = 0;
		list[1].datosNacimiento.diaNacimiento = 10;
		list[1].datosNacimiento.mesNacimiento = 9;
		list[1].datosNacimiento.anioNacimiento = 2000;
		strncpy(list[1].direccionCensista.calle, "Futbolin",sizeof(list[1].name));
		list[1].direccionCensista.altura = 2057;
		list[1].idZona = -1;

		strncpy(list[2].name, "Pedro",sizeof(list[2].name));
		strncpy(list[2].lastName, "Diaz",sizeof(list[2].lastName));
		list[2].idCensista = censistaId();
		list[2].edadCensista = 22;
		list[2].estadoCensista = LIBERADO;
		list[2].isEmpty = 0;
		list[2].datosNacimiento.diaNacimiento = 10;
		list[2].datosNacimiento.mesNacimiento = 9;
		list[2].datosNacimiento.anioNacimiento = 2000;
		strncpy(list[2].direccionCensista.calle, "tefaltacalle",sizeof(list[2].name));
		list[2].direccionCensista.altura = 2057;
		list[2].idZona = -1;

		strncpy(list[3].name, "Estebanio",sizeof(list[3].name));
		strncpy(list[3].lastName, "Lavo",sizeof(list[3].name));
		list[3].idCensista = censistaId();
		list[3].edadCensista = 22;
		list[3].estadoCensista = LIBERADO;
		list[3].isEmpty = 0;
		list[3].datosNacimiento.diaNacimiento = 10;
		list[3].datosNacimiento.mesNacimiento = 9;
		list[3].datosNacimiento.anioNacimiento = 2000;
		strncpy(list[3].direccionCensista.calle, "tefaltacalle",sizeof(list[3].name));
		list[3].direccionCensista.altura = 2057;
		list[3].idZona = -1;

		strncpy(list[4].name, "Pepe",sizeof(list[4].name));
		strncpy(list[4].lastName, "Picapi",sizeof(list[4].name));
		list[4].idCensista = censistaId();
		list[4].edadCensista = 22;
		list[4].estadoCensista = LIBERADO;
		list[4].isEmpty = 0;
		list[4].datosNacimiento.diaNacimiento = 10;
		list[4].datosNacimiento.mesNacimiento = 9;
		list[4].datosNacimiento.anioNacimiento = 2000;
		strncpy(list[4].direccionCensista.calle, "Elpasado",sizeof(list[4].name));
		list[4].direccionCensista.altura = 2057;
		list[4].idZona = -1;
}


int encontrarCensistaLiberado(Censista *list, int len) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].estadoCensista == LIBERADO) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int encontrarCensistaPorIdZona(Censista *cencistas, int len, int id){
	int retorno = -1;

		if(cencistas != NULL && len > 0){
			for(int i = 0; i<len;i++){
				if(cencistas[i].isEmpty==0 && cencistas[i].idZona == id){
					retorno = i;
				}
			}
		}
	return retorno;
}

int verificarCensista(Censista *censistas, int len, int idZona){
	int retorno = -1;

		if(censistas != NULL && len > 0){
			for(int i = 0; i<len; i++){
				if(censistas[i].idZona == idZona && censistas[i].estadoCensista == ACTIVO){
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

int encontrarCensistaActivoEnZona(Censista *censista, int len, int id){
	int retorno = -1;

		if(censista != NULL && len > 0){
			for(int i = 0; i<len;i++){
				if(censista[i].isEmpty==0 && censista[i].idZona == id){
					retorno = i;
				}
			}
		}
	return retorno;
}
