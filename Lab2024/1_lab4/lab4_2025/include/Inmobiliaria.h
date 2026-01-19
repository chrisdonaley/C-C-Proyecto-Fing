#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include <string>
#include <set>
#include <vector>
#include "AdministraPropiedad.h"
#include "Propietario.h"
#include "TipoInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
using namespace std;

// Declaración adelantada de la clase AdministraPropiedad
class AdministraPropiedad;
class Propietario;

class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
        set<AdministraPropiedad*> coleccionAdministraPropiedad;
        set<Propietario*> coleccionPropietarios;
        set<Usuario*> suscriptores;
    public:
        /*Crea una instancia Inmobiliaria con los datos proporcionados*/
        Inmobiliaria(string nickname,string contrasena,string nombre, string email, string direccion, string url, string telefono);

        /*Destructor de Inmobiliaria*/
        virtual ~Inmobiliaria();

        /*Retorna un conjunto de datatypes con los Inmuebles que la Inmobiliaria administra*/
        set<DTInmuebleAdministrado*> getDTInmuebleAdministrado();

        /*Retorno el DtUsuario con los datos de Inmobiliaria*/
        DTUsuario* getDTUsuario();

        /*Retorna el ninckname de la Inmobiliaria*/
        string getNickname();

        /*Retorna la direccion de la Inmobiliaria*/
        string getDireccion();

        /*Retorna la url de la Inmobiliaria*/
        string getUrl();

        /*Retorna el telefono de la Inmobiliaria*/
        string getTelefono();

        /*Retorna el conjunto de suscriptores de la inmobiliaria*/
        set<Usuario*> getSuscriptores();

        /*Retrona el conjutno de Inmuebles que no administra de los propietarios a los que representa*/
        set<DTInmuebleListado*> getInmueblesNoAdminPropietario();

        /*Elimina el link a la Administracion de una propiedad*/
        void eliminarLinkAdminPropiedad(AdministraPropiedad* ap);

        /*Crea una nueva Publicacion y notifica a los suscriptores*/
        bool crearPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio, DTFecha* fecha, int nuevoCodigo);       
        
        /*Añade propietarios al conjunto de propietarios representados*/
        void añadirPropietario(Propietario* p);

        /*Crea una nueva instancia de AdministraPropiedad y la asocia al inmueble*/
        void altaAdministracionPropiedad(Inmueble* inmueble, DTFecha* fecha);

        /*Inmobiliaria implementa el metoodo de Usuario para no generar conflictos pero no deberia ser necesario*/
        void notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto);

        /*Añade un suscriptor a la inmobiliaria*/
        void anadirObservadores(Usuario* o);

        /*Elimina un suscriptor*/
        void eliminarObservadores(Usuario* o);

        /*Notifica a el conjunto de observadores sobre la creacion de una publicacion*/
        void notificarObservadores(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto);
};

#endif