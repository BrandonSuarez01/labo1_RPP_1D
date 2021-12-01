/*
 * Nexo.h
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include "Categorias.h"
#include "Funciones.h"
#include "Productos.h"

int nexo_productosAgregarUno(eProducto producto[], eCategoria categoria[], int* id, int tamCat, int tam);
int nexo_productosEstablecerUno(eProducto producto[], eCategoria categoria[], int* id, int tamCat, int tam,  int index);
int nexo_listarProductos(eProducto producto[], eCategoria categoria[], int tam);
int nexo_eliminarProducto(eProducto producto[], eCategoria categoria[], int tam);
void nexo_mostrarSeleccion(eProducto producto[], eCategoria categoria[], int index);
int nexo_modificarUnProducto(eProducto producto[], eCategoria categoria[], int tamCat, int tam);
int nexo_mostrarCategoriasConProductos(eProducto producto[], eCategoria categoria[], int tamCat, int tam);
#endif /* NEXO_H_ */
