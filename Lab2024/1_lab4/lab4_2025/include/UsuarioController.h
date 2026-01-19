#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include "../include/IUsuarioController.h"
#include "../include/Manejador.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmobiliaria.h"
#include <map>
#include <list>

class UsuarioController: public IUsuarioController{
    private:
        static UsuarioController* instance;
        UsuarioController();
        // Instancias a recordar
        Propietario* p = NULL; // Referencia de la instancia creada en altaPropietario
        Inmobiliaria* i = NULL; // Referencia de la instancia creada en altaPropietario
        Propietario* ps = NULL; // Referencia de la instancia creada en listarNoSuscritas
        Cliente* cs = NULL; // Referencia de la instancia creada en listarNoSuscritas

    public:
        virtual ~UsuarioController();
        static UsuarioController* getInstance();
        void destruirInstance();
        bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        void altaCasa(string direccion, int numeroPuerta, int superficie, int anoContruccion, bool esPH, TipoTecho techo);
        void altaApartamento(string direccion, int numeroPuerta, int superficie, int anoContruccion, int piso, bool tieneAscensor, float gastosComunes);
        set<DTUsuario *> listarPropietarios();
        void representarPropietario(string nicknamePropietario);
        void finalizarAltaUsuario();
        set<DTInmobiliaria *> listarNoSuscritas(string nickname);
        void generarSuscripcion(string nicknameInmobiliaria);
        list<DTNotificacion *> consultarNotificaciones(string nickName);
        set<DTInmobiliaria *> listarSuscripciones(string nickName);
        void eliminarSuscripcion(string nicknameInmobiliaria);
};


#endif