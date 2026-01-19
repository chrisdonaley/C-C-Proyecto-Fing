#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "Inmueble.h"
#include "Usuario.h"
#include "Publicacion.h"
#include <vector>
#include <set>
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmobiliaria.h"

using namespace std;

// Declaración adelantada
class Inmueble;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmueble* inmueble;
        class Inmobiliaria* inmobiliaria;
        set<Publicacion*> coleccionPublicaciones;
        
    public:
        /*Constructor de AdministraPropiedad*/
        AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble,  Inmobiliaria* inmobiliaria);

        /*Destructor de AdministraPropiedad*/
        ~AdministraPropiedad();

        /*Retorna el Inmueble correspondiente a la instancia de AdministraPropiedad*/
        Inmueble* getInmueble();

        /*Elimina la publicacion que se pasa por parametro de coleccionPublicaciones*/
        void deletePublicacion(Publicacion* publicacion);

        /*Retona aquella publicacion activa de la coleccionPublicaciones que cumple que el tipo
        coincide con tipoPublicacion*/
        Publicacion* getPublicacion(TipoPublicacion tipoPublicacion, bool activa);

        /*Determina si la fecha enviada por parametro coincide con la fecha de la
        instancia de AdministraPropiedad*/
        bool esIgual(DTFecha* fecha);

        /*Retorna el inmueble correspondiente a la instancia de AdministraPropiedad pero
        esta vez lo retorna como una instancia de DTInmuebleAdministrado*/
        DTInmuebleAdministrado* getDTInmuebleAdministrado();

        /*Determina si el inmueble de la instancia de AdministraPropiedad cumple que su
        codigo coincide con codigoInmueble enviado por parametro*/
        bool tieneCodigoInmueble(int codigoInmueble);

        /*Determina si se puede crear una Publicacion basandose en el criterio
        de que no exista un elemento en la coleccionPublicaciones de AdministraPropiedad
        que cumpla que tipoPublicacion=tipoPublicacion y fecha=fehca*/
        bool sePuedeCrear(TipoPublicacion tipoPublicacion, DTFecha* fecha);

        /*Crea una nueva Publicacion y se asegura que no haya mas de una Publicacion activa
        del mismo tipo en la colecccionPublicaciones*/ 
        void crearPublicacion(TipoPublicacion tipoPublicacion, string texto, float precio, int nuevoCodigo, DTFecha* fecha);
        
        /*Determina si el tipo del inmueble de la instancia de AdministraPropiedad coincide
        con tipoInmueble enviado por parametro*/
        bool consultarTipo(TipoInmueble tipoInmueble);

        /*Determina si la inmobiliaria asociada a la instancia de AdministraPropiedad coincide
        con la Inmobiliaria i pasada por parametro*/
        bool inmobiliariaAsociada(Inmobiliaria* i);

        /*Elimina la inmobiliaria asociada*/
        void eliminarLinkInmobiliaria();

        /*Retorna la inmobiliaria asociada*/
        Inmobiliaria* getInmobiliaria();
};

#endif