/*
 * nexo.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */

#include "nexo.h"

eCliente PedirUnCliente(eLocalidad *list, int len, int *idCliente) {

	eCliente aux;
	printf("-ingreso de clientes-\n");
	getStringVerificado("ingrese el nombre del nuevo cliente\n",
			"error, ingrese nuevamente el nombre del cliente.\n", aux.nombre);
	getString("ingrese la direccion\n", aux.direccion);
	getCuit(
			"ingrese el cuit, el formato es: 2 numeros, -, 8 numeros -, un numero. (00-12345678-9)\n",
			"ingrese correctamente el cuit\n", aux.cuit);
	mostrarLocalidades(list, len);
	getIntWithParams("ingrese el ID de la localidad que desee\n",
			"error, ingrese un ID valido\n", &aux.idLocalidad, 1, TAMLOCALIDAD);
	*idCliente = *idCliente + 1;
	aux.idCliente = *idCliente;
	return aux;

}

int agregarCliente(eCliente *listaCliente, int lenCliente,
		eLocalidad *listaLocalidad, int lenLocalidad, int *idCliente) {
	int retorno, pos;

	retorno = -1;
	if (listaCliente != NULL && lenCliente > 0 && listaLocalidad != NULL
			&& lenLocalidad > 0) {
		retorno = 0;
		pos = encuentraPosicionLibreCliente(listaCliente, lenCliente);
		if (pos != -1) {
			listaCliente[pos] = PedirUnCliente(listaLocalidad, lenLocalidad,
					idCliente);
			listaCliente[pos].isEmpty = CARGADO;
			retorno = 0;
		}
	}

	return retorno;

}
int mostrarClienteConLocalidadYContador(eCliente cliente, eLocalidad list[],
		int tamLocalidad, int contador) {
	eLocalidad aux;
	int retorno;
	retorno = -1;
	if (list != NULL && tamLocalidad > 0) {
		aux = encontrareLocalidadPorId(list, tamLocalidad, cliente.idLocalidad);
		printf("\t\t\t\t\t|%4d|%10s  |", cliente.idCliente, cliente.nombre);
		printf("%10s  |%25s |%17s|%21d|\n", cliente.cuit, cliente.direccion,
				aux.description, contador);
		retorno = 0;
	}
	return retorno;
}

int mostrarClienteConLocalidad(eCliente cliente, eLocalidad list[],
		int tamLocalidad) {
	eLocalidad aux;
	int retorno;
	retorno = -1;
	if (list != NULL && tamLocalidad > 0) {
		aux = encontrareLocalidadPorId(list, tamLocalidad, cliente.idLocalidad);
		printf("\t\t\t\t\t|%4d|%17s  |", cliente.idCliente, cliente.nombre);
		printf("%10s  |%25s |%17s|\n", cliente.cuit, cliente.direccion,
				aux.description);
		retorno = 0;
	}
	return retorno;
}

int mostrarClientesConLocalidad(eCliente clientes[], int tamCliente,
		eLocalidad localidades[], int tamLocalidades) {
	int retorno;
	retorno = -1;
	if (clientes != NULL && tamCliente > 0 && localidades != NULL
			&& tamLocalidades > 0) {
		printf(
				"\t\t\t\t\t_______________________________________________________________________________________\n");
		printf(
				"\t\t\t\t\t|ID  |NOMBRE             |CUIT           |DIRECCION                 |LOCALIDAD        |\n");
		printf(
				"\t\t\t\t\t|____|___________________|_______________|__________________________|_________________|\n");
		for (int i = 0; i < tamCliente; i++) {
			if (clientes[i].isEmpty == CARGADO) {
				mostrarClienteConLocalidad(clientes[i], localidades,
						tamLocalidades);
			}

		}

		retorno = 0;
	}

	return retorno;
}

