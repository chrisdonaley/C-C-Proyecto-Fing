#ifndef IPUBLICACIONINMUEBLECONTROLLER_H
#define IPUBLICACIONINMUEBLECONTROLLER_H

#include "ControladorFechaActual.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include <set>
using namespace std;

class IPublicacionInmuebleController{
    public:

        /*Devuelve la información el nickname y nombre de todos los inmobiliarias*/
        virtual set<DTUsuario*> listarInmobiliarias() = 0;

        /*Devuelve la información de código, dirección y fecha en la que se comenzó a
        administrar para todos los inmuebles administrados por la inmobiliaria.*/
        virtual set<DTInmuebleAdministrado *> listarInmueblesAdministrados(string nicknameInmobiliaria) = 0;
        
        /*Devuelve la información de código, dirección y nombre del propietario de todos
        los inmuebles no administrados por la inmobiliaria de todos los propietarios
        representados*/
        virtual set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria) = 0;
        
        /*Crea una instancia de AdministraInmueble relacionada a la inmobiliaria y el
        inmueble*/
        virtual void altaAdministraPropiedad(string nicknameInmobiliaria, int codigoInmueble) = 0;
        
        /*Crear una nueva publicación en el sistema con los datos proporcionados y
        notificar si se pudo crear con éxito.*/
        virtual bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio) = 0;
        
        /*Devuelve la información de todas las publicaciones que cumplen con los criterios
        de búsqueda.*/
        virtual set<DTPublicacion *> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;
        
        /*Devuelve la información detallada del inmueble de la publicación.*/
        virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;

        /*Devuelve la información de código, dirección y nombre del propietario de todos
        los inmuebles.*/
        virtual set<DTInmuebleListado*> listarInmuebles() = 0;

        /*Devuelve la información detallada del inmueble de la publicación.*/
        virtual DTInmueble* detalleInmueble(int codigoInmueble) = 0;

        /*Elimina del sistema el inmueble con código codigoInmueble junto con las
        instancias de AdministraPropiedad, Publicacion y Agendas asociadas al mismo
        así como también los links relacionados a estos conceptos eliminados*/
        virtual void eliminarInmueble(int codigoInmueble) = 0; 
};

#endif