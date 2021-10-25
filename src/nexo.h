/*
 * nexo.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Thiago
 */

#ifndef NEXO_H_
#define NEXO_H_
#define TAMCLIENTE 100
#define TAMPEDIDOS 1000
#define TAMLOCALIDAD 5

#include "cliente.h"
#include "pedidos.h"
#include "localidad.h"
#include "input.h"
#endif /* NEXO_H_ */

struct {
	int idCliente;
	int contador;
	int isEmpty;
}typedef eAuxiliar;
//clientes.

/// @fn eCliente PedirUnCliente(eLocalidad*, int)
/// @brief pide los datos del eCLiente
/// @param list lista de eLocalidad
/// @param len tamaño de eLocalidad
/// @param idCliente el id del cliente nuevo
/// @return regresa el eCliente.
eCliente PedirUnCliente(eLocalidad *list, int len, int *idCliente);

/// @fn int agregarCliente(eCliente*, int, eLocalidad*, int)
/// @brief añade un cliente a la lista de clientes.
/// @param listaCliente array de eCliente
/// @param lenCliente tamaño del array de eCliente
/// @param listaLocalidad  array de eLocalidad
/// @param lenLocalidad tamaño del array de eLocalidad
/// @param idCliente el id del cliente nuevo
/// @return regresa -1 si hubo un error o 0 si se agrego
int agregarCliente(eCliente *listaCliente, int lenCliente,
		eLocalidad *listaLocalidad, int lenLocalidad, int *idCliente);

/// @fn int mostrarClienteConLocalidad(eCliente, eLocalidad[], int)
/// @param cliente un eCliente
/// @param list array de eLocalidad
/// @param tamLocalidad tamaño de el array de eLocalidad
/// @return  0 si se pudo mostrar -1 si hubo un error.
int mostrarClienteConLocalidad(eCliente cliente, eLocalidad list[],
		int tamLocalidad);

/// @fn int mostrarClientesConLocalidad(eCliente[], int, eLocalidad[], int)
/// @param clientes array de eCliente
/// @param tamCliente tamaño del array de eCliente
/// @param localidades array de eLocalidad
/// @param tamLocalidades tamaño de localidades
/// @return retorna -1 si no se pudo mostrar y 0 si salio todo bien
int mostrarClientesConLocalidad(eCliente clientes[], int tamCliente,
		eLocalidad localidades[], int tamLocalidades);

/// @fn int mostrarClientePorId(eCliente[], int, eLocalidad[], int, int)
/// @param clientes array de eCliente
/// @param tamCliente tamaño del array de eCliente
/// @param list lista de eLocalidad
/// @param tamLocalidad tamaño de la lista de eLocalidad
/// @param idABuscar el id a buscar
/// @return retorna -1 si no se pudo mostrar y 0 si salio todo bien
int mostrarClientePorId(eCliente clientes[], int tamCliente, eLocalidad list[],
		int tamLocalidad, int idABuscar);

/// @fn int modificarDireccion(eCliente[], int, int, eLocalidad[], int)
/// @brief modifica la direccion de un cliente que se selecciona mediantes ids
/// @param cliente array de eClientes
/// @param tamDeCliente tamaño del array de clientes
/// @param id id a buscar
/// @param localidades array de localidades
/// @param tamLocalidad tamaño de array de localidades
/// @return retorna -1 si no se pudo hacer el cambio y 0 si se pudo hacer
int modificarDireccion(eCliente cliente[], int tamDeCliente,
		eLocalidad localidades[], int tamLocalidad);

/// @fn int modificarLocalidad(eCliente[], int, eLocalidad[], int)
/// @brief modifica la localidad de un cliente que se selecciona mediantes ids
/// @param cliente array de eCLientes
/// @param tamDeCliente tamaño del array de eClientes
/// @param localidades array de eLocalidades
/// @param tamLocalidad tamaño del array de eLocalidades
/// @return retorna -1 si no se pudo hacer el cambio y 0 si se pudo hacer
int modificarLocalidad(eCliente cliente[], int tamDeCliente,
		eLocalidad localidades[], int tamLocalidad);

/// @fn int darDeBaja(eCliente[], int, eLocalidad[], int)
/// @brief elimina un cliente segun la id que se ingrese
/// @param cliente array de eCLientes
/// @param tamDeCliente tamaño del array de eClientes
/// @param localidades array de eLocalidades
/// @param tamLocalidad tamaño del array de eLocalidades
/// @return regresa 0 si se dio de baja y -1 si no.

int darDeBaja(eCliente cliente[], int tamDeCliente, eLocalidad localidades[],
		int tamLocalidad, ePedidos pedidos[], int tamPedidos);

int CrearPedido(ePedidos pedidos[], int tamPedido, eCliente clientes[],
		int tamCliente, eLocalidad localidades[], int tamLocalidades,
		int *idPedido);

int procesarResiduos(ePedidos pedidos[], int tamPedido, eCliente clientes[],
		int tamCliente);

/// @fn int ingresoDeTiposDePlastico(ePedidos)
/// @brief  se ingresa la cantidad de tipos de kilos sobre el toral
/// @param pedidos un array de ePedido
/// @param es la posicion que se ingresaran los datos
/// @return regresa 0
int ingresoDeTiposDePlastico(ePedidos pedidos[], int pos);

/// @fn int mostrarPedidoPendienteConCliente(ePedidos, eCliente[], int)
/// @brief muestra pedido pendiente con cliente
/// @param pedido un ePedido
/// @param clientes clientes array de eClientes
/// @param tamClientes tamaño de eClientes
/// @return retorno 0 si salio todo bien -1 si salio mal.
int mostrarPedidoPendienteConCliente(ePedidos pedido, eCliente clientes[],
		int tamClientes);