int mostrarClientePorId(eCliente clientes[], int tamCliente, eLocalidad list[],
		int tamLocalidad, int idABuscar) {
	int retorno, pos;
	retorno = -1;
	pos = encontrarClientePorId(clientes, tamCliente, idABuscar);
	printf("el empleado fue cargado correctamente:\n");
	printf(
			"\t\t\t\t\t_______________________________________________________________________________________\n");
	printf(
			"\t\t\t\t\t|ID  |NOMBRE             |CUIT           |DIRECCION                 |LOCALIDAD        |\n");
	printf(
			"\t\t\t\t\t|____|___________________|_______________|__________________________|_________________|\n");
	mostrarClienteConLocalidad(clientes[pos], list, tamLocalidad);
	return retorno;
}

int darDeBaja(eCliente cliente[], int tamDeCliente, eLocalidad localidades[],
		int tamLocalidad, ePedidos pedidos[], int tamPedidos) {
	int retorno, id, confirmacion;
	retorno = -1;

	if (cliente != NULL && tamDeCliente > 0) {
		mostrarClientesConLocalidad(cliente, tamDeCliente, localidades,
				tamLocalidad);
		getValidInt("ingrese el id que se quiere eliminar\n", &id);
		getValidInt(
				"si desea confirmar la baja del cliente presione 1, de lo contrario presione cualquier otra tecla\n",
				&confirmacion);
		if (confirmacion == 1) {
			eliminarPedidos(pedidos, tamPedidos, id);
			eliminarCliente(cliente, tamDeCliente, id);
		}

	}
	return retorno;

}

int modificarDireccion(eCliente cliente[], int tamDeCliente,
		eLocalidad localidades[], int tamLocalidad) {
	int retorno, pos;
	retorno = -1;

	if (cliente != NULL && tamDeCliente > 0) {
		mostrarClientesConLocalidad(cliente, tamDeCliente, localidades,
				tamLocalidad);
		getValidInt("ingrese el id que se necesita modificar\n", &pos);
		pos = encontrarClientePorId(cliente, tamDeCliente, pos);
		getString("ingrese la nueva direccion\n", cliente[pos].direccion);

		retorno = 0;
	}

	return retorno;
}

int modificarLocalidad(eCliente cliente[], int tamDeCliente,
		eLocalidad localidades[], int tamLocalidad) {
	int retorno, pos;
	retorno = -1;
	if (cliente != NULL && tamDeCliente > 0) {
		mostrarClientesConLocalidad(cliente, tamDeCliente, localidades,
				tamLocalidad);
		getValidInt("ingrese el id que se necesita modificar\n", &pos);
		pos = encontrarClientePorId(cliente, tamDeCliente, pos);
		printf("\n\n");
		mostrarLocalidades(localidades, tamLocalidad);
		getIntWithParams("ingrese la ID de la nueva localidad\n",
				"ingrese correctamente\n", &cliente[pos].idLocalidad, 1, TAMLOCALIDAD);
		retorno = 0;
	}

	return retorno;
}

//Pedidos

int mostrarPedidosCompletadosConCliente(ePedidos pedidos[], int tamPedido,
		eCliente clientes[], int tamCliente) {
	int retorno;
	retorno = -1;
	if (clientes != NULL && tamCliente > 0 && pedidos != NULL
			&& tamPedido > 0) {
		printf(
				"\t\t\t\t\t__________________________________________________________________________________\n");
		printf(
				"\t\t\t\t\t|CUIT          |DIRECCION                 |Kilos  HDPE |Kilos LDPE  |Kilos PP    |\n");
		printf(
				"\t\t\t\t\t|______________|__________________________|____________|____________|____________|\n");

		for (int i = 0; i < tamCliente; i++) {
			if (pedidos[i].isEmpty == CARGADO && pedidos[i].estado == COMPLETADO) {
				mostrarPedidoCompletadoConCliente(pedidos[i], clientes,
						tamCliente);
			}
		}

	}

	return retorno;
}

