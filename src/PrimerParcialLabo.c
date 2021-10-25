/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : Thiago Mejias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo.h"

int main(void) {
	setbuf(stdout, NULL);
	eCliente clientes[TAMCLIENTE];
	eLocalidad localidades[TAMLOCALIDAD] =
			{ { 1, "Capital Federal" }, { 2, "Wilde" }, { 3, "Olivos" }, { 4,
					"Avellaneda" }, { 5, "San isidro" } };
	ePedidos pedidos[TAMPEDIDOS];
	int opciones, banderaDePrimeraInicializacion, banderaDePedidos, idCliente,
			idPedidos, retornoDeAgregado, opcionDelCaseDos;
	idCliente = 0;
	idPedidos = 0;
	banderaDePrimeraInicializacion = 0;
	banderaDePedidos = 0;
	do {
		printf("\t\t\t\t *MENU*\n");
		printf(
				"*1- Alta de cliente*\n"
						"*2-Modificar datos de cliente*\n"
						"*3-Dar de baja un cliente*\n"
						"*4-Crear Pedido*\n"
						"*5-Procesar Residuos*\n"
						"*6-Imprimir Clientes*\n"
						"*7-Imprimir Pedidos Pendientes*\n"
						"8-Imprimir Pedidos Procesados*\n"
						"*9-Cantidad De Pedidos Por Localidad*\n"
						"*10-Cantidad De Kilos de polipropileno reciclado promedio por cliente*\n"
						"*11-Cliente Con mas Pedidos Pendientes-*\n"
						"*12-Cliente con mas pedidos Completados-*\n"
						"*13-Cliente con mas pedidos-*\n"
						"*14-SALIR-*\n");
		getIntWithParams("ingrese la opcion deseada\n", "error\n", &opciones, 1,
				14);
		switch (opciones) {
		case 1:
			if (banderaDePrimeraInicializacion == 0) {
				initCliente(clientes, TAMCLIENTE);
				banderaDePrimeraInicializacion = 1;
			}

			retornoDeAgregado = agregarCliente(clientes, TAMCLIENTE,
					localidades, TAMLOCALIDAD, &idCliente);
			if (retornoDeAgregado == 0) {
				mostrarClientePorId(clientes, TAMCLIENTE, localidades,
				TAMLOCALIDAD, idCliente);
			}
			break;
		case 2:
			if (banderaDePrimeraInicializacion == 1) {
				system("cls");
				do {
					printf("*menu de modificaciones*\n");
					printf("1. Modificacion de direcciones\n"
							"2. Modificacion de Localidades\n"
							"3.Volver al menu principal\n");
					getIntWithParams("Ingrese la opcion deseada\n", "error-",
							&opcionDelCaseDos, 1, 3);
					switch (opcionDelCaseDos) {
					case 1:
						modificarDireccion(clientes, TAMCLIENTE, localidades,
						TAMLOCALIDAD);
						break;
					case 2:
						modificarLocalidad(clientes, TAMCLIENTE, localidades,
						TAMLOCALIDAD);
						break;
					}
				} while (opcionDelCaseDos != 3);

			} else {
				printf(
						"Es necesario que haya al menos un cliente registrado\n");
			}

			break;

		case 3:
			if (banderaDePrimeraInicializacion == 1) {

				darDeBaja(clientes, TAMCLIENTE, localidades, TAMLOCALIDAD,
						pedidos, TAMPEDIDOS);
			} else {
				printf(
						"Es necesario que haya al menos un cliente registrado\n");
			}

			break;

		case 4:
			if (banderaDePrimeraInicializacion == 1) {
				if (banderaDePedidos == 0) {
					initPedidos(pedidos, TAMPEDIDOS);
					banderaDePedidos = 1;
				}
				CrearPedido(pedidos, TAMPEDIDOS, clientes, TAMCLIENTE,
						localidades, TAMLOCALIDAD, &idPedidos);

			} else {
				printf(
						"Es necesario que haya al menos un cliente registrado\n");
			}
			break;
		case 5:
			if (banderaDePedidos == 1) {
				procesarResiduos(pedidos, TAMPEDIDOS, clientes, TAMCLIENTE);

			} else {
				printf("No hay pedidos cargados\n");
			}

			break;
		case 6:
			if (banderaDePedidos == 1) {
				muestraDeClientesConContador(clientes, TAMCLIENTE, localidades,
				TAMLOCALIDAD, pedidos, TAMPEDIDOS);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;

		case 7:
			if (banderaDePedidos == 1) {
				mostrarPedidosPendientesConCliente(pedidos, TAMPEDIDOS,
						clientes, TAMCLIENTE);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;
		case 8:
			if (banderaDePedidos == 1) {
				mostrarPedidosCompletadosConCliente(pedidos, TAMPEDIDOS,
						clientes, TAMCLIENTE);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;

		case 9:
			if (banderaDePedidos == 1) {
				cantidadDePedidosPorLocalidad(localidades, TAMLOCALIDAD,
						pedidos,
						TAMPEDIDOS, clientes, TAMCLIENTE);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;

		case 10:
			if (banderaDePedidos == 1) {
				promedioDeKilosPP(pedidos, TAMPEDIDOS, clientes, TAMCLIENTE);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;

		case 11:
			if (banderaDePedidos == 1) {
				buscarClienteConMasPedidosPendientes(clientes, TAMCLIENTE,
						pedidos, TAMPEDIDOS);
			} else {
				printf("No hay pedidos cargados\n");
			}
			break;
		case 12:
			if (banderaDePedidos == 1) {
				buscarClienteConMasPedidosCompletados(clientes, TAMCLIENTE,
						pedidos, TAMPEDIDOS);

			} else {
				printf("No hay pedidos cargados\n");
			}
			break;
		case 13:
			if (banderaDePedidos == 1) {
				buscarClientesConMasPedidos(clientes, TAMCLIENTE, pedidos,
				TAMPEDIDOS);

			} else {
				printf("No hay pedidos cargados\n");
			}
			break;
		}

	} while (opciones != 14);

}
