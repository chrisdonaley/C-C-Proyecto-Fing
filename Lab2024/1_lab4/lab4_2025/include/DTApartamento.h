#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H
#include "DTInmueble.h"

class DTApartamento : public DTInmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        /*Crea un datatype con los datos proporcionados de un apartamento*/
        DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        
        /*Devuelve el piso del Apartamento*/
        int getPiso();

        /*Devuelve true si solo si el Apartamento tiene ascensor*/
        bool getTieneAscensor();

        /*Devuelve los gastos comunes de el Apartamento*/
        float getGastosComunes();

        /*Destruye el datatype DTApartamento*/
        virtual ~DTApartamento();
};

#endif