/*
 * Censista.c
 *
 *  Created on: 15 Mayo. 2022
 *      Author: Agustin
 */
#include "Censista.h"

/** \brief Inicia todas las posiciones del array con la flag isEmpty en 1
 * \param list Censista* puntero al array de censistas
 * \param len Len del array
 * \return int retorna -1 si falla y 0 si puede asignar bien.
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
 * \param censistas Censista * puntero al array de censistas
 * \param len int largo del array.
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
			if(getString(auxName,"Ingrese el nombre del censista:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2)==0 && getString(auxLastName,"Ingrese el apellido del censista:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2)==0 && utn_getInt(&anioNacimiento, "Indique el año de nacimiento del censista", "Error", 1957,2004,2)== 0 &&
					utn_getInt(&auxDia, "Indique el dia de nacimiento del censista (1 al 31)", "Error", 1,31,2)== 0 && utn_getInt(&auxMes, "Indique el mes de nacimiento del censista (1 al 12)", "Error", 1,12,2)== 0 && getString(auxCalle,"Ingrese la calle donde vive el censista:\n","Por favor ingrese un nombre valido conformado de letras y espacios de ser necesarios.\n",2) == 0 && utn_getInt(&auxAltura, "Indique la altura.", "Error", 1,20000,2)== 0 &&
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

/** \brief Busca en el array de censistas por id y retorna el indice de su posicion.
 * \param list Censista* puntero al array de censistas
 * \param len int largo del array.
 * \param id int Id a encontrar.
 * \return Retorna el indice del pasajero o -1 si falla o no lo encunetra
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

/** \brief Deja el censista en estado INACTIVO.
 *
 * \param list Censista* puntero al array de censistas.
 * \param len int largo del array.
 * \param id int Id a encontrar.
 * \return int Retorna -1 si hay error o 0si puede cambiar el estado del censista.
 *
 */
