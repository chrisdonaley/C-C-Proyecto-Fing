#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>
#include <list>
#include "DTNotificacion.h"
#include "Inmobiliaria.h"
using namespace std;

class Cliente : public Usuario {
    private:
        string apellido;
        string documento;
        list<DTNotificacion*> notificaciones;
        set<Inmobiliaria*> suscripciones;
    public:
    
        /*Crea una instancia Cliente con los datos proporcionados*/
        Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);

        /*Destructor de Cliente*/
        virtual ~Cliente();

        /*Retorna el conjutno de suscripciones a Inmboliarias del Cliente*/
        set<Inmobiliaria*> getSuscripciones();

        /*Añanade una suscripcion a una Inmobiliria*/
        void añadirSuscripcion(Inmobiliaria* i);

        /*Elimna la suscricion a la Inmoboliaria pasada. 
        PRE: Existe la inmobiliaria en el conjunto de suscripciones*/
        void eliminarSuscripcion(Inmobiliaria* i);

        /*Añade la notificacion al conjutno de notificiones*/
        void notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto);

        /*Retorna el el conjutno de notificaciones del Cliente*/
        list<DTNotificacion*> getNotificaciones();

        /*Elimina las notificones del Cliente*/
        void eliminarNotificaciones();
};

#endif