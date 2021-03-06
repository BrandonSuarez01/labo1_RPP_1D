/*
 * Funciones.h
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


int esUnNumero(char* string);

int validarSigno(char* string);

int stringNormal(char* mensaje, char* string);

void pedirCaracter(char* caracter, char* mensaje);

int obtenerStringYNumeros(char* mensaje, char* input);

void pedirString(char* string, char* primerMensaje, char* mensajeError, int max);

int obtenerNumeroValido(int* numero, char* mensaje, char* mensajeError, int min, int max);

int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max);

int systemPause(char* message);

int verificarConfirmacion(char* mensaje);

#endif /* FUNCIONES_H_ */
