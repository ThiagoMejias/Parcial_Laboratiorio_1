#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include  <ctype.h>
#include <string.h>

#endif


/// @fn int getInt(char*)
/// @brief reibe un entero
/// @param mensaje
/// @return retorna un entero

int getInt(char *mensaje);

/// @fn float getFloat(char*)
/// @brieg recibe un float
/// @param mensaje
/// @return retorna el numero float recibido
float getFloat(char *mensaje);

/// @fn int esNumerico(char*)
/// @brief recibe una cadena y verifica si es numero o no
/// @param str cadena
/// @return retorna 0 si no es un numero o 1 si lo es
int esNumerico(char *str);
/// @fn int esNumerico(char*)
/// @brief recibe una cadena y verifica si es numero flotante o no
/// @param str cadena
/// @return retorna 0 si no es un numero  flotante o 1 si lo es
int esNumericoFlotante(char str[]);
/// @fn int esNumerico(char*)
/// @brief recibe una cadena y verifica si son letras o no
/// @param str cadena
/// @return retorna 0 si no son letras o 1 si lo es
int esSoloLetras(char str[]);
/// @fn int esNumerico(char*)
/// @brief recibe una cadena y verifica si es un cuit o no
/// @param str cadena
/// @return retorna -1 si no es un cuit y 1 si lo es
int isCuit(char cuit[]);
/// @fn int getCuit(char[], char[], char*)
/// @brief pide un cuit verificado
/// @param mensaje cadena de ingreso
/// @param mensajeDeError cadena de error
/// @param cuit cadena a verificar
/// @return retorna -1 si hubo error 0 si no.
int getCuit(char mensaje[], char mensajeDeError[], char *cuit);
/// @fn void getString(char[], char[])
/// @brief pide una cadena.
/// @param mensaje mensaje de entrada
/// @param input donde se cargara la cadena
/// @return retorna -1 si hubo error 0 si no.
void getString(char mensaje[], char input[]);
/// @fn void getString(char[], char[])
/// @brief pide una cadena de numeros.
/// @param mensaje mensaje de entrada
/// @param input donde se cargara la cadena
/// @return 1 si el texto contiene solo numeros
int getStringNumeros(char mensaje[], char input[]);
/// @fn void getString(char[], char[])
/// @brief pide una cadena de numeros flotantes.
/// @param mensaje mensaje de entrada
/// @param input donde se cargara la cadena
/// /// @return 1 si el texto contiene solo numeros flotantes.
int getStringNumerosFlotantes(char mensaje[], char input[]);
/// @fn void getString(char[], char[])
/// @brief pide una cadena de letras.
/// @param mensaje mensaje de entrada
/// @param input donde se cargara la cadena
/// @return 1 si el texto contiene solo letras
int getStringLetras(char mensaje[], char input[]);
int getValidInt(char mensaje[], int *input);
int getIntWithParams(char requestMessage[], char errorMessage[], int *input,
		int lowLimit, int hiLimit);
int getValidFloat(char mensaje[], float *input);
int getFloatWithParams(char requestMessage[], char errorMessage[], float *input,
		float lowLimit, float hiLimit);
int esAlpha(char str[]);
int getStringVerificado(char mensaje[], char mensajeError[], char *input);

