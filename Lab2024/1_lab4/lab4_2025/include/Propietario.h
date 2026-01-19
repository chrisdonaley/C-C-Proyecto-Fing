#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>
#include <set>
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "DTInmuebleListado.h"
#include "DTUsuario.h"
#include <list>
#include "DTNotificacion.h"
using namespace std;

// Predeclara clases para evitar dependencias circulares
class Inmueble;
class Inmobiliaria;


class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        set<Inmueble*> coleccionInmuebles;
        list<DTNotificacion*> notificaciones;
        set<Inmobiliaria*> suscripciones;
    public:
        /*Crea una instancia Propietario con los datos proporcionados*/
        Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);

        /*Destructor de Propietario*/
        virtual ~Propietario();

        /*Añade el inmueble al conjutno de inmuebles que el Propietario es dueño*/
        void añadirInmuebles(Inmueble* i);

        /*Elimina el inmueble del conjutno de inmuebles que el Propietario es dueño*/
        void eliminarLinkInmueble(Inmueble* i);


        set<DTInmuebleListado *> getInmueblesNoAdmin(Inmobiliaria* i);

        /*Retorna el datatype DtUsairio con los datos de la instancia Propieatrio*/
        DTUsuario* getDTUsuario();

        /*Retorna el conjutno de suscripciones a Inmboliarias del Propieatrio*/
        set<Inmobiliaria*> getSuscripciones();

        /*Retorna el el conjutno de notificaciones del Cliente*/
        list<DTNotificacion*> getNotificaciones();

        /*Añanade una suscripcion a una Inmobiliria*/
        void añadirSuscripcion(Inmobiliaria* i);

        /*Elimna la suscricion a la Inmoboliaria pasada. 
        PRE: Existe la inmobiliaria en el conjunto de suscripciones*/
        void eliminarSuscripcion(Inmobiliaria* i);

        /*Añade la notificacion al conjutno de notificiones*/       
        void notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto);

        /*Elimina las notificones del Cliente*/
        void eliminarNotificaciones();

        /*Retorna un conjunto de inmuebles que el Propietario es dueño*/
        // PRE: El Propietario tiene al menos un inmueble
        set<Inmueble*> getInmuebles();
};

#endif