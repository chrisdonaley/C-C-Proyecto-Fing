#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>
using namespace std;

class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        string texto;
        string precio;
        string inmobiliaria;

    public:
        /*Crea un datatype DTPublicacion con los datos proporcionados*/
        DTPublicacion(int codigo, DTFecha* fecha, string texto, string precio, string inmobiliaria);

        /*Retorna el codigo de la publicacion*/
        int getCodigo();

        /*Retorna la fecha de la publicacion*/
        DTFecha* getFecha();

        /*Retorna el texto de la publicacion*/
        string getTexto();

        /*Retorna el precio de la publicacion*/
        string getPrecio();

        /*Retorna el nombre de la inmobiliaria de la publicacion*/
        string getInmobiliaria();

        /*Destructor de DTPublicacion*/
        ~DTPublicacion();
};

#endif