#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha* fechaComienzo;

    public:
        /*Crea un datatype DTInmuebleAdministrado con los datos proporcionados*/
        DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo);

        /*Retorna el codigo del Inmueble Administrado*/
        int getCodigo();

        /*Retorna la direccion del Inmueble Administrado*/
        std::string getDireccion();

        /*Retorna la fecha de comienzo que se comienza a Administrar el Inmueble*/
        DTFecha* getFechaComienzo();

        /*Destructor de DTInmuebleAdministrado*/
        ~DTInmuebleAdministrado();
};

#endif