/// @fn int mostrarPedidosPendientesConCliente(ePedidos[], int, eCliente[], int)
/// @brief muestra los pedidos pendientes con sus clientes
/// @param pedidos lista de ePedidos
/// @param tamPedido tamaño de la lista de ePedidos
/// @param clientes array de eClientes
/// @param tamCliente tamaño de eClientes
/// @return retorno 0 si salio todo bien -1 si salio mal.
int mostrarPedidosPendientesConCliente(ePedidos pedidos[], int tamPedido,
		eCliente clientes[], int tamCliente);

/// @fn int mostrarPedidocompletadoConCliente(ePedidos, eCliente[], int)
/// @brief muestra pedido completo con cliente
/// @param pedido un ePedido
/// @param clientes clientes array de eClientes
/// @param tamClientes tamaño de eClientes
/// @return retorno 0 si salio todo bien -1 si salio mal.
int mostrarPedidoCompletadoConCliente(ePedidos pedido, eCliente clientes[],
		int tamClientes);

/// @fn int mostrarPedidoCompletadoConCliente(ePedidos pedido, eCliente clientes[],tamclientes)
/// @brief muestra los pedidos completados con sus clientes
/// @param pedidos lista de ePedidos
/// @param tamPedido tamaño de la lista de ePedidos
/// @param clientes array de eClientes
/// @param tamCliente tamaño de eClientes
/// @return
int mostrarPedidosCompletadosConCliente(ePedidos pedidos[], int tamPedido,
		eCliente clientes[], int tamCliente);

/// @fn int mostrarClienteConLocalidadYContador(eCliente, eLocalidad[], int, int)
/// @brief muestra un cliente con su localidad y sector
/// @param cliente un eCliente
/// @param list un array de eLocalidades
/// @param tamLocalidad tamaño de array de eLocalidad
/// @param contador contador de pedidos de pendiente
/// @return retorna -1 si fallo y 0 si salio todo bien
int mostrarClienteConLocalidadYContador(eCliente cliente, eLocalidad list[],
		int tamLocalidad, int contador);

/// @fn int muestraDeClientesConContador(eCliente[], int, eLocalidad[], int, ePedidos[], int)
/// @brief muestra los clientes con el contador de los pedidos pendientes
/// @param clientes array de eCliente
/// @param tamCliente tamaño de array eCliente
/// @param localidades array de eLocalidades
/// @param tamLocalidades tamaño de array de eLocalidad
/// @param pedidos array de ePedidos
/// @param tamPedidos tamaño de array de pedidos
/// @return retorna -1 si fallo y 0 si salio todo bien
int muestraDeClientesConContador(eCliente clientes[], int tamCliente,
		eLocalidad localidades[], int tamLocalidades, ePedidos pedidos[],
		int tamPedidos);

/// @fn int cantidadDePedidosPorLocalidad(eLocalidad[], int, ePedidos[], int, eCliente[], int)
/// @brief muestra las localidades y te da a elegir entre las mismas para luego mostrar cuantos pedidos pendientes tiene.
/// @param listaLocalidads array de eLocalidades
/// @param tamLocalidades tamaño del array de eLocalidads
/// @param listaPedidos array de ePedidos
/// @param tamPedidos tamaño del array de ePedidos
/// @param clientes array de eClientes
/// @param tamClientes tamaño de eClientes
/// @return retorna un -1 si fallo un 0 si esta todo bien
int cantidadDePedidosPorLocalidad(eLocalidad listaLocalidads[],
		int tamLocalidades, ePedidos listaPedidos[], int tamPedidos,
		eCliente clientes[], int tamClientes);

/// @fn int contadorDePedidosSegunLocalidad(eLocalidad[], int, ePedidos[], int, eCliente[], int, int)
/// @param listaLocalidads array de eLocalidades
/// @param tamLocalidades tamaño del array de eLocalidads
/// @param listaPedidos array de ePedidos
/// @param tamPedidos tamaño del array de ePedidos
/// @param clientes array de eClientes
/// @param tamClientes tamaño de eClientes
/// @param idLocalidad localidad a buscar en los pedidos pendeintes.
/// @return regresa la cantidad de pedidos segun a localidad
int contadorDePedidosSegunLocalidad(eLocalidad listaLocalidads[],
		int tamLocalidades, ePedidos listaPedidos[], int tamPedidos,
		eCliente clientes[], int tamClientes, int idLocalidad);

/// @fn int promedioDeKilosPP(ePedidos[], int, eCliente[], int)
/// @brief saca el promedio de kilos de prolipropileno
/// @param pedidos array de ePedidos
/// @param tamPedidos tamaño del array de ePedidos
/// @param clientes array de eClientes
/// @param tamClientes tamaño del array de eClientes
/// @return retorna  0 si se pudo sacar el promedio o -1 si no.
int promedioDeKilosPP(ePedidos pedidos[], int tamPedidos, eCliente clientes[],
		int tamClientes);

int buscarClienteConMasPedidosPendientes(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos);

int buscarClienteConMasPedidosCompletados(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos);

int buscarClientesConMasPedidos(eCliente clientes[], int tamClientes,
		ePedidos pedidos[], int tamPedidos);

int sumarContadorPorIdEstado(eAuxiliar contadorPedidosPendientes[],
		int tamPedidos, ePedidos pedidos[], int i, int estado);

int inicializadorDeAuxiliar(int tamClientes,
		eAuxiliar contadorPedidosPendientes[], eCliente clientes[]);

int encontrarPosDelMaximo(eAuxiliar contadorPedidosPendientes[],
		int tamClientes, eCliente clientes[]);
int sumarContador(eAuxiliar contadorPedidosPendientes[], int tamPedidos,
		ePedidos pedidos[], int i);

