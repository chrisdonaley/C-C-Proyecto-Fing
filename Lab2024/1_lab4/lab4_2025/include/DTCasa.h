#ifndef DTCASA_H
#define DTCASA_H
#include "DTInmueble.h"
#include "TipoTecho.h"

class DTCasa : public DTInmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        /*Crea un datatype DTCasa con los datos correspondientes*/
        DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);

        /*Devuelve true si y solo si la casa es EsPH*/
        bool getEsPH();

        /*Devuelve el enumerado TipoTecho*/
        TipoTecho getTecho();

        /*Destrulle la casa*/
        virtual ~DTCasa();
};

#endif