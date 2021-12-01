/*
 * Nexo.c
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include "Categorias.h"
#include "Funciones.h"
#include "Productos.h"
#include "Nexo.h"

int nexo_productosAgregarUno(eProducto producto[], eCategoria categoria[], int* id, int tamCat, int tam)
{
	int retorno = -1;
	int index = productos_buscarEspacio(producto, tam);
	int auxId = *id;

	if(index != -1)
	{
		if(nexo_productosEstablecerUno(producto, categoria, id, tamCat, tam, index) == 0)
		{
			printf("Se cargo el producto correctamente.\n");
			auxId++;
			*id = auxId;
			retorno = 0;
		}
		else
		{
			printf("Se cancelo la carga de el producto.\n");
		}
	}
	else
	{
		printf("ERROR ya no hay espacio en el que cargar un nuevo producto.\n");
	}
	return retorno;
}
int nexo_productosEstablecerUno(eProducto producto[], eCategoria categoria[], int* id, int tamCat, int tam,  int index)
{
	int retorno = -1;
	int auxIdCat;
	float auxPrecio;
	char auxNombre[TAMUNO];
	char auxDescrip[TAMDOS];

	pedirString(auxNombre, "Ingrese el nombre del producto(Hasta 20 caracteres): ", "ERROR - Reingrese el nombre del producto(Hasta 20 caracteres): ", TAMUNO);
	pedirString(auxDescrip, "Ingrese la descripcion del producto(Hasta 30 caracteres): ","ERROR - Reingrese la descripcion del producto(Hasta 30 caracteres): ", TAMDOS);
	pedirFlotante(&auxPrecio, "Ingrese el precio del producto(200 a 2000): ","ERROR - Reingrese el precio del producto(200 a 2000): ", 200, 2000);
	categorias_mostrar(categoria, tamCat);
	obtenerNumeroValido(&auxIdCat, "\nIngrese el ID de la categoria del producto: ", "\nERROR esa ID no existe, reingrese el ID de la categoria del producto: ", 2000, 2002);


	if(verificarConfirmacion("\nDesea cargar este producto? (Presione 'S' para confirmar): ") == 0)
	{
		producto[index].id = *id;
		strcpy(producto[index].nombre, auxNombre);
		strcpy(producto[index].descripcion, auxDescrip);
		producto[index].precio = auxPrecio;
		producto[index].idCategoria = auxIdCat;
		producto[index].estado = OCUPADO;
		retorno = 0;
	}
	return retorno;
}
int nexo_eliminarProducto(eProducto producto[], eCategoria categoria[], int tam)
{
	int retorno = -1;
	int auxId;
	int index;

	nexo_listarProductos(producto, categoria, tam);

	obtenerNumeroValido(&auxId, "Ingrese la ID de la estadia que desea eliminar: ", "ERROR esa ID no existe, reingrese la ID de la estadia que desea eliminar: ", 1000,1010);
	index = productos_buscarPorId(producto, tam, auxId);

	if(index != -1)
	{
		nexo_mostrarSeleccion(producto, categoria, index);
		if(verificarConfirmacion("\nDesea confirmar la baja de la estadia? (Presione 'S' para confirmar): ") == 0)
		{
			producto[index].estado = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}
int nexo_listarProductos(eProducto producto[], eCategoria categoria[], int tam)
{
	int retorno = -1;

	printf("\n%-10s - %-20s - %-20s - %-20s - %-20s - %-20s\n", "ID", "Nombre", "Descripcion", "Precio", "ID Categoria", "Nombre categoria");
	for(int i = 0; i < tam; i++)
	{
		for(int j = 0; j < tam; j++)
		{
			if(producto[i].idCategoria == categoria[j].id && producto[i].estado == OCUPADO)
			{
				printf("%-10d - %-20s - %-20s - %-20.2f - %-20d - %-20s\n",
						producto[i].id, producto[i].nombre, producto[i].descripcion, producto[i].precio, categoria[j].id, categoria[j].nombre);
				break;
				retorno = 0;
			}
		}
	}
	return retorno;
}
void nexo_mostrarSeleccion(eProducto producto[], eCategoria categoria[], int index)
{
	printf("\n%-10s - %-20s - %-20s - %-20s - %-20s - %-20s\n", "ID", "Nombre", "Descripcion", "Precio", "ID Categoria", "Nombre categoria");
	printf("%-10d - %-20s - %-20s - %-20.2f - %-20d - %-20s\n",
	producto[index].id, producto[index].nombre, producto[index].descripcion, producto[index].precio, categoria[index].id, categoria[index].nombre);
}
int nexo_modificarUnProducto(eProducto producto[], eCategoria categoria[], int tamCat, int tam)
{
	int retorno = -1;
	int opcionSubMenu;
	int idIngresada;
	int index;
	int auxIdCat;
	float auxPrecio;

	nexo_listarProductos(producto, categoria, tam);
	obtenerNumeroValido(&idIngresada, "\nIngrese el ID de el producto a modificar: ", "\nERROR - Esa ID no existe, reingrese: ", 1000, 1010);
	index = productos_buscarPorId(producto, tam, idIngresada);

	while(productos_recorrerArray(producto, tam, idIngresada) == -1)
	{
		nexo_listarProductos(producto, categoria, tam);
		obtenerNumeroValido(&idIngresada, "\nERROR - No es posible encontrar esa ID, reingrese: ", "\nERROR - reingrese: ", 1000, 1010);
		productos_recorrerArray(producto, tam, idIngresada);
	}

	index = productos_buscarPorId(producto, tam, idIngresada);

	do
	{
		obtenerNumeroValido(&opcionSubMenu, "----------MODIFICAR----------\n"
											"1. Modificar categoria\n"
											"2. Modificar precio\n"
											"3. Salir.\n"
											"---------------------------\n"
											"Ingrese la opcion deseada: ",
											"----------MODIFICAR----------\n"
											"1. Modificar categoria\n"
											"2. Modificar precio\n"
											"3. Salir.\n"
											"---------------------------\n"
											"ERROR - reingrese la opcion deseada: ", 1, 3);
			switch(opcionSubMenu)
			{
				case 1 :
					if(index != -1)
					{
						categorias_mostrar(categoria, tamCat);
						obtenerNumeroValido(&auxIdCat, "\nIngrese el id de la nueva categoria: ", "\nERROR - Esa no es una categoria valida, reingrese: ",2000 , 2002);
						printf("\nDesea modificar la categoria %d del productp, por la nueva: %d?\n" ,producto[index].idCategoria, auxIdCat);
						if(verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
						{
							producto[index].idCategoria = auxIdCat;
							printf("Numero modificado correctamente...\n");
						}
						else
						{
							printf("Se cancelo la modificacion del telefono...\n");
						}
						systemPause("Presione una tecla para continuar...\n");
						retorno = 0;
					}
				break;
				case 2 :
					if(index != -1)
					{
						pedirFlotante(&auxPrecio, "Ingrese el nuevo precio(200 a 2000): ", "ERROR - Reingrese el nuevo precio(200 a 2000): ", 200, 2000);
						printf("\nDesea modificar el siguiente precio %.2f del producto, por el nuevo: %.2f?\n", producto[index].precio, auxPrecio);
						if(verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
						{
							producto[index].precio = auxPrecio;
							printf("Precio del producto modificado correctamente...\n");
						}
						else
						{
							printf("Se cancelo la modificacion del precio del producto...\n");
						}
						systemPause("Presione una tecla para continuar...\n");
						retorno = 0;
					}
				break;
			}
	}while(opcionSubMenu != 3);

	return retorno;
}
int nexo_mostrarCategoriasConProductos(eProducto producto[], eCategoria categoria[], int tamCat, int tam)
{
	int retorno = -1;
	int i;
	int j;


	for(i = 0; i < tamCat; i++)
	{
		printf("\nID: %d - Nombre : %s:\n",categoria[i].id, categoria[i].nombre);
		printf("\n%-10s - %-20s - %-20s\n", "ID producto", "Precio", "Descripcion");
		for(j = 0; j < tam; j++)
		{
			if(producto[j].estado == OCUPADO && categoria[i].id == producto[j].idCategoria)
			{
				printf("\n%-10d %-20.2f %-20s\n", producto[j].id, producto[j].precio, producto[j].descripcion);
				retorno = 0;
			}
		}
	}
	return retorno;
}
