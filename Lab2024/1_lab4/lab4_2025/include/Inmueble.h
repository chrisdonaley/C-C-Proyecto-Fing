#ifndef INMUEBLE_H
#define INMUEBLE_H

#include "TipoInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "Inmobiliaria.h"
#include "AdministraPropiedad.h"
#include "DTInmueble.h"
#include "Propietario.h"
#include <set>
#include <string>

using namespace std;

class Inmobiliaria;
class AdministraPropiedad;

class Inmueble {
    private:
        int codigo;
        string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        set<AdministraPropiedad*> administraciones;
        Propietario* propietario;

    public:

        /*Constructor de Inmueble*/
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        
        /*Destructor de Inmueble*/
        virtual ~Inmueble();

        /*Determina si el tipo de Inmueble coincide con tipoInmueble*/
        virtual bool consultarTipo(TipoInmueble tipoInmueble) = 0;
        
        /*Retorna el codigo del Inmueble*/
        int getCodigo();

        /*Retorna la direccion del Inmueble*/
        std::string getDireccion();

        /*Retorna el numero de puerta del Inmueble*/
        int getNumeroPuerta();

        /*Retorna la superficie del Inmueble*/
        int getSuperficie();

        /*Retorna el año de construccion del Inmueble*/
        int getAnoConstruccion(); 

        /*Genera el link entre Propietario y el Inmueble en cuestion*/
        void addPropietario(Propietario* p);

        /*Elimina el link existente entre el propietario y el Inmueble en cuestion*/
        void eliminarLinkPropietario();

        /*Determina si la inmobiliara asociada a este Inmueble mediante administraPropiedad
        coincide con la Inmobiliaria i pasada por parametro*/
        bool esAdministrado(Inmobiliaria *i);

        /*Añade la instancia adminPropiedad a la coleccion administraciones*/
        void asociarAdministracionPropiedad(AdministraPropiedad* adminPropiedad);

        /*Retorna un DTInmueble con los mismos datos que Inmueble*/
        virtual DTInmueble* getDTInmueble();
};

#endif