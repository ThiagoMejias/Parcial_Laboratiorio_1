/*
 * localidad.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Thiago
 */

#include "localidad.h"

int mostrarUnaLocalidad(eLocalidad localidad) {
	int retorno;
	retorno = 0;

	printf("\t\t\t\t\t|%4d|%20s|\n", localidad.id, localidad.description);

	return retorno;
}
int mostrarLocalidades(eLocalidad *list, int len) {
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0) {
		system("cls");
		printf("\t\t\t\t\t___________________________\n");
		printf("\t\t\t\t\t|ID  |Localdidad          |\n");
		printf("\t\t\t\t\t|____|____________________|\n");
		for (int i = 0; i < len; i++) {
			mostrarUnaLocalidad(list[i]);
			retorno = 0;

		}
	}

	return retorno;
}

eLocalidad encontrareLocalidadPorId(eLocalidad localidades[], int len, int IdABuscar) {
	eLocalidad aux;
	if (localidades != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (localidades[i].id == IdABuscar) {
				aux = localidades[i];
				break;
			}

		}

	}
	return aux;

}

