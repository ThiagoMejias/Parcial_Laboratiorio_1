/*
 * pedidos.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define VACIO 1
#define CARGADO 0
#define PENDIENTE 3
#define COMPLETADO  2
#define NULO -1

#include "input.h"
struct {
	int IdPedido;
	int idCliente;
	int estado;
	int isEmpty;
	float kilos;
	float HDPE;
	float LDPE;
	float PP;
	float basura;

}typedef ePedidos;

#endif /* PEDIDOS_H_ */
/// @fn int initPedidos(ePedidos*, int)
/// @brief recibe la lista y pone su estado en VACIO.
/// @param list lista de ePedidos
/// @param tamCliente tamaño de la lista
/// @return retorna 0 si pudo iniciar los clientes y -1 si no
int initPedidos(ePedidos *list, int tamCliente);

/// @fn int encuentraPosicionLibrePedidos(ePedidos*, int)
/// @brief recibe una lista el tamaño y encuentra la primer posicion libre del array
/// @param list
/// @param len
/// @return retorna la primer posicion libre del array si la encuentra o -1 si no lo hace
int encuentraPosicionLibrePedidos(ePedidos *list, int len);

/// @fn int mostrarUnPedido(ePedidos)
/// @brief muestra el ePedido recibido
/// @param pedido un ePedido
/// @return 0

int mostrarUnPedido(ePedidos pedido);

/// @fn int encontrarPedidoPorId(ePedidos*, int, int)
/// @brief encuentra un pedido por id.
/// @param list array de pedidos
/// @param len tamaño del array de pedidos
/// @param id id a buscar
/// @return regresa la posicion del pedido si se encontro o -1 si no fue asi.
int encontrarPedidoPorId(ePedidos *list, int len, int id);

/// @fn int cantidadDeKilosTotalesDePP(ePedidos[], int, float*)
/// @brief suma  el total de kilos  de PP de todos los pedidos completados
/// @param pedidos array de ePedidos
/// @param tamPedidos tamaño del array de pedidos
/// @param total variable donde se retornara el total
/// @return regresa 0 si salio todo bien, de lo contrario -1
int cantidadDeKilosTotalesDePP(ePedidos pedidos[], int tamPedidos, float *total);

int eliminarPedidos(ePedidos list[], int len, int id);