int mostrarPedidoCompletadoConCliente(ePedidos pedido, eCliente clientes[],
		int tamClientes) {
	eCliente aux;
	int retorno;
	retorno = -1;
	if (clientes != NULL && tamClientes > 0) {
		aux = encontrarUnClientePorId(clientes, tamClientes, pedido.idCliente);
		printf("\t\t\t\t\t|%14s|%26s|%12.2f|%12.2f|%12.2f|\n", aux.cuit,
				aux.direccion, pedido.HDPE, pedido.LDPE, pedido.PP);

		retorno = 0;
	}
	return retorno;
}

int mostrarPedidoPendienteConCliente(ePedidos pedido, eCliente clientes[],
		int tamClientes) {
	eCliente aux;
	int retorno;
	retorno = -1;
	if (clientes != NULL && tamClientes > 0) {
		aux = encontrarUnClientePorId(clientes, tamClientes, pedido.idCliente);
		printf("\t\t\t\t\t|%4d |%14s|%26s|%12.2f|\n", pedido.IdPedido, aux.cuit,
				aux.direccion, pedido.kilos);

		retorno = 0;
	}
	return retorno;
}

int mostrarPedidosPendientesConCliente(ePedidos pedidos[], int tamPedido,
		eCliente clientes[], int tamCliente) {
	int retorno;
	retorno = -1;
	if (clientes != NULL && tamCliente > 0 && pedidos != NULL
			&& tamPedido > 0) {
		printf(
				"\t\t\t\t\t______________________________________________________________\n");
		printf(
				"\t\t\t\t\t|ID.P.|CUIT          |DIRECCION                 |Kilos       |\n");
		printf(
				"\t\t\t\t\t|_____|______________|__________________________|____________|\n");

		for (int i = 0; i < tamCliente; i++) {
			if (pedidos[i].isEmpty == CARGADO && pedidos[i].estado == PENDIENTE) {
				mostrarPedidoPendienteConCliente(pedidos[i], clientes,
						tamCliente);
			}
		}

	}

	return retorno;
}

int procesarResiduos(ePedidos pedidos[], int tamPedido, eCliente clientes[],
		int tamCliente) {
	int retorno, posPedido;
	retorno = -1;
	if (clientes != NULL && tamCliente > 0 && pedidos != NULL
			&& tamPedido > 0) {

		printf("*Procesamiento De Residuos*\n");
		mostrarPedidosPendientesConCliente(pedidos, tamPedido, clientes,
				tamCliente);

		getValidInt("ingrese el id del pedido que se debera procesar\n",
				&posPedido);
		posPedido = encontrarPedidoPorId(pedidos, tamPedido, posPedido);

		if (posPedido != -1 && pedidos[posPedido].estado == PENDIENTE) {
			ingresoDeTiposDePlastico(pedidos, posPedido);

		}
		retorno = 0;
	}
	return retorno;
}

int ingresoDeTiposDePlastico(ePedidos pedidos[], int pos) {
	float kilosTotales, limiteDeKilosPermitidos;
	kilosTotales = pedidos[pos].kilos;
	limiteDeKilosPermitidos = kilosTotales;

	printf("kilos totales: %.2f\n", kilosTotales);
	getFloatWithParams(
			"ingrese la cantidad de kilos recolectados de polietileno de alta densidad\n",
			"error, ingrese un valor valido.(asegurese"
					"de que no pase de los kilos restantes o kilos totales)\n",
			&pedidos[pos].HDPE, 0, limiteDeKilosPermitidos);

	limiteDeKilosPermitidos = limiteDeKilosPermitidos - pedidos[pos].HDPE;
	printf("kilos restantes(cuidado no poner un valor mayor:%.2f)\n",
			limiteDeKilosPermitidos);
	getFloatWithParams(
			"ingrese la cantidad de kilos de polietileno de baja densidad\n",
			"error, ingrese un valor valido.(asegurese"
					"de que no pase de los kilos restantes o kilos totales)\n",
			&pedidos[pos].LDPE, 0, limiteDeKilosPermitidos);

	limiteDeKilosPermitidos = limiteDeKilosPermitidos - pedidos[pos].LDPE;
	printf("kilos restantes(cuidado no poner un valor mayor:%.2f)\n	",
			limiteDeKilosPermitidos);
	getFloatWithParams("ingrese la cantidad de kilos de polipropileno\n",
			"error, ingrese un valor valido.(asegurese"
					"de que no pase de los kilos restantes o kilos totales)\n",
			&pedidos[pos].PP, 0, limiteDeKilosPermitidos);
	limiteDeKilosPermitidos = limiteDeKilosPermitidos - pedidos[pos].PP;

	pedidos[pos].estado = COMPLETADO;
	if (limiteDeKilosPermitidos > 0) {
		pedidos[pos].basura = limiteDeKilosPermitidos;
	}
	return 0;

}

