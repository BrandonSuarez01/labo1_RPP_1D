/*
 * Categorias.c
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Categorias.h"

void categorias_hardCodear(eCategoria categorias[], int tam)
{
	int i;
	int auxId[] = {2000, 2001, 2002};
	char auxNombre[][TAMC] = {"Comida", "Juguete", "Golosina"};

	for(i = 0; i < tam; i++)
	{
		categorias[i].id = auxId[i];
		strcpy(categorias[i].nombre, auxNombre[i]);
	}
}
int categorias_mostrar(eCategoria categorias[], int tam)
{
	int retorno = -1;
	int i;

	printf("\n%-10s - %-20s \n\n", "ID", "Nombre");
	for(i = 0; i < tam; i++)
	{
		printf("%-10d - %-20s\n", categorias[i].id, categorias[i]. nombre);
	}

	return retorno;
}

