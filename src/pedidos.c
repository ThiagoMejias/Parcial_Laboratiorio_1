/*
 * pedidos.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */
#include "pedidos.h"

int initPedidos(ePedidos *list, int tamCliente) {
	int retorno;
	retorno = -1;
	if (list != NULL && tamCliente > 0) {
		for (int i = 0; i < tamCliente; i++) {
			list[i].isEmpty = VACIO;
			list[i].estado = NULO;
		}
		retorno = 0;
	}

	return retorno;
}

int encuentraPosicionLibrePedidos(ePedidos *list, int len) {
	int pos = -1;
	if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == VACIO) {
				pos = i;
				break;
			}
		}

	}

	return pos;
}

int mostrarUnPedido(ePedidos pedido) {
	printf("%d,%.2f, %.2f,%.2f,%.2f,%.2f\n ", pedido.IdPedido, pedido.kilos,
			pedido.basura, pedido.HDPE, pedido.LDPE, pedido.PP);

	return 0;
}
int encontrarPedidoPorId(ePedidos *list, int len, int id) {
	int pos;
	pos = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == CARGADO && list[i].IdPedido == id) {
				pos = i;
				break;
			}
		}
	}

	if (pos == -1) {
		printf("no existe Pedido con ese ID\n");
	}

	return pos;
}

int cantidadDeKilosTotalesDePP(ePedidos pedidos[], int tamPedidos, float *total) {
	int retorno;
	float acumuladorDePP;
	acumuladorDePP = 0;
	retorno = -1;
	if (pedidos != NULL && tamPedidos > 0) {

		for (int i = 0; i < tamPedidos; i++) {
			if (pedidos[i].estado == COMPLETADO) {
				acumuladorDePP = acumuladorDePP + pedidos[i].PP;
			}

		}
		*total = acumuladorDePP;
		retorno = 0;
	}

	return retorno;
}

int eliminarPedidos(ePedidos list[], int len, int id) {
	int retorno;

	retorno = -1;
	if (list != NULL && len > 0) {
		retorno = 0;
		for (int i = 0; i < len; i++)
		{
			if (list[i].idCliente == id) {

				list[i].isEmpty = VACIO;
			}
		}
	}
	return retorno;
}