int CrearPedido(ePedidos pedidos[], int tamPedido, eCliente clientes[],
		int tamCliente, eLocalidad localidades[], int tamLocalidades,
		int *idPedido) {
	int posCliente, retorno, posPedido;
	retorno = -1;
	mostrarClientesConLocalidad(clientes, tamCliente, localidades,
			tamLocalidades);
	if (clientes != NULL && tamCliente > 0 && pedidos != NULL && tamPedido > 0
			&& localidades != NULL) {
		printf("ingrese el ID del cliente que iniciara un pedido\n");
		getValidInt("ingrese el id\n", &posCliente);
		posCliente = encontrarClientePorId(clientes, tamCliente, posCliente);
		if (posCliente != -1) {
			posPedido = encuentraPosicionLibrePedidos(pedidos, tamPedido);
			getValidFloat(
					"ingrese la cantidad de kilos que se recolectaran del cliente\n",
					&pedidos[posPedido].kilos);
			pedidos[posPedido].estado = PENDIENTE;
			*idPedido = *idPedido + 1;
			pedidos[posPedido].IdPedido = *idPedido;
			pedidos[posPedido].idCliente = clientes[posCliente].idCliente;
			pedidos[posPedido].isEmpty = CARGADO;
			retorno = 0;
		}

	}

	return retorno;
}

int contadorDeClientesPendientes(ePedidos list[], int tamPedidos, int id) {
	int contador;
	contador = 0;

	if (list != NULL && tamPedidos > 0) {
		for (int i = 0; i < tamPedidos; i++) {

			if (list[i].idCliente == id && list[i].estado == PENDIENTE) {
				contador++;
			}
		}
	}
	return contador;
}

int muestraDeClientesConContador(eCliente clientes[], int tamCliente,
		eLocalidad localidades[], int tamLocalidades, ePedidos pedidos[],
		int tamPedidos) {
	int contador, retorno;

	retorno = -1;
	if (clientes != NULL && tamCliente > 0 && localidades != NULL
			&& tamLocalidades > 0 && pedidos != NULL && tamPedidos > 0) {
		printf(
				"\t\t\t\t\t______________________________________________________________________________________________________\n");
		printf(
				"\t\t\t\t\t|ID  |NOMBRE      |CUIT           |DIRECCION                 |LOCALIDAD        |Cant.Pedid.Pendientes|\n");
		printf(
				"\t\t\t\t\t|____|____________|_______________|__________________________|_________________|_____________________|\n");
		for (int i = 0; i < tamCliente; i++) {
			if (clientes[i].isEmpty == CARGADO) {
				contador = contadorDeClientesPendientes(pedidos, tamPedidos,
						clientes[i].idCliente);
				mostrarClienteConLocalidadYContador(clientes[i], localidades,
						tamLocalidades, contador);
			}

		}

		retorno = 0;
	}

	return retorno;
}

