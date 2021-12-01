/*
Suarez Brandon
Recuperatorio primer parcial.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Categorias.h"
#include "Funciones.h"
#include "Productos.h"
#include "Nexo.h"

#define TAMCAT 3
#define TAM 10

int main(void)
{
	setbuf(stdout, NULL);

	eCategoria categorias[TAMCAT];
	eProducto productos[TAM];

	categorias_hardCodear(categorias, TAMCAT);
	productos_inicializar(productos, TAM);

	int opcion = 0;
	int id = 1000;
	int contador = 0;
	float promedio;

	do
	{
		obtenerNumeroValido(&opcion, "-----------Menu-----------\n"
									 "1. CARGAR un producto.\n"
									 "2. MODIFICAR un producto.\n"
									 "3. BAJA de un producto.\n"
									 "4. LISTAR productos.\n"
									 "5. LISTAR categorias.\n"
									 "6. PROMEDIO del precio de los productos.\n"
									 "7. LISTAR categorias con sus productos.\n"
									 "8. Salir.\n"
									 "--------------------------\n"
									 "Ingrese la opcion deseada: ",
									 "-----------Menu-----------\n"
									 "1. CARGAR un producto.\n"
									 "2. MODIFICAR un producto.\n"
									 "3. BAJA de un producto.\n"
									 "4. LISTAR productos.\n"
									 "5. LISTAR categorias.\n"
									 "6. PROMEDIO del precio de los productos.\n"
									 "7. LISTAR categorias con sus productos.\n"
									 "8. Salir.\n"
									 "--------------------------\n"
									 "ERROR - Reingrese la opcion deseada: ", 1, 8);

		switch(opcion)
		{
			case 1 :
				if(nexo_productosAgregarUno(productos, categorias, &id, TAMCAT, TAM) == 0)
				{
					contador++;
				}
			break;
			case 2 :
				if(contador > 0)
				{
					nexo_modificarUnProducto(productos, categorias, TAMCAT, TAM);
				}
				else
				{
					printf("Aun no se ingreso ningun producto...\n");
				}
			break;
			case 3 :
				if(contador > 0)
				{
					if(nexo_eliminarProducto(productos, categorias, TAM) == 0)
					{
						printf("\nSe dio de baja el producto...\n");
						contador--;
					}
					else
					{
						printf("\nSe interrumpio la baja del producto(Se cancelo o el ID no existe)...\n");
					}
				}
				else
				{
					printf("Aun no se ingreso ningun producto...\n");
				}
			break;
			case 4 :
				if(contador > 0)
				{
					systemPause("Listando, espere...Presione cualquier tecla para continuar...\n");
					nexo_listarProductos(productos, categorias, TAM);
				}
				else
				{
					printf("Aun no se ingreso ningun producto...\n");
				}
			break;
			case 5 :
				categorias_mostrar(categorias, TAMCAT);
			break;
			case 6 :
				if(contador > 0)
				{
					promedio = productos_promediarPrecio(productos, TAM);
					systemPause("\nCalculando...Presione cualquier tecla para continuar...\n");
					productos_mostrarPromedio(promedio);
				}
				else
				{
					printf("Aun no se ingreso ningun producto...\n");
				}
			break;
			case 7 :
				if(contador > 0)
				{
					systemPause("Listando, espere...Presione cualquier tecla para continuar...\n");
					nexo_mostrarCategoriasConProductos(productos, categorias, TAMCAT, TAM);
				}
				else
				{
					printf("Aun no se ingreso ningun producto...\n");
				}
			break;
			case 8 :
				printf("Finalizando el programa...");
			break;

		}


	}while(opcion != 8);
	return EXIT_SUCCESS;
}
