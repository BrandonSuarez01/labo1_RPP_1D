/*
 * Productos.h
 *
 *  Created on: 1 dic. 2021
 *      Author: brans
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#define TAMUNO 21
#define TAMDOS 31
#define VACIO 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[TAMUNO];
	char descripcion[TAMDOS];
	float precio;
	int idCategoria;
	int estado;

}eProducto;

int productos_inicializar(eProducto productos[], int tam);
int productos_buscarEspacio(eProducto productos[], int tam);
int productos_buscarPorId(eProducto productos[], int tam, int id);
int productos_recorrerArray(eProducto productos[], int tam, int id);
float productos_promediarPrecio(eProducto productos[], int tam);
void productos_mostrarPromedio(float promedio);

#endif /* PRODUCTOS_H_ */
