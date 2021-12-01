/*
 * Productos.c
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"

int productos_inicializar(eProducto productos[], int tam)
{
	int retorno = -1;
	int i;

	for(i = 0; i < tam; i++)
	{
		productos[i].estado = VACIO;
	}
	return retorno;
}
int productos_buscarEspacio(eProducto productos[], int tam)
{
	int index = -1;
	int i;

	for(i = 0; i < tam; i++)
	{
		if(productos[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}
int productos_buscarPorId(eProducto productos[], int tam, int id)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
		{
			if(productos[i].estado == OCUPADO && productos[i].id == id)
			{
				index = i;
				break;
			}
		}
	return index;
}
int productos_recorrerArray(eProducto productos[], int tam, int id)
{
	int retorno = -1;

	for(int i = 0; i < tam; i++)
	{
		if(productos[i].id == id)
		{
			retorno = 0;
		}
	}
	return retorno;
}
float productos_promediarPrecio(eProducto productos[], int tam)
{
	int i;
	float acumulador = 0;
	int divisor = 0;
	float promedio;

	for(i = 0; i < tam; i++)
	{
		if(productos[i].estado == OCUPADO)
		{
			acumulador = acumulador + productos[i].precio;
			divisor++;
		}

	}

	promedio = acumulador / (float)divisor;

	return promedio;
}
void productos_mostrarPromedio(float promedio)
{
	printf("\nEl promedio de precio de los productos es: %.2f\n", promedio);
}