int cantidadDePedidosPorLocalidad(eLocalidad listaLocalidads[],
		int tamLocalidades, ePedidos listaPedidos[], int tamPedidos,
		eCliente clientes[], int tamClientes) {
	int retorno, idLocalidad, contador;
	retorno = -1;
	contador = 0;
	if (clientes != NULL && tamClientes > 0 && listaLocalidads != NULL
			&& tamLocalidades > 0 && listaPedidos != NULL && tamPedidos > 0) {

		mostrarLocalidades(listaLocalidads, tamLocalidades);
		getIntWithParams(
				"ingrese el id de la localidad que desee, para ver la cantidad de pedidos por localidad\n",
				"ingrese una localidad Valida\n", &idLocalidad, 1, 5);

		contador = contadorDePedidosSegunLocalidad(listaLocalidads,
				tamLocalidades, listaPedidos, tamPedidos, clientes, tamClientes,
				idLocalidad);
		retorno = 0;

	}
	if (retorno == 0) {
		printf("la cantidad de pedidos pendientes de esa localidad son:%d\n",
				contador);

	}

	return retorno;
}

int contadorDePedidosSegunLocalidad(eLocalidad listaLocalidads[],
		int tamLocalidades, ePedidos listaPedidos[], int tamPedidos,
		eCliente clientes[], int tamClientes, int idLocalidad) {
	int contador;
	contador = 0;
	for (int i = 0; i < tamClientes; i++) {
		if (clientes[i].isEmpty == CARGADO
				&& clientes[i].idLocalidad == idLocalidad) {
			contador = contador
					+ contadorDeClientesPendientes(listaPedidos, tamPedidos,
							clientes[i].idCliente);
		}

	}

	return contador;
}

int promedioDeKilosPP(ePedidos pedidos[], int tamPedidos, eCliente clientes[],
		int tamClientes) {
	int retorno, totalClientesCargados;
	float kilosTotales, promedio;
	retorno = -1;

	if (pedidos != NULL && tamPedidos > 0 && clientes != NULL
			&& tamClientes > 0) {
		retorno = 0;
		cantidadDeKilosTotalesDePP(pedidos, tamPedidos, &kilosTotales);
		totalClientesCargados = contadorrDeClientesCargados(clientes,
				tamClientes);
		promedio = kilosTotales / (float) totalClientesCargados;
		printf("el promedio de kilos de polipropileno es de: %.2f ", promedio);
	}

	return retorno;
}

// agregado de parcial.

int buscarClientesConMasPedidos(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos) {

	int retorno, posicionDelClienteConMasPedidos;
	eAuxiliar contadorPedidos[tamClientes];
	eCliente ClienteAuxiliar;
	retorno = -1;
	if (pedidos != NULL && tamPedidos > 0 && clientes != NULL
			&& tamClientes > 0) {

		inicializadorDeAuxiliar(tamClientes, contadorPedidos, clientes);

		for (int i = 0; i < tamClientes; i++) {
			if (clientes[i].isEmpty == CARGADO) {

				sumarContador(contadorPedidos, tamPedidos, pedidos, i);

			}

		}
		posicionDelClienteConMasPedidos = encontrarPosDelMaximo(contadorPedidos,
				tamClientes, clientes);

		ClienteAuxiliar = encontrarUnClientePorId(clientes, tamClientes,
				contadorPedidos[posicionDelClienteConMasPedidos].idCliente);
		printf("el cliente con mas pedidos:  %s\n", ClienteAuxiliar.nombre);
		retorno = 0;

	}
	return retorno;

}

