#ifndef DTINMUEBLELISTADO_H
#define DTINMUEBLELISTADO_H
#include <string>

class DTInmuebleListado {
    private:
        int codigo;
        std::string direccion;
        std::string propietario;

    public:
        /*Crea un datatype DTInmuebleListado con los datos proporcionados*/
        DTInmuebleListado(int codigo, std::string direccion, std::string propietario);

        /*Retorna el codigo que el datatype tiene como atributo*/
        int getCodigo();

        /*Retorna la direccion que el datatype tiene como atributo*/
        std::string getDireccion();

        /*Retorna el propietario que el datatype tiene como atributo*/
        std::string getPropietario();
};

#endif