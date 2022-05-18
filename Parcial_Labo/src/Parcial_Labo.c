#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaESDeDatos.h"
#include "informes.h"

#define LEN_CEN 10
#define LEN_ZONAS 15

int main(void) {
	setbuf(stdout, NULL);

	int opcionDelMenu;
	int eleccionlocalidad;
	Censista censistas[LEN_CEN];
	zonaCenso zonasACensar[LEN_ZONAS];
	initCensistas(censistas, LEN_CEN);
	initZonas(zonasACensar, LEN_ZONAS);
	int localidades[5]={LANUS, AVELLANEDA,GERLI, ALSINA, BARRACAS};

	do{
		fflush(stdin);
		if(utn_getInt(&opcionDelMenu,"Indique la opcion del menu\n1)Cargar censista\n2)Modificar censista\n3)Dar de baja censista\n4)Cargar zona\n5)Asignar zona a censar\n6)Carga de datos:\n7)Mostrar censistas:\n8)Mostrar zonas\n9)Carga forzada de censistas\n10)Carga forzada de zonas\n11)opcion a descubrir en el futuro\n12)Salir", "Indique una opcion valida", 1, 12,2)== 0){
			switch(opcionDelMenu){
			case 1:
					agregarCensista(censistas, LEN_CEN);
				break;
			case 2:
					modificarCensista(censistas, LEN_CEN);
				break;
			case 3:
					removeCensista(censistas,LEN_CEN);
				break;
			case 4:
				if (utn_getInt(&eleccionlocalidad, "¿Que localidad desea cargar?\n1)Lanus\n2)Avellaneda\n3)Gerli\n4)Alsina\n5)Barracas", "Error", 1,6,2)==0){
					switch(eleccionlocalidad){
						case LANUS:
							cargarZona(zonasACensar, LEN_ZONAS,localidades[0]);
							break;
						case AVELLANEDA:
							cargarZona(zonasACensar, LEN_ZONAS,localidades[1]);
							break;
						case GERLI:
							cargarZona(zonasACensar, LEN_ZONAS,localidades[2]);
							break;
						case ALSINA:
							cargarZona(zonasACensar, LEN_ZONAS,localidades[3]);
							break;
						case BARRACAS:
							cargarZona(zonasACensar, LEN_ZONAS,localidades[4]);
							break;
						}
				}
				break;
			case 5:
					asignarZonaACensar(censistas, LEN_CEN,zonasACensar, LEN_ZONAS);
				break;
			case 6:
					cargaDeDatos(zonasACensar,LEN_CEN,censistas,LEN_ZONAS);
				break;
			case 7:
					printCensistas(censistas, LEN_CEN);
				break;
			case 8:
				printZonasyCensistas(zonasACensar, LEN_CEN, censistas);
				break;
			case 9:
				cargaForzadaCensistas(censistas);
				break;
			case 10:
				cargaForzadaZona(zonasACensar);
				break;
			case 11:

				break;
			case 12:
				break;
			}
		}
	}while(opcionDelMenu != 12);
	return 0;
}