int buscarClienteConMasPedidosCompletados(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos) {
	int retorno, posicionDelClienteConMasPedidosComlpetados;
	eAuxiliar contadorPedidosCompletados[tamClientes];
	eCliente ClienteAuxiliar;
	retorno = -1;

	if (pedidos != NULL && tamPedidos > 0 && clientes != NULL
			&& tamClientes > 0) {

		inicializadorDeAuxiliar(tamClientes, contadorPedidosCompletados,
				clientes);

		for (int i = 0; i < tamClientes; i++) {
			sumarContadorPorIdEstado(contadorPedidosCompletados, tamPedidos,
					pedidos, i, COMPLETADO);

		}
		posicionDelClienteConMasPedidosComlpetados = encontrarPosDelMaximo(
				contadorPedidosCompletados, tamClientes, clientes);
		ClienteAuxiliar =
				encontrarUnClientePorId(clientes, tamClientes,
						contadorPedidosCompletados[posicionDelClienteConMasPedidosComlpetados].idCliente);

		printf("el cliente con mas pedidos completados es: %s\n",
				ClienteAuxiliar.nombre);
		retorno = 0;
	}

	return retorno;
}

int buscarClienteConMasPedidosPendientes(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos) {
	int PosicionclienteConMasPedido, retorno;
	eAuxiliar contadorPedidosPendientes[tamClientes];
	eCliente auxiliarCliente;
	retorno = -1;
	if (pedidos != NULL && tamPedidos > 0 && clientes != NULL
			&& tamClientes > 0) {

		inicializadorDeAuxiliar(tamClientes, contadorPedidosPendientes,
				clientes);

		for (int i = 0; i < tamClientes; i++) {

			sumarContadorPorIdEstado(contadorPedidosPendientes, tamPedidos,
					pedidos, i, PENDIENTE);

		}

		PosicionclienteConMasPedido = encontrarPosDelMaximo(
				contadorPedidosPendientes, tamClientes, clientes);
		auxiliarCliente =
				encontrarUnClientePorId(clientes, tamClientes,
						contadorPedidosPendientes[PosicionclienteConMasPedido].idCliente);
		printf("el cliente con mas pedidos pendientess es: %s\n",
				auxiliarCliente.nombre);
		retorno = 0;

	}

	return retorno;
}

int encontrarPosDelMaximo(eAuxiliar contadorPedidosPendientes[],
		int tamClientes, eCliente clientes[]) {
	int i, bandera, maximo, contadorMaximo;
	bandera = 0;
	contadorMaximo = 0;
	maximo = -1;
	for (i = 0; i < tamClientes; i++) {
		if (clientes[i].isEmpty == CARGADO) {
			if ((bandera == 0 && contadorPedidosPendientes[i].contador != 0)
					|| contadorMaximo < contadorPedidosPendientes[i].contador) {
				contadorMaximo = contadorPedidosPendientes[i].contador;
				maximo = i;
				bandera = 1;
			}

		}

	}
	if (bandera == 0) {
		printf("NO HAY PEDIDOS\n");
	}
	return maximo;
}

int inicializadorDeAuxiliar(int tamClientes,
		eAuxiliar contadorPedidosPendientes[], eCliente clientes[]) {
	for (int i = 0; i < tamClientes; i++) {

		contadorPedidosPendientes[i].contador = 0;
		contadorPedidosPendientes[i].idCliente = clientes[i].idCliente;

	}

	return 0;
}

int sumarContadorPorIdEstado(eAuxiliar contadorPedidosPendientes[],
		int tamPedidos, ePedidos pedidos[], int i, int estado) {

	for (int j = 0; j < tamPedidos; j++) {
		if (contadorPedidosPendientes[i].idCliente == pedidos[j].idCliente
				&& pedidos[j].estado == estado) {
			contadorPedidosPendientes[i].contador =
					contadorPedidosPendientes[i].contador + 1;
		}
	}

	return 0;
}

int sumarContador(eAuxiliar contadorPedidosPendientes[], int tamPedidos,
		ePedidos pedidos[], int i) {

	for (int j = 0; j < tamPedidos; j++) {
		if (contadorPedidosPendientes[i].idCliente == pedidos[j].idCliente) {
			contadorPedidosPendientes[i].contador =
					contadorPedidosPendientes[i].contador + 1;
		}
	}

	return 0;
}

