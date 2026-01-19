#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include <string>
#include <set>
#include <list>
#include "ControladorFechaActual.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "DTInmobiliaria.h"
#include "DTNotificacion.h"
using namespace std;

class IUsuarioController{
    public:

        /*Crear un nuevo cliente con los datos proporcionados. Notifica en caso de éxito o
        de error al crear al cliente.*/
        virtual bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) = 0;

        /*Crear un nuevo propietario con los datos proporcionados. Notifica en caso de
        éxito o de error al crear al propietario.*/
        virtual bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) = 0;

        /*Crear una nueva inmobiliaria con los datos proporcionados. Notifica en caso de
        éxito o de error al crear la inmobililiaria.*/
        virtual bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) = 0;

        /*Crear una nueva instancia de casa con los datos proporcionados, incluyendo un
        código autogenerado y asociarla al propietario que tiene recordado.*/
        virtual void altaCasa(string direccion, int numeroPuerta, int superficie, int anoContruccion, bool esPH, TipoTecho techo) = 0;

        /*Crear una nueva instancia de apartamento con los datos proporcionados,
        incluyendo un código autogenerado y asociarlo al propietario que tiene
        recordado.*/
        virtual void altaApartamento(string direccion, int numeroPuerta, int superficie, int anoContruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;

        /*Devuelve la información el nickname y nombre de todos los propietarios.*/
        virtual set<DTUsuario*> listarPropietarios() = 0;

        /*Genera una asociación entre la instancia de propietario con el nickname
        proporcionado y la instancia de inmobiliaria recordada.*/
        virtual void representarPropietario(string nicknamePropietario) = 0;

        /*Libera las referencias recordades en el alta de usuario*/
        virtual void finalizarAltaUsuario() = 0;

        /*Se retorna el conjunto de los datavalue dti del tipo DTInmobiliaria 
        correspondientes a las instancias de Inmobiliaria que cumplen que el 
        valor nickname no pertenece a suscriptores */
        virtual set<DTInmobiliaria *> listarNoSuscritas(string nickname) = 0;

        /*Genera una asociación entre la instancia de Inmobiliaria con el nickname 
        proporcionado y la instancia de Cliente (Propietario) recordada*/
        virtual void generarSuscripcion(string nicknameInmobiliaria) = 0;

        /*Se retorna el conjunto de notificaciones de las inmobiliarias a las que el usuario esté suscrito.
        Se muestran notificaciones desde su ultima consulta*/
        virtual list<DTNotificacion *> consultarNotificaciones(string nickName) = 0;

        /*Se retorna el conjunto de Inmobiliarias a las que el usuario este suscrito*/
        virtual set<DTInmobiliaria *> listarSuscripciones(string nickName) = 0;

        /*Elimina la relación de suscripción entre inmobiliaria y usiario (cliente o propietario)*/
        virtual void eliminarSuscripcion(string nicknameInmobiliaria) = 0;
};

#endif 