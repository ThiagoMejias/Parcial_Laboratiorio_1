/*
 * localidad.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Thiago
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include "input.h"

#endif /* LOCALIDAD_H_ */

struct{
	int id;
	char description[51];

}typedef eLocalidad;


/// @fn int mostrarUnaLocalidad(eLocalidad)
/// @brief muestra una localidad
/// @param localidad eLocalidad
/// @return 0
int mostrarUnaLocalidad(eLocalidad localidad);
/// @fn int mostrarLocalidades(eLocalidad*, int)
/// @brief muestra todas las localidads
/// @param list lista de eLocalidads
/// @param len tamaño
/// @return 0 si se puede mostrar -1 si no.
int mostrarLocalidades(eLocalidad *list, int len);
/// @fn eLocalidad encontrareLocalidadPorId(eLocalidad[], int, int)
/// @param localidades array de elocalidad
/// @param len tamaño de elocalidad
/// @param IdABuscar el id a encontrar dentro del array
/// @return devuelve un eLocalidad donde se encontro el id.
eLocalidad encontrareLocalidadPorId(eLocalidad localidades[], int len, int IdABuscar);

