#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

#define PRECIO_MINIMO 10000

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	char idCaracter[15];
	char nombre[50];
	char apellido[50];
	char precioCaracter[50];
	char tipoPasajeroCaracter[30];
	char codigoVuelo[8];
	char statusFlightCaracter[30];

	Passenger* nuevoPasajero;

	retorno=1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter);

		while(7 == fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCaracter, nombre, apellido, precioCaracter, codigoVuelo, tipoPasajeroCaracter, statusFlightCaracter))
		{
			nuevoPasajero = Passenger_newParametros(idCaracter, nombre, apellido, precioCaracter, tipoPasajeroCaracter, codigoVuelo, statusFlightCaracter);
			if(nuevoPasajero   != NULL &&
					!ll_add(pArrayListPassenger, nuevoPasajero))
			{
				Passenger_MostrarUnPasajero(nuevoPasajero);
			}
			else
			{
				retorno=2;
				break;
			}

			if(feof(pFile))
			{
				retorno=0;
				break;
			}
		}
	}

    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* nuevoPasajero;
	int retorno;
	int activarRomper;
	int estadoLeido;

	activarRomper=0;

	retorno =1;
	estadoLeido=0;



	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno=0;
		while(!feof(pFile))
		{
			nuevoPasajero = Passenger_new();
			if(nuevoPasajero != NULL)
			{
				estadoLeido = fread(nuevoPasajero, sizeof(Passenger), 1, pFile);

				if(estadoLeido)
				{
					if(ll_add(pArrayListPassenger, nuevoPasajero))
					{
						activarRomper=1;
					}
					else
					{
						Passenger_MostrarUnPasajero(nuevoPasajero);
					}
				}

			}
			else
			{
				activarRomper=1;
			}

			if(activarRomper)
			{
				retorno =2;
				break;
			}
		}
	}

    return retorno;
}

int parser_contadorFromBinary(FILE* pArchivo, int* pContador)
{
	int retorno;
	int contadorADevolver;

	retorno =1;

	if(pArchivo != NULL && pContador != NULL)
	{
		if(fread(&contadorADevolver, sizeof(int), 1, pArchivo)>0)
		{
			*pContador = contadorADevolver;
			retorno=0;
		}
	}

	return retorno;
}
