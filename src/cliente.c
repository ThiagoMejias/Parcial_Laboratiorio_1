/*
 * cliente.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */

#include "cliente.h"

int initCliente(eCliente *list, int tamCliente) {
	int retorno;
	retorno = -1;
	if (list != NULL && tamCliente > 0) {
		for (int i = 0; i < tamCliente; i++) {
			list[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int encuentraPosicionLibreCliente(eCliente *list, int len) {
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

int encontrarClientePorId(eCliente *list, int len, int id) {
	int pos;
	pos = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == CARGADO && list[i].idCliente == id) {
				pos = i;
				break;
			}
		}
	}

	if (pos == -1) {
		printf("no existe cliente con ese ID\n");
	}

	return pos;
}

int eliminarCliente(eCliente *list, int len, int id) {
	int retorno, pos;
	retorno = -1;
	pos = encontrarClientePorId(list, len, id);
	if (pos > -1) {

		list[pos].isEmpty = VACIO;
		printf("el empleado fue dado de baja correctamente\n");
		retorno = 0;
	}

	return retorno;

}

eCliente encontrarUnClientePorId(eCliente lista[], int len, int IdABuscar) {
	eCliente aux;
	if (lista != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (lista[i].idCliente == IdABuscar) {
				aux = lista[i];
				break;
			}

		}

	}
	return aux;

}

eCliente encontrarUnClientePorIdLocalidad(eCliente lista[], int len,
		int IdABuscar) {
	eCliente aux;
	if (lista != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (lista[i].idLocalidad == IdABuscar) {
				aux = lista[i];
				break;
			}

		}

	}
	return aux;

}

int contadorrDeClientesCargados(eCliente lista[], int len) {
	int acumulador;
	acumulador = -1;

	if (lista != NULL && len > 0) {
		acumulador = 0;

		for (int i = 0; i < len; i++) {
			if (lista[i].isEmpty == CARGADO) {
				acumulador++;
			}
		}

	}

	return acumulador;
}