int removeCensista(Censista *censista, int len) {
	int retorno;
	int indiceAEliminar;
	int idCensistaAux;
	retorno = -1;

	if (censista != NULL && len > 0) {
		if(hayCensista(censista, len) == 1){
			if(utn_getInt(&idCensistaAux,"Ingrese el id del censista a eliminar:\n","Error ingrese un id valido.\n",1000,5000,2)==0){
				if(findCensistaById(censista,len,idCensistaAux)!=-1){
					indiceAEliminar = findCensistaById(censista,len,idCensistaAux);
					if (indiceAEliminar != -1 && censista[indiceAEliminar].estadoCensista != ACTIVO) {
						censista[indiceAEliminar].estadoCensista = INACTIVO;
						retorno = 0;
						printf("El censista ahora se encuentra en estado INACTIVO.\n");
					}
					else {
						printf("No puede dar de baja un censista en estado ACTIVO.\n");
					}
				}
				else{
					printf("El id no corresponde a ningun censista cargado en el sistema.\n");
				}
			}
		}
		else{
			printf("Para acceder a esta opcion debe haber cargado al menos un censista. \n");
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

/** \brief Imprime el contenido en el array de censistas.
 *
 * \param list Censista* puntero al array de censistas
 * \param length int largo del array.
 */
void printCensistas(Censista *censistas, int length) {
char estados[3][12]= {"LIBERADO", "ACTIVO", "INACTIVO"};
int estadoCensista;

	if (censistas != NULL && length > 0) {
		if(hayCensista(censistas, length) == 1){
			printf("\n____________________________________________________________________________________________");
			printf("\nNOMBRE         APELLIDO        FECHA NAC  DIRECCION                  ESTADO      EDAD  ID   ");
			printf("\n____________________________________________________________________________________________");
			for (int i = 0; i < length; i++) {
				estadoCensista = censistas[i].estadoCensista;
				estadoCensista--;
				if (censistas[i].isEmpty == 0) {
					printf(
							"\n%-15s%-15s %-2.i/%-2.i/%-4.i %-20s %-5i %-9s   %-2i    %-5i\n\n",
							censistas[i].name, censistas[i].lastName, censistas[i].datosNacimiento.diaNacimiento,censistas[i].datosNacimiento.mesNacimiento,censistas[i].datosNacimiento.anioNacimiento,
							censistas[i].direccionCensista.calle,censistas[i].direccionCensista.altura,estados[estadoCensista],censistas[i].edadCensista,censistas[i].idCensista);
				}
			}
			mensajeGenerico("Presione una tecla para continuar...\n");
			fflush(stdin);
			getchar();
		}
		else{
			printf("Debe cargar al menos un censista para acceder a esta opcion.\n");
		}
	}
}


/// @brief Encuentra un indice libre en el array de censistas.
///
/// @param list Censista* puntero al array de censistas
/// @param len int largo del array.
/// @return int Retorna -1 si hay error - un indice vacio si sale bien.
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
/// @param list Censista* puntero al array de censistas.
/// @param len int largo del array.
/// @return int Retorna (0) si tiene error o no puede encontrar un censista - 1 si al menos hay uno.
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
/// @brief Verifica si hay al menos un censista con el estado ACTIVO
/// en el array de censistas.
///
/// @param list Censista* puntero al array de censistas.
/// @param len int largo del array.
/// @return int Retorna (0) si tiene error o no puede encontrar un censista - 1 si al menos hay uno.
int hayCensistaActivo(Censista *list, int len) {
	int retorno;
	retorno = 0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].estadoCensista == ACTIVO) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @brief Modifica un campo del censista indicando por el usuario.
///
/// @param list Censista * puntero al array de censistas.
/// @param len int largo del array.
/// @return int Retorna (-1) si tiene error  - 0 si pudo realizar los cambios correctamente.
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
								if(utn_getInt(&mesNacimientoAux,"Ingrese el nuevo mes de nacimiento: \n", "error",1, 12, 2) == 0){
									list[indiceAModificar].datosNacimiento.mesNacimiento = mesNacimientoAux;
									mensajeGenerico("Mes de nacimiento actualizado.\n");
									retorno = 0;
								}
								else {
									mensajeGenerico("La modificacion fallo.\n");
									}
								break;
							case 3:
								if(utn_getInt(&diaNacimientoAux,"Ingrese el nuevo dia de nacimiento: \n","error",1, 31, 2) == 0){
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


/// @brief Genera una id autoincremental.
///
/// @return Retorna el numero de id.
int censistaId(void) {
	static int id = 999;
	id++;
	return id;
}


/** @brief Carga 5 censistas de manera automatica en las primeras
 * 5 posiciones del array de censistas.
 *
 */
void cargaForzadaCensistas(Censista * list)
{
		strncpy(list[0].name, "Juan",sizeof(list[0].name));
		strncpy(list[0].lastName, "Perez",sizeof(list[0].lastName));
		list[0].idCensista = censistaId();
		list[0].edadCensista = 49;
		list[0].estadoCensista = LIBERADO;
		list[0].isEmpty = 0;
		list[0].datosNacimiento.diaNacimiento = 10;
		list[0].datosNacimiento.mesNacimiento = 9;
		list[0].datosNacimiento.anioNacimiento = 1973;
		strncpy(list[0].direccionCensista.calle, "Avenida mitre",sizeof(list[0].direccionCensista.calle));
		list[0].direccionCensista.altura = 500;


		strncpy(list[1].name, "Marcos",sizeof(list[1].name));
		strncpy(list[1].lastName, "Amarillo",sizeof(list[1].lastName));
		list[1].idCensista = censistaId();
		list[1].edadCensista = 20;
		list[1].estadoCensista = LIBERADO;
		list[1].isEmpty = 0;
		list[1].datosNacimiento.diaNacimiento = 26;
		list[1].datosNacimiento.mesNacimiento = 2;
		list[1].datosNacimiento.anioNacimiento = 2002;
		strncpy(list[1].direccionCensista.calle, "Donato alvarez",sizeof(list[1].direccionCensista.calle));
		list[1].direccionCensista.altura = 2057;


		strncpy(list[2].name, "Pedro",sizeof(list[2].name));
		strncpy(list[2].lastName, "Diaz",sizeof(list[2].lastName));
		list[2].idCensista = censistaId();
		list[2].edadCensista = 29;
		list[2].estadoCensista = LIBERADO;
		list[2].isEmpty = 0;
		list[2].datosNacimiento.diaNacimiento = 16;
		list[2].datosNacimiento.mesNacimiento = 3;
		list[2].datosNacimiento.anioNacimiento = 1993;
		strncpy(list[2].direccionCensista.calle, "Victor hugo",sizeof(list[2].direccionCensista.calle));
		list[2].direccionCensista.altura = 1453;


		strncpy(list[3].name, "Juanita",sizeof(list[3].name));
		strncpy(list[3].lastName, "Lavo",sizeof(list[3].lastName));
		list[3].idCensista = censistaId();
		list[3].edadCensista = 19;
		list[3].estadoCensista = LIBERADO;
		list[3].isEmpty = 0;
		list[3].datosNacimiento.diaNacimiento = 30;
		list[3].datosNacimiento.mesNacimiento = 12;
		list[3].datosNacimiento.anioNacimiento = 2003;
		strncpy(list[3].direccionCensista.calle, "belgrano",sizeof(list[3].direccionCensista.calle));
		list[3].direccionCensista.altura = 652;


		strncpy(list[4].name, "Jorge",sizeof(list[4].name));
		strncpy(list[4].lastName, "Dotero",sizeof(list[4].lastName));
		list[4].idCensista = censistaId();
		list[4].edadCensista = 31;
		list[4].estadoCensista = LIBERADO;
		list[4].isEmpty = 0;
		list[4].datosNacimiento.diaNacimiento = 10;
		list[4].datosNacimiento.mesNacimiento = 9;
		list[4].datosNacimiento.anioNacimiento = 1991;
		strncpy(list[4].direccionCensista.calle, "Washington",sizeof(list[4].direccionCensista.calle));
		list[4].direccionCensista.altura = 354;

}

/** @brief Busca en el array de censistas el primer censista en estado
 * LIBERADO
 * @param list Censista * puntero al array de censistas.
 * @param len int largo del array.
 * @return Retorna la posicion del censista liberado si lo encuentra
 * o -1 si no hay ninguno que este liberado.
 */
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

/** @brief Busca en el array de censistas uno que coincida con el id
 * que recibe por parametro.
 * @param list Censista * puntero al array de censistas.
 *@param len int largo del array.
 *@param id que busca en el array de censistas.
 *@return Retorna la posicion (indice) del censista que coincide
 * o -1 si no lo encontro.
 */
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

/** @brief Verifica en el array de censistas si hay uno que coincida con el
 * id y ademas este en estado ACTIVO.
 * @param list Censista * puntero al array de censistas.
 * @param len int largo del array.
 * @param idZona Id que busca en el array de censistas.
 *  *@return Retorna la posicion (indice) del censista que coincide
 * o -1 si no lo encontro.
 */
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

