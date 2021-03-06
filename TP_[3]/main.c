#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//Hay algunos IDs que faltan porque estubo probando que el id siga aunque cierre el programa o elimine un pasajero

#define MENU_OPCION_MINIMA 1
#define MENU_OPCION_MAXIMA 10

int main()
{
	setbuf(stdout, NULL);

	int contadorId;
	int option;
	int quedarseEnPrograma;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int banderaOpcionDiez;
	int modoGuardado;
	int mostrarPasajerosBinario;
	int mostrarPasajerosTexto;
	LinkedList* listaPasajeros;


	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;
	banderaOpcionDiez = 0;
	quedarseEnPrograma=1;
	modoGuardado=-1;

    listaPasajeros = ll_newLinkedList();

    while(controller_loadFromBinaryContador("contador.bin" , &contadorId));

    do{
		printf("---------------------Menu-----------------------\n"
				"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
				"3. Ingresar datos de un pasajero\n"
				"4. Modificar datos de un pasajero, se requiere su ID\n"
				"5. Eliminar un pasajero, se requiere su ID\n"
				"6. Informe sobre pasajeros:\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
				"10. Salir\n\n");

		if(!utn_GetIntRango(&option, "Ingrese la opcion: ", "Dato invalido. Ingrese la opcion: ", MENU_OPCION_MINIMA, MENU_OPCION_MAXIMA, 1))
		{
			switch(option)
			{
				case 1:
					if(!banderaOpcionUno && !banderaOpcionDos)
					{
						switch(controller_loadFromText("data.csv",listaPasajeros))
						{
							case 0:
								printf("\n\nSe cargaron con exito todos los pasajeros\n\n");
								banderaOpcionUno=1;
								break;

							case 1:
								printf("\n\nHa habido un error en la lectura del archivo\n\n");
								break;

							case 2:
								printf("\n\nNo se pudieron cargar algunos los archivos\n\n");
								banderaOpcionUno=1;
								break;
						}
					}
					else
					{
						printf("\n\nNo se puede cargar el archivo si ya lo hiciste antes\n\n");
					}
					break;

				case 2:
					if(!banderaOpcionUno && !banderaOpcionDos)
					{
						switch(controller_loadFromBinary("data.bin",listaPasajeros))
						{
							case 0:
								printf("\n\nSe cargaron con exito todos los pasajeros\n\n");
								banderaOpcionDos=1;
								break;

							case 1:
								printf("\n\nHa habido un error en la lectura del archivo\n\n");
								break;

							case 2:
								printf("\n\nNo se pudieron cargar algunos los archivos\n\n");
								banderaOpcionDos=1;
								break;
						}
					}
					else
					{
						printf("\n\nNo se puede cargar el archivo si ya lo hiciste antes\n\n");
					}
					break;

				case 3:
					if(controller_addPassenger(listaPasajeros, &contadorId))
					{
						printf("\n\nHa habido un error en la carga del pasajero\n\n");
					}
					else
					{
						banderaOpcionTres=1;
						banderaOpcionDiez=0;
						while(controller_saveAsBinaryContador("contador.bin" , &contadorId));
					}

					break;

				case 4:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						switch(controller_editPassenger(listaPasajeros))
						{
							case 0:
								printf("\n\nEl pasajero se ha modificado con exito\n\n");
								banderaOpcionDiez=0;
								break;

							case -1:
								printf("\n\nHa ocurrido un error en la modificacion del pasajero\n\n");
								break;

							case 1:
								printf("\n\nNo se ha encontrado el pasajero que desea modificar, posiblemento no existe o ya habia sido eliminado\n\n");
								break;
						}
					}
					else
					{
						printf("\n\nNo se puede editar ningun pasajero, debido a que no hay ninguno cargado\n\n");
					}

					break;

				case 5:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						switch(controller_removePassenger(listaPasajeros))
						{
							case -1:
								printf("\n\nNo se ha encontrado el pasajero que desea eliminar o ya habia sido eliminado\n\n");
							break;

							case 0:
								printf("\n\nSe ha eliminado con exito al pasajero\n\n");
								banderaOpcionDiez=0;
								break;

							case 1:
								printf("\n\nHa ocurrido un error en la eliminacion del pasajero\n\n");
								break;

							case 2:
								printf("\n\nCancelaste la eliminacion del pasajero, o hubo un error de ultimo momento\n\n");
								break;
						}
					}
					else
					{
						printf("\n\nNo se puede eliminar ningun pasajero, debido a que no hay ninguno cargado\n\n");
					}
					break;

				case 6:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						switch(controller_ListPassenger(listaPasajeros))
						{
							case 0:
								printf("\n\nNO ha habido incovenientes a la hora de mostrar los pasajeros\n\n");
								break;

							case 1:
								printf("\n\nHa ocurrido un error debido a que el puntero recibido es nulo\n\n");

								break;

							case 2:
								printf("\n\nHa ocurrido un error en la lectura de al menos un pasajero\n\n");
								break;
						}
					}
					else
					{
						printf("\n\nNo se pueden listar los pasajeros, debido a que no hay ninguno cargado\n\n");
					}

					break;

				case 7:
					if(banderaOpcionUno || banderaOpcionDos || banderaOpcionTres)
					{
						switch(controller_sortPassenger(listaPasajeros))
						{
							case -1:
								printf("\n\nNo se pueden ordenar los pasajeros, debido a que el puntero es nulo\n\n");
								break;

							case 0:
								printf("\n\nLos pasajeros han sido ordenados con exito\n\n");
								banderaOpcionDiez=0;
								break;

							case 1:
								printf("\n\nHa habido un error a la hora de elejir los criterios de ordenamiento\n\n");
								break;
						}
					}
					else
					{
						printf("\n\nNo se pueden ordenar los pasajeros, debido a que no hay ninguno cargado\n\n");
					}

					break;

				case 8:
				case 9:
					if(banderaOpcionUno || banderaOpcionDos)
					{
						modoGuardado =1;
					}
					else
					{
						if(banderaOpcionTres)
						{
							modoGuardado=0;
						}
						else
						{
							printf("\n\nNo se pueden guardar los pasajeros, debido a que no hay ninguno cargado\n\n");
						}
					}

					if(option == 8)
					{
						mostrarPasajerosBinario = 0;
						mostrarPasajerosTexto = 1;
					}
					else
					{
						if(option == 9)
						{
							mostrarPasajerosBinario = 1;
							mostrarPasajerosTexto = 0;
						}
					}

					if(modoGuardado != -1)
					{
						switch(controller_saveTextAndBinary("data.csv", "data.bin", listaPasajeros, modoGuardado, mostrarPasajerosBinario, mostrarPasajerosTexto))
						{
							case 0:
								printf("\n\nLos archivos se han guardado con exito\n\n");
								banderaOpcionDiez=1;
								break;

							case 1:
								printf("\n\nHa habido un error en el guardado del archivo\n\n");
								break;

							case 2:
								printf("\n\nNo se pudieron guardar algunos los archivos, si lo desea puede guardar pero no es conveniente\n\n");
								banderaOpcionDiez=1;
								break;
						}
					}
					break;

				case 10:
					if(banderaOpcionDiez)
					{
						quedarseEnPrograma=0;
						printf("\n\nSaliendo...\n\n");
					}
					else
					{
						printf("\n\nNO PUEDE salir del programa sin antes haber guardado algun archivo\n\n");
					}
					break;
			}
			printf("\n\n");
		}
    }while(quedarseEnPrograma);

    ll_deleteLinkedList(listaPasajeros);

    return 0;
}
