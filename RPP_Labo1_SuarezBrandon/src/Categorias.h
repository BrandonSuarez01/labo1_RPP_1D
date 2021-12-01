/*
 * Categorias.h
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */

#ifndef CATEGORIAS_H_
#define CATEGORIAS_H_

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


#define TAMC 21

typedef struct
{
	int id;
	char nombre[TAMC];

}eCategoria;

void categorias_hardCodear(eCategoria categorias[], int tam);
int categorias_mostrar(eCategoria categorias[], int tam);
#endif /* CATEGORIAS_H_ */
