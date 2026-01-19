#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"
#include <string>
#include "DTInmueble.h"
#include "DTApartamento.h"
using namespace std;


class Apartamento: public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        /*Contruye una instancia Apartamento con los datos proporcionados*/
        Apartamento(int codigo,string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);

        /*Destructor de Apartamento*/
        virtual ~Apartamento();

        /*Retorna true si tipoInmueble es Apartamento, false en caso contrario*/
        virtual bool consultarTipo(TipoInmueble tipoInmueble) override;

        /*Retorna un puntero a un datatype DTInmueble que contiene la información del Apartamento*/
        DTInmueble* getDTInmueble();
};

#endif