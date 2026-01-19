#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"
#include "TipoTecho.h"
#include <string>
#include "DTCasa.h"

class Casa: public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;
    public:
        /*Crea una instancia Casa con los datos proporcionados*/
        Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);

        /*Destructor de Casa*/
        virtual ~Casa();

        /*Retorna true si tipoInmueble es Casa, false en caso contrario*/
        virtual bool consultarTipo(TipoInmueble tipoInmueble) override;

        /*Retorna un puntero a un datatype DTCasa que contiene la información de la Casa*/
        DTInmueble* getDTInmueble();
};

#endif