/*
 * cliente.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */
#define VACIO 1
#define CARGADO 0
#include "input.h"

struct {
	char nombre[51];
	char direccion[101];
	char cuit[14];
	int idCliente;
	int  idLocalidad;
	int isEmpty;
}typedef eCliente;


/// @fn int initCliente(eCliente*, int)
/// @bref recibe la lista y pone su estado en VACIO.
/// @param list lista de cliente
/// @param tamCliente tamaño de cliente
/// @return retorna 0 si pudo iniciar los clientes y -1 si no.
int initCliente(eCliente *list, int tamCliente);


/// @fn int encuentraPosicionLibre(eCliente*, int)
/// @brief recibe una lista el tamaño y encuentra la primer posicion libre del array
/// @param list
/// @param len
/// @return retorna la primer posicion libre del array si la encuentra o -1 si no lo hace
int encuentraPosicionLibreCliente(eCliente *list, int len);

/// @brief encuentra a un cliente  segun la id
/// @param list lista de clientes
/// @param len tamaño de la lista de clientes
/// @param id a buscar
/// @return retorna la posicion del cliente
int encontrarClientePorId(eCliente *list, int len, int id);


eCliente encontrarUnClientePorIdLocalidad(eCliente lista[], int len, int IdABuscar);

/// @fn int eliminarCliente(eCliente*, int, int)
/// @param list lista de eCliente
/// @param len tamaño de la lista
/// @param id id del empleado a borrar
/// @return regresa 0 si fue eliminado correctamente y 0 si no.
int eliminarCliente(eCliente *list, int len, int id);

eCliente encontrarUnClientePorId(eCliente lista[], int len, int IdABuscar);


/// @fn int contadorrDeClientesCargados(eCliente[], int)
/// @brief cuenta cuantos empleados cargados hay
/// @param lista array de eClientes.
/// @param len tamaño del array de eCliente.
/// @return retorna el numero de empleados cargados.
int contadorrDeClientesCargados(eCliente lista[], int len);

